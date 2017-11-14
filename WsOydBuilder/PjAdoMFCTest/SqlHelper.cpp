// SqlHelper.cpp: implementation of the SqlHelper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PjAdoMFCTest.h"
#include "SqlHelper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


SqlHelper * SqlHelper::m_SqlHelper = NULL;

SqlHelper::SqlHelper()
:m_pRecordset("ADODB.Recordset"), m_pConnection("ADODB.Connection")
{
	
}

BOOL SqlHelper::open()
{
	BOOL ret = FALSE;

	try
	{
		// 初始化资源
		// 初始化OLE/COM库环境 ，为访问ADO接口做准备
		::CoInitialize(NULL);

		// 创建Connection对象  
		m_pConnection.CreateInstance("ADODB.Connection");

		// 连接字符串
		m_strConnect = "Provider=SQLOLEDB;Server=127.0.0.1;Database=VP_Oydbuilder; uid=sa; pwd=sql2000;";
	}
	catch (const std::exception & e)
	{
	}



	return ret;
}

SqlHelper * SqlHelper::Create()
{
	if (m_SqlHelper == NULL)
	{
		m_SqlHelper = new SqlHelper();
	}

	return m_SqlHelper;
}