// DBUtil.h: interface for the CDBUtil class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBUTIL_H__67F000EA_B8D9_435A_B8DD_EE6868FDB3F5__INCLUDED_)
#define AFX_DBUTIL_H__67F000EA_B8D9_435A_B8DD_EE6868FDB3F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable:4146)
#import "c:/Program Files/Common Files/System/ADO/msado15.dll" \
no_namespace rename("EOF", "EndOfFile")

#include <vector>

class CDBUtil  
{
public:
	CDBUtil();
	virtual ~CDBUtil();



	_RecordsetPtr m_pRecordset;
	_ConnectionPtr m_pConnection;
	_CommandPtr m_Cmd;
	CString m_Sql;
	//std::vector<_ParameterPtr> m_Parameters;

	void SetSql(CString & sql);
	void AddInputParameter(DataTypeEnum isadIntegerornot, int len, _variant_t val);
	void Execute();

};

#endif // !defined(AFX_DBUTIL_H__67F000EA_B8D9_435A_B8DD_EE6868FDB3F5__INCLUDED_)
