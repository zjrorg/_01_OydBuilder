#if !defined(AFX_LEFTTAB1_H__6649159B_99B8_4520_862C_9A52CB9D0465__INCLUDED_)
#define AFX_LEFTTAB1_H__6649159B_99B8_4520_862C_9A52CB9D0465__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftTab1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeftTab1 dialog
#define WM_UPDTREE_MESSAGE (WM_USER+101) // 自定义消息
#pragma warning(disable : 4786) // 使用stl类名过长

#include "DialogNewCateGory.h"
#include "DialogNewCodeTab.h"
#include "DBTSYSCategory.h"
#include "Config.h"
#include <map>

//typedef std::map<DWORD, BOOL> MAP_DWORD_BOOL

class CLeftTab1 : public CDialog
{
// Construction
public:
	CDialogNewCodeTab * m_CodeTabDlg;
	CDialogNewCateGory * m_MdfDlg;


	//std::map<DWORD, BOOL> m_HeapDatas;
	std::map<DWORD, BOOL> m_HeapDatas;
	
	CLeftTab1(CWnd* pParent = NULL);   // standard constructor
	virtual ~CLeftTab1();
	void GetSelCode(CMTSYSCodes * codem);
	

// Dialog Data
	//{{AFX_DATA(CLeftTab1)
	enum { IDD = IDD_LEFTTAB1 };
	CTreeCtrl	m_TCMain;
	//}}AFX_DATA
	int LoadTreeData();
	int OnDel();
	int OnMdf();
	int Newcodetab();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftTab1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL



// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLeftTab1)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg void OnClickTreemain(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg LRESULT OnUpdTree(WPARAM wParam, LPARAM lParam);
	afx_msg void OnRclickTreemain(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkTreemain(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTTAB1_H__6649159B_99B8_4520_862C_9A52CB9D0465__INCLUDED_)
