// PjOydCodeSystemView.h : interface of the CPjOydCodeSystemView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PJOYDCODESYSTEMVIEW_H__762B8119_DB8C_49E9_B268_EBF83E2B2C9D__INCLUDED_)
#define AFX_PJOYDCODESYSTEMVIEW_H__762B8119_DB8C_49E9_B268_EBF83E2B2C9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPjOydCodeSystemView : public CFormView
{
protected: // create from serialization only
	CPjOydCodeSystemView();
	DECLARE_DYNCREATE(CPjOydCodeSystemView)

public:
	//{{AFX_DATA(CPjOydCodeSystemView)
	enum{ IDD = IDD_PJOYDCODESYSTEM_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CPjOydCodeSystemDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPjOydCodeSystemView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPjOydCodeSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPjOydCodeSystemView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PjOydCodeSystemView.cpp
inline CPjOydCodeSystemDoc* CPjOydCodeSystemView::GetDocument()
   { return (CPjOydCodeSystemDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PJOYDCODESYSTEMVIEW_H__762B8119_DB8C_49E9_B268_EBF83E2B2C9D__INCLUDED_)
