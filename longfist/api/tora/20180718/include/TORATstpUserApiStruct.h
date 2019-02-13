/////////////////////////////////////////////////////////////////////////
///@company �Ϻ�̩����Ϣ�Ƽ����޹�˾
///@file TORATstpUserApiStruct.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ�����ݽṹ
///@history 
/////////////////////////////////////////////////////////////////////////

#if !defined(_TORA_TSTPCSTRUCT_H)
#define _TORA_TSTPCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TORATstpUserApiDataType.h"

/// fens�û���Ϣ
struct CTORATstpFensUserInfoField
{
		
	///��¼�˻�
	TTORATstpLogInAccountType	LogInAccount;

	///��¼�˻�����
	TTORATstpLogInAccountTypeType	LogInAccountType;


};

/// �۸��쳣��������
struct CTORATstpEffectPriceMarketDataField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///���¼�
	TTORATstpPriceType	LastPrice;

	///�ܳɽ�����
	TTORATstpLongVolumeType	TotalVolume;

	///�ɽ����
	TTORATstpMoneyType	Turnover;

	///����޸�ʱ��
	TTORATstpTimeType	UpdateTime;

	///����޸ĺ���
	TTORATstpMillisecType	UpdateMillisec;


};

/// �����쳣��������
struct CTORATstpEffectVolumeMarketDataField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///���¼�
	TTORATstpPriceType	LastPrice;

	///�ܳɽ�����
	TTORATstpLongVolumeType	TotalVolume;

	///�ɽ����
	TTORATstpMoneyType	Turnover;

	///����޸�ʱ��
	TTORATstpTimeType	UpdateTime;

	///����޸ĺ���
	TTORATstpMillisecType	UpdateMillisec;


};

/// �ʽ�������������
struct CTORATstpFundsFlowMarketDataField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///ɢ��������
	TTORATstpMoneyType	RetailBuyTurnover;

	///ɢ����������
	TTORATstpLongVolumeType	RetailBuyVolume;

	///ɢ���������
	TTORATstpLongVolumeType	RetailBuyAmount;

	///ɢ���������
	TTORATstpMoneyType	RetailSellTurnover;

	///ɢ����������
	TTORATstpLongVolumeType	RetailSellVolume;

	///ɢ����������
	TTORATstpLongVolumeType	RetailSellAmount;

	///�л�������
	TTORATstpMoneyType	MiddleBuyTurnover;

	///�л���������
	TTORATstpLongVolumeType	MiddleBuyVolume;

	///�л��������
	TTORATstpLongVolumeType	MiddleBuyAmount;

	///�л��������
	TTORATstpMoneyType	MiddleSellTurnover;

	///�л���������
	TTORATstpLongVolumeType	MiddleSellVolume;

	///�л���������
	TTORATstpLongVolumeType	MiddleSellAmount;

	///��������
	TTORATstpMoneyType	LargeBuyTurnover;

	///����������
	TTORATstpLongVolumeType	LargeBuyVolume;

	///���������
	TTORATstpLongVolumeType	LargeBuyAmount;

	///���������
	TTORATstpMoneyType	LargeSellTurnover;

	///����������
	TTORATstpLongVolumeType	LargeSellVolume;

	///����������
	TTORATstpLongVolumeType	LargeSellAmount;

	///����������
	TTORATstpMoneyType	InstitutionBuyTurnover;

	///������������
	TTORATstpLongVolumeType	InstitutionBuyVolume;

	///�����������
	TTORATstpLongVolumeType	InstitutionBuyAmount;

	///�����������
	TTORATstpMoneyType	InstitutionSellTurnover;

	///������������
	TTORATstpLongVolumeType	InstitutionSellVolume;

	///������������
	TTORATstpLongVolumeType	InstitutionSellAmount;


};

/// ��¼����
struct CTORATstpReqUserLoginField
{
		
	///��¼�˻�
	TTORATstpLogInAccountType	LogInAccount;

	///��¼�˻�����
	TTORATstpLogInAccountTypeType	LogInAccountType;

	///����
	TTORATstpPasswordType	Password;

	///�û��˲�Ʒ��Ϣ
	TTORATstpProductInfoType	UserProductInfo;

	///�ӿڶ˲�Ʒ��Ϣ
	TTORATstpProductInfoType	InterfaceProductInfo;

	///Э����Ϣ
	TTORATstpProtocolInfoType	ProtocolInfo;

	///Mac��ַ
	TTORATstpMacAddressType	MacAddress;

	///��̬����
	TTORATstpPasswordType	OneTimePassword;

	///�ն�IP��ַ
	TTORATstpIPAddressType	ClientIPAddress;

	///�ӿ�����
	TTORATstpLangType	Lang;

	///�ն���Ϣ
	TTORATstpTerminalInfoType	TerminalInfo;

	///����Mac��ַ
	TTORATstpMacAddressType	GWMacAddress;

	///��������IP��ַ
	TTORATstpIPAddressType	GWInnerIPAddress;

	///��������IP��ַ
	TTORATstpIPAddressType	GWOuterIPAddress;

	///���͹�˾���Ŵ��루���ʽ��˺ŷ�ʽ��¼ʱ���
	TTORATstpDepartmentIDType	DepartmentID;

	///Ӳ�����к�
	TTORATstpHDSerialType	HDSerial;


};

/// ��¼Ӧ��
struct CTORATstpRspUserLoginField
{
		
	///��¼�ɹ�ʱ��
	TTORATstpTimeType	LoginTime;

	///��¼�˻�
	TTORATstpLogInAccountType	LogInAccount;

	///��¼�˻�����
	TTORATstpLogInAccountTypeType	LogInAccountType;

	///����ϵͳ����
	TTORATstpSystemNameType	SystemName;

	///ǰ�ñ��
	TTORATstpFrontIDType	FrontID;

	///�Ự���
	TTORATstpSessionIDType	SessionID;

	///��󱨵�����
	TTORATstpOrderRefType	MaxOrderRef;

	///˽��������
	TTORATstpVolumeType	PrivateFlowCount;

	///����������
	TTORATstpVolumeType	PublicFlowCount;

	///���׷���������
	TTORATstpDateType	TradingDay;

	///�û�����
	TTORATstpUserIDType	UserID;

	///�û�����
	TTORATstpUserNameType	UserName;

	///�û�����
	TTORATstpUserTypeType	UserType;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;

	///�ն�IP��ַ
	TTORATstpIPAddressType	ClientIPAddress;

	///Mac��ַ
	TTORATstpMacAddressType	MacAddress;

	///Ӳ�����к�
	TTORATstpHDSerialType	HDSerial;

	///ͨѶ����
	TTORATstpCommFluxType	CommFlux;


};

/// ��Ӧ��Ϣ
struct CTORATstpRspInfoField
{
		
	///�������
	TTORATstpErrorIDType	ErrorID;

	///������Ϣ
	TTORATstpErrorMsgType	ErrorMsg;


};

/// �û��ǳ�
struct CTORATstpUserLogoutField
{
		
	///�û�����
	TTORATstpUserIDType	UserID;


};

/// ǿ�ƽ���Ա�˳�
struct CTORATstpForceUserLogoutField
{
		
	///�û�����
	TTORATstpUserIDType	UserID;


};

/// �����û�����
struct CTORATstpUserPasswordUpdateField
{
		
	///�û�����
	TTORATstpUserIDType	UserID;

	///������
	TTORATstpPasswordType	OldPassword;

	///������
	TTORATstpPasswordType	NewPassword;


};

/// �����û�
struct CTORATstpActivateUserField
{
		
	///�û�����
	TTORATstpUserIDType	UserID;


};

/// �û��Ự��ʶ
struct CTORATstpVerifyUserPasswordField
{
		
	///�û�����
	TTORATstpUserIDType	UserID;

	///����
	TTORATstpPasswordType	Password;


};

/// ���뱨��
struct CTORATstpInputOrderField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///��Լ��ϵͳ�еı��
	TTORATstpSecurityIDType	SecurityID;

	///Ͷ����˵���ĶԱ�����Ψһ����
	TTORATstpOrderRefType	OrderRef;

	///�û�����
	TTORATstpUserIDType	UserID;

	///�޼۵����м۵�
	TTORATstpOrderPriceTypeType	OrderPriceType;

	///1����2����
	TTORATstpDirectionType	Direction;

	///���ֽڱ�ʾ��������Լ�Ŀ�ƽ����
	TTORATstpCombOffsetFlagType	CombOffsetFlag;

	///���ֽڱ�ʾ��������Լ������ױ���־
	TTORATstpCombHedgeFlagType	CombHedgeFlag;

	///�޼۵��۸�
	TTORATstpPriceType	LimitPrice;

	///��������
	TTORATstpVolumeType	VolumeTotalOriginal;

	///IOC��GFS��GFD��GTD��GTC��GFA
	TTORATstpTimeConditionType	TimeCondition;

	///AV��MV��CV
	TTORATstpVolumeConditionType	VolumeCondition;

	///���ɽ�������ΪMVʱ��Ч
	TTORATstpVolumeType	MinVolume;

	///ǿƽԭ��
	TTORATstpForceCloseReasonType	ForceCloseReason;

	///������
	TTORATstpRequestIDType	RequestID;

	///�û�ǿ����־
	TTORATstpBoolType	UserForceClose;

	///��������־
	TTORATstpBoolType	IsSwapOrder;

	///һ���������ı��
	TTORATstpExchangeIDType	ExchangeID;

	///Ŀǰ���ֶδ�ŵ�����֤�������ڵĹɶ����롣
	TTORATstpShareholderIDType	ShareholderID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///IP��ַ
	TTORATstpIPAddressType	IPAddress;

	///Mac��ַ
	TTORATstpMacAddressType	MacAddress;

	///ͷ������
	TTORATstpCreditPositionTypeType	CreditPositionType;

	///�������
	TTORATstpOrderSysIDType	OrderSysID;

	///�ն���Ϣ
	TTORATstpTerminalInfoType	TerminalInfo;

	///���ַ���������Ϣ
	TTORATstpBigsInfoType	BInfo;

	///���ַ���������Ϣ
	TTORATstpShortsInfoType	SInfo;

	///���θ�����Ϣ
	TTORATstpIntInfoType	IInfo;

	///ת�뽻�׵�Ԫ����(����ת�йܲ���ʱ��Ч)
	TTORATstpPbuIDType	TransfereePbuID;

	///ί�з�ʽ
	TTORATstpOperwayType	Operway;

	///�������
	TTORATstpCondCheckType	CondCheck;

	///Ӳ�����к�
	TTORATstpHDSerialType	HDSerial;


};

/// ����
struct CTORATstpOrderField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///��Լ��ϵͳ�еı��
	TTORATstpSecurityIDType	SecurityID;

	///Ͷ����˵���ĶԱ�����Ψһ����
	TTORATstpOrderRefType	OrderRef;

	///�û�����
	TTORATstpUserIDType	UserID;

	///�޼۵����м۵�
	TTORATstpOrderPriceTypeType	OrderPriceType;

	///1����2����
	TTORATstpDirectionType	Direction;

	///���ֽڱ�ʾ��������Լ�Ŀ�ƽ����
	TTORATstpCombOffsetFlagType	CombOffsetFlag;

	///���ֽڱ�ʾ��������Լ������ױ���־
	TTORATstpCombHedgeFlagType	CombHedgeFlag;

	///�޼۵��۸�
	TTORATstpPriceType	LimitPrice;

	///��������
	TTORATstpVolumeType	VolumeTotalOriginal;

	///IOC��GFS��GFD��GTD��GTC��GFA
	TTORATstpTimeConditionType	TimeCondition;

	///AV��MV��CV
	TTORATstpVolumeConditionType	VolumeCondition;

	///���ɽ�������ΪMVʱ��Ч
	TTORATstpVolumeType	MinVolume;

	///ǿƽԭ��
	TTORATstpForceCloseReasonType	ForceCloseReason;

	///������
	TTORATstpRequestIDType	RequestID;

	///���ر���˳���
	TTORATstpOrderLocalIDType	OrderLocalID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///�ͻ���ϵͳ�еı�ţ����Ψһ����ѭ�������ƶ��ı������
	TTORATstpShareholderIDType	ShareholderID;

	///��Լ�ڽ������Ĵ���
	TTORATstpExchangeInstIDType	ExchangeInstID;

	///����������Ա����
	TTORATstpTraderIDType	TraderID;

	///�����ύ״̬
	TTORATstpOrderSubmitStatusType	OrderSubmitStatus;

	///���׷���������
	TTORATstpDateType	TradingDay;

	///�������
	TTORATstpOrderSysIDType	OrderSysID;

	///0��ȫ���ɽ�1�����ֳɽ����ڶ�����2�����ֳɽ����ڶ�����3��δ�ɽ����ڶ�����4��δ�ɽ����ڶ�����5������
	TTORATstpOrderStatusType	OrderStatus;

	///0����ͨ1����������2���������
	TTORATstpOrderTypeType	OrderType;

	///�����������
	TTORATstpVolumeType	VolumeTraded;

	///����δ�������
	TTORATstpVolumeType	VolumeTotal;

	///��������
	TTORATstpDateType	InsertDate;

	///ί��ʱ��
	TTORATstpTimeType	InsertTime;

	///����ʱ��
	TTORATstpTimeType	CancelTime;

	///����޸Ľ���������Ա����
	TTORATstpTraderIDType	ActiveTraderID;

	///ǰ�ñ��
	TTORATstpFrontIDType	FrontID;

	///ÿһλ����Ա��������¼�ߵ�¼ϵͳ��õĻỰ��ţ���ǰʱ��Ψһ
	TTORATstpSessionIDType	SessionID;

	///˵���û���ʹ�õ������Ʒ�Ͱ汾��
	TTORATstpProductInfoType	UserProductInfo;

	///״̬��Ϣ
	TTORATstpErrorMsgType	StatusMsg;

	///�û�ǿ����־
	TTORATstpBoolType	UserForceClose;

	///�����û�����
	TTORATstpUserIDType	ActiveUserID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///IP��ַ
	TTORATstpIPAddressType	IPAddress;

	///Mac��ַ
	TTORATstpMacAddressType	MacAddress;

	///ͷ������
	TTORATstpCreditPositionTypeType	CreditPositionType;

	///���ַ���������Ϣ
	TTORATstpBigsInfoType	BInfo;

	///���ַ���������Ϣ
	TTORATstpShortsInfoType	SInfo;

	///���θ�����Ϣ
	TTORATstpIntInfoType	IInfo;

	///ת�뽻�׵�Ԫ����(����ת�йܲ���ʱ��Ч)
	TTORATstpPbuIDType	TransfereePbuID;

	///ί�з�ʽ
	TTORATstpOperwayType	Operway;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;

	///�ʵ��Կ���ҵ�����
	TTORATstpProperCtrlBusinessTypeType	ProperCtrlBusinessType;

	///�ʵ��Կ���ͨ����ʾ
	TTORATstpProperCtrlPassFlagType	ProperCtrlPassFlag;

	///�������
	TTORATstpCondCheckType	CondCheck;

	///�Ƿ�Ԥ��
	TTORATstpBoolType	IsCacheOrder;

	///���ݳɽ��۸������ı��ʳɽ��Ľ����������ã�
	TTORATstpMoneyType	Turnover;


};

