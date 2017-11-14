#if !defined(AFX_MONITORRTOPVIEW_H__E9C59346_906C_4C8B_A4A4_130DF9964FBF__INCLUDED_)
#define AFX_MONITORRTOPVIEW_H__E9C59346_906C_4C8B_A4A4_130DF9964FBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MonitorRTopView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMonitorRTopView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "MTSYSCodes.h"

class CMonitorRTopView : public CFormView
{
protected:
	CMonitorRTopView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMonitorRTopView)

// Form Data
public:
	//{{AFX_DATA(CMonitorRTopView)
	enum { IDD = IDD_MONITORRTOP_FORM };
	//CButton	m_BtnTest;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	void NewCode(const CMTSYSCodes & codesel);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMonitorRTopView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMonitorRTopView();
	virtual void OnInitialUpdate();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMonitorRTopView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONITORRTOPVIEW_H__E9C59346_906C_4C8B_A4A4_130DF9964FBF__INCLUDED_)
