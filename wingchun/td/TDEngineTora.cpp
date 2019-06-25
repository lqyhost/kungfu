#include "TDEngineTORA.h"
#include "longfist/tora.h"
#include "longfist/LFUtils.h"
#include "TypeConvert.hpp"
#include <boost/algorithm/string.hpp>

USING_WC_NAMESPACE

#define GBK2UTF8(msg) kungfu::yijinjing::gbk2utf8(string(msg))

TDEngineTORA::TDEngineTORA() : ITDEngine(SOURCE_TORA), req_id(0), real_trade(false)
{
    logger = yijinjing::KfLog::getLogger("TradeEngine.TORA");
    KF_LOG_INFO(logger, "[ATTENTION] default to confirm settlement and no authentication!");
    //logger = KfLog::getLogger("engine.trade.tora");
}

void TDEngineTORA::init()
{
    ITDEngine::init();
    JournalPair tdRawPair = getTdRawJournalPair(source_id);
    raw_writer = yijinjing::JournalWriter::create(tdRawPair.first, tdRawPair.second, "RAW_" + name());
}

void TDEngineTORA:: pre_load(const json& j_config)
{
    front_uri = j_config[WC_CONFIG_KEY_FRONT_URI].get<string>();
    mac = j_config["Mac"].get<string>();
    ip = j_config["IP"].get<string>();
    gw_mac = j_config["GatewayMac"].get<string>();
    gw_inner_ip = j_config["GatewayInnerIP"].get<string>();
    gw_outer_ip = j_config["GatewayOuterIP"].get<string>();
    hd_sn = j_config["HDSerial"].get<string>();
    if (j_config.find("RealTrade") != j_config.end())
    {
        real_trade = j_config["RealTrade"].get<bool>();
    }
}
/*
bool TDEngineTORA::validate_account_info(const json& j_config)
{
    bool is_valid_json = j_config.find("InvestorId") != j_config.end()
                      && j_config["InvestorId"].is_string()
                      && j_config.find(WC_CONFIG_KEY_ACCOUNT_ID) != j_config.end()
                      && j_config[WC_CONFIG_KEY_ACCOUNT_ID].is_string()
                      && j_config.find(WC_CONFIG_KEY_PASSWORD) != j_config.end()
                      && j_config[WC_CONFIG_KEY_PASSWORD].is_string();

    return is_valid_json;
}
*/
TradeAccount TDEngineTORA::load_account(int idx, const json& j_account)
{
    // for tora td, we use InvestorId as UserId, AccountId as InvestorId
    string user_id = j_account[WC_CONFIG_KEY_USER_ID].get<string>();
    string investor_id = j_account[WC_CONFIG_KEY_INVESTOR_ID].get<string>();
    string password = j_account[WC_CONFIG_KEY_PASSWORD].get<string>();

    auto& unit = account_units[idx];
    unit.api = nullptr;
    unit.front_id = -1;
    unit.session_id = -1;
    unit.initialized = false;
    unit.connected = false;
    unit.logged_in = false;
    unit.shareholders[EXCHANGE_SSE] = "";
    unit.shareholders[EXCHANGE_SZE] = "";

    TradeAccount account = {};
    strncpy(account.UserID, user_id.c_str(), 16);
    strncpy(account.InvestorID, investor_id.c_str(), 19);
    strncpy(account.Password, password.c_str(), 21);
    return account;
}

void TDEngineTORA::resize_accounts(int account_num)
{
    account_units.resize(account_num);
}

void TDEngineTORA::release_api()
{
    for (size_t idx = 0; idx < account_units.size(); idx++)
    {
        auto& unit = account_units[idx];
        unit.initialized = false;
        if (nullptr != unit.api)
        {
            unit.api->Release();
            unit.api = nullptr;
        }
    }
}

void TDEngineTORA::connect(long timeout_nsec)
{
    KF_LOG_INFO(logger, "[connect] connect " );
    for (size_t idx=0; idx <account_units.size(); idx ++)
    {
        if (account_units[idx].api == nullptr)
        {
            CTORATstpTraderApi* api = CTORATstpTraderApi::CreateTstpTraderApi();
            if (!api)
            {
                throw std::runtime_error("TORA_TD failed to create api");
            }
            api->RegisterSpi(this);
            account_units[idx].api = api;
            KF_LOG_INFO(logger, "[unit.api] "<<(account_units[idx].api != nullptr)<<" "<<idx );
        }
        if (!account_units[idx].connected)
        {
            curAccountIdx = idx;
            account_units[idx].api->RegisterFront((char*)front_uri.c_str());
            account_units[idx].api->SubscribePrivateTopic(TORA_TERT_QUICK);
            account_units[idx].api->SubscribePublicTopic(TORA_TERT_QUICK);
            if (!account_units[idx].initialized)
            {
                account_units[idx].api->Init();
                account_units[idx].initialized = true;
            }
            long start_time = yijinjing::getNanoTime();
            while (!account_units[idx].connected && yijinjing::getNanoTime() - start_time < timeout_nsec)
            {}
        }
    }
}

