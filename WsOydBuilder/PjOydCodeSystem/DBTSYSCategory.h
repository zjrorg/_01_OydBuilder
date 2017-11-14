// DBTSYSCategory.h: interface for the CDBTSYSCategory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBTSYSCATEGORY_H__6C30D061_60F9_4C15_AD3D_1BC3CA91188B__INCLUDED_)
#define AFX_DBTSYSCATEGORY_H__6C30D061_60F9_4C15_AD3D_1BC3CA91188B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable:4146)
#import "c:/Program Files/Common Files/System/ADO/msado15.dll" \
no_namespace rename("EOF", "EndOfFile")

#define NEWCATE_EXISTS 1
#define NEWCATE_NOTEXISTS 2

#include <iostream>
#include "MTSYSCategory.h"
#include <vector>


//#include <

class CDBTSYSCategory  
{
public:
	static int AddNewCategory(CString & catename);
	static int GetCategories(std::vector<CMTSYSCategory *> & parr, int * len);
	static int DelCategory(CString & scguid, CString * pmsg);
	static int MdfCategory(char * scguid, CString & scname);
};

#endif // !defined(AFX_DBTSYSCATEGORY_H__6C30D061_60F9_4C15_AD3D_1BC3CA91188B__INCLUDED_)
