#include "TDEngineTora.h"
#include "longfist/tora.h"
#include "longfist/LFUtils.h"
#include "TypeConvert.hpp"
#include <boost/algorithm/string.hpp>

USING_WC_NAMESPACE

#define GBK2UTF8(msg) kungfu::gbk2utf8(string(msg))

TDEngineTora::TDEngineTora() : ITDEngine(SOURCE_TORA), req_id(0), real_trade(false)
{
    logger = KfLog::getLogger("engine.trade.tora");
}

void TDEngineTora::init()
{
    ITDEngine::init();
    JournalPair tdRawPair = getTdRawJournalPair(source_id);
    raw_writer = yijinjing::JournalWriter::create(tdRawPair.first, tdRawPair.second, "RAW_" + name());
}

void TDEngineTora:: pre_load(const json& j_config)
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

bool TDEngineTora::validate_account_info(const json& j_config)
{
    bool is_valid_json = j_config.find("InvestorId") != j_config.end()
                      && j_config["InvestorId"].is_string()
                      && j_config.find(WC_CONFIG_KEY_ACCOUNT_ID) != j_config.end()
                      && j_config[WC_CONFIG_KEY_ACCOUNT_ID].is_string()
                      && j_config.find(WC_CONFIG_KEY_PASSWORD) != j_config.end()
                      && j_config[WC_CONFIG_KEY_PASSWORD].is_string();

    return is_valid_json;
}

TradeAccount TDEngineTora::load_account(int idx, const json& j_account)
{
    // for tora td, we use InvestorId as UserId, AccountId as InvestorId
    string user_id = j_account["InvestorId"].get<string>();
    string investor_id = j_account[WC_CONFIG_KEY_ACCOUNT_ID].get<string>();
    string password = j_account[WC_CONFIG_KEY_PASSWORD].get<string>();

    auto& unit = account_units[idx];
    unit.api = nullptr;
    unit.front_id = -1;
    unit.session_id = -1;
    unit.api_initialized = false;
    unit.shareholders[EXCHANGE_SSE] = "";
    unit.shareholders[EXCHANGE_SZE] = "";

    TradeAccount account = {};
    strncpy(account.UserID, user_id.c_str(), 16);
    strncpy(account.InvestorID, investor_id.c_str(), 19);
    strncpy(account.Password, password.c_str(), 21);
    return account;
}

void TDEngineTora::resize_accounts(int account_num)
{
    account_units.resize(account_num);
}

bool TDEngineTora::try_init(size_t account_idx)
{
    auto& unit = account_units[account_idx];
    drop_api(account_idx);
    unit.api = CTORATstpTraderApi::CreateTstpTraderApi();
    if (nullptr == unit.api)
    {
        KF_LOG_ERROR(logger, "[Init] Failed to create api for acc (acc_idx) " << account_idx);
        return false;
    }
    unit.api->RegisterSpi(this);
    return true;
}

void TDEngineTora::drop_api(size_t account_idx)
{
    auto& unit = account_units[account_idx];
    unit.api_initialized = false;
    if (nullptr != unit.api)
    {
        unit.api->Release();
        unit.api = nullptr;
    }
}

bool TDEngineTora::req_connect(size_t account_idx)
{
    auto& unit = account_units[account_idx];
    if (!unit.api_initialized)
    {
        unit.api->RegisterFront((char*)front_uri.c_str());
        unit.api->SubscribePrivateTopic(TORA_TERT_QUICK);
        unit.api->SubscribePublicTopic(TORA_TERT_QUICK);
        unit.api->Init();
        unit.api_initialized = true;
    }
    return true;
}

bool TDEngineTora::req_disconnect(size_t account_idx)
{
    auto& unit = account_units[account_idx];
    unit.api_initialized = false;
    status_wrapper->on_disconnect();
    return true;
}

