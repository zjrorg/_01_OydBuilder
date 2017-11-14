#if !defined(AFX_MONITORRBOTTOMVIEW_H__B067787D_8B0F_4ABF_99DA_D36983BE143A__INCLUDED_)
#define AFX_MONITORRBOTTOMVIEW_H__B067787D_8B0F_4ABF_99DA_D36983BE143A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MonitorRBOTTOMView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMonitorRBOTTOMView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CMonitorRBOTTOMView : public CFormView
{
protected:
	CMonitorRBOTTOMView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMonitorRBOTTOMView)

// Form Data
public:
	//{{AFX_DATA(CMonitorRBOTTOMView)
	enum { IDD = IDD_MONITORRBOTTOM_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMonitorRBOTTOMView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMonitorRBOTTOMView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMonitorRBOTTOMView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONITORRBOTTOMVIEW_H__B067787D_8B0F_4ABF_99DA_D36983BE143A__INCLUDED_)
