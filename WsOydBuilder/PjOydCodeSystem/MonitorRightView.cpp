// MonitorRightView.cpp : implementation file
//

#include "stdafx.h"
#include "PjOydCodeSystem.h"
#include "MonitorRightView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMonitorRightView

IMPLEMENT_DYNCREATE(CMonitorRightView, CFormView)

CMonitorRightView::CMonitorRightView()
	: CFormView(CMonitorRightView::IDD)
{
	//{{AFX_DATA_INIT(CMonitorRightView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CMonitorRightView::~CMonitorRightView()
{
}

void CMonitorRightView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMonitorRightView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMonitorRightView, CFormView)
	//{{AFX_MSG_MAP(CMonitorRightView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMonitorRightView diagnostics

#ifdef _DEBUG
void CMonitorRightView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMonitorRightView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMonitorRightView message handlers
