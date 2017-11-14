// MonitorRTopView.cpp : implementation file
//

#include "stdafx.h"
#include "PjOydCodeSystem.h"
#include "MonitorRTopView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMonitorRTopView

IMPLEMENT_DYNCREATE(CMonitorRTopView, CFormView)

CMonitorRTopView::CMonitorRTopView()
	: CFormView(CMonitorRTopView::IDD)
{
	//{{AFX_DATA_INIT(CMonitorRTopView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CMonitorRTopView::~CMonitorRTopView()
{
}

void CMonitorRTopView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	//MessageBox(_T("CMonitorRTopView::OnInitalUpdate()"));
	CWnd * wnd = this->GetDlgItem(IDC_NEWCODEENGNAME);
	if (wnd)
	{	
		((CEdit *)wnd)->SetFocus();
	}
}

void CMonitorRTopView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMonitorRTopView)
	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMonitorRTopView, CFormView)
	//{{AFX_MSG_MAP(CMonitorRTopView)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMonitorRTopView diagnostics

#ifdef _DEBUG
void CMonitorRTopView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMonitorRTopView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMonitorRTopView message handlers

void CMonitorRTopView::OnSize(UINT nType, int cx, int cy) 
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

	  

	  //
	  /*CRect rect2;
	  rect2.SetRect(0, 0, 120, 20);
	  CWnd * btntest = this->CWnd::GetDlgItem(IDC_BTNTEST);
	  if (btntest)
	  {
			btntest->MoveWindow(&rect2);
			btntest->ShowWindow(FALSE);		
	  }*/


	
}

void CMonitorRTopView::NewCode(const CMTSYSCodes & codesel)
{
	//codesel.m_SCTCHNNAME
	CString str;
	str.Format("新增代码的代码表是%s\n", codesel.m_SCTENGNAME);
	MessageBox(str);
}
