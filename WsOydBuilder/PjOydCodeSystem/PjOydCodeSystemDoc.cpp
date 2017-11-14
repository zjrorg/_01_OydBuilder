// PjOydCodeSystemDoc.cpp : implementation of the CPjOydCodeSystemDoc class
//

#include "stdafx.h"
#include "PjOydCodeSystem.h"

#include "PjOydCodeSystemDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPjOydCodeSystemDoc

IMPLEMENT_DYNCREATE(CPjOydCodeSystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CPjOydCodeSystemDoc, CDocument)
	//{{AFX_MSG_MAP(CPjOydCodeSystemDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPjOydCodeSystemDoc construction/destruction

CPjOydCodeSystemDoc::CPjOydCodeSystemDoc()
{
	// TODO: add one-time construction code here

}

CPjOydCodeSystemDoc::~CPjOydCodeSystemDoc()
{
}

BOOL CPjOydCodeSystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPjOydCodeSystemDoc serialization

void CPjOydCodeSystemDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPjOydCodeSystemDoc diagnostics

#ifdef _DEBUG
void CPjOydCodeSystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPjOydCodeSystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPjOydCodeSystemDoc commands
