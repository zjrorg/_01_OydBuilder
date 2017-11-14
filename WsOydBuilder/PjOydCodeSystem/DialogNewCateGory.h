#if !defined(AFX_DIALOGNEWCATEGORY_H__F050F63A_9CA5_4914_B615_409EFFAA6A8D__INCLUDED_)
#define AFX_DIALOGNEWCATEGORY_H__F050F63A_9CA5_4914_B615_409EFFAA6A8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogNewCateGory.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogNewCateGory dialog

#include "DBTSYSCategory.h"

class CDialogNewCateGory : public CDialog
{
// Construction
public:
	CDialogNewCateGory(BOOL isModify = FALSE, CWnd* pParent = NULL);   // standard constructor

	BOOL m_IsModify;
	char m_ModifySCGUID[37];
	char m_ModifySCName[51];

// Dialog Data
	//{{AFX_DATA(CDialogNewCateGory)
	enum { IDD = IDD_NEWCATEGORY };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogNewCateGory)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogNewCateGory)
	afx_msg void OnOK();
	afx_msg void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGNEWCATEGORY_H__F050F63A_9CA5_4914_B615_409EFFAA6A8D__INCLUDED_)
