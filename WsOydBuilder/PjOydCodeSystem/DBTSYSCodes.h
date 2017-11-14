// DBTSYSCodes.h: interface for the CDBTSYSCodes class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBTSYSCODES_H__7B623535_D5CB_46BB_A178_6456A9326EFE__INCLUDED_)
#define AFX_DBTSYSCODES_H__7B623535_D5CB_46BB_A178_6456A9326EFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>

#pragma warning(disable:4146)
#import "c:/Program Files/Common Files/System/ADO/msado15.dll" \
no_namespace rename("EOF", "EndOfFile")

#include "DBUtil1.h"
#include "MTSYSCodes.h"

class CDBTSYSCodes  
{
public:
	static int AddNewCode(CString & eng, CString & chn, CString & selscguid);
	static int GetCodes(std::vector<CMTSYSCodes *> & parr, CString & scguidsel, int * len);

};

#endif // !defined(AFX_DBTSYSCODES_H__7B623535_D5CB_46BB_A178_6456A9326EFE__INCLUDED_)
