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
		  // ͬ��CScrollView�Ĵ�С
	  CFormView::OnSize(nType, cx, cy);
      CRect rect;
      GetClientRect(&rect); // ��ȡ��ǰ�ͻ���view��С

      CSize size;
      size.cx = rect.right - rect.left;
      size.cy = rect.bottom - rect.top;
      SetScrollSizes(MM_HIMETRIC, size); // ��CScrollView�Ĵ�С����Ϊ��ǰ�ͻ�����С
	
}
