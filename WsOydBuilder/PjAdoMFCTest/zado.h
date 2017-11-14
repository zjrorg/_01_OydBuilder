// zado.h: interface for the zado class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZADO_H__7B3B559C_B1A5_4D85_AAE7_8C5463558795__INCLUDED_)
#define AFX_ZADO_H__7B3B559C_B1A5_4D85_AAE7_8C5463558795__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// 帮助类的引入文件
#pragma warning(disable:4146)
#import "c:/Program Files/Common Files/System/ADO/msado15.dll" \
no_namespace rename("EOF", "EndOfFile")

// 帮助类包含头文件
#include <iostream>
#include <cstdlib>


class zado  
{
public:
	_RecordsetPtr m_pRecordset;//("ADODB.Recordset");
	_ConnectionPtr m_pConnection;//("ADODB.Connection");
public:
	zado();
	virtual ~zado();
	BOOL init();

};

#endif // !defined(AFX_ZADO_H__7B3B559C_B1A5_4D85_AAE7_8C5463558795__INCLUDED_)
