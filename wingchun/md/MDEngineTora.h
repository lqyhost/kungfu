#ifndef WINGCHUN_MDENGINETORA_H
#define WINGCHUN_MDENGINETORA_H

#include "IMDEngine.h"
#include "longfist/LFConstants.h"
#include "TORATstpMdApi.h"

WC_NAMESPACE_START

class MDEngineTORA : public IMDEngine, public CTORATstpMdSpi
{
public:
    /** load internal information from config json */
    virtual void load(const json& j_config);
    virtual void connect(long timeout_nsec);
    virtual void login(long timeout_nsec);
    virtual void logout();
    virtual void release_api();
    virtual bool is_connected() const { return connected; };
    virtual bool is_logged_in() const { return logged_in; };

    virtual void subscribeMarketData(const vector<string>& instruments, const vector<string>& markets);
    virtual string name() const { return "MDEngineTORA"; };

public:
    MDEngineTORA();

private:
    CTORATstpMdApi* api;

    string front_uri;
    string user_id;
    string password;
    bool connected;
    bool logged_in;
    int reqId;

public:
    virtual void OnFrontConnected();
    virtual void OnFrontDisconnected(int nReason);
    virtual void OnRspError(CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspUserLogin(CTORATstpRspUserLoginField *pRspUserLogin, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspUserLogout(CTORATstpUserLogoutField *pUserLogout, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspSubMarketData(CTORATstpSpecificSecurityField *pSpecificSecurity, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRtnDepthMarketData(CTORATstpMarketDataField *pDepthMarketData);
};

DECLARE_PTR(MDEngineTORA);

WC_NAMESPACE_END

#endif //WINGCHUN_MDENGINETORA_H