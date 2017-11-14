// PjAdoMFCTest.h : main header file for the PJADOMFCTEST application
//

#if !defined(AFX_PJADOMFCTEST_H__327D376A_D5BC_4510_B874_CE20BF8DE9DC__INCLUDED_)
#define AFX_PJADOMFCTEST_H__327D376A_D5BC_4510_B874_CE20BF8DE9DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


#pragma warning(disable:4146)
#import "c:/Program Files/Common Files/System/ADO/msado15.dll" \
no_namespace rename("EOF", "EndOfFile")

#include <iostream>
#include <cstdlib>

using namespace ::std;

/////////////////////////////////////////////////////////////////////////////
// CPjAdoMFCTestApp:
// See PjAdoMFCTest.cpp for the implementation of this class
//

class CPjAdoMFCTestApp : public CWinApp
{
public:
	CPjAdoMFCTestApp();
	void adotest();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPjAdoMFCTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPjAdoMFCTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PJADOMFCTEST_H__327D376A_D5BC_4510_B874_CE20BF8DE9DC__INCLUDED_)