bool TDEngineTORA::is_connected() const
{
    for (auto& unit: account_units)
    {
        if (!unit.connected)
            return false;
    }
    return true;
}

bool TDEngineTORA::is_logged_in() const
{
    for (auto& unit: account_units)
    {
        if (!unit.logged_in)
            return false;
    }
    return true;
}

void TDEngineTORA::login(long timeout_nsec)
{
    KF_LOG_INFO(logger, "[request] login "<<account_units.size() );
    for (size_t idx = 0; idx < account_units.size(); idx ++)
    {
        curAccountIdx = idx;
        KF_LOG_INFO(logger, "[unit.api] "<<(account_units[idx].api != nullptr)<<" "<<idx );
        AccountUnitTORA& unit = account_units[idx];
        TradeAccount& account = accounts[idx];
        KF_LOG_INFO(logger, "[request] " << " (InvestorID)" << account.InvestorID);
        if (!unit.logged_in)
        {
            KF_LOG_INFO(logger, "[request] in " << " (InvestorID)" << account.InvestorID);
            CTORATstpReqUserLoginField req = {};
            req.LogInAccountType = TORA_TSTP_LACT_UserID;
            strncpy(req.LogInAccount, account.InvestorID, 21);
            strncpy(req.Password, account.Password, 41);

            strncpy(req.MacAddress, mac.c_str(), 21);
            strncpy(req.ClientIPAddress, ip.c_str(), 16);
            strncpy(req.GWMacAddress, gw_mac.c_str(), 21);
            strncpy(req.GWInnerIPAddress, gw_inner_ip.c_str(), 16);
            strncpy(req.GWOuterIPAddress, gw_outer_ip.c_str(), 16);
            strncpy(req.HDSerial, hd_sn.c_str(), 33);

            if (unit.api != nullptr)
            {
                KF_LOG_ERROR(logger, "[request] unit.api != nullptr" << " (Uid)" << req.LogInAccount);
                int rid = unit.api->ReqUserLogin(&req, request_id++);
                account_units[idx].login_rid = request_id - 1;
                if  (rid)
                {
                    KF_LOG_ERROR(logger, "[request] login failed!" << " (Uid)" << req.LogInAccount);
                }

            }
            else
            {
                KF_LOG_INFO(logger, "[request] login !" << " (Uid)" << req.LogInAccount);
            }

            long start_time = yijinjing::getNanoTime();
            //while (!unit.logged_in && yijinjing::getNanoTime() - start_time < timeout_nsec)
            while (!unit.logged_in && yijinjing::getNanoTime() - start_time <  timeout_nsec)
            {
            }
        }
        else
        {
            KF_LOG_INFO(logger, "[request] alread login !" << " (InvestorID)" << account.InvestorID);
        }
        
    }
}

void TDEngineTORA::logout()
{
    for (size_t idx = 0; idx < account_units.size(); idx++)
    {
        AccountUnitTORA& unit = account_units[idx];
        TradeAccount& account = accounts[idx];
        if (unit.logged_in)
        {
            CTORATstpUserLogoutField req = {};
            strncpy(req.UserID, account.UserID, 16);
            if (account_units[idx].api->ReqUserLogout(&req, ++req_id) != 0)
            {
                KF_LOG_ERROR(logger, "[Logout] Logout failed! (Uid)" << account.UserID);
            }
        }
        unit.logged_in = false;
    }
}

void TDEngineTORA::req_investor_position(const LFQryPositionField* data, int account_index, int requestId)
{
    CTORATstpQryPositionField req = parseTo(*data);
    auto& account = accounts[account_index];//  account_helper->get_trade_account(account_index);
    strncpy(req.InvestorID, account.UserID, 13);
    int ret = account_units[account_index].api->ReqQryPosition(&req, requestId);
    if (ret != 0)
    {
        KF_LOG_ERROR(logger, "[ReqPos] Request investor position failed!" << " (rid)" << requestId
                                                                           << " (idx)" << account_index
                                                                           << " (error_id)" << ret);
    }
    send_writer->write_frame(&req, sizeof(CTORATstpQryPositionField), source_id, MSG_TYPE_LF_QRY_POS_TORA, 1, requestId);
}

