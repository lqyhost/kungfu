/////////////////////////////////////////////////////////////////////////
///@company �Ϻ�̩����Ϣ�Ƽ����޹�˾
///@file TORATstpMdApi.h
///@brief �����˿ͻ��˽ӿ�
///@history 
/////////////////////////////////////////////////////////////////////////

#if !defined(_TORA_TSTPMDAPI_H)
#define _TORA_TSTPMDAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TORATstpUserApiStruct.h"


#ifdef MD_API_EXPORT
#ifdef WINDOWS
#define MD_API_DLL_EXPORT __declspec(dllexport)
#else
#define MD_API_DLL_EXPORT __attribute__ ((visibility("default")))
#endif
#else
#define MD_API_DLL_EXPORT 
#endif

class CTORATstpMdSpi
{
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected(){};
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///        -3 �����ѶϿ�
	///        -4 �����ʧ��
	///        -5 ����дʧ��
	///        -6 ����������
	///        -7 ����Ŵ���
	///        -8 �������������
	///        -9 ����ı���
	virtual void OnFrontDisconnected(int nReason){};
			
	///����Ӧ��
	virtual void OnRspError(CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��¼������Ӧ
	virtual void OnRspUserLogin(CTORATstpRspUserLoginField *pRspUserLogin, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CTORATstpUserLogoutField *pUserLogout, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspSubMarketData(CTORATstpSpecificSecurityField *pSpecificSecurity, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ȡ����������Ӧ��
	virtual void OnRspUnSubMarketData(CTORATstpSpecificSecurityField *pSpecificSecurity, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ض�����Ӧ��
	virtual void OnRspSubSpecialMarketData(CTORATstpSpecificSecurityField *pSpecificSecurity, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ȡ�������ض�����Ӧ��
	virtual void OnRspUnSubSpecialMarketData(CTORATstpSpecificSecurityField *pSpecificSecurity, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ʽ���������Ӧ��
	virtual void OnRspSubFundsFlowMarketData(CTORATstpSpecificSecurityField *pSpecificSecurity, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ȡ�������ʽ���������Ӧ��
	virtual void OnRspUnSubFundsFlowMarketData(CTORATstpSpecificSecurityField *pSpecificSecurity, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CTORATstpMarketDataField *pDepthMarketData) {};

	///�������֪ͨ
	virtual void OnRtnSpecialMarketData(CTORATstpSpecialMarketDataField *pSpecialMarketData) {};

	///�۸񲨶��쳣����֪ͨ
	virtual void OnRtnEffectPriceMarketData(CTORATstpEffectPriceMarketDataField *pEffectPriceMarketData) {};

	///���������쳣����֪ͨ
	virtual void OnRtnEffectVolumeMarketData(CTORATstpEffectVolumeMarketDataField *pEffectVolumeMarketData) {};

	///�ʽ���������֪ͨ
	virtual void OnRtnFundsFlowMarketData(CTORATstpFundsFlowMarketDataField *pFundsFlowMarketData) {};
};

class MD_API_DLL_EXPORT CTORATstpMdApi
{
public:
	///����MdApi
	///@return ��������MdApi
	static CTORATstpMdApi *CreateTstpMdApi();
	
	///��ȡAPI�汾��
	///@return �汾��
	static const char* GetApiVersion();
	
	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;
	
	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual void Init() = 0;
	
	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	virtual int Join() = 0;

	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	virtual void RegisterFront(char *pszFrontAddress) = 0;

	///ע�����ַ����������ַ
	///@param pszNsAddress�����ַ����������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
	///@remark RegisterNameServer������RegisterFront
	virtual void RegisterNameServer(char *pszNsAddress) = 0;

	///ע��������������������ַ
	///@param pszNsAddress��������������������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:15001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����15001������������˿ںš�
	virtual void RegisterDeriveServer(char *pszDeriveAddress) = 0;

	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CTORATstpMdSpi *pSpi) = 0;
	
	///�������顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int SubscribeMarketData(char **ppSecurityID, int nCount, TTORATstpExchangeIDType ExchageID) = 0;

	///�˶����顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int UnSubscribeMarketData(char **ppSecurityID, int nCount, TTORATstpExchangeIDType ExchageID) = 0;

	///�����ض����顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int SubscribeSpecialMarketData(char **ppSecurityID, int nCount, TTORATstpExchangeIDType ExchageID) = 0;

	///�˶��ض����顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int UnSubscribeSpecialMarketData(char **ppSecurityID, int nCount, TTORATstpExchangeIDType ExchageID) = 0;

	///�����ʽ��������顣
	///@param ppInstrumentID ��ԼID
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark
	virtual int SubscribeFundsFlowMarketData(char *ppInstrumentID[], int nCount, TTORATstpExchangeIDType ExchageID) = 0;

	///�˶��ʽ��������顣
	///@param ppInstrumentID ��ԼID
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark
	virtual int UnSubscribeFundsFlowMarketData(char *ppInstrumentID[], int nCount, TTORATstpExchangeIDType ExchageID) = 0;

	///�û���¼����
	virtual int ReqUserLogin(CTORATstpReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;
	

	///�ǳ�����
	virtual int ReqUserLogout(CTORATstpUserLogoutField *pUserLogout, int nRequestID) = 0;
protected:
	~CTORATstpMdApi(){};
};
#endif
