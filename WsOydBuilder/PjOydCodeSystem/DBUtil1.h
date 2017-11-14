// DBUtil1.h: interface for the CDBUtil class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBUTIL1_H__95DA5246_2C37_4956_95C5_D24B0E9DFE17__INCLUDED_)
#define AFX_DBUTIL1_H__95DA5246_2C37_4956_95C5_D24B0E9DFE17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable:4146)
#import "c:/Program Files/Common Files/System/ADO/msado15.dll" \
no_namespace rename("EOF", "EndOfFile")

#include <vector>
#include "Config.h"

class CDBUtilPara;

class CDBUtil  
{
public:
	CDBUtil();
	virtual ~CDBUtil();

	_RecordsetPtr m_pRecordset;
	_ConnectionPtr m_pConnection;
	_CommandPtr m_pCmd;

	//void InitAndOpen();
	void AddParameter(DataTypeEnum adInteger, ADO_LONGPTR size, _variant_t val);
	void AddIntegerParameter(int val);
	void AddCStringParameter(CString & val, int dblen);
	void AddPCharParameter(const char * val, int dblen);
	void AddCommonParameter(int CDBUTIL_PARA_TYPE, CString & val1, const char * val2, int val3,  int dblen);// int *, CString *, char * 
	void AddCommonParameters(std::vector<CDBUtilPara> & paras); // 每个元素自己管理内存周期。
	void Init();
	void InitCommand(const char * constr);
	void Execute();
	CDBUtil & ExecuteAuto(const char * constr, const char * cmdstr, std::vector<CDBUtilPara> & paras);
	CDBUtil & ExecuteAuto(const char * constr, CString & cmdstr, std::vector<CDBUtilPara> & paras);
	void Open(const char * constr);
	void Open2();

	int GetPCharValue(_variant_t & buffer, char * dest, const char * dbcolname);
	int GetGUIDValue(_variant_t & buffer, char * dest, const char * dbcolname);

	static CString m_ConStr;
};

class CDBUtilPara
{
public:
	CDBUtilPara();
	CDBUtilPara(int CDBUTILPARA_TYPE, CString & csval, char * pcharval, int ival, int dblen);
	CString m_CStringVal;
	char *  m_PCharVal;
	int		m_iVal;
	int		m_dblen;
	int		m_CDBUTILPARA_TYPE;
	static const int CDBUTILPARA_TYPE_INT;//1
	static const int CDBUTILPARA_TYPE_PCHAR;//2
	static const int CDBUTILPARA_TYPE_CSTRING;//3


};

#endif // !defined(AFX_DBUTIL1_H__95DA5246_2C37_4956_95C5_D24B0E9DFE17__INCLUDED_)
