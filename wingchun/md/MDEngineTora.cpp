#include "MDEngineTORA.h"
#include "longfist/tora.h"
#include "TypeConvert.hpp"
#include "Timer.h"
#include "longfist/LFUtils.h"
//#include "EngineUtil.hpp"

USING_WC_NAMESPACE

#define GBK2UTF8(msg) kungfu::yijinjing::gbk2utf8(string(msg))

MDEngineTORA::MDEngineTORA() : IMDEngine(SOURCE_TORA), api(nullptr), reqId(0)
{
    logger = yijinjing::KfLog::getLogger("MdEngine.TORA");
}

void MDEngineTORA::load(const json& j_config)
{
    front_uri = j_config[WC_CONFIG_KEY_FRONT_URI].get<string>();
    user_id = j_config[WC_CONFIG_KEY_USER_ID].get<string>();
    password = j_config[WC_CONFIG_KEY_PASSWORD].get<string>();
}

void MDEngineTORA::logout()
{
    if (logged_in)
    {
        CTORATstpUserLogoutField req = {};
        strncpy(req.UserID, user_id.c_str(), 16);
        if (api->ReqUserLogout(&req, reqId++))
        {
            KF_LOG_ERROR(logger, "[request] logout failed!" << " (Uid)" << req.UserID);
        }
    }
    connected = false;
    logged_in = false;
}

void MDEngineTORA::release_api()
{
    if (api != nullptr)
    {
        api->Release();
        api = nullptr;
    }
}

void MDEngineTORA::connect(long timeout_nsec)
{
    api = CTORATstpMdApi::CreateTstpMdApi();
    if (nullptr != api)
    {
        api->RegisterSpi((CTORATstpMdSpi*)this);
    }
    if (!connected)
    {
        api->RegisterFront((char*)front_uri.c_str());
        api->Init();
        //long start_time = yijinjing::getNanoTime();
        //while (!connected && yijinjing::getNanoTime() - start_time < timeout_nsec)
        //{}
    }
}

void MDEngineTORA::login(long timeout_nsec)
{
    CTORATstpReqUserLoginField req = {};
    strncpy(req.LogInAccount, user_id.c_str(), 21);
    req.LogInAccountType = TORA_TSTP_LACT_UserID;
    strncpy(req.Password, password.c_str(), 41);
    if (api->ReqUserLogin(&req, ++reqId) != 0)
    {
        KF_LOG_ERROR(logger, "[Login] Login failed! (Uid)" << user_id);
    }
    long start_time = yijinjing::getNanoTime();
    while (!logged_in && yijinjing::getNanoTime() - start_time < timeout_nsec)
    {}
}

void MDEngineTORA::subscribeMarketData(const vector<string>& instruments, const vector<string>& markets)
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

void MDEngineTORA::OnFrontConnected()
{
    KF_LOG_INFO(logger, "[Connect] OnFrontConnected");
    connected = true;
}

///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///        -3 连接已断开
///        -4 网络读失败
///        -5 网络写失败
///        -6 订阅流错误
///        -7 流序号错误
///        -8 错误的心跳报文
///        -9 错误的报文
void MDEngineTORA::OnFrontDisconnected(int nReason)
{
    KF_LOG_ERROR(logger, "[Connect] OnFrontDisconnected (reason)" << nReason);
    connected = false;
}

void MDEngineTORA::OnRspError(CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
        KF_LOG_ERROR(logger, "[OnRspError]" << " (errID)" << pRspInfo->ErrorID
                                            << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg)
                                            << " (requestID)" << nRequestID
                                            << " (isLast)" << bIsLast);
    }
}

void MDEngineTORA::OnRspUserLogin(CTORATstpRspUserLoginField *pRspUserLogin, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
        logged_in = true;
    }
}

void MDEngineTORA::OnRspUserLogout(CTORATstpUserLogoutField *pUserLogout, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
        logged_in = false;
    }
}

void MDEngineTORA::OnRspSubMarketData(CTORATstpSpecificSecurityField *pSpecificSecurity, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    if (nullptr != pRspInfo && pRspInfo->ErrorID != 0)
    {
         KF_LOG_ERROR(logger, "[Subscribe] OnRspSubMarketData" << " (errID)" << pRspInfo->ErrorID
                                                               << " (errMsg)" << GBK2UTF8(pRspInfo->ErrorMsg)
                                                               << " (Tid)" << (nullptr != pSpecificSecurity ? pSpecificSecurity->SecurityID : "null")
                                                               << " (isLast)" << bIsLast);
    }
}

void MDEngineTORA::OnRtnDepthMarketData(CTORATstpMarketDataField *pDepthMarketData)
{
    auto data = parseFrom(*pDepthMarketData);
    on_market_data(&data);
    //raw_writer->write_frame(pDepthMarketData, sizeof(CTORATstpMarketDataField), source_id, MSG_TYPE_LF_MD_TORA, 1, -1);
}

BOOST_PYTHON_MODULE(libtoramd)
{
    using namespace boost::python;
    class_<MDEngineTORA, boost::shared_ptr<MDEngineTORA> >("Engine")
    .def(init<>())
    .def("init", &MDEngineTORA::initialize)
    .def("start", &MDEngineTORA::start)
    .def("stop", &MDEngineTORA::stop)
    .def("logout", &MDEngineTORA::logout)
    .def("wait_for_stop", &MDEngineTORA::wait_for_stop);
}