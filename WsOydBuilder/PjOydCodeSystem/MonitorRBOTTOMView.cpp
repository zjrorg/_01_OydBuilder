// MonitorRBOTTOMView.cpp : implementation file
//

#include "stdafx.h"
#include "PjOydCodeSystem.h"
#include "MonitorRBOTTOMView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMonitorRBOTTOMView

IMPLEMENT_DYNCREATE(CMonitorRBOTTOMView, CFormView)

CMonitorRBOTTOMView::CMonitorRBOTTOMView()
	: CFormView(CMonitorRBOTTOMView::IDD)
{
	//{{AFX_DATA_INIT(CMonitorRBOTTOMView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CMonitorRBOTTOMView::~CMonitorRBOTTOMView()
{
}

void CMonitorRBOTTOMView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMonitorRBOTTOMView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMonitorRBOTTOMView, CFormView)
	//{{AFX_MSG_MAP(CMonitorRBOTTOMView)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMonitorRBOTTOMView diagnostics

#ifdef _DEBUG
void CMonitorRBOTTOMView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMonitorRBOTTOMView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMonitorRBOTTOMView message handlers

void CMonitorRBOTTOMView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
		  // 同步CScrollView的大小
	  CFormView::OnSize(nType, cx, cy);
      CRect rect;
      GetClientRect(&rect); // 获取当前客户区view大小

      CSize size;
      size.cx = rect.right - rect.left;
      size.cy = rect.bottom - rect.top;
      SetScrollSizes(MM_HIMETRIC, size); // 将CScrollView的大小设置为当前客户区大小
	
}
