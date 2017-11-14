// PjOydCodeSystemDoc.h : interface of the CPjOydCodeSystemDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PJOYDCODESYSTEMDOC_H__B9ACDF18_D236_41BF_B6EC_56154DE326BA__INCLUDED_)
#define AFX_PJOYDCODESYSTEMDOC_H__B9ACDF18_D236_41BF_B6EC_56154DE326BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPjOydCodeSystemDoc : public CDocument
{
protected: // create from serialization only
	CPjOydCodeSystemDoc();
	DECLARE_DYNCREATE(CPjOydCodeSystemDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPjOydCodeSystemDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPjOydCodeSystemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPjOydCodeSystemDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PJOYDCODESYSTEMDOC_H__B9ACDF18_D236_41BF_B6EC_56154DE326BA__INCLUDED_)
