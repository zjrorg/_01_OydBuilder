// zado.cpp: implementation of the zado class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PjAdoMFCTest.h"
#include "zado.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

zado::zado()
:m_pRecordset("ADODB.Recordset"), m_pConnection("ADODB.Connection")
{

}

zado::~zado()
{

}

BOOL zado::init()
{
		BOOL retsuc = FALSE;

		::CoInitialize(NULL);

		try
		{
			// ����Connection����  
			this->m_pConnection.CreateInstance("ADODB.Connection");

			// ���������ַ�����������BSTR�ͻ���_bstr_t����  
			_bstr_t strConnect = "Provider=SQLOLEDB;Server=127.0.0.1;Database=VP_Oydbuilder; uid=sa; pwd=sql2000;";


		}
		catch (const std::exception& e)
		{
			retsuc = FALSE;
		}



		retsuc = TRUE;
		return retsuc;
}