/// �û���ʶ
struct CTORATstpUserRefField
{
		
	///�û�����
	TTORATstpUserIDType	UserID;


};

/// ���볷������
struct CTORATstpInputOrderActionField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ����˵���ĶԱ���������Ψһ����
	TTORATstpOrderRefType	OrderActionRef;

	///Ͷ����˵���ĶԱ�����Ψһ����
	TTORATstpOrderRefType	OrderRef;

	///������
	TTORATstpRequestIDType	RequestID;

	///ǰ�ñ��
	TTORATstpFrontIDType	FrontID;

	///ÿһλ����Ա��������¼�ߵ�¼ϵͳ��õĻỰ��ţ���ǰʱ��Ψһ
	TTORATstpSessionIDType	SessionID;

	///һ���������ı��
	TTORATstpExchangeIDType	ExchangeID;

	///�������
	TTORATstpOrderSysIDType	OrderSysID;

	///������־
	TTORATstpActionFlagType	ActionFlag;

	///�޼۵��۸�
	TTORATstpPriceType	LimitPrice;

	///���������仯
	TTORATstpVolumeType	VolumeChange;

	///�û�����
	TTORATstpUserIDType	UserID;

	///��Լ��ϵͳ�еı��
	TTORATstpSecurityIDType	SecurityID;

	///IP��ַ
	TTORATstpIPAddressType	IPAddress;

	///Mac��ַ
	TTORATstpMacAddressType	MacAddress;

	///ȫϵͳ��Ψһ������š�16λ��1-2λΪ��������ʶ��3-5λΪ���͹�˾���룬6-8λΪ���׵�Ԫ��ʶ������8λΪ��ˮ�š�
	TTORATstpOrderLocalIDType	CancelOrderLocalID;

	///�ն���Ϣ
	TTORATstpTerminalInfoType	TerminalInfo;

	///���ַ���������Ϣ
	TTORATstpBigsInfoType	BInfo;

	///���ַ���������Ϣ
	TTORATstpShortsInfoType	SInfo;

	///���θ�����Ϣ
	TTORATstpIntInfoType	IInfo;

	///ί�з�ʽ
	TTORATstpOperwayType	Operway;

	///Ӳ�����к�
	TTORATstpHDSerialType	HDSerial;


};

/// ��������
struct CTORATstpOrderActionField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ����˵���ĶԱ���������Ψһ����
	TTORATstpOrderRefType	OrderActionRef;

	///Ͷ����˵���ĶԱ�����Ψһ����
	TTORATstpOrderRefType	OrderRef;

	///������
	TTORATstpRequestIDType	RequestID;

	///ǰ�ñ��
	TTORATstpFrontIDType	FrontID;

	///ÿһλ����Ա��������¼�ߵ�¼ϵͳ��õĻỰ��ţ���ǰʱ��Ψһ
	TTORATstpSessionIDType	SessionID;

	///һ���������ı��
	TTORATstpExchangeIDType	ExchangeID;

	///�������
	TTORATstpOrderSysIDType	OrderSysID;

	///������־
	TTORATstpActionFlagType	ActionFlag;

	///�޼۵��۸�
	TTORATstpPriceType	LimitPrice;

	///���������仯
	TTORATstpVolumeType	VolumeChange;

	///��������
	TTORATstpDateType	ActionDate;

	///����ʱ��
	TTORATstpTimeType	ActionTime;

	///����������Ա����
	TTORATstpTraderIDType	TraderID;

	///���ر������
	TTORATstpOrderLocalIDType	OrderLocalID;

	///�������ر��
	TTORATstpOrderLocalIDType	ActionLocalID;

	///�ͻ���ϵͳ�еı�ţ����Ψһ����ѭ�������ƶ��ı������
	TTORATstpShareholderIDType	ShareholderID;

	///��������״̬
	TTORATstpOrderActionStatusType	OrderActionStatus;

	///�û�����
	TTORATstpUserIDType	UserID;

	///״̬��Ϣ
	TTORATstpErrorMsgType	StatusMsg;

	///��Լ��ϵͳ�еı��
	TTORATstpSecurityIDType	SecurityID;

	///IP��ַ
	TTORATstpIPAddressType	IPAddress;

	///Mac��ַ
	TTORATstpMacAddressType	MacAddress;

	///���ַ���������Ϣ
	TTORATstpBigsInfoType	BInfo;

	///���ַ���������Ϣ
	TTORATstpShortsInfoType	SInfo;

	///���θ�����Ϣ
	TTORATstpIntInfoType	IInfo;

	///ί�з�ʽ
	TTORATstpOperwayType	Operway;


};

/// �ɽ�
struct CTORATstpTradeField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///��Լ��ϵͳ�еı��
	TTORATstpSecurityIDType	SecurityID;

	///�û�����
	TTORATstpUserIDType	UserID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�ɽ����
	TTORATstpTradeIDType	TradeID;

	///1.��2.��
	TTORATstpDirectionType	Direction;

	///�������
	TTORATstpOrderSysIDType	OrderSysID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///�ͻ���ϵͳ�еı�ţ����Ψһ����ѭ�������ƶ��ı������
	TTORATstpShareholderIDType	ShareholderID;

	///��Լ�ڽ������Ĵ���
	TTORATstpExchangeInstIDType	ExchangeInstID;

	///1������2��ƽ��3��ƽ��4��ǿƽ
	TTORATstpOffsetFlagType	OffsetFlag;

	///1.Ͷ��2.�ױ�
	TTORATstpHedgeFlagType	HedgeFlag;

	///�ɽ��۸�
	TTORATstpPriceType	Price;

	///�ɽ�����
	TTORATstpVolumeType	Volume;

	///�ɽ�����
	TTORATstpDateType	TradeDate;

	///�ɽ�ʱ��
	TTORATstpTimeType	TradeTime;

	///����Ա��ϵͳ�еı�ţ����Ψһ����ѭ�������ƶ��ı������
	TTORATstpTraderIDType	TraderID;

	///���ر���˳���
	TTORATstpOrderLocalIDType	OrderLocalID;

	///���׷���������
	TTORATstpDateType	TradingDay;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///��������
	TTORATstpOrderRefType	OrderRef;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;


};

/// �г�״̬
struct CTORATstpMarketStatusField
{
		
	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///�г�״̬
	TTORATstpMarketStatusType	MarketStatus;


};

/// ������¼����
struct CTORATstpInputCondOrderField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ɶ��˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///��������
	TTORATstpDirectionType	Direction;

	///�������۸�����
	TTORATstpOrderPriceTypeType	OrderPriceType;

	///��������������
	TTORATstpOrderVolumeTypeType	OrderVolumeType;

	///��Ч������
	TTORATstpTimeConditionType	TimeCondition;

	///�ɽ�������
	TTORATstpVolumeConditionType	VolumeCondition;

	///�����۸�
	TTORATstpPriceType	LimitPrice;

	///��������
	TTORATstpVolumeType	VolumeTotalOriginal;

	///��Ͽ�ƽ��־
	TTORATstpCombOffsetFlagType	CombOffsetFlag;

	///���Ͷ���ױ���־
	TTORATstpCombHedgeFlagType	CombHedgeFlag;

	///������������
	TTORATstpOrderRefType	CondOrderRef;

	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///�û�����
	TTORATstpUserIDType	UserID;

	///������
	TTORATstpRequestIDType	RequestID;

	///IP��ַ
	TTORATstpIPAddressType	IPAddress;

	///Mac��ַ
	TTORATstpMacAddressType	MacAddress;

	///�������
	TTORATstpCondOrderIDType	CondOrderID;

	///�ն���Ϣ
	TTORATstpTerminalInfoType	TerminalInfo;

	///���ַ���������Ϣ
	TTORATstpBigsInfoType	BInfo;

	///���ַ���������Ϣ
	TTORATstpShortsInfoType	SInfo;

	///���θ�����Ϣ
	TTORATstpIntInfoType	IInfo;

	///ί�з�ʽ
	TTORATstpOperwayType	Operway;

	///�������
	TTORATstpCondCheckType	CondCheck;

	///��������������
	TTORATstpContingentConditionType	ContingentCondition;

	///������
	TTORATstpPriceType	ConditionPrice;

	///�۸񸡶�tick��,>0���ϸ���,<0���¸���,=0������
	TTORATstpVolumeType	PriceTicks;

	///������������,����>=0
	TTORATstpVolumeMultipleType	VolumeMultiple;

	///���ǰ�ñ��
	TTORATstpFrontIDType	RelativeFrontID;

	///��ػỰ���
	TTORATstpSessionIDType	RelativeSessionID;

	///�����������,����ΪOrderRef��OrderSysID��Time��SecurityID
	TTORATstpRelativeCondParamType	RelativeParam;

	///������������������
	TTORATstpContingentConditionType	AppendContingentCondition;

	///����������
	TTORATstpPriceType	AppendConditionPrice;

	///�������ǰ�ñ��
	TTORATstpFrontIDType	AppendRelativeFrontID;

	///������ػỰ���
	TTORATstpSessionIDType	AppendRelativeSessionID;

	///���������������,����ΪOrderRef��OrderSysID��Time��SecurityID
	TTORATstpRelativeCondParamType	AppendRelativeParam;

	///Ӳ�����к�
	TTORATstpHDSerialType	HDSerial;


};

/// ��������
struct CTORATstpConditionOrderField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ɶ��˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///��������
	TTORATstpDirectionType	Direction;

	///�������۸�����
	TTORATstpOrderPriceTypeType	OrderPriceType;

	///��������������
	TTORATstpOrderVolumeTypeType	OrderVolumeType;

	///��Ч������
	TTORATstpTimeConditionType	TimeCondition;

	///�ɽ�������
	TTORATstpVolumeConditionType	VolumeCondition;

	///�����۸�
	TTORATstpPriceType	LimitPrice;

	///��������
	TTORATstpVolumeType	VolumeTotalOriginal;

	///��Ͽ�ƽ��־
	TTORATstpCombOffsetFlagType	CombOffsetFlag;

	///���Ͷ���ױ���־
	TTORATstpCombHedgeFlagType	CombHedgeFlag;

	///������������
	TTORATstpOrderRefType	CondOrderRef;

	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///�û�����
	TTORATstpUserIDType	UserID;

	///������
	TTORATstpRequestIDType	RequestID;

	///IP��ַ
	TTORATstpIPAddressType	IPAddress;

	///Mac��ַ
	TTORATstpMacAddressType	MacAddress;

	///�������
	TTORATstpCondOrderIDType	CondOrderID;

	///�ն���Ϣ
	TTORATstpTerminalInfoType	TerminalInfo;

	///���ַ���������Ϣ
	TTORATstpBigsInfoType	BInfo;

	///���ַ���������Ϣ
	TTORATstpShortsInfoType	SInfo;

	///���θ�����Ϣ
	TTORATstpIntInfoType	IInfo;

	///ί�з�ʽ
	TTORATstpOperwayType	Operway;

	///�������
	TTORATstpCondCheckType	CondCheck;

	///��������������
	TTORATstpContingentConditionType	ContingentCondition;

	///������
	TTORATstpPriceType	ConditionPrice;

	///�۸񸡶�tick��,>0���ϸ���,<0���¸���,=0������
	TTORATstpVolumeType	PriceTicks;

	///������������,����>=0
	TTORATstpVolumeMultipleType	VolumeMultiple;

	///���ǰ�ñ��
	TTORATstpFrontIDType	RelativeFrontID;

	///��ػỰ���
	TTORATstpSessionIDType	RelativeSessionID;

	///�����������,����ΪOrderRef��OrderSysID��Time��SecurityID
	TTORATstpRelativeCondParamType	RelativeParam;

	///������������������
	TTORATstpContingentConditionType	AppendContingentCondition;

	///����������
	TTORATstpPriceType	AppendConditionPrice;

	///�������ǰ�ñ��
	TTORATstpFrontIDType	AppendRelativeFrontID;

	///������ػỰ���
	TTORATstpSessionIDType	AppendRelativeSessionID;

	///���������������,����ΪOrderRef��OrderSysID��Time��SecurityID
	TTORATstpRelativeCondParamType	AppendRelativeParam;

	///���׷���������
	TTORATstpDateType	TradingDay;

	///������״̬
	TTORATstpCondOrderStatusType	CondOrderStatus;

	///��������
	TTORATstpDateType	InsertDate;

	///ί��ʱ��
	TTORATstpTimeType	InsertTime;

	///����ʱ��
	TTORATstpTimeType	CancelTime;

	///�����û�
	TTORATstpUserIDType	CancelUser;

	///ǰ�ñ��
	TTORATstpFrontIDType	FrontID;

	///ÿһλ����Ա��������¼�ߵ�¼ϵͳ��õĻỰ��ţ���ǰʱ��Ψһ
	TTORATstpSessionIDType	SessionID;

	///˵���û���ʹ�õ������Ʒ�Ͱ汾��
	TTORATstpProductInfoType	UserProductInfo;

	///״̬��Ϣ
	TTORATstpErrorMsgType	StatusMsg;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;

	///�ʵ��Կ���ҵ�����
	TTORATstpProperCtrlBusinessTypeType	ProperCtrlBusinessType;

	///�ʵ��Կ���ͨ����ʶ
	TTORATstpProperCtrlPassFlagType	ProperCtrlPassFlag;

	///��������
	TTORATstpDateType	ActiveDate;

	///����ʱ��
	TTORATstpTimeType	ActiveTime;


};

/// ����������¼��
struct CTORATstpInputCondOrderActionField
{
		
	///������
	TTORATstpRequestIDType	RequestID;

	///һ���������ı��
	TTORATstpExchangeIDType	ExchangeID;

	///��������������
	TTORATstpOrderRefType	CondOrderActionRef;

	///����������
	TTORATstpOrderRefType	CondOrderRef;

	///ǰ�ñ��
	TTORATstpFrontIDType	FrontID;

