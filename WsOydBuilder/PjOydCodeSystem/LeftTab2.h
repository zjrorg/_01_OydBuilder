#if !defined(AFX_LEFTTAB2_H__55356CCA_0C7C_4C51_8FDE_38E03CDED199__INCLUDED_)
#define AFX_LEFTTAB2_H__55356CCA_0C7C_4C51_8FDE_38E03CDED199__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftTab2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeftTab2 dialog

class CLeftTab2 : public CDialog
{
// Construction
public:
	CLeftTab2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLeftTab2)
	enum { IDD = IDD_LEFTTAB2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftTab2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLeftTab2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTTAB2_H__55356CCA_0C7C_4C51_8FDE_38E03CDED199__INCLUDED_)
