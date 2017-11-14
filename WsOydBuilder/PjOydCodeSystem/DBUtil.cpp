// DBUtil.cpp: implementation of the CDBUtil class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PjOydCodeSystem.h"
#include "DBUtil.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDBUtil::CDBUtil()
{
	::CoInitialize(NULL);
	m_pRecordset = _RecordsetPtr("ADODB.Recordset");
	m_pConnection = _ConnectionPtr("ADODB.Connection");

	m_pConnection.CreateInstance("ADODB.Connection");
	// 设置连接字符串
	_bstr_t strConnect = "Provider=SQLOLEDB;Server=127.0.0.1;Database=VP_Oydbuilder; uid=sa; pwd=sql2000;";

	// 打开
	HRESULT hsre = m_pConnection->Open(strConnect, "", "", adModeUnknown);

	// 创建业务级cmd对象
	m_Cmd.CreateInstance(__uuidof(Command));

	m_Cmd->ActiveConnection = m_pConnection;

	//
	//m_pRecordset.CreateInstance(__uuidof(Recordset));

}

void CDBUtil::SetSql(CString & sql)
{
	this->m_Sql = sql;
}

void CDBUtil::AddInputParameter(DataTypeEnum isadIntegerornot, int len, _variant_t val)
{
	_ParameterPtr theone;
	theone = this->m_Cmd->CreateParameter(_bstr_t(""), isadIntegerornot, adParamInput, len);
	theone->Value = val;
	//this->m_Parameters.std::vector<_ParameterPtr>::push_back(theone);
	this->m_Cmd->Parameters->Append(theone);

}

void CDBUtil::Execute()
{
	this->m_pRecordset.CreateInstance(__uuidof(Recordset));
	this->m_pRecordset = this->m_Cmd->Execute(NULL, NULL, adCmdText);
}

CDBUtil::~CDBUtil()
{
	if (m_pConnection->State)
	{
		m_pConnection->Close();
	}
	::CoUninitialize();
}