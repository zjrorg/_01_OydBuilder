// PjOydCodeSystem.h : main header file for the PJOYDCODESYSTEM application
//

#if !defined(AFX_PJOYDCODESYSTEM_H__B53C30B9_1D0B_41F4_9893_C27AF5E91D39__INCLUDED_)
#define AFX_PJOYDCODESYSTEM_H__B53C30B9_1D0B_41F4_9893_C27AF5E91D39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPjOydCodeSystemApp:
// See PjOydCodeSystem.cpp for the implementation of this class
//

class CPjOydCodeSystemApp : public CWinApp
{
public:
	CPjOydCodeSystemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPjOydCodeSystemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPjOydCodeSystemApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PJOYDCODESYSTEM_H__B53C30B9_1D0B_41F4_9893_C27AF5E91D39__INCLUDED_)