bool TDEngineTora::req_login(size_t account_idx)
{
    auto& account = account_helper->get_trade_account(account_idx);
    CTORATstpReqUserLoginField req = {};
    strncpy(req.LogInAccount, account.InvestorID, 21);
    strncpy(req.MacAddress, mac.c_str(), 21);
    strncpy(req.ClientIPAddress, ip.c_str(), 16);
    strncpy(req.GWMacAddress, gw_mac.c_str(), 21);
    strncpy(req.GWInnerIPAddress, gw_inner_ip.c_str(), 16);
    strncpy(req.GWOuterIPAddress, gw_outer_ip.c_str(), 16);
    strncpy(req.HDSerial, hd_sn.c_str(), 33);

    req.LogInAccountType = TORA_TSTP_LACT_UserID;

    strncpy(req.Password, account.Password, 41);
    if (account_units[account_idx].api->ReqUserLogin(&req, ++req_id) != 0)
    {
        KF_LOG_ERROR(logger, "[Login] Login failed! (Iid)" << account.InvestorID);
        return false;
    }
    return true;
}

bool TDEngineTora::req_logout(size_t account_idx)
{
    auto& account = account_helper->get_trade_account(account_idx);
    CTORATstpUserLogoutField req = {};
    strncpy(req.UserID, account.UserID, 16);
    if (account_units[account_idx].api->ReqUserLogout(&req, ++req_id) != 0)
    {
        KF_LOG_ERROR(logger, "[Logout] Logout failed! (Uid)" << account.UserID);
        return false;
    }

    // OnRspUserLogout won't be called for current
    status_wrapper->on_logout();
    return true;
}

bool TDEngineTora::req_investor_position(const LFQryPositionField* data, int account_index, int requestId)
{
    CTORATstpQryPositionField req = parseTo(*data);
    auto& account = account_helper->get_trade_account(account_index);
    strncpy(req.InvestorID, account.UserID, 13);
    int ret = account_units[account_index].api->ReqQryPosition(&req, requestId);
    if (ret != 0)
    {
        KF_LOG_ERROR(logger, "[ReqPos] Request investor position failed!" << " (rid)" << requestId
                                                                           << " (idx)" << account_index
                                                                           << " (error_id)" << ret);
        return false;
    }
    send_writer->write_frame(&req, sizeof(CTORATstpQryPositionField), source_id, MSG_TYPE_LF_QRY_POS_TORA, 1, requestId);
    return true;
}

bool TDEngineTora::req_qry_account(const LFQryAccountField* data, int account_index, int requestId)
{
    CTORATstpQryTradingAccountField req = parseTo(*data);
    auto& account = account_helper->get_trade_account(account_index);
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
        return false;
    }
    send_writer->write_frame(&req, sizeof(CTORATstpQryTradingAccountField), source_id, MSG_TYPE_LF_QRY_ACCOUNT_TORA, 1, requestId);
    return true;
}

bool TDEngineTora::req_order_insert(const LFInputOrderField* data, int account_index, int requestId, long rcv_time)
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
                                                                          << " (idx)" << account_index
                                                                          << " (error_id)" << ret);
        return false;
    }
    send_writer->write_frame(&req, sizeof(CTORATstpInputOrderField), source_id, MSG_TYPE_LF_ORDER_TORA, 1, requestId);
    return true;
}

bool TDEngineTora::req_order_action(const LFOrderActionField* data, int account_index, int requestId, long rcv_time)
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
    auto& account = account_helper->get_trade_account(account_index);
    strncpy(req.InvestorID, account.UserID, 13);
    KF_LOG_INFO(logger, "[OrderAction] (investor_id)" << req.InvestorID << " (security)" << req.SecurityID << " (user)" << req.UserID 
                                                      << " (exchange)" << req.ExchangeID);
    int ret = account_units[account_index].api->ReqOrderAction(&req, requestId);
    if (ret != 0)
    {
        KF_LOG_ERROR(logger, "[OrderAction] Request order action failed!" << " (rid)" << requestId
                                                                          << " (idx)" << account_index
                                                                          << " (error_id)" << ret);
        return false;
    }
    send_writer->write_frame(&req, sizeof(CTORATstpInputOrderActionField), source_id, MSG_TYPE_LF_ORDER_ACTION_TORA, 1, requestId);
    return true;
}

void TDEngineTora::OnFrontConnected()
{
    KF_LOG_INFO(logger, "[Connect] (idx)" << status_wrapper->get_current_account_idx());
    status_wrapper->on_connect();
}

void TDEngineTora::OnFrontDisconnected(int nReason)
{
    KF_LOG_INFO(logger, "[Connect] (reason)" << nReason << " (idx)" << status_wrapper->get_current_account_idx());
    status_wrapper->on_disconnect();
}