	///�Ự���
	TTORATstpSessionIDType	SessionID;

	///�������
	TTORATstpCondOrderIDType	CondOrderID;

	///������־
	TTORATstpActionFlagType	ActionFlag;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///��Լ��ϵͳ�еı��
	TTORATstpSecurityIDType	SecurityID;

	///�û�����
	TTORATstpUserIDType	UserID;

	///IP��ַ
	TTORATstpIPAddressType	IPAddress;

	///Mac��ַ
	TTORATstpMacAddressType	MacAddress;

	///�������������
	TTORATstpCondOrderIDType	CancelCondOrderID;

	///�ն���Ϣ
	TTORATstpTerminalInfoType	TerminalInfo;

	///���ַ���������Ϣ
	TTORATstpBigsInfoType	BInfo;

	///���ַ���������Ϣ
	TTORATstpShortsInfoType	SInfo;

	///���θ�����Ϣ
	TTORATstpIntInfoType	IInfo;

	///ί�з�ʽ
	TTORATstpOperwayType	Operway;

	///Ӳ�����к�
	TTORATstpHDSerialType	HDSerial;


};

/// ��ѯ���н���ϵͳ�ʽ�����
struct CTORATstpReqInquiryJZFundField
{
		
	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///����
	TTORATstpCurrencyIDType	CurrencyID;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;


};

/// ��ѯ���н���ϵͳ�ʽ���Ӧ
struct CTORATstpRspInquiryJZFundField
{
		
	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///����
	TTORATstpCurrencyIDType	CurrencyID;

	///���ý��
	TTORATstpMoneyType	UsefulMoney;

	///��ȡ���
	TTORATstpMoneyType	FetchLimit;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;


};

/// �ʽ�ת��
struct CTORATstpInputTransferFundField
{
		
	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///����
	TTORATstpCurrencyIDType	CurrencyID;

	///������ˮ��
	TTORATstpExternalSerialType	ApplySerial;

	///ת�Ʒ���
	TTORATstpTransferDirectionType	TransferDirection;

	///ת�˽��
	TTORATstpMoneyType	Amount;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;


};

/// ��λת��
struct CTORATstpInputTransferPositionField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///Ŀǰ���ֶδ�ŵ�����֤�������ڵĹɶ����롣
	TTORATstpShareholderIDType	ShareholderID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///������ˮ��
	TTORATstpExternalSerialType	ApplySerial;

	///ת�Ʒ���
	TTORATstpTransferDirectionType	TransferDirection;

	///����
	TTORATstpVolumeType	Volume;

	///ת�Ƴֲ�����
	TTORATstpTransferPositionTypeType	TransferPositionType;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;


};

/// �ʽ�ת�ƻر�
struct CTORATstpTransferFundField
{
		
	///ת����ˮ��(��̨���)
	TTORATstpSerialType	FundSerial;

	///������ˮ��
	TTORATstpExternalSerialType	ApplySerial;

	///ǰ�ñ��
	TTORATstpFrontIDType	FrontID;

	///�Ự���
	TTORATstpSessionIDType	SessionID;

	///�ʽ��˻�����
	TTORATstpAccountIDType	AccountID;

	///���ִ���
	TTORATstpCurrencyIDType	CurrencyID;

	///ת�Ʒ���
	TTORATstpTransferDirectionType	TransferDirection;

	///�ʽ��˻����ճ������
	TTORATstpMoneyType	Amount;

	///ת��״̬
	TTORATstpTransferStatusType	TransferStatus;

	///������Ա
	TTORATstpUserIDType	OperatorID;

	///��������
	TTORATstpDateType	OperateDate;

	///����ʱ��
	TTORATstpTimeType	OperateTime;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;


};

/// ��λת�ƻر�
struct CTORATstpTransferPositionField
{
		
	///��λת����ˮ��
	TTORATstpSerialType	PositionSerial;

	///������ˮ��
	TTORATstpExternalSerialType	ApplySerial;

	///ǰ�ñ��
	TTORATstpFrontIDType	FrontID;

	///�Ự���
	TTORATstpSessionIDType	SessionID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///Ŀǰ���ֶδ�ŵ�����֤�������ڵĹɶ����롣
	TTORATstpShareholderIDType	ShareholderID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///������
	TTORATstpDateType	TradingDay;

	///ת�Ʒ���
	TTORATstpTransferDirectionType	TransferDirection;

	///ת�Ƴֲ�����
	TTORATstpTransferPositionTypeType	TransferPositionType;

	///���ղ�λת��ת��������
	TTORATstpVolumeType	HistoryVolume;

	///����������λת��ת��������
	TTORATstpVolumeType	TodayBSVolume;

	///���������λת��ת��������
	TTORATstpVolumeType	TodayPRVolume;

	///ת��״̬��0��������1���ѳ���
	TTORATstpTransferStatusType	TransferStatus;

	///������Ա
	TTORATstpUserIDType	OperatorID;

	///��������
	TTORATstpDateType	OperateDate;

	///����ʱ��
	TTORATstpTimeType	OperateTime;


};

/// ��������
struct CTORATstpSpecificSecurityField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;


};

/// ����Ʒת������
struct CTORATstpInputTransferCollateralField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///Ŀǰ���ֶδ�ŵ�����֤�������ڵĹɶ����롣
	TTORATstpShareholderIDType	ShareholderID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///������ˮ��
	TTORATstpExternalSerialType	ApplySerial;

	///����Ʒ��ת����
	TTORATstpCollateralDirectionType	CollateralDirection;

	///����
	TTORATstpVolumeType	Volume;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///ί�з�ʽ
	TTORATstpOperwayType	Operway;


};

/// Lev2����
struct CTORATstpLev2MarketDataField
{
		
	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///���齻��������
	TTORATstpExchangeIDType	ExchangeID;

	///ʱ���
	TTORATstpTimeStampType	DataTimeStamp;

	///������
	TTORATstpPriceType	PreClosePrice;

	///����
	TTORATstpPriceType	OpenPrice;

	///�ɽ�����
	TTORATstpLongVolumeType	NumTrades;

	///�ɽ�����
	TTORATstpLongVolumeType	TotalVolumeTrade;

	///�ɽ��ܽ��
	TTORATstpMoneyType	TotalValueTrade;

	///ί������������ֻ���Ͻ������ͣ�
	TTORATstpLongVolumeType	TotalBidVolume;

	///��Ȩƽ��ί����۸�ֻ���Ͻ������ͣ�
	TTORATstpPriceType	AvgBidPrice;

	///ί������������ֻ���Ͻ������ͣ�
	TTORATstpLongVolumeType	TotalAskVolume;

	///��Ȩƽ��ί�����۸�ֻ���Ͻ������ͣ�
	TTORATstpPriceType	AvgAskPrice;

	///��߼�
	TTORATstpPriceType	HighestPrice;

	///��ͼ�
	TTORATstpPriceType	LowestPrice;

	///�ּ�
	TTORATstpPriceType	LastPrice;

	///�����һ
	TTORATstpPriceType	BidPrice1;

	///������һ
	TTORATstpLongVolumeType	BidVolume1;

	///������һ
	TTORATstpPriceType	AskPrice1;

	///������һ
	TTORATstpLongVolumeType	AskVolume1;

	///�����۶�
	TTORATstpPriceType	AskPrice2;

	///��������
	TTORATstpLongVolumeType	AskVolume2;

	///��������
	TTORATstpPriceType	AskPrice3;

	///��������
	TTORATstpLongVolumeType	AskVolume3;

	///����۶�
	TTORATstpPriceType	BidPrice2;

	///��������
	TTORATstpLongVolumeType	BidVolume2;

	///�������
	TTORATstpPriceType	BidPrice3;

	///��������
	TTORATstpLongVolumeType	BidVolume3;

	///��������
	TTORATstpPriceType	AskPrice4;

	///��������
	TTORATstpLongVolumeType	AskVolume4;

	///��������
	TTORATstpPriceType	AskPrice5;

	///��������
	TTORATstpLongVolumeType	AskVolume5;

	///�������
	TTORATstpPriceType	BidPrice4;

	///��������
	TTORATstpLongVolumeType	BidVolume4;

	///�������
	TTORATstpPriceType	BidPrice5;

	///��������
	TTORATstpLongVolumeType	BidVolume5;

	///��������
	TTORATstpPriceType	AskPrice6;

	///��������
	TTORATstpLongVolumeType	AskVolume6;

	///��������
	TTORATstpPriceType	AskPrice7;

	///��������
	TTORATstpLongVolumeType	AskVolume7;

	///�������
	TTORATstpPriceType	BidPrice6;

	///��������
	TTORATstpLongVolumeType	BidVolume6;

	///�������
	TTORATstpPriceType	BidPrice7;

	///��������
	TTORATstpLongVolumeType	BidVolume7;

	///�����۰�
	TTORATstpPriceType	AskPrice8;

	///��������
	TTORATstpLongVolumeType	AskVolume8;

	///�����۾�
	TTORATstpPriceType	AskPrice9;

	///��������
	TTORATstpLongVolumeType	AskVolume9;

	///����۰�
	TTORATstpPriceType	BidPrice8;

	///��������
	TTORATstpLongVolumeType	BidVolume8;

	///����۾�
	TTORATstpPriceType	BidPrice9;

	///��������
	TTORATstpLongVolumeType	BidVolume9;

	///�����ʮ
	TTORATstpPriceType	BidPrice10;

	///������ʮ
	TTORATstpLongVolumeType	BidVolume10;

	///������ʮ
	TTORATstpPriceType	AskPrice10;

	///������ʮ
	TTORATstpLongVolumeType	AskVolume10;

	///������Ϣ1
	TTORATstpIntInfoType	Info1;

	///������Ϣ2
	TTORATstpIntInfoType	Info2;

	///������Ϣ3
	TTORATstpIntInfoType	Info3;

	///��ͣ���(ֻ������������Ч)
	TTORATstpPriceType	UpperLimitPrice;

	///��ͣ���(ֻ������������Ч)
	TTORATstpPriceType	LowerLimitPrice;

	///�����̼�(ֻ���Ϻ�������Ч)
	TTORATstpPriceType	ClosePrice;

	///�����Ʒʵʱ״̬
	TTORATstpMDSecurityStatType	MDSecurityStat;


};

/// Lev2ָ������
struct CTORATstpLev2IndexField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///ʱ���
	TTORATstpTimeStampType	DataTimeStamp;

	///ǰ����ָ��
	TTORATstpPriceType	PreCloseIndex;

	///����ָ��
	TTORATstpPriceType	OpenIndex;

	///���ָ��
	TTORATstpPriceType	HighIndex;

	///���ָ��
	TTORATstpPriceType	LowIndex;

	///����ָ��
	TTORATstpPriceType	LastIndex;

	///���������Ӧָ���ĳɽ���Ԫ
	TTORATstpMoneyType	Turnover;

	///���������Ӧָ���Ľ�������(��)
	TTORATstpLongVolumeType	TotalVolumeTraded;

	///������Ϣ1
	TTORATstpIntInfoType	Info1;

	///������Ϣ2
	TTORATstpIntInfoType	Info2;

	///������Ϣ3
	TTORATstpIntInfoType	Info3;


};

/// Lev2��ʳɽ�
struct CTORATstpLev2TransactionField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///ʱ���
	TTORATstpTimeStampType	TradeTime;

	///�ɽ��۸�
	TTORATstpPriceType	TradePrice;

	///�ɽ�����
	TTORATstpLongVolumeType	TradeVolume;

	///�ɽ����
	TTORATstpExecTypeType	ExecType;

	///�����
	TTORATstpSequenceNoType	MainSeq;

	///�����
	TTORATstpLongSequenceType	SubSeq;

	///��ί�����
	TTORATstpLongSequenceType	BuyNo;

	///����ί�����
	TTORATstpLongSequenceType	SellNo;

	///������Ϣ1
	TTORATstpIntInfoType	Info1;

	///������Ϣ2
	TTORATstpIntInfoType	Info2;

	///������Ϣ3
	TTORATstpIntInfoType	Info3;


};

/// Lev2���ί��
struct CTORATstpLev2OrderDetailField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///ʱ���
	TTORATstpTimeStampType	OrderTime;

	///ί�м۸�
	TTORATstpPriceType	Price;

	///ί������
	TTORATstpLongVolumeType	Volume;

	///ί�з���
	TTORATstpLSideType	Side;

	///�������
	TTORATstpLOrderTypeType	OrderType;

	///�����
	TTORATstpSequenceNoType	MainSeq;

	///�����
	TTORATstpSequenceNoType	SubSeq;

	///������Ϣ1
	TTORATstpIntInfoType	Info1;

	///������Ϣ2
	TTORATstpIntInfoType	Info2;

	///������Ϣ3
	TTORATstpIntInfoType	Info3;


};

/// �ش���������
struct CTORATstpUploadTradeDataField
{
		
	///���������룬Ŀǰ֧�� SSE(�Ϻ�֤ȯ������)��SZSE(����֤ȯ������)
	TTORATstpExchangeIDType	ExchangeID;

	///������
	TTORATstpDateType	TradingDay;

	///�Ƿ�ǿ�ƻش���0=��;1=��
	TTORATstpBoolType	bForce;


};

/// ����ָ�����׵Ǽ�&����
struct CTORATstpInputDesignationRegistrationField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///�û�����
	TTORATstpUserIDType	UserID;

	///0��ָ���Ǽ� 1��ָ������
	TTORATstpDesignationTypeType	DesignationType;

	///Ŀǰ���ֶδ�ŵ�����֤�������ڵĹɶ����롣
	TTORATstpShareholderIDType	ShareholderID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///�������
	TTORATstpOrderSysIDType	OrderSysID;

	///IP��ַ
	TTORATstpIPAddressType	IPAddress;

	///Mac��ַ
	TTORATstpMacAddressType	MacAddress;

	///�ն���Ϣ
	TTORATstpTerminalInfoType	TerminalInfo;

	///Ӳ�����к�
	TTORATstpHDSerialType	HDSerial;


};

