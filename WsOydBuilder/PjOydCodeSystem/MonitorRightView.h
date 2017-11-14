#if !defined(AFX_MONITORRIGHTVIEW_H__2312D278_4940_4D43_9729_F1A0A79A7DAE__INCLUDED_)
#define AFX_MONITORRIGHTVIEW_H__2312D278_4940_4D43_9729_F1A0A79A7DAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MonitorRightView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMonitorRightView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CMonitorRightView : public CFormView
{
protected:
	CMonitorRightView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMonitorRightView)

// Form Data
public:
	//{{AFX_DATA(CMonitorRightView)
	enum { IDD = IDD_MONITORRIGHT_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMonitorRightView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMonitorRightView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMonitorRightView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONITORRIGHTVIEW_H__2312D278_4940_4D43_9729_F1A0A79A7DAE__INCLUDED_)
