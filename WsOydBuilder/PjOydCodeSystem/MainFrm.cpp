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
	// 先分左右两边（一行两列）
	if (NULL == this->m_SplitterV.CreateStatic(this, 1, 2))
	{
		return FALSE;
	}

	/*
	 //将CMonitorTopView视图连接到0行0列窗格上
   wndSplitter_horizontal.CreateView(0,0,RUNTIME_CLASS(CMonitorTopView),CSize(50,50),pContext);
	*/ 
	this->m_SplitterV.CreateView(0, 0, RUNTIME_CLASS(CMonitorLeftView), CSize(200, 150), pContext);
	//this->m_SplitterV.CreateView(0, 1, RUNTIME_CLASS(CMonitorRightView), CSize(50, 50), pContext);

	// 获取左边的View
	//this->m_SplitterV.GetPane(0, 0);
	this->m_LeftView = (CMonitorLeftView *) this->m_SplitterV.GetPane(0, 0);

	/*
	 //将第1行0列再分开1行2列
    if(wndSplitter_erect.CreateStatic(&wndSplitter_horizontal,1,2,WS_CHILD|WS_VISIBLE, wndSplitter_horizontal.IdFromRowCol(1, 0))==NULL)
    
    return FALSE; 

	*/
	if (NULL == this->m_SplitterH.CreateStatic(&this->m_SplitterV, 2, 1, WS_CHILD | WS_VISIBLE, this->m_SplitterV.IdFromRowCol(0, 1)))
	{
		return FALSE;
	}

	/*
	    //将CMonitorView类连接到第二个分栏对象的0行0列
     wndSplitter_erect.CreateView(0,0,RUNTIME_CLASS(CMonitorView),CSize(220,220),pContext);
     
     //将CMonitorRightView类连接到第二个分栏对象的0行1列
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
	//HWND gshpre = this->m_Tab1.m_hWnd; // 为空
	HWND cnm = this->m_hWnd; // 不为空

	int modr = m_DlgNewCate.DoModal();
	if (IDOK == modr)
	{
		//MessageBox(_T("IDOK"));

		
		//MessageBox(_T("只能使用异步的方式"));
		//给LeftTab1发消息！
		//PostMessage(
		//m_Diag1.SendMessage(WM_MY_MESSAGE?,?wparam,?lparam);//
		//this->m_Tab1.CWnd::PostMessage(WM_UPDTREE_MESSAGE);
		//?::PostMessage(dlg.GetSafeHwnd(), WM_MY_MSG,wParam,0);??? //传送消息
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

	// 传递Del命令，一直到Dialog
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
	// 先把左边所选中的打印出来



	// TODO: Add your command handler code here
	this->m_LeftView->OnNewcodetab();
	this->m_LeftView->OnUpdTree(0, 0);
	
}

void CMainFrame::OnNewcode() 
{
	// TODO: Add your command handler code here
	
	// 得到选中的代码表对象数据
	CMTSYSCodes codesel;
	this->m_LeftView->GetSelCode(&codesel);

	if (strcmp(codesel.m_SCGUID, "") == 0)
	{

	}
	else
	{
		// 调用子对象方法
		this->m_RTopView->NewCode(codesel);
	}
	
}

void CMainFrame::OnSave() 
{
	// TODO: Add your command handler code here
	MessageBox(_T("保存新的代码"));
	
}