void TDEngineTora::OnRspError(CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
        KF_LOG_ERROR(logger, "[OnRspError]" << " (errID)" << pRspInfo->ErrorID
                                            << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg)
                                            << " (requestID)" << nRequestID
                                            << " (isLast)" << bIsLast);
    }
}

void TDEngineTora::OnRspUserLogin(CTORATstpRspUserLoginField *pRspUserLoginField, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
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
        int account_idx = status_wrapper->get_current_account_idx();
        if (account_idx >= 0)
        {
            auto& unit = account_units[account_idx];
            unit.front_id = pRspUserLoginField->FrontID;
            unit.session_id = pRspUserLoginField->SessionID;

            // req shareholder info
            auto& account = account_helper->get_trade_account(account_idx);

            CTORATstpQryShareholderAccountField req = {};
            strcpy(req.InvestorID, account.InvestorID);
            req.TradingCodeClass = TORA_TSTP_CIDT_Normal;
            unit.api->ReqQryShareholderAccount(&req, 100);
        }
        else
        {
            status_wrapper->on_login();
        }
    }
}

void TDEngineTora::OnRspUserLogout(CTORATstpUserLogoutField *pUserLogoutField, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
        if (status_wrapper->get_current_account_idx() >= 0)
        {
            auto& unit = account_units[status_wrapper->get_current_account_idx()];
            unit.front_id = -1;
            unit.session_id = -1;
        }
        status_wrapper->on_logout();
    }
}

void TDEngineTora::OnRspOrderInsert(CTORATstpInputOrderField *pInputOrderField, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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

void TDEngineTora::OnErrRtnOrderInsert(CTORATstpInputOrderField *pInputOrder, CTORATstpRspInfoField *pRspInfo)
{
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
        KF_LOG_ERROR(logger, "[OrderInsert] OnErrRtnOrderInsert" << " (errID)" << pRspInfo->ErrorID
                                                                 << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg));
    }
}

void TDEngineTora::OnRspOrderAction(CTORATstpInputOrderActionField *pInputOrderActionField, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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

void TDEngineTora::OnErrRtnOrderAction(CTORATstpOrderActionField *pOrderAction, CTORATstpRspInfoField *pRspInfo)
{
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
        KF_LOG_ERROR(logger, "[OrderAction] OnErrRtnOrderAction" << " (errID)" << pRspInfo->ErrorID
                                                                 << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg));
    }
}

void TDEngineTora::OnRtnOrder(CTORATstpOrderField *pOrder)
{
    auto data = parseFrom(*pOrder);
    on_rtn_order(&data);
    raw_writer->write_frame(pOrder, sizeof(CTORATstpOrderField), source_id, MSG_TYPE_LF_RTN_ORDER_TORA, 1, (pOrder->RequestID > 0) ? pOrder->RequestID: -1);
}

void TDEngineTora::OnRtnTrade(CTORATstpTradeField *pTrade)
{
    auto data = parseFrom(*pTrade);
    on_rtn_trade(&data);
    raw_writer->write_frame(pTrade, sizeof(CTORATstpTradeField), source_id, MSG_TYPE_LF_RTN_TRADE_TORA, 1, -1);
}

void TDEngineTora::OnRspQryTradingAccount(CTORATstpTradingAccountField *pTradingAccount, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
        int account_idx = status_wrapper->get_current_account_idx();
        if (account_idx >= 0)
        {
            auto& account = account_helper->get_trade_account(account_idx);
             
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
    }
}

void TDEngineTora::OnRspQryPosition(CTORATstpPositionField *pPosition, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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

void TDEngineTora::OnRspQryShareholderAccount(CTORATstpShareholderAccountField *pShareholderAccount, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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

            if (status_wrapper->get_current_account_idx() >= 0)
            {
                KF_LOG_INFO(logger, "[Shareholder]" << " (exchange)" << exchange << " (shareholderID)" << pShareholderAccount->ShareholderID);
                auto& unit = account_units[status_wrapper->get_current_account_idx()];
                unit.shareholders[exchange] = pShareholderAccount->ShareholderID;
            }
        }
    }

    if (bIsLast)
    {
        status_wrapper->on_login();
    }
}

EXPORT_ENGINE_TO_PYTHON(libtoratd, TDEngineTora);
