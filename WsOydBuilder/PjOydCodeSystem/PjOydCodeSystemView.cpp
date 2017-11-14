// PjOydCodeSystemView.cpp : implementation of the CPjOydCodeSystemView class
//

#include "stdafx.h"
#include "PjOydCodeSystem.h"

#include "PjOydCodeSystemDoc.h"
#include "PjOydCodeSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPjOydCodeSystemView

IMPLEMENT_DYNCREATE(CPjOydCodeSystemView, CFormView)

BEGIN_MESSAGE_MAP(CPjOydCodeSystemView, CFormView)
	//{{AFX_MSG_MAP(CPjOydCodeSystemView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPjOydCodeSystemView construction/destruction

CPjOydCodeSystemView::CPjOydCodeSystemView()
	: CFormView(CPjOydCodeSystemView::IDD)
{
	//{{AFX_DATA_INIT(CPjOydCodeSystemView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CPjOydCodeSystemView::~CPjOydCodeSystemView()
{
}

void CPjOydCodeSystemView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPjOydCodeSystemView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CPjOydCodeSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CPjOydCodeSystemView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CPjOydCodeSystemView printing

BOOL CPjOydCodeSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPjOydCodeSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPjOydCodeSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPjOydCodeSystemView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CPjOydCodeSystemView diagnostics

#ifdef _DEBUG
void CPjOydCodeSystemView::AssertValid() const
{
	CFormView::AssertValid();
}

void CPjOydCodeSystemView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CPjOydCodeSystemDoc* CPjOydCodeSystemView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPjOydCodeSystemDoc)));
	return (CPjOydCodeSystemDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPjOydCodeSystemView message handlers