/// ������֤ת�й�
struct CTORATstpInputCustodyTransferField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///�û�����
	TTORATstpUserIDType	UserID;

	///|����ע��ת�й����� ~��ת�йܳ���
	TTORATstpCustodyTransferTypeType	CustodyTransferType;

	///Ŀǰ���ֶδ�ŵ�����֤�������ڵĹɶ����롣
	TTORATstpShareholderIDType	ShareholderID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///�������
	TTORATstpOrderSysIDType	OrderSysID;

	///ת�뽻�׵�Ԫ����
	TTORATstpPbuIDType	TransfereePbuID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///ȫϵͳ��Ψһ������š�16λ��1-2λΪ��������ʶ��3-5λΪ���͹�˾���룬6-8λΪ���׵�Ԫ��ʶ������8λΪ��ˮ�š�
	TTORATstpOrderLocalIDType	OrignalOrderLocalID;

	///ȫϵͳ��Ψһ������š�16λ��1-2λΪ��������ʶ��3-5λΪ���͹�˾���룬6-8λΪ���׵�Ԫ��ʶ������8λΪ��ˮ�š�
	TTORATstpOrderLocalIDType	OrderLocalID;

	///��������
	TTORATstpVolumeType	VolumeTotalOriginal;

	///IP��ַ
	TTORATstpIPAddressType	IPAddress;

	///Mac��ַ
	TTORATstpMacAddressType	MacAddress;

	///�ն���Ϣ
	TTORATstpTerminalInfoType	TerminalInfo;

	///Ӳ�����к�
	TTORATstpHDSerialType	HDSerial;


};

/// ���׳ɽ����ж�
struct CTORATstpInquiryTradeConcentrationField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///�����˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///Ͷ���߳ɽ���/�ɽ�����
	TTORATstpRatioType	ConcentrationRatio1;

	///Ͷ���߳ɽ����/�ɽ��ܽ��
	TTORATstpRatioType	ConcentrationRatio2;


};

/// ��ѯ�ļ�ί������
struct CTORATstpInquiryFileOrderField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�ɶ��˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///ί����ʼ��ˮ��
	TTORATstpSequenceNoType	OrderSerialBeg;

	///ί�н�����ˮ��
	TTORATstpSequenceNoType	OrderSerialEnd;

	///ί���ύ״̬
	TTORATstpCommitStatusType	CommitStatus;


};

/// �ļ�ί��
struct CTORATstpFileOrderField
{
		
	///������
	TTORATstpRequestIDType	RequestID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�ɶ��˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///��������
	TTORATstpOrderRefType	OrderRef;

	///�ļ��������
	TTORATstpFileOrderTypeType	FileOrderType;

	///��������
	TTORATstpDirectionType	Direction;

	///�޼۵��۸�
	TTORATstpPriceType	LimitPrice;

	///��������
	TTORATstpVolumeType	VolumeTotalOriginal;

	///ί�з�ʽ
	TTORATstpOperwayType	Operway;

	///������������
	TTORATstpOrderRefType	OrderActionRef;

	///�������
	TTORATstpOrderSysIDType	OrderSysID;

	///ί�м��
	TTORATstpCondCheckType	CondCheck;

	///ί����ˮ��
	TTORATstpSequenceNoType	OrderSerial;

	///�ļ�ί���ύ״̬
	TTORATstpCommitStatusType	CommitStatus;

	///�ļ�ί��״̬��Ϣ
	TTORATstpStatusMsgType	StatusMsg;

	///ί��ʱ���
	TTORATstpBigTimeStampType	TimeStamp;


};

/// ��ѯӦ����
struct CTORATstpQryRspInfoField
{
		
	///������ʶ
	TTORATstpEndFlagType	EndFlag;

	///�������
	TTORATstpErrorIDType	ErrorID;

	///������Ϣ
	TTORATstpErrorMsgType	ErrorMsg;


};

/// �ļ�ί�и�������
struct CTORATstpReviewFileOrderField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�ɶ��˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///ί����ʼ��ˮ��
	TTORATstpSequenceNoType	OrderSerialBeg;

	///ί�н�����ˮ��
	TTORATstpSequenceNoType	OrderSerialEnd;


};

/// �ļ��ύ��Ϣ
struct CTORATstpCommitInfoField
{
		
	///ί����ˮ��
	TTORATstpSequenceNoType	OrderSerial;

	///�ļ�ί���ύ״̬
	TTORATstpCommitStatusType	CommitStatus;

	///�ļ�ί��״̬��Ϣ
	TTORATstpStatusMsgType	StatusMsg;


};

/// ������뽻��֪ͨ
struct CTORATstpReqInsTradingNoticeField
{
		
	///֪ͨ��ˮ��
	TTORATstpSerialType	NoticeSerial;

	///֪ͨ����
	TTORATstpDateType	InsertDate;

	///֪ͨʱ��
	TTORATstpTimeType	InsertTime;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///֪ͨ��Ϣ����
	TTORATstpContentType	Content;

	///����Ա
	TTORATstpUserIDType	OperatorID;


};

/// ����֪ͨ
struct CTORATstpTradingNoticeField
{
		
	///֪ͨ��ˮ��
	TTORATstpSerialType	NoticeSerial;

	///֪ͨ����
	TTORATstpDateType	InsertDate;

	///֪ͨʱ��
	TTORATstpTimeType	InsertTime;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///֪ͨ��Ϣ����
	TTORATstpContentType	Content;

	///����Ա
	TTORATstpUserIDType	OperatorID;


};

/// װ���ļ�ί��
struct CTORATstpLoadFileOrderField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///�Ƿ���Ҫ����
	TTORATstpBoolType	bReview;


};

/// �ļ�ί����Ϣ
struct CTORATstpFileOrderInfoField
{
		
	///������
	TTORATstpRequestIDType	RequestID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�ɶ��˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///��������
	TTORATstpOrderRefType	OrderRef;

	///�ļ��������
	TTORATstpFileOrderTypeType	FileOrderType;

	///��������
	TTORATstpDirectionType	Direction;

	///�޼۵��۸�
	TTORATstpPriceType	LimitPrice;

	///��������
	TTORATstpVolumeType	VolumeTotalOriginal;

	///ί�з�ʽ
	TTORATstpOperwayType	Operway;

	///������������
	TTORATstpOrderRefType	OrderActionRef;

	///�������
	TTORATstpOrderSysIDType	OrderSysID;

	///ί�м��
	TTORATstpCondCheckType	CondCheck;

	///ί����ˮ��
	TTORATstpSequenceNoType	OrderSerial;

	///�ļ�ί���ύ״̬
	TTORATstpCommitStatusType	CommitStatus;

	///�ļ�ί��״̬��Ϣ
	TTORATstpStatusMsgType	StatusMsg;


};

/// ��ѯ��󱨵�������
struct CTORATstpReqInquiryMaxOrderVolumeField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///�����˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///��������
	TTORATstpDirectionType	Direction;

	///�޼۵����м۵�
	TTORATstpOrderPriceTypeType	OrderPriceType;

	///���ֽڱ�ʾ��������Լ�Ŀ�ƽ����
	TTORATstpCombOffsetFlagType	CombOffsetFlag;

	///���ֽڱ�ʾ��������Լ������ױ���־
	TTORATstpCombHedgeFlagType	CombHedgeFlag;

	///IOC��GFS��GFD��GTD��GTC��GFA
	TTORATstpTimeConditionType	TimeCondition;

	///AV��MV��CV
	TTORATstpVolumeConditionType	VolumeCondition;

	///�޼۵��۸�
	TTORATstpPriceType	LimitPrice;

	///ת�뽻�׵�Ԫ����(����ת�йܲ���ʱ��Ч)
	TTORATstpPbuIDType	TransfereePbuID;

	///���ί������
	TTORATstpVolumeType	MaxVolume;


};

/// ��ѯ��󱨵���Ӧ��
struct CTORATstpRspInquiryMaxOrderVolumeField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///�����˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///��������
	TTORATstpDirectionType	Direction;

	///�޼۵����м۵�
	TTORATstpOrderPriceTypeType	OrderPriceType;

	///���ֽڱ�ʾ��������Լ�Ŀ�ƽ����
	TTORATstpCombOffsetFlagType	CombOffsetFlag;

	///���ֽڱ�ʾ��������Լ������ױ���־
	TTORATstpCombHedgeFlagType	CombHedgeFlag;

	///IOC��GFS��GFD��GTD��GTC��GFA
	TTORATstpTimeConditionType	TimeCondition;

	///AV��MV��CV
	TTORATstpVolumeConditionType	VolumeCondition;

	///�޼۵��۸�
	TTORATstpPriceType	LimitPrice;

	///ת�뽻�׵�Ԫ����(����ת�йܲ���ʱ��Ч)
	TTORATstpPbuIDType	TransfereePbuID;

	///���ί������
	TTORATstpVolumeType	MaxVolume;


};

/// ��Χϵͳ��λ������ˮ��ϸ
struct CTORATstpPeripheryPositionTransferDetailField
{
		
	///��λ����ϵͳ��ˮ��
	TTORATstpIntSerialType	PositionSerial;

	///��λ����������ˮ��
	TTORATstpIntSerialType	ApplySerial;

	///ǰ�ñ��
	TTORATstpFrontIDType	FrontID;

	///�Ự���
	TTORATstpSessionIDType	SessionID;

	///��λ��������
	TTORATstpTransferDirectionType	TransferDirection;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ֻ�ϵͳ�����˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///����������λת��ת������
	TTORATstpVolumeType	TodayBSPos;

	///���������λת������
	TTORATstpVolumeType	TodayPRPos;

	///���ղ�λת������
	TTORATstpVolumeType	HistoryPos;

	///��������
	TTORATstpDateType	TradingDay;

	///��λ����ԭ��
	TTORATstpTransferReasonType	TransferReason;

	///ת��״̬
	TTORATstpTransferStatusType	TransferStatus;

	///��������
	TTORATstpDateType	OperateDate;

	///����ʱ��
	TTORATstpTimeType	OperateTime;

	///��������
	TTORATstpDateType	RepealDate;

	///����ʱ��
	TTORATstpTimeType	RepealTime;

	///����ԭ��
	TTORATstpTransferReasonType	RepealReason;

	///״̬��Ϣ
	TTORATstpErrorMsgType	StatusMsg;


};

/// ��ѯ��ʷί��
struct CTORATstpQryHistoryOrderField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///��ʼ����
	TTORATstpDateType	BegDate;

	///��������
	TTORATstpDateType	EndDate;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///ÿҳ��¼��
	TTORATstpVolumeType	PageCount;

	///ҳ��λ��
	TTORATstpPageLocateType	PageLocate;


};

/// ��ѯ��ʷ��Ӧ��Ϣ
struct CTORATstpQryHistoryRspInfoField
{
		
	///�������
	TTORATstpErrorIDType	ErrorID;

	///������Ϣ
	TTORATstpErrorMsgType	ErrorMsg;

	///��ҳ�Ƿ����
	TTORATstpBoolType	bPageEnd;


};

/// ��ʷί����Ϣ
struct CTORATstpHistoryOrderField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///��Լ��ϵͳ�еı��
	TTORATstpSecurityIDType	SecurityID;

	///Ͷ����˵���ĶԱ�����Ψһ����
	TTORATstpOrderRefType	OrderRef;

	///�û�����
	TTORATstpUserIDType	UserID;

	///�޼۵����м۵�
	TTORATstpOrderPriceTypeType	OrderPriceType;

	///1����2����
	TTORATstpDirectionType	Direction;

	///���ֽڱ�ʾ��������Լ�Ŀ�ƽ����
	TTORATstpCombOffsetFlagType	CombOffsetFlag;

	///���ֽڱ�ʾ��������Լ������ױ���־
	TTORATstpCombHedgeFlagType	CombHedgeFlag;

	///�޼۵��۸�
	TTORATstpPriceType	LimitPrice;

	///��������
	TTORATstpVolumeType	VolumeTotalOriginal;

	///IOC��GFS��GFD��GTD��GTC��GFA
	TTORATstpTimeConditionType	TimeCondition;

	///AV��MV��CV
	TTORATstpVolumeConditionType	VolumeCondition;

	///���ɽ�������ΪMVʱ��Ч
	TTORATstpVolumeType	MinVolume;

	///ǿƽԭ��
	TTORATstpForceCloseReasonType	ForceCloseReason;

	///������
	TTORATstpRequestIDType	RequestID;

	///���ر���˳���
	TTORATstpOrderLocalIDType	OrderLocalID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///�ͻ���ϵͳ�еı�ţ����Ψһ����ѭ�������ƶ��ı������
	TTORATstpShareholderIDType	ShareholderID;

	///��Լ�ڽ������Ĵ���
	TTORATstpExchangeInstIDType	ExchangeInstID;

	///����������Ա����
	TTORATstpTraderIDType	TraderID;

	///�����ύ״̬
	TTORATstpOrderSubmitStatusType	OrderSubmitStatus;

	///���׷���������
	TTORATstpDateType	TradingDay;

	///�������
	TTORATstpOrderSysIDType	OrderSysID;

	///0��ȫ���ɽ�1�����ֳɽ����ڶ�����2�����ֳɽ����ڶ�����3��δ�ɽ����ڶ�����4��δ�ɽ����ڶ�����5������
	TTORATstpOrderStatusType	OrderStatus;

	///0����ͨ1����������2���������
	TTORATstpOrderTypeType	OrderType;

	///�����������
	TTORATstpVolumeType	VolumeTraded;

	///����δ�������
	TTORATstpVolumeType	VolumeTotal;

	///��������
	TTORATstpDateType	InsertDate;

	///ί��ʱ��
	TTORATstpTimeType	InsertTime;

	///����ʱ��
	TTORATstpTimeType	CancelTime;

	///����޸Ľ���������Ա����
	TTORATstpTraderIDType	ActiveTraderID;

	///ǰ�ñ��
	TTORATstpFrontIDType	FrontID;

	///ÿһλ����Ա��������¼�ߵ�¼ϵͳ��õĻỰ��ţ���ǰʱ��Ψһ
	TTORATstpSessionIDType	SessionID;

	///˵���û���ʹ�õ������Ʒ�Ͱ汾��
	TTORATstpProductInfoType	UserProductInfo;

	///״̬��Ϣ
	TTORATstpErrorMsgType	StatusMsg;

	///�û�ǿ����־
	TTORATstpBoolType	UserForceClose;

	///�����û�����
	TTORATstpUserIDType	ActiveUserID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///IP��ַ
	TTORATstpIPAddressType	IPAddress;

	///Mac��ַ
	TTORATstpMacAddressType	MacAddress;

	///ͷ������
	TTORATstpCreditPositionTypeType	CreditPositionType;

	///���ַ���������Ϣ
	TTORATstpBigsInfoType	BInfo;

	///���ַ���������Ϣ
	TTORATstpShortsInfoType	SInfo;

	///���θ�����Ϣ
	TTORATstpIntInfoType	IInfo;

	///ת�뽻�׵�Ԫ����(����ת�йܲ���ʱ��Ч)
	TTORATstpPbuIDType	TransfereePbuID;

	///ί�з�ʽ
	TTORATstpOperwayType	Operway;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;

	///�ʵ��Կ���ҵ�����
	TTORATstpProperCtrlBusinessTypeType	ProperCtrlBusinessType;

	///�ʵ��Կ���ͨ����ʾ
	TTORATstpProperCtrlPassFlagType	ProperCtrlPassFlag;

	///�������
	TTORATstpCondCheckType	CondCheck;

	///�Ƿ�Ԥ��
	TTORATstpBoolType	IsCacheOrder;

	///���ݳɽ��۸������ı��ʳɽ��Ľ����������ã�
	TTORATstpMoneyType	Turnover;

	///ҳ��λ��
	TTORATstpPageLocateType	PageLocate;


};

/// ��ѯ��ʷ�ɽ�
struct CTORATstpQryHistoryTradeField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///��ʼ����
	TTORATstpDateType	BegDate;

	///��������
	TTORATstpDateType	EndDate;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///ÿҳ��¼��
	TTORATstpVolumeType	PageCount;

	///ҳ��λ��
	TTORATstpPageLocateType	PageLocate;


};

/// ��ʷ�ɽ���Ϣ
struct CTORATstpHistoryTradeField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///��Լ��ϵͳ�еı��
	TTORATstpSecurityIDType	SecurityID;

	///�û�����
	TTORATstpUserIDType	UserID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�ɽ����
	TTORATstpTradeIDType	TradeID;

	///1.��2.��
	TTORATstpDirectionType	Direction;

	///�������
	TTORATstpOrderSysIDType	OrderSysID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///�ͻ���ϵͳ�еı�ţ����Ψһ����ѭ�������ƶ��ı������
	TTORATstpShareholderIDType	ShareholderID;

	///��Լ�ڽ������Ĵ���
	TTORATstpExchangeInstIDType	ExchangeInstID;

	///1������2��ƽ��3��ƽ��4��ǿƽ
	TTORATstpOffsetFlagType	OffsetFlag;

	///1.Ͷ��2.�ױ�
	TTORATstpHedgeFlagType	HedgeFlag;

	///�ɽ��۸�
	TTORATstpPriceType	Price;

	///�ɽ�����
	TTORATstpVolumeType	Volume;

	///�ɽ�����
	TTORATstpDateType	TradeDate;

	///�ɽ�ʱ��
	TTORATstpTimeType	TradeTime;

	///����Ա��ϵͳ�еı�ţ����Ψһ����ѭ�������ƶ��ı������
	TTORATstpTraderIDType	TraderID;

	///���ر���˳���
	TTORATstpOrderLocalIDType	OrderLocalID;

	///���׷���������
	TTORATstpDateType	TradingDay;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///��������
	TTORATstpOrderRefType	OrderRef;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;

	///ҳ��λ��
	TTORATstpPageLocateType	PageLocate;


};

/// ��ѯ������
struct CTORATstpQryExchangeField
{
		
	///���������룬Ŀǰ֧�� SSE(�Ϻ�֤ȯ������)��SZSE(����֤ȯ������)
	TTORATstpExchangeIDType	ExchangeID;


};

/// ������
struct CTORATstpExchangeField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///����������
	TTORATstpNameType	ExchangeName;

	///������
	TTORATstpDateType	TradingDay;


};

/// ��ѯPBU
struct CTORATstpQryPBUField
{
		
	///���׵�Ԫ����
	TTORATstpPbuIDType	PbuID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;


};

/// PBU
struct CTORATstpPBUField
{
		
	///���׵�Ԫ����
	TTORATstpPbuIDType	PbuID;

	///���׵�Ԫ����
	TTORATstpNameType	PbuName;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�г�����
	TTORATstpMarketIDType	MarketID;


};

/// ��ѯʵʱ����
struct CTORATstpQryMarketDataField
{
		
	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///���������룬Ŀǰ֧�� SSE(�Ϻ�֤ȯ������)��SZSE(����֤ȯ������)
	TTORATstpExchangeIDType	ExchangeID;


};

/// ʵʱ����
struct CTORATstpMarketDataField
{
		
	///������
	TTORATstpDateType	TradingDay;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///��Լ�ڽ������Ĵ���
	TTORATstpExchangeInstIDType	ExchangeInstID;

	///���¼�
	TTORATstpPriceType	LastPrice;

	///������
	TTORATstpPriceType	PreClosePrice;

	///����
	TTORATstpPriceType	OpenPrice;

	///��߼�
	TTORATstpPriceType	HighestPrice;

	///��ͼ�
	TTORATstpPriceType	LowestPrice;

	///����
	TTORATstpLongVolumeType	Volume;

	///�ɽ����
	TTORATstpMoneyType	Turnover;

	///�ֲ���
	TTORATstpLargeVolumeType	OpenInterest;

	///��ͣ���
	TTORATstpPriceType	UpperLimitPrice;

	///��ͣ���
	TTORATstpPriceType	LowerLimitPrice;

	///����޸�ʱ��
	TTORATstpTimeType	UpdateTime;

	///����޸ĺ���
	TTORATstpMillisecType	UpdateMillisec;

	///�����һ
	TTORATstpPriceType	BidPrice1;

	///������һ
	TTORATstpLongVolumeType	BidVolume1;

	///������һ
	TTORATstpPriceType	AskPrice1;

	///������һ
	TTORATstpLongVolumeType	AskVolume1;

	///����۶�
	TTORATstpPriceType	BidPrice2;

	///��������
	TTORATstpLongVolumeType	BidVolume2;

	///�����۶�
	TTORATstpPriceType	AskPrice2;

	///��������
	TTORATstpLongVolumeType	AskVolume2;

	///�������
	TTORATstpPriceType	BidPrice3;

	///��������
	TTORATstpLongVolumeType	BidVolume3;

	///��������
	TTORATstpPriceType	AskPrice3;

	///��������
	TTORATstpLongVolumeType	AskVolume3;

	///�������
	TTORATstpPriceType	BidPrice4;

	///��������
	TTORATstpLongVolumeType	BidVolume4;

	///��������
	TTORATstpPriceType	AskPrice4;

	///��������
	TTORATstpLongVolumeType	AskVolume4;

	///�������
	TTORATstpPriceType	BidPrice5;

	///��������
	TTORATstpLongVolumeType	BidVolume5;

	///��������
	TTORATstpPriceType	AskPrice5;

	///��������
	TTORATstpLongVolumeType	AskVolume5;

	///��Լ����
	TTORATstpSecurityNameType	SecurityName;

	///�ɽ�����
	TTORATstpLongVolumeType	TradingCount;

	///��ӯ��1
	TTORATstpRatioType	PERatio1;

	///��ӯ��2
	TTORATstpRatioType	PERatio2;

	///�۸�����1
	TTORATstpPriceType	PriceUpDown1;

	///�۸�����2
	TTORATstpPriceType	PriceUpDown2;

	///���̼�
	TTORATstpPriceType	ClosePrice;

	///֤ȯʵʱ״̬
	TTORATstpMDSecurityStatType	MDSecurityStat;

	///�Ƿ���վ�ʾ��־0��1��
	TTORATstpBoolType	HWFlag;


};

/// ��ѯ֤ȯ��Ϣ
struct CTORATstpQrySecurityField
{
		
	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///���������룬Ŀǰ֧�� SSE(�Ϻ�֤ȯ������)��SZSE(����֤ȯ������)
	TTORATstpExchangeIDType	ExchangeID;

	///��Լ�ڽ������Ĵ���
	TTORATstpExchangeInstIDType	ExchangeInstID;

	///֤ȯ�г��еľ���Ʒ�֣����Ϻ���Ʊ
	TTORATstpProductIDType	ProductID;


};

/// ֤ȯ��Ϣ
struct CTORATstpSecurityField
{
		
	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///��Լ����
	TTORATstpSecurityNameType	SecurityName;

	///��Լ�ڽ������Ĵ���
	TTORATstpExchangeInstIDType	ExchangeInstID;

	///�г�����
	TTORATstpMarketIDType	MarketID;

	///��Ʒ����
	TTORATstpProductIDType	ProductID;

	///֤ȯ������
	TTORATstpSecurityTypeType	SecurityType;

	///�걨��λ
	TTORATstpOrderUnitType	OrderUnit;

	///���뽻�׵�λ
	TTORATstpTradingUnitType	BuyTradingUnit;

	///�������׵�λ
	TTORATstpTradingUnitType	SellTradingUnit;

	///�м۵�������µ���
	TTORATstpVolumeType	MaxMarketOrderBuyVolume;

	///�м۵�����С�µ���
	TTORATstpVolumeType	MinMarketOrderBuyVolume;

	///�޼۵�������µ���
	TTORATstpVolumeType	MaxLimitOrderBuyVolume;

	///�޼۵�����С�µ���
	TTORATstpVolumeType	MinLimitOrderBuyVolume;

	///�м۵�������µ���
	TTORATstpVolumeType	MaxMarketOrderSellVolume;

	///�м۵�����С�µ���
	TTORATstpVolumeType	MinMarketOrderSellVolume;

	///�޼۵�������µ���
	TTORATstpVolumeType	MaxLimitOrderSellVolume;

	///�޼۵�����С�µ���
	TTORATstpVolumeType	MinLimitOrderSellVolume;

	///��������
	TTORATstpVolumeMultipleType	VolumeMultiple;

	///��С�䶯��λ
	TTORATstpPriceTickType	PriceTick;

	///������
	TTORATstpDateType	OpenDate;

	///�ֲ�����
	TTORATstpPositionTypeType	PositionType;

	///��ֵ
	TTORATstpParValueType	ParValue;

	///֤ȯ״̬
	TTORATstpSecurityStatusType	SecurityStatus;

	///ծȯӦ����Ϣ
	TTORATstpInterestType	BondInterest;

	///������
	TTORATstpRatioType	ConversionRate;

	///�Ƿ񵣱�Ʒ
	TTORATstpBoolType	IsCollateral;


};

/// ��ѯETF�嵥��Ϣ
struct CTORATstpQryETFFileField
{
		
	///���������룬Ŀǰ֧�� SSE(�Ϻ�֤ȯ������)��SZSE(����֤ȯ������)
	TTORATstpExchangeIDType	ExchangeID;

	///ETF�����г����״���
	TTORATstpSecurityIDType	ETFSecurityID;

	///ETFһ���г��������
	TTORATstpSecurityIDType	ETFCreRedSecurityID;


};

/// ETF�嵥��Ϣ
struct CTORATstpETFFileField
{
		
	///������
	TTORATstpDateType	TradingDay;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///ETF���״���
	TTORATstpSecurityIDType	ETFSecurityID;

	///ETF�������
	TTORATstpSecurityIDType	ETFCreRedSecurityID;

	///��С�깺��ص�λ����
	TTORATstpVolumeType	CreationRedemptionUnit;

	///����ֽ��������
	TTORATstpRatioType	Maxcashratio;

	///�Ƿ������깺
	TTORATstpBoolType	CreationStatus;

	///�Ƿ��������
	TTORATstpBoolType	RedemptionStatus;

	///Ԥ���ֽ���
	TTORATstpMoneyType	EstimateCashComponent;

	///ǰһ�������ֽ���
	TTORATstpMoneyType	CashComponent;

	///ǰһ�����ջ���λ��ֵ
	TTORATstpMoneyType	NAV;

	///ǰһ�����������׼��λ��ֵ
	TTORATstpMoneyType	NAVperCU;

	///�����깺��ػ�׼��λ�ĺ������
	TTORATstpMoneyType	DividendPerCU;


};

/// ��ѯETF�ɷ�֤ȯ��Ϣ
struct CTORATstpQryETFBasketField
{
		
	///���������룬Ŀǰ֧�� SSE(�Ϻ�֤ȯ������)��SZSE(����֤ȯ������)
	TTORATstpExchangeIDType	ExchangeID;

	///ETF�����г����״���
	TTORATstpSecurityIDType	ETFSecurityID;

	///ETF�����еĳɷ�֤ȯ����
	TTORATstpSecurityIDType	SecurityID;


};

/// ETF�ɷ�֤ȯ��Ϣ
struct CTORATstpETFBasketField
{
		
	///������
	TTORATstpDateType	TradingDay;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///ETF���״���
	TTORATstpSecurityIDType	ETFSecurityID;

	///ETF�ɷ�֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///֤ȯ���
	TTORATstpSecurityNameType	SecurityName;

	///֤ȯ����
	TTORATstpVolumeType	Volume;

	///�����־
	TTORATstpETFCurrenceReplaceStatusType	ETFCurrenceReplaceStatus;

	///��۱���
	TTORATstpRatioType	Premium;

	///�깺������
	TTORATstpMoneyType	CreationReplaceAmount;

	///���������
	TTORATstpMoneyType	RedemptionReplaceAmount;

	///�����г�
	TTORATstpListingMarketType	Market;


};

/// ��ѯ���͹�˾������Ϣ
struct CTORATstpQryDepartmentInfoField
{
		
	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;


};

/// ���͹�˾������Ϣ
struct CTORATstpDepartmentInfoField
{
		
	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;

	///���͹�˾��������
	TTORATstpNameType	DepartmentName;


};

/// ��ѯ�¹���Ϣ
struct CTORATstpQryIPOInfoField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�깺����
	TTORATstpSecurityIDType	SecurityID;


};

/// �¹���Ϣ
struct CTORATstpIPOInfoField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�깺����
	TTORATstpSecurityIDType	SecurityID;

	///�г�����
	TTORATstpMarketIDType	MarketID;

	///��Ʒ����
	TTORATstpProductIDType	ProductID;

	///֤ȯ������
	TTORATstpSecurityTypeType	SecurityType;

	///�����깺����
	TTORATstpVolumeType	OnlineLimit;

	///���м۸�
	TTORATstpPriceType	Price;

	///���ִ���
	TTORATstpCurrencyIDType	CurrencyID;

	///�깺֤ȯ����
	TTORATstpSecurityNameType	SecurityName;

	///�¹�֤ȯ����
	TTORATstpSecurityIDType	UnderlyingSecurityID;

	///�¹�֤ȯ����
	TTORATstpSecurityNameType	UnderlyingSecurityName;

	///�����깺��С����
	TTORATstpVolumeType	OnlineMinVol;

	///�����깺��λ����
	TTORATstpVolumeType	OnlineVolUnit;


};

/// ��ѯBrokerUserFunction
struct CTORATstpQryBrokerUserFunctionField
{
		
	///�����û�����
	TTORATstpUserIDType	UserID;


};