void TDEngineTORA::req_qry_account(const LFQryAccountField* data, int account_index, int requestId)
{
    CTORATstpQryTradingAccountField req = parseTo(*data);
    auto& account = accounts[account_index];//account_helper->get_trade_account(account_index);
    if (real_trade)
    {
        strcat(req.AccountID, "01");
    }
    strncpy(req.InvestorID, account.UserID, 13);
    strcpy(req.CurrencyID, "CNY");
    int ret = account_units[account_index].api->ReqQryTradingAccount(&req, requestId);
    if (ret != 0)
    {
        KF_LOG_ERROR(logger, "[ReqAcc] Request trading account failed!" << " (rid)" << requestId
                                                                        << " (idx)" << account_index
                                                                        << " (error_id)" << ret);
    }
    send_writer->write_frame(&req, sizeof(CTORATstpQryTradingAccountField), source_id, MSG_TYPE_LF_QRY_ACCOUNT_TORA, 1, requestId);
}

void TDEngineTORA::req_order_insert(const LFInputOrderField* data, int account_index, int requestId, long rcv_time)
{
    auto& unit = account_units[account_index];
    CTORATstpInputOrderField req = parseTo(*data);
    if (real_trade)
    {
        strcat(req.AccountID, "01");
    }
    if (unit.shareholders.find(data->ExchangeID) != unit.shareholders.end())
        strncpy(req.ShareholderID, unit.shareholders[data->ExchangeID].c_str(), 11);
    if (data->OrderPriceType == LF_CHAR_AnyPrice)
    {
        req.OrderPriceType = TORA_TSTP_OPT_FiveLevelPrice;
    }
    int ret = account_units[account_index].api->ReqOrderInsert(&req, requestId);
    if (ret != 0)
    {
        KF_LOG_ERROR(logger, "[OrderInsert] Request order insert failed!" << " (rid)" << requestId
                                                                          << " (idx)" << account_index);
    }
    send_writer->write_frame(&req, sizeof(CTORATstpInputOrderField), source_id, MSG_TYPE_LF_ORDER_TORA, 1, requestId);
}

void TDEngineTORA::req_order_action(const LFOrderActionField* data, int account_index, int requestId, long rcv_time)
{
    CTORATstpInputOrderActionField req = parseTo(*data);
    req.FrontID = account_units[account_index].front_id;
    req.SessionID = account_units[account_index].session_id;
    if (EngineUtil::getExchangeIdFromStockTicker(data->InstrumentID) == 1)
    {
        req.ExchangeID = '1';
    }
    else
    {
        req.ExchangeID = '2';
    }
    auto& account = accounts[account_index]; //account_helper->get_trade_account(account_index);
    strncpy(req.InvestorID, account.UserID, 13);
    KF_LOG_INFO(logger, "[OrderAction] (investor_id)" << req.InvestorID << " (security)" << req.SecurityID << " (user)" << req.UserID 
                                                      << " (exchange)" << req.ExchangeID);
    int ret = account_units[account_index].api->ReqOrderAction(&req, requestId);
    if (ret != 0)
    {
        KF_LOG_ERROR(logger, "[OrderAction] Request order action failed!" << " (rid)" << requestId
                                                                          << " (idx)" << account_index
                                                                          << " (error_id)" << ret);
    }
    send_writer->write_frame(&req, sizeof(CTORATstpInputOrderActionField), source_id, MSG_TYPE_LF_ORDER_ACTION_TORA, 1, requestId);
}

void TDEngineTORA::OnFrontConnected()
{
    KF_LOG_INFO(logger, "[Connect] (account)" << accounts[curAccountIdx].UserID);
    account_units[curAccountIdx].connected = true;
}

void TDEngineTORA::OnFrontDisconnected(int nReason)
{
    KF_LOG_INFO(logger, "[Connect] (reason)" << nReason << " (idx)" <<  curAccountIdx);
    account_units[curAccountIdx].connected = false;
}

void TDEngineTORA::OnRspError(CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
        KF_LOG_ERROR(logger, "[OnRspError]" << " (errID)" << pRspInfo->ErrorID
                                            << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg)
                                            << " (requestID)" << nRequestID
                                            << " (isLast)" << bIsLast);
    }
}

