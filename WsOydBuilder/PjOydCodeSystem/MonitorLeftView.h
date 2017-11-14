#if !defined(AFX_MONITORLEFTVIEW_H__736CE05E_C5DF_49D7_8CB2_311DE53633CF__INCLUDED_)
#define AFX_MONITORLEFTVIEW_H__736CE05E_C5DF_49D7_8CB2_311DE53633CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MonitorLeftView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMonitorLeftView form view

#define WM_UPDTREE_MESSAGE (WM_USER+101) // 自定义消息

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "LeftTab1.h"
#include "LeftTab2.h"
#include "LeftTab3.h"

class CMonitorLeftView : public CFormView
{
protected:
	CMonitorLeftView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMonitorLeftView)

// Form Data
public:
	//{{AFX_DATA(CMonitorLeftView)
	enum { IDD = IDD_MONITORLEFT_FORM };
	CTabCtrl	m_TabCtrl;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	CLeftTab1 m_Tab1;
	CLeftTab2 m_Tab2;
	CLeftTab3 m_Tab3;


	LRESULT OnUpdTree(WPARAM wParam, LPARAM lParam);
	void GetSelCode(CMTSYSCodes * codem);
	int OnDel();
	// always return 0
	int OnMdf();
	int OnNewcodetab();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMonitorLeftView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMonitorLeftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMonitorLeftView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSelChangeTab(NMHDR *pNMHDR,LRESULT *pResult);

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONITORLEFTVIEW_H__736CE05E_C5DF_49D7_8CB2_311DE53633CF__INCLUDED_)