/// BrokerUserFunction
struct CTORATstpBrokerUserFunctionField
{
		
	///�û�����
	TTORATstpUserIDType	UserID;

	///���ܴ���
	TTORATstpFunctionIDType	FunctionID;


};

/// ��ѯ���͹�˾�û���Ͷ���߹�ϵ
struct CTORATstpQryBUProxyField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///�����û�����
	TTORATstpUserIDType	UserID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;


};

/// ���͹�˾�û���Ͷ���߹�ϵ
struct CTORATstpBUProxyField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///�û�����
	TTORATstpUserIDType	UserID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;


};

/// ��ѯUser
struct CTORATstpQryUserField
{
		
	///�û�����
	TTORATstpUserIDType	UserID;

	///�û�����
	TTORATstpUserTypeType	UserType;


};

/// User
struct CTORATstpUserField
{
		
	///�û�����
	TTORATstpUserIDType	UserID;

	///�û�����
	TTORATstpUserNameType	UserName;

	///�û�����
	TTORATstpUserTypeType	UserType;

	///�Ƿ��Ծ
	TTORATstpBoolType	IsActive;

	///��¼����
	TTORATstpLoginLimitType	LoginLimit;


};

/// ��ѯͶ����
struct CTORATstpQryInvestorField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;


};

/// Ͷ����
struct CTORATstpInvestorField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ��������
	TTORATstpInvestorNameType	InvestorName;

	///֤������
	TTORATstpIdCardTypeType	IdCardType;

	///֤������
	TTORATstpIdCardNoType	IdCardNo;

	///��ϵ�绰
	TTORATstpTelephoneType	Telephone;

	///ͨѶ��ַ
	TTORATstpAddressType	Address;

	///��������
	TTORATstpDateType	OpenDate;

	///�ֻ�
	TTORATstpMobileType	Mobile;

	///ί�з�ʽ
	TTORATstpOperwaysType	Operways;

	///�ͻ����յȼ�
	TTORATstpCRiskLevelType	CRiskLevel;

	///רҵͶ�������
	TTORATstpProfInvestorTypeType	ProfInvestorType;


};

/// ��ѯ���ױ���
struct CTORATstpQryShareholderAccountField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///�ɶ�����
	TTORATstpShareholderIDType	ShareholderID;

	///��ͨ�����ã�����Ʒ��
	TTORATstpClientIDTypeType	TradingCodeClass;


};

/// ���ױ���
struct CTORATstpShareholderAccountField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�ͻ�����
	TTORATstpShareholderIDType	ShareholderID;

	///���ױ�������
	TTORATstpClientIDTypeType	ClientIDType;

	///�г�����
	TTORATstpMarketIDType	MarketID;


};

/// ��ѯͶ�ʵ�Ԫ
struct CTORATstpQryBusinessUnitField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;


};

/// Ͷ�ʵ�Ԫ
struct CTORATstpBusinessUnitField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitNameType	BusinessUnitName;


};

/// ��ѯͶ�ʵ�Ԫ�뽻���˻���ϵ
struct CTORATstpQryBusinessUnitAndTradingAcctField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///֤ȯ�г��еľ���Ʒ�֣����Ϻ���Ʊ
	TTORATstpProductIDType	ProductID;

	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///����
	TTORATstpCurrencyIDType	CurrencyID;


};

/// Ͷ�ʵ�Ԫ�뽻���˻���ϵ
struct CTORATstpBusinessUnitAndTradingAcctField
{
		
	///���͹�˾����
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�г�����
	TTORATstpMarketIDType	MarketID;

	///�ͻ�����
	TTORATstpShareholderIDType	ShareholderID;

	///��Ʒ����
	TTORATstpProductIDType	ProductID;

	///�ʽ��˻�����
	TTORATstpAccountIDType	AccountID;

	///�ʽ��˻�����
	TTORATstpCurrencyIDType	CurrencyID;

	///�û�����
	TTORATstpUserIDType	UserID;


};

/// ��ѯ����
struct CTORATstpQryOrderField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///��Լ��ϵͳ�еı��
	TTORATstpSecurityIDType	SecurityID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///�ͻ���ϵͳ�еı�ţ����Ψһ����ѭ�������ƶ��ı������
	TTORATstpShareholderIDType	ShareholderID;

	///�������
	TTORATstpOrderSysIDType	OrderSysID;

	///Insert Time
	TTORATstpTimeType	InsertTimeStart;

	///Insert Time
	TTORATstpTimeType	InsertTimeEnd;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///���ַ���������Ϣ
	TTORATstpBigsInfoType	BInfo;

	///���ַ���������Ϣ
	TTORATstpShortsInfoType	SInfo;

	///���θ�����Ϣ
	TTORATstpIntInfoType	IInfo;

	///�Ƿ�ɳ�
	TTORATstpBoolType	IsCancel;


};

/// ��ѯ����
struct CTORATstpQryOrderActionField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///һ���������ı��
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///�ͻ���ϵͳ�еı�ţ����Ψһ����ѭ�������ƶ��ı������
	TTORATstpShareholderIDType	ShareholderID;

	///���ַ���������Ϣ
	TTORATstpBigsInfoType	BInfo;

	///���ַ���������Ϣ
	TTORATstpShortsInfoType	SInfo;

	///���θ�����Ϣ
	TTORATstpIntInfoType	IInfo;


};

/// ��ѯ�ɽ�
struct CTORATstpQryTradeField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///��Լ��ϵͳ�еı��
	TTORATstpSecurityIDType	SecurityID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///�ͻ���ϵͳ�еı�ţ����Ψһ����ѭ�������ƶ��ı������
	TTORATstpShareholderIDType	ShareholderID;

	///�ɽ����
	TTORATstpTradeIDType	TradeID;

	///Insert Time
	TTORATstpTimeType	TradeTimeStart;

	///Insert Time
	TTORATstpTimeType	TradeTimeEnd;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;


};

/// ��ѯ�ʽ��˻�
struct CTORATstpQryTradingAccountField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///����
	TTORATstpCurrencyIDType	CurrencyID;

	///�ʽ��˻�
	TTORATstpAccountIDType	AccountID;

	///1����ͨ��2�����ã�3������Ʒ
	TTORATstpAccountTypeType	AccountType;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;


};

/// �ʽ��˻�
struct CTORATstpTradingAccountField
{
		
	///�ʽ��˻�����
	TTORATstpAccountIDType	AccountID;

	///�����ʽ�
	TTORATstpMoneyType	Available;

	///��ȡ�ʽ�
	TTORATstpMoneyType	WithdrawQuota;

	///���ִ���
	TTORATstpCurrencyIDType	CurrencyID;

	///�����
	TTORATstpMoneyType	Deposit;

	///������
	TTORATstpMoneyType	Withdraw;

	///����ı�֤��
	TTORATstpMoneyType	FrozenMargin;

	///������ʽ�
	TTORATstpMoneyType	FrozenCash;

	///�����������
	TTORATstpMoneyType	FrozenCommission;

	///��ǰ��֤���ܶ�
	TTORATstpMoneyType	CurrMargin;

	///������
	TTORATstpMoneyType	Commission;

	///�ʽ��˻�����
	TTORATstpAccountTypeType	AccountType;

	///�ʽ��˻�����Ͷ���ߴ���
	TTORATstpInvestorIDType	AccountOwner;

	///���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;


};

/// ��ѯͶ���ֲ߳�
struct CTORATstpQryPositionField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///�����˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;


};

/// Ͷ���ֲ߳�
struct CTORATstpPositionField
{
		
	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�г�����
	TTORATstpMarketIDType	MarketID;

	///�ͻ�����
	TTORATstpShareholderIDType	ShareholderID;

	///������
	TTORATstpDateType	TradingDay;

	///���ճֲ�
	TTORATstpVolumeType	HistoryPos;

	///���ճֲֶ���
	TTORATstpVolumeType	HistoryPosFrozen;

	///���������ֲ�
	TTORATstpVolumeType	TodayBSPos;

	///���������ֲֶ���
	TTORATstpVolumeType	TodayBSFrozen;

	///��������ֲ�
	TTORATstpVolumeType	TodayPRPos;

	///��������ֲֶ���
	TTORATstpVolumeType	TodayPRFrozen;

	///�ֲֳɱ�
	TTORATstpMoneyType	TotalPosCost;

	///���ղ�ֺϲ��ֲ�
	TTORATstpVolumeType	TodaySMPos;

	///���ղ�ֺϲ��ֲֶ���
	TTORATstpVolumeType	TodaySMPosFrozen;

	///���ʲ�λ
	TTORATstpVolumeType	MarginBuyPos;

	///��ȯ��λ
	TTORATstpVolumeType	ShortSellPos;

	///�ϴ����(���в���)
	TTORATstpVolumeType	PrePosition;

	///�ɷݿ���
	TTORATstpVolumeType	AvailablePosition;

	///�ɷ����
	TTORATstpVolumeType	CurrentPosition;

	///���¼�
	TTORATstpPriceType	LastPrice;


};

/// ��ѯ�������׷���
struct CTORATstpQryTradingFeeField
{
		
	///���������룬Ŀǰ֧�� SSE(�Ϻ�֤ȯ������)��SZSE(����֤ȯ������)
	TTORATstpExchangeIDType	ExchangeID;


};

/// �������׷���
struct CTORATstpTradingFeeField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///��Ʒ����
	TTORATstpProductIDType	ProductID;

	///֤ȯ������
	TTORATstpSecurityTypeType	SecurityType;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///ҵ�����
	TTORATstpBizClassType	BizClass;

	///ӡ��˰�������ȡ����
	TTORATstpRatioType	StampTaxRatioByAmt;

	///ӡ��˰����ֵ��ȡ����
	TTORATstpRatioType	StampTaxRatioByPar;

	///ӡ��˰������ȡ���
	TTORATstpMoneyType	StampTaxFeePerOrder;

	///ӡ��˰�����ȡ���
	TTORATstpMoneyType	StampTaxFeeMin;

	///ӡ��˰�����ȡ���
	TTORATstpMoneyType	StampTaxFeeMax;

	///�����Ѱ������ȡ����
	TTORATstpRatioType	TransferRatioByAmt;

	///�����Ѱ���ֵ��ȡ����
	TTORATstpRatioType	TransferRatioByPar;

	///�����Ѱ�����ȡ���
	TTORATstpMoneyType	TransferFeePerOrder;

	///�����������ȡ���
	TTORATstpMoneyType	TransferFeeMin;

	///�����������ȡ���
	TTORATstpMoneyType	TransferFeeMax;

	///���ַѰ������ȡ����
	TTORATstpRatioType	HandlingRatioByAmt;

	///���ַѰ���ֵ��ȡ����
	TTORATstpRatioType	HandlingRatioByPar;

	///���ַѰ�����ȡ���
	TTORATstpMoneyType	HandlingFeePerOrder;

	///���ַ������ȡ���
	TTORATstpMoneyType	HandlingFeeMin;

	///���ַ������ȡ���
	TTORATstpMoneyType	HandlingFeeMax;

	///֤�ܷѰ������ȡ����
	TTORATstpRatioType	RegulateRatioByAmt;

	///֤�ܷѰ���ֵ��ȡ����
	TTORATstpRatioType	RegulateRatioByPar;

	///֤�ܷѰ�����ȡ���
	TTORATstpMoneyType	RegulateFeePerOrder;

	///֤�ܷ������ȡ���
	TTORATstpMoneyType	RegulateFeeMin;

	///֤�ܷ������ȡ���
	TTORATstpMoneyType	RegulateFeeMax;

	///�����Ѱ�������ȡ���
	TTORATstpMoneyType	TransferFeeByVolume;

	///���ַѰ�������ȡ���
	TTORATstpMoneyType	HandlingFeeByVolume;

	///����Ѱ������ȡ����
	TTORATstpRatioType	SettlementRatioByAmt;

	///����Ѱ���ֵ��ȡ����
	TTORATstpRatioType	SettlementRatioByPar;

	///����Ѱ�����ȡ���
	TTORATstpMoneyType	SettlementFeePerOrder;

	///����Ѱ�������ȡ���
	TTORATstpMoneyType	SettlementFeeByVolume;

	///����������ȡ���
	TTORATstpMoneyType	SettlementFeeMin;

	///����������ȡ���
	TTORATstpMoneyType	SettlementFeeMax;


};

/// ��ѯӶ�����
struct CTORATstpQryInvestorTradingFeeField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///���������룬Ŀǰ֧�� SSE(�Ϻ�֤ȯ������)��SZSE(����֤ȯ������)
	TTORATstpExchangeIDType	ExchangeID;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;


};

/// Ӷ�����
struct CTORATstpInvestorTradingFeeField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///��Ʒ����
	TTORATstpProductIDType	ProductID;

	///֤ȯ������
	TTORATstpSecurityTypeType	SecurityType;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///ҵ�����
	TTORATstpBizClassType	BizClass;

	///Ӷ������
	TTORATstpBrokerageTypeType	BrokerageType;

	///Ӷ�𰴽����ȡ����
	TTORATstpRatioType	RatioByAmt;

	///Ӷ����ֵ��ȡ����
	TTORATstpRatioType	RatioByPar;

	///Ӷ�𰴱���ȡ���
	TTORATstpMoneyType	FeePerOrder;

	///Ӷ�������ȡ���
	TTORATstpMoneyType	FeeMin;

	///Ӷ�������ȡ���
	TTORATstpMoneyType	FeeMax;

	///Ӷ��������ȡ���
	TTORATstpMoneyType	FeeByVolume;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;


};

/// ��ѯ�¹��깺���
struct CTORATstpQryIPOQuotaField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///���������룬Ŀǰ֧�� SSE(�Ϻ�֤ȯ������)��SZSE(����֤ȯ������)
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///Ŀǰ���ֶδ�ŵ�����֤�������ڵĹɶ����롣
	TTORATstpShareholderIDType	ShareholderID;


};

/// �¹��깺���
struct CTORATstpIPOQuotaField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�г�����
	TTORATstpMarketIDType	MarketID;

	///�ͻ�����
	TTORATstpShareholderIDType	ShareholderID;

	///���깺���
	TTORATstpLongVolumeType	MaxVolume;


};

/// ��ѯ�г�
struct CTORATstpQryMarketField
{
		
	///���������룬Ŀǰ֧�� SSE(�Ϻ�֤ȯ������)��SZSE(����֤ȯ������)
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;


};

/// �г�
struct CTORATstpMarketField
{
		
	///�г�����
	TTORATstpMarketIDType	MarketID;

	///�г�����
	TTORATstpNameType	MarketName;