void TDEngineTORA::OnRspUserLogin(CTORATstpRspUserLoginField *pRspUserLoginField, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    KF_LOG_INFO(logger, "[OnRspUserLogin]");
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
         KF_LOG_ERROR(logger, "[Login] OnRspUserLogin Error " << " (errID)" << pRspInfo->ErrorID
                                                              << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg)
                                                              << " (isLast)" << bIsLast);
    }
    else
    {
        KF_LOG_INFO(logger, "[Login] OnRspUserLogin" << " (Uid)" << pRspUserLoginField->UserID
                                                     << " (SName)" << pRspUserLoginField->SystemName);

        for (auto& unit: account_units)
        {
            KF_LOG_INFO(logger, "login_rid: "<<unit.login_rid << " nRequestID: " << nRequestID);
            if (unit.login_rid == nRequestID)
            {
                unit.front_id = pRspUserLoginField->FrontID;
                unit.session_id = pRspUserLoginField->SessionID;
                unit.logged_in = true;
                CTORATstpQryShareholderAccountField req = {};
                strcpy(req.InvestorID, accounts[curAccountIdx].InvestorID);
                KF_LOG_INFO(logger, "ReqQryShareholderAccount InvestorID: " << accounts[curAccountIdx].InvestorID <<" nullptr: "<<(unit.api == nullptr));
                //strcpy(req.InvestorID, pRspUserLoginField->UserID);

                req.TradingCodeClass = TORA_TSTP_CIDT_Normal;
                int rid = unit.api->ReqQryShareholderAccount(&req, request_id++);
                KF_LOG_INFO(logger,"rid: "<<request_id);
                long start_time = yijinjing::getNanoTime();
                while (((unit.shareholders[EXCHANGE_SSE] == "") || (unit.shareholders[EXCHANGE_SZE] == "")) && yijinjing::getNanoTime() - start_time < 5*1e9)
                {}
                if ((unit.shareholders[EXCHANGE_SSE] == "") || (unit.shareholders[EXCHANGE_SZE] == ""))
                {
                    KF_LOG_INFO(logger,"shareholders did not get: "<<EXCHANGE_SSE<<unit.shareholders[EXCHANGE_SSE]<<EXCHANGE_SZE<<unit.shareholders[EXCHANGE_SZE]);
                }
                else
                {
                    KF_LOG_INFO(logger,"shareholders: sse: "<<unit.shareholders[EXCHANGE_SSE]<<"sze: "<<unit.shareholders[EXCHANGE_SZE]);
                }
                
            }
            //todo
        }
    }
}

void TDEngineTORA::OnRspUserLogout(CTORATstpUserLogoutField *pUserLogoutField, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
         KF_LOG_ERROR(logger, "[Logout] OnRspUserLogout" << " (errID)" << pRspInfo->ErrorID
                                                         << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg)
                                                         << " (isLast)" << bIsLast);
    }
    else
    {
        KF_LOG_INFO(logger, "[Logout] OnRspUserLogout" << " (Uid)" << pUserLogoutField->UserID);
        if ( curAccountIdx >= 0)
        {
            auto& unit =  account_units[curAccountIdx];
            unit.front_id = -1;
            unit.session_id = -1;
        }
         account_units[curAccountIdx].logged_in = false;
    }
}

void TDEngineTORA::OnRspOrderInsert(CTORATstpInputOrderField *pInputOrderField, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    LFInputOrderField data = {};
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
        on_rsp_order_insert(&data, nRequestID, pRspInfo->ErrorID, GBK2UTF8(pRspInfo->ErrorMsg).c_str());
    }
    else
    {
        data = parseFrom(*pInputOrderField);
        on_rsp_order_insert(&data, nRequestID);
    }
}

void TDEngineTORA::OnErrRtnOrderInsert(CTORATstpInputOrderField *pInputOrder, CTORATstpRspInfoField *pRspInfo)
{
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
        KF_LOG_ERROR(logger, "[OrderInsert] OnErrRtnOrderInsert" << " (errID)" << pRspInfo->ErrorID
                                                                 << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg));
    }
}

void TDEngineTORA::OnRspOrderAction(CTORATstpInputOrderActionField *pInputOrderActionField, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    LFOrderActionField data = {};
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
        on_rsp_order_action(&data, nRequestID, pRspInfo->ErrorID, GBK2UTF8(pRspInfo->ErrorMsg).c_str());
    }
    else
    {
        data = parseFrom(*pInputOrderActionField);
        on_rsp_order_action(&data, nRequestID);
    }
}

