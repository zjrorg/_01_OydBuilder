// DBUtil1.cpp: implementation of the CDBUtil class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PjOydCodeSystem.h"
#include "DBUtil1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const int CDBUtilPara::CDBUTILPARA_TYPE_INT = 1;
const int CDBUtilPara::CDBUTILPARA_TYPE_PCHAR = 2;
const int CDBUtilPara::CDBUTILPARA_TYPE_CSTRING = 3;

CString CDBUtil::m_ConStr = "";

//#include <vector>

CDBUtil::CDBUtil()
{
	::CoInitialize(NULL);
	_RecordsetPtr m_pRecordset("ADODB.Recordset");
	_ConnectionPtr m_pConnection("ADODB.Connection");
	this->m_pRecordset = m_pRecordset;
	this->m_pConnection = m_pConnection;

	// 配置帮助类需要给自己的文件路径赋值，然后给数据库帮助类赋值连接字符串
	CConfig config;
	CConfig::GetValue(CString("PjOydCodeSystem"), CString("constr"), CDBUtil::m_ConStr);
	
}

CDBUtilPara::CDBUtilPara()
{
}

int CDBUtil::GetPCharValue(_variant_t & buffer, char * dest, const char * dbcolname)
{	
	buffer = this->m_pRecordset->GetCollect(dbcolname);
	CString teststr;
	teststr = (LPCTSTR)(_bstr_t)buffer;
			//MessageBox(NULL, teststr, _T("tip"), MB_OK);
	char * str = (LPSTR)(LPCTSTR)teststr;
	strcpy(dest, str);
	return 0;
}

CDBUtilPara::CDBUtilPara(int CDBUTILPARA_TYPE, CString & csval, char * pcharval, int ival, int dblen)
{
	this->m_CDBUTILPARA_TYPE = CDBUTILPARA_TYPE;
	this->m_CStringVal = csval;
	this->m_dblen = dblen;
	this->m_iVal = ival;
	this->m_PCharVal = pcharval;
}



void CDBUtil::Init()
{
	// 创建业务级Connection对象
	m_pConnection.CreateInstance("ADODB.Connection");


}
//(_variant_t & buffer, char * dest, const char * dbcolname)
int CDBUtil::GetGUIDValue(_variant_t & buffer, char * dest, const char * dbcolname)
{
	buffer = m_pRecordset->GetCollect(dbcolname);
	const wchar_t * wstr = _bstr_t(buffer);		
	size_t len1 = wcslen(wstr) + 1;
	size_t converted = 0;
	char *CStr;
	CStr = (char*)malloc(len1*sizeof(char));
	
	wcstombs(CStr, wstr, len1*sizeof(char));	
	memset(dest, 0, 37);
	strncpy(dest, CStr + 1, 36);			
	
	if (CStr)
	{
		free(CStr);
		CStr = NULL;
	}

	return 0;
}

void CDBUtil::InitCommand(const char * constr)
{
	this->m_pCmd.CreateInstance(__uuidof(Command));

	m_pCmd->ActiveConnection = m_pConnection;

		// SQL
	m_pCmd->CommandText = constr;
}

void CDBUtil::Open(const char * constr)
{
		// 设置连接字符串
	_bstr_t strConnect = constr;
	HRESULT hsre = m_pConnection->Open(strConnect, "", "", adModeUnknown);
}

void CDBUtil::Open2()
{
	_bstr_t strConnect = (LPSTR)(LPCSTR)this->m_ConStr;
	HRESULT hsre = m_pConnection->Open(strConnect, "", "", adModeUnknown);
}

void CDBUtil::AddParameter(DataTypeEnum isadInteger, ADO_LONGPTR size, _variant_t val)
{
	_ParameterPtr temp;
	// 创建业务级参数对象
	temp = m_pCmd->CreateParameter(_bstr_t(""), isadInteger, adParamInput, size);	
	temp->Value = val;
	m_pCmd->Parameters->Append(temp);
}

