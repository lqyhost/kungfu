#ifndef WINGCHUN_MDENGINETORA_H
#define WINGCHUN_MDENGINETORA_H

#include "IMDEngine.h"
#include "tora/TORATstpMdApi.h"

WC_NAMESPACE_START

class MDEngineTora : public IMDEngine, public CTORATstpMdSpi
{
public:
    /** load internal information from config json */
    virtual void load(const json& j_config);
    virtual void subscribeMarketData(const vector<string>& instruments, const vector<string>& markets);
    virtual string name() const { return "MDEngineTora"; };

    // IStatusUtil
    /** init all account related fields */
    virtual bool try_init(size_t account_idx);
    /** drop all account related fields and memory */
    virtual void drop_api(size_t account_idx);
    /** req connection -> on_connect */
    virtual bool req_connect(size_t account_idx);
    /** req disconnect -> on_disconnect */
    virtual bool req_disconnect(size_t account_idx);
    /** req login -> on_login */
    virtual bool req_login(size_t account_idx);
    /** req logout -> on_logout */
    virtual bool req_logout(size_t account_idx);

public:
    MDEngineTora();

private:
    CTORATstpMdApi* api;

    string front_uri;
    string user_id;
    string password;

    int req_id;

public:
    virtual void OnFrontConnected();
    virtual void OnFrontDisconnected(int nReason);
    virtual void OnRspError(CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspUserLogin(CTORATstpRspUserLoginField *pRspUserLogin, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspUserLogout(CTORATstpUserLogoutField *pUserLogout, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspSubMarketData(CTORATstpSpecificSecurityField *pSpecificSecurity, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRtnDepthMarketData(CTORATstpMarketDataField *pDepthMarketData);
};

DECLARE_PTR(MDEngineTora);

WC_NAMESPACE_END

#endif //WINGCHUN_MDENGINETORA_H