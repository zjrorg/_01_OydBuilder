// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "PjOydCodeSystem.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(IDMI_NEW, OnNew)
	ON_COMMAND(IDMI_DEL, OnDel)
	ON_COMMAND(IDMI_MDF, OnMdf)
	ON_COMMAND(IDMI_NEWCODETAB, OnNewcodetab)
	ON_COMMAND(IDMI_NEWCODE, OnNewcode)
	ON_COMMAND(IDT_NEW, OnNew)
	ON_COMMAND(IDMI_SAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext * pContext)
{
	// �ȷ��������ߣ�һ�����У�
	if (NULL == this->m_SplitterV.CreateStatic(this, 1, 2))
	{
		return FALSE;
	}

	/*
	 //��CMonitorTopView��ͼ���ӵ�0��0�д�����
   wndSplitter_horizontal.CreateView(0,0,RUNTIME_CLASS(CMonitorTopView),CSize(50,50),pContext);
	*/ 
	this->m_SplitterV.CreateView(0, 0, RUNTIME_CLASS(CMonitorLeftView), CSize(200, 150), pContext);
	//this->m_SplitterV.CreateView(0, 1, RUNTIME_CLASS(CMonitorRightView), CSize(50, 50), pContext);

	// ��ȡ��ߵ�View
	//this->m_SplitterV.GetPane(0, 0);
	this->m_LeftView = (CMonitorLeftView *) this->m_SplitterV.GetPane(0, 0);

	/*
	 //����1��0���ٷֿ�1��2��
    if(wndSplitter_erect.CreateStatic(&wndSplitter_horizontal,1,2,WS_CHILD|WS_VISIBLE, wndSplitter_horizontal.IdFromRowCol(1, 0))==NULL)
    
    return FALSE; 

	*/
	if (NULL == this->m_SplitterH.CreateStatic(&this->m_SplitterV, 2, 1, WS_CHILD | WS_VISIBLE, this->m_SplitterV.IdFromRowCol(0, 1)))
	{
		return FALSE;
	}

	/*
	    //��CMonitorView�����ӵ��ڶ������������0��0��
     wndSplitter_erect.CreateView(0,0,RUNTIME_CLASS(CMonitorView),CSize(220,220),pContext);
     
     //��CMonitorRightView�����ӵ��ڶ������������0��1��
     wndSplitter_erect.CreateView(0,1,RUNTIME_CLASS(CMonitorRightView),CSize(220,220),pContext); 

	*/
	// 0, 0
	this->m_SplitterH.CreateView(0, 0, RUNTIME_CLASS(CMonitorRTopView), CSize(220, 220), pContext);

	// 1, 0
	this->m_SplitterH.CreateView(1, 0, RUNTIME_CLASS(CMonitorRBOTTOMView), CSize(220, 220), pContext);

	//(CMonitorLeftView *) this->m_SplitterV.GetPane(0, 0);
	this->m_RTopView = (CMonitorRTopView *)this->m_SplitterH.GetPane(0, 0);




	return TRUE;
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers





void CMainFrame::OnNew() 
{
	// TODO: Add your command handler code here
	//MessageBox(_T("New!"));

	//m_DlgNewCate
	//this->m
	//this->m_DlgNewCate.Create(
	/*
		virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL);
	*/
	//HWND gshpre = this->m_Tab1.m_hWnd; // Ϊ��
	HWND cnm = this->m_hWnd; // ��Ϊ��

	int modr = m_DlgNewCate.DoModal();
	if (IDOK == modr)
	{
		//MessageBox(_T("IDOK"));

		
		//MessageBox(_T("ֻ��ʹ���첽�ķ�ʽ"));
		//��LeftTab1����Ϣ��
		//PostMessage(
		//m_Diag1.SendMessage(WM_MY_MESSAGE?,?wparam,?lparam);//
		//this->m_Tab1.CWnd::PostMessage(WM_UPDTREE_MESSAGE);
		//?::PostMessage(dlg.GetSafeHwnd(), WM_MY_MSG,wParam,0);??? //������Ϣ
		//HWND gsh = this->m_Tab1.m_hWnd;
		//::PostMessage(gsh, WM_UPDTREE_MESSAGE, 0, 0);
		//::PostMessage(this->m_
		//::PostMessage(this->m_LeftView->m_hWnd, WM_UPDTREE_MESSAGE, 0, 0);
		this->m_LeftView->OnUpdTree(0, 0);

		

	}
	else if (IDCANCEL == modr)
	{
		//MessageBox(_T("IDCANCEL"));
	}
	else
	{
		//MessageBox(_T("EXCEPTION"));
	}
	
	
}

void CMainFrame::OnDel() 
{
	// TODO: Add your command handler code here
	//MessageBox(_T("OnDel"));
	//this->m_LeftView->OnDel();

	// ����Del���һֱ��Dialog
	this->m_LeftView->OnDel();
	
}

void CMainFrame::OnMdf() 
{
	// TODO: Add your command handler code here
	//MessageBox(_T("TODO: MDF"));
	this->m_LeftView->OnMdf();
	this->m_LeftView->OnUpdTree(0, 0);
}

void CMainFrame::OnNewcodetab() 
{
	// �Ȱ������ѡ�еĴ�ӡ����



	// TODO: Add your command handler code here
	this->m_LeftView->OnNewcodetab();
	this->m_LeftView->OnUpdTree(0, 0);
	
}

void CMainFrame::OnNewcode() 
{
	// TODO: Add your command handler code here
	
	// �õ�ѡ�еĴ�����������
	CMTSYSCodes codesel;
	this->m_LeftView->GetSelCode(&codesel);

	if (strcmp(codesel.m_SCGUID, "") == 0)
	{

	}
	else
	{
		// �����Ӷ��󷽷�
		this->m_RTopView->NewCode(codesel);
	}
	
}

void CMainFrame::OnSave() 
{
	// TODO: Add your command handler code here
	MessageBox(_T("�����µĴ���"));
	
}