	///����������
	TTORATstpExchangeIDType	ExchangeID;


};

/// ��ѯ������ϸ�ʽ�
struct CTORATstpQryOrderFundDetailField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///ϵͳ�������
	TTORATstpOrderSysIDType	OrderSysID;

	///Insert Time
	TTORATstpTimeType	InsertTimeStart;

	///Insert Time
	TTORATstpTimeType	InsertTimeEnd;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;


};

/// ������ϸ�ʽ�
struct CTORATstpOrderFundDetailField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///��Լ����
	TTORATstpSecurityIDType	InstrumentID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///������
	TTORATstpDateType	TradingDay;

	///ϵͳ�������
	TTORATstpOrderSysIDType	OrderSysID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ʽ��˻�����
	TTORATstpAccountIDType	AccountID;

	///��ʼ������
	TTORATstpMoneyType	TotalFrozen;

	///�ܷ���
	TTORATstpMoneyType	TotalFee;

	///ӡ��˰
	TTORATstpMoneyType	StampTaxFee;

	///���ַ�
	TTORATstpMoneyType	HandlingFee;

	///������
	TTORATstpMoneyType	TransferFee;

	///֤�ܷ�
	TTORATstpMoneyType	RegulateFee;

	///Ӷ��
	TTORATstpMoneyType	BrokerageFee;

	///�����
	TTORATstpMoneyType	SettlementFee;

	///��ʼ������úϼ�
	TTORATstpMoneyType	TotalFeeFrozen;

	///������ʼ������
	TTORATstpMoneyType	OrderAmount;


};

/// ��ѯ�ʽ�ת����ˮ
struct CTORATstpQryFundTransferDetailField
{
		
	///�ʽ��˻�����
	TTORATstpAccountIDType	AccountID;

	///����
	TTORATstpCurrencyIDType	CurrencyID;

	///ת�Ʒ���
	TTORATstpTransferDirectionType	TransferDirection;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;


};

/// �ʽ�ת����ˮ
struct CTORATstpFundTransferDetailField
{
		
	///ת����ˮ��
	TTORATstpSerialType	FundSerial;

	///������ˮ��
	TTORATstpExternalSerialType	ApplySerial;

	///ǰ�ñ��
	TTORATstpFrontIDType	FrontID;

	///�Ự���
	TTORATstpSessionIDType	SessionID;

	///�ʽ��˻�����
	TTORATstpAccountIDType	AccountID;

	///����
	TTORATstpCurrencyIDType	CurrencyID;

	///ת�Ʒ���
	TTORATstpTransferDirectionType	TransferDirection;

	///�������
	TTORATstpMoneyType	Amount;

	///ת��״̬
	TTORATstpTransferStatusType	TransferStatus;

	///������Դ
	TTORATstpOperateSourceType	OperateSource;

	///������Ա
	TTORATstpUserIDType	OperatorID;

	///��������
	TTORATstpDateType	OperateDate;

	///����ʱ��
	TTORATstpTimeType	OperateTime;

	///״̬��Ϣ
	TTORATstpErrorMsgType	StatusMsg;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;


};

/// ��ѯ�ֲ�ת����ˮ
struct CTORATstpQryPositionTransferDetailField
{
		
	///Ŀǰ���ֶδ�ŵ�����֤�������ڵĹɶ����롣
	TTORATstpShareholderIDType	ShareholderID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///ת�Ʒ���
	TTORATstpTransferDirectionType	TransferDirection;


};

/// �ֲ�ת����ˮ
struct CTORATstpPositionTransferDetailField
{
		
	///��ˮ��
	TTORATstpSerialType	PositionSerial;

	///������ˮ��
	TTORATstpExternalSerialType	ApplySerial;

	///ǰ�ñ��
	TTORATstpFrontIDType	FrontID;

	///�Ự���
	TTORATstpSessionIDType	SessionID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�����˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///�г�����
	TTORATstpMarketIDType	MarketID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///��������
	TTORATstpDateType	TradingDay;

	///ת�Ʒ���
	TTORATstpTransferDirectionType	TransferDirection;

	///ת�Ƴֲ�����
	TTORATstpTransferPositionTypeType	TransferPositionType;

	///ת��״̬
	TTORATstpTransferStatusType	TransferStatus;

	///���ղ�λ����
	TTORATstpVolumeType	HistoryVolume;

	///����������λ����
	TTORATstpVolumeType	TodayBSVolume;

	///���������λ����
	TTORATstpVolumeType	TodayPRVolume;

	///������Ա
	TTORATstpUserIDType	OperatorID;

	///��������
	TTORATstpDateType	OperateDate;

	///����ʱ��
	TTORATstpTimeType	OperateTime;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///״̬��Ϣ
	TTORATstpErrorMsgType	StatusMsg;

	///ί�з�ʽ
	TTORATstpOperwayType	Operway;


};

/// ��ѯͶ������Ѻ�ֲ�
struct CTORATstpQryPledgePositionField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///�����˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;


};

/// Ͷ������Ѻ�ֲ�
struct CTORATstpPledgePositionField
{
		
	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�г�����
	TTORATstpMarketIDType	MarketID;

	///�ͻ�����
	TTORATstpShareholderIDType	ShareholderID;

	///������
	TTORATstpDateType	TradingDay;

	///������Ѻ�ֲ�
	TTORATstpVolumeType	HisPledgePos;

	///������Ѻ�ֲֶ���
	TTORATstpVolumeType	HisPledgePosFrozen;

	///����������Ѻ�ֲ�
	TTORATstpVolumeType	TodayPledgePos;

	///����������Ѻ�ֲֶ���
	TTORATstpVolumeType	TodayPledgePosFrozen;

	///������Ѻ������ȯ����
	TTORATstpVolumeType	PreTotalPledgePos;

	///������Ѻ������ȯ��������
	TTORATstpVolumeType	preAvailablePledgePos;


};

/// ��ѯ֤ȯ��Ѻ��Ϣ
struct CTORATstpQryPledgeInfoField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;


};

/// ֤ȯ��Ѻ��Ϣ
struct CTORATstpPledgeInfoField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�г�����
	TTORATstpMarketIDType	MarketID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///��Ѻ�걨����
	TTORATstpSecurityIDType	PledgeOrderID;

	///��׼ȯ����
	TTORATstpSecurityIDType	StandardBondID;

	///�Ƿ�����
	TTORATstpBoolType	AllowPledgeIn;

	///�Ƿ�ɳ���
	TTORATstpBoolType	AllowPledgeOut;

	///��׼ȯ������/����ֵ
	TTORATstpRatioType	ConversionRate;

	///ÿ�ο���������С���׵�λ
	TTORATstpTradingUnitType	PledgeInTradingUnit;

	///ÿ�ο��Գ������С���׵�λ
	TTORATstpTradingUnitType	PledgeOutTradingUnit;

	///֤ȯ���������������
	TTORATstpVolumeType	PledgeInVolMax;

	///֤ȯ����������С����
	TTORATstpVolumeType	PledgeInVolMin;

	///֤ȯ���Գ�����������
	TTORATstpVolumeType	PledgeOutVolMax;

	///֤ȯ���Գ������С����
	TTORATstpVolumeType	PledgeOutVolMin;

	///������Ѻ������Ѻȯ�Ƿ��ܳ���
	TTORATstpBoolType	IsTodayToPlegeOut;

	///�Ƿ�ɳ���
	TTORATstpBoolType	IsCancelOrder;


};

/// ��ѯ��תծ��Ϣ
struct CTORATstpQryConversionBondInfoField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;


};

/// ��תծ��Ϣ
struct CTORATstpConversionBondInfoField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�г�����
	TTORATstpMarketIDType	MarketID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///ת���걨����
	TTORATstpSecurityIDType	ConvertOrderID;

	///ת�ɼ۸�
	TTORATstpPriceType	ConvertPrice;

	///ÿ�ο���ת����С���׵�λ
	TTORATstpTradingUnitType	ConvertVolUnit;

	///֤ȯ����ת�ɵ��������
	TTORATstpVolumeType	ConvertVolMax;

	///֤ȯ����ת�ɵ���С����
	TTORATstpVolumeType	ConvertVolMin;

	///ת�ɿ�ʼ����
	TTORATstpDateType	BeginDate;

	///ת�ɽ�������
	TTORATstpDateType	EndDate;

	///�Ƿ�ɳ���
	TTORATstpBoolType	IsSupportCancel;


};

/// ��ѯծȯ������Ϣ
struct CTORATstpQryBondPutbackInfoField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;


};

/// ծȯ������Ϣ
struct CTORATstpBondPutbackInfoField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�г�����
	TTORATstpMarketIDType	MarketID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///�����걨����
	TTORATstpSecurityIDType	PutbackOrderID;

	///���ۼ۸�
	TTORATstpPriceType	PutbackPrice;

	///ÿ�ο��Ի�����С���׵�λ
	TTORATstpTradingUnitType	PutbackVolUnit;

	///ծȯ���Ի��۵��������
	TTORATstpVolumeType	PutbackVolMax;

	///ծȯ���Ի��۵���С����
	TTORATstpVolumeType	PutbackVolMin;

	///���ۿ�ʼ����
	TTORATstpDateType	BeginDate;

	///���۽�������
	TTORATstpDateType	EndDate;

	///�Ƿ�ɳ���
	TTORATstpBoolType	IsSupportCancel;


};

/// ��ѯͶ���߱�׼ȯ���
struct CTORATstpQryStandardBondPositionField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///�����˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;


};

/// Ͷ���߱�׼ȯ���
struct CTORATstpStandardBondPositionField
{
		
	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�г�����
	TTORATstpMarketIDType	MarketID;

	///�ͻ�����
	TTORATstpShareholderIDType	ShareholderID;

	///������
	TTORATstpDateType	TradingDay;

	///��׼ȯ���ö��
	TTORATstpPositionVolumeType	AvailablePosition;

	///��׼ȯ���ö�ȶ���
	TTORATstpPositionVolumeType	AvailablePosFrozen;

	///��׼ȯ�������
	TTORATstpPositionVolumeType	TotalPosition;


};

/// ��ѯָ�����׵Ǽ�&��������
struct CTORATstpQryDesignationRegistrationField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ŀǰ���ֶδ�ŵ�����֤�������ڵĹɶ����롣
	TTORATstpShareholderIDType	ShareholderID;

	///ȫϵͳ��Ψһ������š�16λ��1-2λΪ��������ʶ��3-5λΪ���͹�˾���룬6-8λΪ���׵�Ԫ��ʶ������8λΪ��ˮ�š�
	TTORATstpOrderSysIDType	OrderSysID;

	///Insert Time
	TTORATstpTimeType	InsertTimeStart;

	///Insert Time
	TTORATstpTimeType	InsertTimeEnd;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;


};

/// ָ�����׵Ǽ�&��������
struct CTORATstpDesignationRegistrationField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///�û�����
	TTORATstpUserIDType	UserID;

	///��������
	TTORATstpDesignationTypeType	DesignationType;

	///���ر������
	TTORATstpOrderLocalIDType	OrderLocalID;

	///�ͻ�����
	TTORATstpShareholderIDType	ShareholderID;

	///���׵�Ԫ����
	TTORATstpPbuIDType	PbuID;

	///�����ύ״̬
	TTORATstpOrderSubmitStatusType	OrderSubmitStatus;

	///������
	TTORATstpDateType	TradingDay;

	///�������
	TTORATstpOrderSysIDType	OrderSysID;

	///����״̬
	TTORATstpOrderStatusType	OrderStatus;

	///��������
	TTORATstpDateType	InsertDate;

	///ί��ʱ��
	TTORATstpTimeType	InsertTime;

	///״̬��Ϣ
	TTORATstpErrorMsgType	StatusMsg;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ʽ��˻�����
	TTORATstpAccountIDType	AccountID;

	///����
	TTORATstpCurrencyIDType	CurrencyID;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;


};

/// ��֤ת�йܱ�����
struct CTORATstpQryCustodyTransferField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ŀǰ���ֶδ�ŵ�����֤�������ڵĹɶ����롣
	TTORATstpShareholderIDType	ShareholderID;

	///ȫϵͳ��Ψһ������š�16λ��1-2λΪ��������ʶ��3-5λΪ���͹�˾���룬6-8λΪ���׵�Ԫ��ʶ������8λΪ��ˮ�š�
	TTORATstpOrderSysIDType	OrderSysID;

	///Insert Time
	TTORATstpTimeType	InsertTimeStart;

	///Insert Time
	TTORATstpTimeType	InsertTimeEnd;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;


};

/// ת�йܱ�����
struct CTORATstpCustodyTransferField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///�û�����
	TTORATstpUserIDType	UserID;

	///ת�й�����
	TTORATstpCustodyTransferTypeType	CustodyTransferType;

	///���ر������
	TTORATstpOrderLocalIDType	OrderLocalID;

	///�ͻ�����
	TTORATstpShareholderIDType	ShareholderID;

	///���׵�Ԫ����
	TTORATstpPbuIDType	PbuID;

	///�����ύ״̬
	TTORATstpOrderSubmitStatusType	OrderSubmitStatus;

	///������
	TTORATstpDateType	TradingDay;

	///�������
	TTORATstpOrderSysIDType	OrderSysID;

	///����״̬
	TTORATstpOrderStatusType	OrderStatus;

	///��������
	TTORATstpDateType	InsertDate;

	///ί��ʱ��
	TTORATstpTimeType	InsertTime;

	///״̬��Ϣ
	TTORATstpErrorMsgType	StatusMsg;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ʽ��˻�����
	TTORATstpAccountIDType	AccountID;

	///����
	TTORATstpCurrencyIDType	CurrencyID;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;

	///ת�뽻�׵�Ԫ����
	TTORATstpPbuIDType	TransfereePbuID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///���س������,������������ת�йܵ�ԭʼ���
	TTORATstpOrderLocalIDType	OrignalOrderLocalID;

	///��������
	TTORATstpVolumeType	VolumeTotalOriginal;

	///����ʱ��
	TTORATstpTimeType	CancelTime;

	///�������׵�Ԫ����
	TTORATstpPbuIDType	ActiveTraderID;

	///��������Ա
	TTORATstpUserIDType	ActiveUserID;


};

/// ��ѯʵʱ�ر�����
struct CTORATstpQrySpecialMarketDataField
{
		
	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///���������룬Ŀǰ֧�� SSE(�Ϻ�֤ȯ������)��SZSE(����֤ȯ������)
	TTORATstpExchangeIDType	ExchangeID;


};

/// ʵʱ�ر�����
struct CTORATstpSpecialMarketDataField
{
		
