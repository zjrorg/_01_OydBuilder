// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__C7E4E09C_46E9_49CF_A25A_04FD22A09412__INCLUDED_)
#define AFX_MAINFRM_H__C7E4E09C_46E9_49CF_A25A_04FD22A09412__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MySplitter.h"
#include "MonitorLeftView.h"
#include "MonitorRightView.h"
#include "MonitorRTopView.h"
#include "MonitorRBOTTOMView.h"
#include "LeftTab1.h"
#include "LeftTab2.h"
#include "LeftTab3.h"
#include "DialogNewCateGory.h"

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);

// Attributes
public:
	CMySplitter m_SplitterV;
	CMySplitter m_SplitterH;
	//CLeftTab1 m_Tab1;
	//CLeftTab2 m_Tab2;
	//CLeftTab3 m_Tab3;
	CDialogNewCateGory m_DlgNewCate;

	CBitmap m_IconIDT_New;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	CMonitorLeftView * m_LeftView;
	CMonitorRTopView * m_RTopView;
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNew();
	afx_msg void OnDel();
	afx_msg void OnMdf();
	afx_msg void OnNewcodetab();
	afx_msg void OnNewcode();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__C7E4E09C_46E9_49CF_A25A_04FD22A09412__INCLUDED_)
