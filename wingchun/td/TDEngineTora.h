#ifndef WINGCHUN_TDENGINETORA_H
#define WINGCHUN_TDENGINETORA_H

#include "ITDEngine.h"
#include "tora/TORATstpTraderApi.h"
#include "longfist/LFConstants.h"

WC_NAMESPACE_START

struct AccountUnitTora
{
    CTORATstpTraderApi* api;
    int front_id;
    int session_id;
    bool api_initialized;
    map<string, string> shareholders;
};

class TDEngineTora : public ITDEngine, public CTORATstpTraderSpi
{
public:
    /** init internal journal writer (both raw and send) */
    virtual void init();
    /** for settleconfirm and authenticate setting */
    virtual void pre_load(const json& j_config);
    virtual bool validate_account_info(const json& j_account) override;
    virtual TradeAccount load_account(int idx, const json& j_account);
    virtual void resize_accounts(int account_num);
    virtual string name() const { return "TDEngineTora"; };

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

    // req functions
    virtual bool req_investor_position(const LFQryPositionField* data, int account_index, int requestId);
    virtual bool req_qry_account(const LFQryAccountField* data, int account_index, int requestId);
    virtual bool req_order_insert(const LFInputOrderField* data, int account_index, int requestId, long rcv_time);
    virtual bool req_order_action(const LFOrderActionField* data, int account_index, int requestId, long rcv_time);

public:
    TDEngineTora();

private:
    yijinjing::JournalWriterPtr raw_writer;
    string front_uri;
    string mac;
    string ip;
    string gw_mac;
    string gw_inner_ip;
    string gw_outer_ip;
    string hd_sn;
    vector<AccountUnitTora> account_units;
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