	///������
	TTORATstpDateType	TradingDay;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///֤ȯ����
	TTORATstpSecurityNameType	SecurityName;

	///�ƶ�ƽ����
	TTORATstpPriceType	MovingAvgPrice;

	///�ƶ�ƽ���۵Ĳ�������
	TTORATstpVolumeType	MovingAvgPriceSamplingNum;

	///����޸�ʱ��
	TTORATstpTimeType	UpdateTime;

	///����޸ĺ���
	TTORATstpMillisecType	UpdateMillisec;


};

/// ��ѯδ����ծȯ��Ѻ�ع�ί��
struct CTORATstpQryPrematurityRepoOrderField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�������µĽ����г����绦A����B�г�
	TTORATstpMarketIDType	MarketID;

	///�����˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�������
	TTORATstpOrderLocalIDType	OrderLocalID;

	///֤ȯƷ�ִ���
	TTORATstpProductIDType	ProductID;

	///֤ȯ������
	TTORATstpSecurityTypeType	SecurityType;

	///�������
	TTORATstpDirectionType	Direction;

	///�ɽ����
	TTORATstpTradeIDType	TradeID;


};

/// δ����ծȯ��Ѻ�ع�ί��
struct CTORATstpPrematurityRepoOrderField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�г�����
	TTORATstpMarketIDType	MarketID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///�����˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ɽ�����
	TTORATstpDateType	TradeDay;

	///��������
	TTORATstpDateType	ExpireDay;

	///�������
	TTORATstpOrderLocalIDType	OrderLocalID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///֤ȯ����
	TTORATstpSecurityNameType	SecurityName;

	///֤ȯƷ�ִ���
	TTORATstpProductIDType	ProductID;

	///֤ȯ������
	TTORATstpSecurityTypeType	SecurityType;

	///�������
	TTORATstpDirectionType	Direction;

	///�ɽ�����
	TTORATstpVolumeType	VolumeTraded;

	///�ɽ��۸�
	TTORATstpPriceType	Price;

	///�ɽ����
	TTORATstpMoneyType	Turnover;

	///�ɽ����
	TTORATstpTradeIDType	TradeID;

	///����Ӧ�ս��
	TTORATstpMoneyType	RepoTotalMoney;

	///��Ϣ���
	TTORATstpMoneyType	InterestAmount;


};

/// ��ѯ�ɶ�����
struct CTORATstpQryShareholderParamField
{
		
	///�г�����
	TTORATstpMarketIDType	MarketID;

	///�ɶ��˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///��ͨ�����ã�����Ʒ��
	TTORATstpClientIDTypeType	TradingCodeClass;

	///��Ʒ���
	TTORATstpProductIDType	ProductID;

	///֤ȯ���
	TTORATstpSecurityTypeType	SecurityType;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///��������
	TTORATstpParamTypeType	ParamType;

	///����������
	TTORATstpExchangeIDType	ExchangeID;


};

/// �ɶ�����
struct CTORATstpShareholderParamField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�г�����
	TTORATstpMarketIDType	MarketID;

	///�����˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///�˻�����
	TTORATstpClientIDTypeType	TradingCodeClass;

	///֤ȯƷ��
	TTORATstpProductIDType	ProductID;

	///֤ȯ���
	TTORATstpSecurityTypeType	SecurityType;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///�ɶ���������
	TTORATstpParamTypeType	ParamType;

	///�ɶ�����ֵ
	TTORATstpParameterCharValType	ParamValue;


};

/// ��ѯ��Χϵͳ��λ������ˮ
struct CTORATstpQryPeripheryPositionTransferDetailField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///�ֻ�ϵͳ�����˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///��λ��������
	TTORATstpTransferDirectionType	TransferDirection;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;


};

/// ��ѯͶ�������������Ʋ���
struct CTORATstpQryInvestorCondOrderLimitParamField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;


};

/// Ͷ�������������Ʋ���
struct CTORATstpInvestorCondOrderLimitParamField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///�����������
	TTORATstpVolumeType	MaxCondOrderLimitCnt;

	///��ǰ��������
	TTORATstpVolumeType	CurrCondOrderCnt;


};

/// ��ѯ������
struct CTORATstpQryCondOrderField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///���������룬Ŀǰ֧�� SSE(�Ϻ�֤ȯ������)��SZSE(����֤ȯ������)
	TTORATstpExchangeIDType	ExchangeID;

	///�ͻ���ϵͳ�еı�ţ����Ψһ����ѭ�������ƶ��ı������
	TTORATstpShareholderIDType	ShareholderID;

	///�������
	TTORATstpCondOrderIDType	CondOrderID;

	///Insert Time
	TTORATstpTimeType	InsertTimeStart;

	///Insert Time
	TTORATstpTimeType	InsertTimeEnd;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///���ַ���������Ϣ
	TTORATstpBigsInfoType	BInfo;

	///���ַ���������Ϣ
	TTORATstpShortsInfoType	SInfo;

	///���θ�����Ϣ
	TTORATstpIntInfoType	IInfo;


};

/// ������
struct CTORATstpCondOrderField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ɶ��˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///��������
	TTORATstpDirectionType	Direction;

	///�������۸�����
	TTORATstpOrderPriceTypeType	OrderPriceType;

	///��������������
	TTORATstpOrderVolumeTypeType	OrderVolumeType;

	///��Ч������
	TTORATstpTimeConditionType	TimeCondition;

	///�ɽ�������
	TTORATstpVolumeConditionType	VolumeCondition;

	///�����۸�
	TTORATstpPriceType	LimitPrice;

	///��������
	TTORATstpVolumeType	VolumeTotalOriginal;

	///��Ͽ�ƽ��־
	TTORATstpCombOffsetFlagType	CombOffsetFlag;

	///���Ͷ���ױ���־
	TTORATstpCombHedgeFlagType	CombHedgeFlag;

	///������������
	TTORATstpOrderRefType	CondOrderRef;

	///�ʽ��˻�����
	TTORATstpAccountIDType	AccountID;

	///�û�����
	TTORATstpUserIDType	UserID;

	///������
	TTORATstpRequestIDType	RequestID;

	///IP��ַ
	TTORATstpIPAddressType	IPAddress;

	///Mac��ַ
	TTORATstpMacAddressType	MacAddress;

	///�����������
	TTORATstpCondOrderIDType	CondOrderID;

	///�ն���Ϣ
	TTORATstpTerminalInfoType	TerminalInfo;

	///���ַ���������Ϣ
	TTORATstpBigsInfoType	BInfo;

	///���ַ���������Ϣ
	TTORATstpShortsInfoType	SInfo;

	///���θ�����Ϣ
	TTORATstpIntInfoType	IInfo;

	///ί�з�ʽ
	TTORATstpOperwayType	Operway;

	///�������
	TTORATstpCondCheckType	CondCheck;

	///��������
	TTORATstpContingentConditionType	ContingentCondition;

	///������
	TTORATstpPriceType	ConditionPrice;

	///�۸񸡶�tick��
	TTORATstpVolumeType	PriceTicks;

	///������������
	TTORATstpVolumeMultipleType	VolumeMultiple;

	///���ǰ�ñ��
	TTORATstpFrontIDType	RelativeFrontID;

	///��ػỰ���
	TTORATstpSessionIDType	RelativeSessionID;

	///�����������
	TTORATstpRelativeCondParamType	RelativeParam;

	///���Ӵ�������
	TTORATstpContingentConditionType	AppendContingentCondition;

	///����������
	TTORATstpPriceType	AppendConditionPrice;

	///�������ǰ�ñ��
	TTORATstpFrontIDType	AppendRelativeFrontID;

	///������ػỰ���
	TTORATstpSessionIDType	AppendRelativeSessionID;

	///���������������
	TTORATstpRelativeCondParamType	AppendRelativeParam;

	///������
	TTORATstpDateType	TradingDay;

	///������״̬
	TTORATstpCondOrderStatusType	CondOrderStatus;

	///��������
	TTORATstpDateType	InsertDate;

	///ί��ʱ��
	TTORATstpTimeType	InsertTime;

	///����ʱ��
	TTORATstpTimeType	CancelTime;

	///�����û�
	TTORATstpUserIDType	CancelUser;

	///ǰ�ñ��
	TTORATstpFrontIDType	FrontID;

	///�Ự���
	TTORATstpSessionIDType	SessionID;

	///�û��˲�Ʒ��Ϣ
	TTORATstpProductInfoType	UserProductInfo;

	///״̬��Ϣ
	TTORATstpErrorMsgType	StatusMsg;

	///���͹�˾���Ŵ���
	TTORATstpDepartmentIDType	DepartmentID;

	///�ʵ��Կ���ҵ�����
	TTORATstpProperCtrlBusinessTypeType	ProperCtrlBusinessType;

	///�ʵ��Կ���ͨ����ʾ
	TTORATstpProperCtrlPassFlagType	ProperCtrlPassFlag;

	///��������
	TTORATstpDateType	ActiveDate;

	///����ʱ��
	TTORATstpTimeType	ActiveTime;


};

/// ��ѯ����������
struct CTORATstpQryCondOrderActionField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///һ���������ı��
	TTORATstpExchangeIDType	ExchangeID;

	///�ɶ��˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///���ַ���������Ϣ
	TTORATstpBigsInfoType	BInfo;

	///���ַ���������Ϣ
	TTORATstpShortsInfoType	SInfo;

	///���θ�����Ϣ
	TTORATstpIntInfoType	IInfo;


};

/// ����������
struct CTORATstpCondOrderActionField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///������
	TTORATstpRequestIDType	RequestID;

	///��������������
	TTORATstpOrderRefType	CondOrderActionRef;

	///����������
	TTORATstpOrderRefType	CondOrderRef;

	///ǰ�ñ��
	TTORATstpFrontIDType	FrontID;

	///�Ự���
	TTORATstpSessionIDType	SessionID;

	///���������
	TTORATstpCondOrderIDType	CondOrderID;

	///������־
	TTORATstpActionFlagType	ActionFlag;

	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///��Լ����
	TTORATstpSecurityIDType	SecurityID;

	///�û�����
	TTORATstpUserIDType	UserID;

	///�������������
	TTORATstpCondOrderIDType	CancelCondOrderID;

	///IP��ַ
	TTORATstpIPAddressType	IPAddress;

	///MAC��ַ
	TTORATstpMacAddressType	MacAddress;

	///�ն���Ϣ
	TTORATstpTerminalInfoType	TerminalInfo;

	///���ַ���������Ϣ
	TTORATstpBigsInfoType	BInfo;

	///���ַ���������Ϣ
	TTORATstpShortsInfoType	SInfo;

	///���θ�����Ϣ
	TTORATstpIntInfoType	IInfo;

	///ί�з�ʽ
	TTORATstpOperwayType	Operway;

	///Ͷ�ʵ�Ԫ����
	TTORATstpBusinessUnitIDType	BusinessUnitID;

	///�ɶ��˻�����
	TTORATstpShareholderIDType	ShareholderID;

	///��������
	TTORATstpDateType	ActionDate;

	///����ʱ��
	TTORATstpTimeType	ActionTime;


};

/// ��ѯBrokerUserRole
struct CTORATstpQryBrokerUserRoleField
{
		
	///��ɫ���
	TTORATstpRoleIDType	RoleID;


};

/// BrokerUserRole
struct CTORATstpBrokerUserRoleField
{
		
	///��ɫ���
	TTORATstpRoleIDType	RoleID;

	///��ɫ����
	TTORATstpRoleDescriptionType	RoleDescription;

	///����Ȩ�޼���
	TTORATstpFunctionsType	Functions;


};

/// ��ѯBrokerUserRoleAssignment
struct CTORATstpQryBrokerUserRoleAssignmentField
{
		
	///�����û�����
	TTORATstpUserIDType	UserID;


};

/// BrokerUserRoleAssignment
struct CTORATstpBrokerUserRoleAssignmentField
{
		
	///�û�����
	TTORATstpUserIDType	UserID;

	///��ɫ���
	TTORATstpRoleIDType	RoleID;

	///��ɫ����
	TTORATstpRoleDescriptionType	RoleDescription;


};

/// ��ѯ����֪ͨ
struct CTORATstpQryTradingNoticeField
{
		
	///Ͷ���ߴ���
	TTORATstpInvestorIDType	InvestorID;

	///Insert Date
	TTORATstpDateType	InsertDateStart;

	///Insert Date
	TTORATstpDateType	InsertDateEnd;

	///Insert Time
	TTORATstpTimeType	InsertTimeStart;

	///Insert Time
	TTORATstpTimeType	InsertTimeEnd;


};

/// ��ѯ�¹��깺��Ž��
struct CTORATstpQryIPONumberResultField
{
		
	///�깺����
	TTORATstpSecurityIDType	SecurityID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�ɶ�����
	TTORATstpShareholderIDType	ShareholderID;


};

/// �¹��깺��Ž��
struct CTORATstpIPONumberResultField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///����
	TTORATstpDateType	Day;

	///�깺֤ȯ����
	TTORATstpSecurityNameType	SecurityName;

	///�ɶ�����
	TTORATstpShareholderIDType	ShareholderID;

	///֤ȯ������
	TTORATstpSecurityTypeType	SecurityType;

	///��ʼ���
	TTORATstpIPONumberIDType	BeginNumberID;

	///�������
	TTORATstpVolumeType	Volume;


};

/// ��ѯ�¹��깺��ǩ���
struct CTORATstpQryIPOMatchNumberResultField
{
		
	///�깺����
	TTORATstpSecurityIDType	SecurityID;

	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///�ɶ�����
	TTORATstpShareholderIDType	ShareholderID;

	///��ǩ���
	TTORATstpIPONumberIDType	MatchNumberID;


};

/// �¹��깺��ǩ���
struct CTORATstpIPOMatchNumberResultField
{
		
	///����������
	TTORATstpExchangeIDType	ExchangeID;

	///֤ȯ����
	TTORATstpSecurityIDType	SecurityID;

	///����
	TTORATstpDateType	Day;

	///�깺֤ȯ����
	TTORATstpSecurityNameType	SecurityName;

	///�ɶ�����
	TTORATstpShareholderIDType	ShareholderID;

	///֤ȯ������
	TTORATstpSecurityTypeType	SecurityType;

	///��ǩ���
	TTORATstpIPONumberIDType	MatchNumberID;

	///����ǩ��ӵ�е�֤ȯ����
	TTORATstpVolumeType	Volume;

	///�깺�۸�
	TTORATstpPriceType	Price;

	///�깺���
	TTORATstpMoneyType	Amout;


};

#endif