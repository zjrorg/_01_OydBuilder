// MonitorLeftView.cpp : implementation file
//

#include "stdafx.h"
#include "PjOydCodeSystem.h"
#include "MonitorLeftView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMonitorLeftView

IMPLEMENT_DYNCREATE(CMonitorLeftView, CFormView)

CMonitorLeftView::CMonitorLeftView()
	: CFormView(CMonitorLeftView::IDD)
{
	//{{AFX_DATA_INIT(CMonitorLeftView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CMonitorLeftView::~CMonitorLeftView()
{
}

//	void GetSelCode(CMTSYSCodes * codem);
void CMonitorLeftView::GetSelCode(CMTSYSCodes * codem)
{
	this->m_Tab1.GetSelCode(codem);
}

void CMonitorLeftView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMonitorLeftView)

	//}}AFX_DATA_MAP
}

int CMonitorLeftView::OnNewcodetab()
{
	this->m_Tab1.Newcodetab();
	return 0;
}

LRESULT CMonitorLeftView::OnUpdTree(WPARAM wParam, LPARAM lParam)
{
	//MessageBox(_T("hello!123123"));
	this->m_Tab1.LoadTreeData();
	return -1;
}

int CMonitorLeftView::OnDel()
{
	this->m_Tab1.OnDel();
	return 0;
}

int CMonitorLeftView::OnMdf()
{
	this->m_Tab1.OnMdf();
	return 0;
}


BEGIN_MESSAGE_MAP(CMonitorLeftView, CFormView)
	//{{AFX_MSG_MAP(CMonitorLeftView)
	ON_WM_SIZE()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE,IDC_TABCTRL,OnSelChangeTab)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMonitorLeftView diagnostics

#ifdef _DEBUG
void CMonitorLeftView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMonitorLeftView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMonitorLeftView message handlers

void CMonitorLeftView::OnSize(UINT nType, int cx, int cy) 
{
	  // ͬ��CScrollView�Ĵ�С
	  CFormView::OnSize(nType, cx, cy);
      CRect rect;
      GetClientRect(&rect); // ��ȡ��ǰ�ͻ���view��С

      CSize size;
      size.cx = rect.right - rect.left;
      size.cy = rect.bottom - rect.top;
      SetScrollSizes(MM_HIMETRIC, size); // ��CScrollView�Ĵ�С����Ϊ��ǰ�ͻ�����С

	  // ͬ��CTabCtrl�Ĳ���
	  CWnd * tab = this->CFormView::GetDlgItem(IDC_TABCTRL);
	  if (tab)
	  {
		  // ʹ��CTabCtrl�ؼ�ͬ��λ�úʹ�С
		  tab->MoveWindow(&rect, TRUE);

		  // ʹ��һ�����壨CTabCtrl�еĵ�һ��tab�еģ�ͬ��λ�úʹ�С  
		  this->m_Tab1.MoveWindow(0, 25, cx, cy);
		  this->m_Tab2.MoveWindow(0, 25, cx, cy);
		  this->m_Tab3.MoveWindow(0, 25, cx, cy);
	  }	  
	
}


// CFormView��OnInitialUpdate������CDialog��OnInitialDialog!!!!!!	
void CMonitorLeftView::OnInitialUpdate()
{	
	CRect rec;  
	GetClientRect(&rec);  
	int cr = m_TabCtrl.Create(TCS_TABS|WS_CHILD|WS_VISIBLE,rec,this,IDC_TABCTRL);  
	if (cr)
	{
		m_TabCtrl.InsertItem(0, _T("Ŀ¼"));
		m_TabCtrl.InsertItem(1, _T("����"));
		m_TabCtrl.InsertItem(2, _T("����"));

		//m_page1.Create(IDD_DIALOG1,GetDlgItem(IDC_TABCTRL)); 
		this->m_Tab1.Create(IDD_LEFTTAB1, &m_TabCtrl);
		this->m_Tab2.Create(IDD_LEFTTAB2, &m_TabCtrl);
		this->m_Tab3.Create(IDD_LEFTTAB3, &m_TabCtrl);


		this->m_Tab1.ShowWindow(SW_SHOWNORMAL);
		this->m_TabCtrl.SetCurSel(0);
	}
	else
	{
		MessageBox(_T("m_TabCtrl.Create Failed!"));
	}
}
//afx_msg void OnSelChangeTab(NMHDR *pNMHDR,LRESULT *pResult);
void CMonitorLeftView::OnSelChangeTab(NMHDR * pNMHDR, LRESULT * pResult)
{
		//��ȡ��ѡ���ҳ��
	int nCurSel = this->m_TabCtrl.GetCurSel();
	
	if (0 == nCurSel)
	{
		this->m_Tab1.ShowWindow(SW_SHOW);
		this->m_Tab2.ShowWindow(SW_HIDE);
		this->m_Tab3.ShowWindow(SW_HIDE);
	}
	else if (1 == nCurSel)
	{
			this->m_Tab1.ShowWindow(SW_HIDE);
		this->m_Tab2.ShowWindow(SW_SHOW);
		this->m_Tab3.ShowWindow(SW_HIDE);
	}
	else if (2 == nCurSel)
	{
			this->m_Tab1.ShowWindow(SW_HIDE);
		this->m_Tab2.ShowWindow(SW_HIDE);
		this->m_Tab3.ShowWindow(SW_SHOW);

	}


	//this->m_Tab1.ShowWindow(nCurSel == 0?SW_SHOW:SW_HIDE);
	//this->m_Tab2.ShowWindow(nCurSel == 1?SW_SHOW:SW_HIDE);
	//this->m_Tab3.ShowWindow(nCurSel == 2?SW_SHOW:SW_HIDE);
	*pResult = 0;
}