void CDBUtil::AddCStringParameter(CString & val, int dblen)
{
	//_variant_t paraval;
	//_ParameterPtr paraptr;
	//paraptr = m_pCmd->CreateParameter(_bstr_t(""), adVarWChar, adParamInput, dblen);

	char * pparaval = val.GetBuffer(val.GetLength());

	this->CDBUtil::AddPCharParameter(pparaval, dblen);

	val.ReleaseBuffer();
	//paraval.SetString(pparaval);
	//paraptr->Value = paraval;
	//m_pCmd->Parameters->Append(paraptr);
}

void CDBUtil::AddPCharParameter(const char * val, int dblen)
{
	_variant_t paraval;
	_ParameterPtr paraptr;
	paraptr = m_pCmd->CreateParameter(_bstr_t(""), adVarWChar, adParamInput, dblen);
	
	paraval.SetString(val);
	paraptr->Value = paraval;
	m_pCmd->Parameters->Append(paraptr);
}

void CDBUtil::AddIntegerParameter(int val)
{
	_ParameterPtr temp;
	// 创建业务级参数对象
	temp = m_pCmd->CreateParameter(_bstr_t(""), adInteger, adParamInput, 4);
	_variant_t varval((long)val);
	temp->Value = varval;
	m_pCmd->Parameters->Append(temp);
}

void CDBUtil::AddCommonParameter(int CDBUTIL_PARA_TYPE
								 , CString & val1
								 , const char * val2
								 , int val3
								 ,  int dblen)// int *, CString *, char * 
{
	switch (CDBUTIL_PARA_TYPE)
	{
	case CDBUtilPara::CDBUTILPARA_TYPE_INT:
		CDBUtil::AddIntegerParameter(val3);
		break;
	case CDBUtilPara::CDBUTILPARA_TYPE_PCHAR:
		CDBUtil::AddPCharParameter(val2, dblen);
		break;
	case CDBUtilPara::CDBUTILPARA_TYPE_CSTRING:
		CDBUtil::AddCStringParameter(val1, dblen);
		break;
	default:
		break;
	}
}

void CDBUtil::AddCommonParameters(std::vector<CDBUtilPara> & paras)
{
	for(std::vector<CDBUtilPara>::iterator i = paras.begin(); i!=paras.end(); i++)
	{
		//*i is CDBUtilPara
		//(*i)->CDBUtilPara::CDBUTILPARA_TYPE_CSTRING
		CDBUtil::AddCommonParameter((i)->CDBUtilPara::m_CDBUTILPARA_TYPE
			, (i)->CDBUtilPara::m_CStringVal			
			, (i)->CDBUtilPara::m_PCharVal
			, (i)->CDBUtilPara::m_iVal
			, (i)->CDBUtilPara::m_dblen);
	}
}

void CDBUtil::Execute()
{
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordset = m_pCmd->Execute(NULL, NULL, adCmdText);
}

CDBUtil & CDBUtil::ExecuteAuto(const char * constr, const char * cmdstr, std::vector<CDBUtilPara> & paras)
{
	this->CDBUtil::Init();
	/*
		util.Init();
	util.Open("Provider=SQLOLEDB;Server=127.0.0.1;Database=VP_Oydbuilder; uid=sa; pwd=sql2000;");
	util.InitCommand("Update TSYSCategory Set SCName = ? Where SCGUID = ? And SCDataState = 1");
	add
	execute
	*/
	//this->CDBUtil::Open(constr);
	this->CDBUtil::Open2();
	this->CDBUtil::InitCommand(cmdstr);
	this->CDBUtil::AddCommonParameters(paras);
	this->CDBUtil::Execute();

	return *this;
}

CDBUtil & CDBUtil::ExecuteAuto(const char * constr, CString & cmdstr, std::vector<CDBUtilPara> & paras)
{
	return ExecuteAuto(constr, (LPSTR)(LPCSTR)cmdstr, paras);
}

CDBUtil::~CDBUtil()
{
	if (m_pConnection->State)
	{
		m_pConnection->Close();
	}
	::CoUninitialize();
}
