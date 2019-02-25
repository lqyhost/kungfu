#include "MDEngineTora.h"
#include "longfist/tora.h"
#include "EngineUtil.hpp"
#include "TypeConvert.hpp"

USING_WC_NAMESPACE

#define GBK2UTF8(msg) kungfu::gbk2utf8(string(msg))

MDEngineTora::MDEngineTora() : IMDEngine(SOURCE_TORA), api(nullptr), req_id(0)
{
    logger = KfLog::getLogger("engine.md.tora");
}

void MDEngineTora::load(const json& j_config)
{
    front_uri = j_config[WC_CONFIG_KEY_FRONT_URI].get<string>();
    user_id = j_config[WC_CONFIG_KEY_USER_ID].get<string>();
    password = j_config[WC_CONFIG_KEY_PASSWORD].get<string>();
    status_wrapper->resize_accounts(1);
}

bool MDEngineTora::try_init(size_t account_idx)
{
    drop_api(account_idx);
    api = CTORATstpMdApi::CreateTstpMdApi();
    if (nullptr != api)
    {
        api->RegisterSpi(this);
        return true;
    }
    return false;
}

void MDEngineTora::drop_api(size_t account_idx)
{
    if (nullptr != api)
    {
        api->Release();
        api = nullptr;
    }
}

bool MDEngineTora::req_connect(size_t account_idx)
{
    api->RegisterFront((char*)front_uri.c_str());
    api->Init();
    return true;
}

bool MDEngineTora::req_disconnect(size_t account_idx)
{
    status_wrapper->on_disconnect();
    return true;
}

bool MDEngineTora::req_login(size_t account_idx)
{
    CTORATstpReqUserLoginField req = {};
    strncpy(req.LogInAccount, user_id.c_str(), 21);
    req.LogInAccountType = TORA_TSTP_LACT_UserID;
    strncpy(req.Password, password.c_str(), 41);
    if (api->ReqUserLogin(&req, ++req_id) != 0)
    {
        KF_LOG_ERROR(logger, "[Login] Login failed! (Uid)" << user_id);
        return false;
    }
    return true;
}

bool MDEngineTora::req_logout(size_t account_idx)
{
    CTORATstpUserLogoutField req = {};
    strncpy(req.UserID, user_id.c_str(), 16);
    if (api->ReqUserLogout(&req, ++req_id) != 0)
    {
        KF_LOG_ERROR(logger, "[Logout] Logout failed! (Uid)" << user_id);
        return false;
    }

    // OnRspUserLogout won't be called for current
    status_wrapper->on_logout();
    return true;
}

void MDEngineTora::subscribeMarketData(const vector<string>& instruments, const vector<string>& markets)
{
    map<TTORATstpExchangeIDType, vector<string>> ticker_map;
    for (size_t i = 0; i < markets.size(); ++i)
    {
        TTORATstpExchangeIDType exId = TORA_TSTP_EXD_COMM;
        if (markets[i].size() > 0)
        {
            ToToraExchangeId(exId, markets[i].c_str());
        }
        else
        {
            auto lf_exchange_id = EngineUtil::getExchangeIdFromStockTicker(instruments[i].c_str());
            if (lf_exchange_id == EXCHANGE_ID_SSE)
                exId = TORA_TSTP_EXD_SSE;
            else if (lf_exchange_id == EXCHANGE_ID_SZE)
                exId = TORA_TSTP_EXD_SZSE;
            else if (lf_exchange_id == EXCHANGE_ID_HK)
                exId = TORA_TSTP_EXD_HK;
        }
        if (exId != TORA_TSTP_EXD_COMM)
        {
            ticker_map[exId].push_back(instruments[i]);
        }
    }
    for (auto iter : ticker_map)
    {
        auto& tickers = iter.second;
        int count = tickers.size();
        char** insts = new char*[count];
        for (size_t i = 0; i < tickers.size(); ++i)
        {
            insts[i] = (char*)tickers[i].c_str();
        }
        api->SubscribeMarketData(insts, count, iter.first);
        delete[] insts;
    }
}

void MDEngineTora::OnFrontConnected()
{
    KF_LOG_INFO(logger, "[Connect] OnFrontConnected");
    status_wrapper->on_connect();
}

///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///        -3 连接已断开
///        -4 网络读失败
///        -5 网络写失败
///        -6 订阅流错误
///        -7 流序号错误
///        -8 错误的心跳报文
///        -9 错误的报文
void MDEngineTora::OnFrontDisconnected(int nReason)
{
    KF_LOG_ERROR(logger, "[Connect] OnFrontDisconnected (reason)" << nReason);
    status_wrapper->on_disconnect();
}

void MDEngineTora::OnRspError(CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
        KF_LOG_ERROR(logger, "[OnRspError]" << " (errID)" << pRspInfo->ErrorID
                                            << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg)
                                            << " (requestID)" << nRequestID
                                            << " (isLast)" << bIsLast);
    }
}

void MDEngineTora::OnRspUserLogin(CTORATstpRspUserLoginField *pRspUserLogin, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
         KF_LOG_ERROR(logger, "[Login] OnRspUserLogin" << " (errID)" << pRspInfo->ErrorID
                                                       << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg)
                                                       << " (isLast)" << bIsLast);
    }
    else
    {
        KF_LOG_INFO(logger, "[Login] OnRspUserLogin" << " (Uid)" << pRspUserLogin->UserID
                                                     << " (SName)" << pRspUserLogin->SystemName);
        status_wrapper->on_login();
    }
}

void MDEngineTora::OnRspUserLogout(CTORATstpUserLogoutField *pUserLogout, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
         KF_LOG_ERROR(logger, "[Logout] OnRspUserLogout" << " (errID)" << pRspInfo->ErrorID
                                                         << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg)
                                                         << " (isLast)" << bIsLast);
    }
    else
    {
        KF_LOG_INFO(logger, "[Logout] OnRspUserLogout" << " (Uid)" << pUserLogout->UserID);
        status_wrapper->on_logout();
    }
}

void MDEngineTora::OnRspSubMarketData(CTORATstpSpecificSecurityField *pSpecificSecurity, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
         KF_LOG_ERROR(logger, "[Subscribe] OnRspSubMarketData" << " (errID)" << pRspInfo->ErrorID
                                                               << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg)
                                                               << " (Tid)" << (nullptr != pSpecificSecurity ? pSpecificSecurity->SecurityID : "null")
                                                               << " (isLast)" << bIsLast);
    }
}

void MDEngineTora::OnRtnDepthMarketData(CTORATstpMarketDataField *pDepthMarketData)
{
    auto data = parseFrom(*pDepthMarketData);
    on_market_data(&data);
    raw_writer->write_frame(pDepthMarketData, sizeof(CTORATstpMarketDataField), source_id, MSG_TYPE_LF_MD_TORA, 1, -1);
}

EXPORT_ENGINE_TO_PYTHON(libtoramd, MDEngineTora);