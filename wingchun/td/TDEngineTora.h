#ifndef WINGCHUN_TDENGINETORA_H
#define WINGCHUN_TDENGINETORA_H

#include "ITDEngine.h"
#include "TORATstpTraderApi.h"
#include "longfist/LFConstants.h"

WC_NAMESPACE_START

struct AccountUnitTORA
{
    CTORATstpTraderApi* api;
    int front_id;
    int session_id;
    bool    initialized;
    bool    connected;
    bool    logged_in;
    // some rids
    int     login_rid;
    bool api_initialized;
    map<string, string> shareholders;
};

class TDEngineTORA : public ITDEngine, public CTORATstpTraderSpi
{
public:
    /** init internal journal writer (both raw and send) */
    virtual void init();
    /** for settleconfirm and authenticate setting */
    virtual void pre_load(const json& j_config);
    //virtual bool validate_account_info(const json& j_account) override;
    virtual TradeAccount load_account(int idx, const json& j_account);
    virtual void resize_accounts(int account_num);

    virtual void connect(long timeout_nsec);
    virtual void login(long timeout_nsec);
    virtual void logout();
    virtual void release_api();
    virtual bool is_connected() const;
    virtual bool is_logged_in() const;
    virtual string name() const { return "TDEngineTORA"; };

    // req functions
    virtual void req_investor_position(const LFQryPositionField* data, int account_index, int requestId);
    virtual void req_qry_account(const LFQryAccountField* data, int account_index, int requestId);
    virtual void req_order_insert(const LFInputOrderField* data, int account_index, int requestId, long rcv_time);
    virtual void req_order_action(const LFOrderActionField* data, int account_index, int requestId, long rcv_time);

public:
    TDEngineTORA();

private:
    yijinjing::JournalWriterPtr raw_writer;
    string front_uri;
    string mac;
    string ip;
    string gw_mac;
    string gw_inner_ip;
    string gw_outer_ip;
    string hd_sn;
    vector<AccountUnitTORA> account_units;
    int curAccountIdx;
    int req_id;
    bool real_trade;

public:
    virtual void OnFrontConnected();
    virtual void OnFrontDisconnected(int nReason);
    virtual void OnRspError(CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspUserLogin(CTORATstpRspUserLoginField *pRspUserLoginField, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspUserLogout(CTORATstpUserLogoutField *pUserLogoutField, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspOrderInsert(CTORATstpInputOrderField *pInputOrderField, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnErrRtnOrderInsert(CTORATstpInputOrderField *pInputOrder, CTORATstpRspInfoField *pRspInfo);
    virtual void OnRspOrderAction(CTORATstpInputOrderActionField *pInputOrderActionField, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnErrRtnOrderAction(CTORATstpOrderActionField *pOrderAction, CTORATstpRspInfoField *pRspInfo);
    virtual void OnRtnOrder(CTORATstpOrderField *pOrder);
    virtual void OnRtnTrade(CTORATstpTradeField *pTrade);
    virtual void OnRspQryTradingAccount(CTORATstpTradingAccountField *pTradingAccount, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspQryPosition(CTORATstpPositionField *pPosition, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspQryShareholderAccount(CTORATstpShareholderAccountField *pShareholderAccount, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
};

WC_NAMESPACE_END

#endif //WINGCHUN_TDENGINETORA_H
