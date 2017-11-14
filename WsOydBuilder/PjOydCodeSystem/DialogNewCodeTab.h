#if !defined(AFX_DIALOGNEWCODETAB_H__41AF7158_714A_4B07_96AB_F1125E343718__INCLUDED_)
#define AFX_DIALOGNEWCODETAB_H__41AF7158_714A_4B07_96AB_F1125E343718__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogNewCodeTab.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogNewCodeTab dialog

#include "DBTSYSCodes.h"

class CDialogNewCodeTab : public CDialog
{
// Construction
public:
	CString m_SelSCGUID;

	CDialogNewCodeTab(CWnd* pParent = NULL);   // standard constructor
	void SetSelSCGUID(CString & selscguid);

// Dialog Data
	//{{AFX_DATA(CDialogNewCodeTab)
	enum { IDD = IDD_NEWCODETAB };
	CEdit	m_TxtNewEngName;
	CEdit	m_TxtNewChnName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogNewCodeTab)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogNewCodeTab)
	afx_msg void OnOK();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGNEWCODETAB_H__41AF7158_714A_4B07_96AB_F1125E343718__INCLUDED_)