void TDEngineTORA::OnErrRtnOrderAction(CTORATstpOrderActionField *pOrderAction, CTORATstpRspInfoField *pRspInfo)
{
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
        KF_LOG_ERROR(logger, "[OrderAction] OnErrRtnOrderAction" << " (errID)" << pRspInfo->ErrorID
                                                                 << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg));
    }
}

void TDEngineTORA::OnRtnOrder(CTORATstpOrderField *pOrder)
{
    auto data = parseFrom(*pOrder);
    on_rtn_order(&data);
    raw_writer->write_frame(pOrder, sizeof(CTORATstpOrderField), source_id, MSG_TYPE_LF_RTN_ORDER_TORA, 1, (pOrder->RequestID > 0) ? pOrder->RequestID: -1);
}

void TDEngineTORA::OnRtnTrade(CTORATstpTradeField *pTrade)
{
    auto data = parseFrom(*pTrade);
    on_rtn_trade(&data);
    raw_writer->write_frame(pTrade, sizeof(CTORATstpTradeField), source_id, MSG_TYPE_LF_RTN_TRADE_TORA, 1, -1);
}

void TDEngineTORA::OnRspQryTradingAccount(CTORATstpTradingAccountField *pTradingAccount, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    // AccountID?
    LFRspAccountField acc = {};
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
        on_rsp_account(&acc, bIsLast, nRequestID, pRspInfo->ErrorID, GBK2UTF8(pRspInfo->ErrorMsg).c_str());
    }
    else
    {
        CTORATstpTradingAccountField empty = {};
        if (nullptr == pTradingAccount)
        {
            pTradingAccount = &empty;
        }
        int account_idx = curAccountIdx;
        if (account_idx >= 0)
        {
            auto& account = accounts[curAccountIdx];// account_helper->get_trade_account(account_idx);
             
            if (strcmp(account.InvestorID, pTradingAccount->AccountOwner) == 0)
            {
                acc = parseFrom(*pTradingAccount);
                on_rsp_account(&acc, true, nRequestID);
            }
        }
        else
        {
            if (strlen(pTradingAccount->AccountID) > 0)
            {
                acc = parseFrom(*pTradingAccount);
                on_rsp_account(&acc, true, nRequestID);
            }
        }
        //to do
    }
}

void TDEngineTORA::OnRspQryPosition(CTORATstpPositionField *pPosition, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    // CurrentPosition?
    LFRspPositionField pos = {};
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
        on_rsp_position(&pos, bIsLast, nRequestID, pRspInfo->ErrorID, GBK2UTF8(pRspInfo->ErrorMsg).c_str());
    }
    else
    {
        CTORATstpPositionField empty = {};
        if (nullptr == pPosition)
        {
            pPosition = &empty;
        }
        auto pos = parseFrom(*pPosition);
        on_rsp_position(&pos, bIsLast, nRequestID);
    }
}

void TDEngineTORA::OnRspQryShareholderAccount(CTORATstpShareholderAccountField *pShareholderAccount, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
        KF_LOG_ERROR(logger, "[Logout] OnRspQryShareholderAccount"
                << " (errID)" << pRspInfo->ErrorID
                << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg)
                << " (isLast)" << bIsLast);
    }
    else
    {
        if (nullptr != pShareholderAccount)
        {
            char exchange[9] = {0};
            FromToraExchangeId(exchange, pShareholderAccount->ExchangeID);

            if ( curAccountIdx >= 0)
            {
                KF_LOG_INFO(logger, "[Shareholder]" << " (exchange)" << exchange << " (shareholderID)" << pShareholderAccount->ShareholderID);
                auto& unit = account_units[curAccountIdx];
                unit.shareholders[exchange] = pShareholderAccount->ShareholderID;
            }
        }
    }
    if (bIsLast)
    {
        account_units[curAccountIdx].logged_in = true;
        KF_LOG_INFO(logger, "[bIsLast]"<<curAccountIdx);
        //status_wrapper->on_login();
    }
}

//EXPORT_ENGINE_TO_PYTHON(libtoratd, TDEngineTORA);
BOOST_PYTHON_MODULE(libtoratd)
{
    using namespace boost::python;
    class_<TDEngineTORA, boost::shared_ptr<TDEngineTORA> >("Engine")
    .def(init<>())
    .def("init", &TDEngineTORA::initialize)
    .def("start", &TDEngineTORA::start)
    .def("stop", &TDEngineTORA::stop)
    .def("logout", &TDEngineTORA::logout)
    .def("wait_for_stop", &TDEngineTORA::wait_for_stop);
}