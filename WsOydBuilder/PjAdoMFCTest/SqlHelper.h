// SqlHelper.h: interface for the SqlHelper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SQLHELPER_H__E0DFBE08_048A_490D_9812_ABC4D51556A8__INCLUDED_)
#define AFX_SQLHELPER_H__E0DFBE08_048A_490D_9812_ABC4D51556A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// 使用ado必须引入
#pragma warning(disable:4146)
#import "c:/Program Files/Common Files/System/ADO/msado15.dll" \
no_namespace rename("EOF", "EndOfFile")

#include <iostream>
#include <cstdlib>
// //使用ado必须引入

class SqlHelper  
{
public:
	_RecordsetPtr m_pRecordset;//("ADODB.Recordset");
	_ConnectionPtr m_pConnection;//("ADODB.Connection");
	_bstr_t m_strConnect;
	static SqlHelper * Create();
	BOOL open();
private:
	SqlHelper();
	static SqlHelper * m_SqlHelper;
};

#endif // !defined(AFX_SQLHELPER_H__E0DFBE08_048A_490D_9812_ABC4D51556A8__INCLUDED_)
