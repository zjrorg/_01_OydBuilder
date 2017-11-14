// PjAdoMFCTestDlg.h : header file
//

#if !defined(AFX_PJADOMFCTESTDLG_H__76FC483A_3813_4FEB_B2D2_64DF5729A1A8__INCLUDED_)
#define AFX_PJADOMFCTESTDLG_H__76FC483A_3813_4FEB_B2D2_64DF5729A1A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPjAdoMFCTestDlg dialog

class CPjAdoMFCTestDlg : public CDialog
{
// Construction
public:
	CPjAdoMFCTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPjAdoMFCTestDlg)
	enum { IDD = IDD_PJADOMFCTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPjAdoMFCTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPjAdoMFCTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PJADOMFCTESTDLG_H__76FC483A_3813_4FEB_B2D2_64DF5729A1A8__INCLUDED_)
