// LeftTab1.cpp : implementation file
//

#include "stdafx.h"
#include "PjOydCodeSystem.h"
#include "LeftTab1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



using namespace ::std;

/////////////////////////////////////////////////////////////////////////////
// CLeftTab1 dialog


CLeftTab1::CLeftTab1(CWnd* pParent /*=NULL*/)
	: CDialog(CLeftTab1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLeftTab1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	this->CLeftTab1::m_MdfDlg = new CDialogNewCateGory(TRUE, NULL);
	//this->CLeftTab1::m_CodeTabDlg = NULL;
	this->CLeftTab1::m_CodeTabDlg = new CDialogNewCodeTab;
}


void CLeftTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeftTab1)
	DDX_Control(pDX, IDC_TREEMAIN, m_TCMain);
	//}}AFX_DATA_MAP
}

void CLeftTab1::GetSelCode(CMTSYSCodes * codem)
{
	HTREEITEM item = this->m_TCMain.GetSelectedItem();
	DWORD datadw = this->m_TCMain.GetItemData(item);
	CMTSYSCodes * datac = (CMTSYSCodes *)datadw;
	int scguid = strlen(datac->m_SCGUID);
	if (scguid == 0)
	{
		MessageBox(_T("请选择正确的代码表"));
		//strcpy(codem->m_SCGUID, "");
		//strcpy(codem->m_SCTCHNNAME, "");
		//strcpy(codem->)
		memset(codem, 0, sizeof(*codem));
	}
	else
	{
		//MessageBox(_T("选中的确实是代码表"));
		memcpy(codem, datac, sizeof(*datac));
	}

}


BEGIN_MESSAGE_MAP(CLeftTab1, CDialog)
	//{{AFX_MSG_MAP(CLeftTab1)
	ON_WM_SIZE()
	ON_NOTIFY(NM_CLICK, IDC_TREEMAIN, OnClickTreemain)
	ON_MESSAGE(WM_UPDTREE_MESSAGE, OnUpdTree)
	ON_NOTIFY(NM_RCLICK, IDC_TREEMAIN, OnRclickTreemain)
	ON_NOTIFY(NM_DBLCLK, IDC_TREEMAIN, OnDblclkTreemain)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftTab1 message handlers
LRESULT CLeftTab1::OnUpdTree(WPARAM wParam, LPARAM lParam)
{
	MessageBox(_T("hello!"));
	return -1;
}

// always return 0;
int CLeftTab1::OnMdf()
{
	// 获取选中的节点，如果没有，提示并返回。
	HTREEITEM itemSel = this->m_TCMain.CTreeCtrl::GetSelectedItem();
	if (!itemSel)
	{
		MessageBox(_T("没有选中任何节点！"));
		return 0;
	}

	// 得到选中，即将要修改的数据（在对象 theSelObj（CMTSYSCategory *） 中）
	DWORD data = this->m_TCMain.CTreeCtrl::GetItemData(itemSel);
	CMTSYSCategory * theSelObj = (CMTSYSCategory *)data;
	CString scguidandname;
	scguidandname.Format("%s - %s", theSelObj->m_SCGUID, theSelObj->m_SCName);
	//MessageBox(scguidandname);

	strcpy(this->m_MdfDlg->CDialogNewCateGory::m_ModifySCGUID, theSelObj->m_SCGUID);
	strcpy(this->m_MdfDlg->CDialogNewCateGory::m_ModifySCName, theSelObj->m_SCName);	
	int mr = this->CLeftTab1::m_MdfDlg->CDialog::DoModal();

	return 0;
}

int CLeftTab1::OnDel()
{
	// 获取选中的节点

	// 删除它
	// 	BOOL DeleteItem(HTREEITEM hItem);
	//this->m_TCMain.DeleteItem(NULL);
	//this->m_TCMain.CTreeCtrl::DeleteItem(
	HTREEITEM itemSel = this->m_TCMain.CTreeCtrl::GetSelectedItem();

	if (!itemSel)
	{
		MessageBox(_T("没有选中任何节点！"));
		return 0;
	}

	//this->m_TCMain.CTreeCtrl::DeleteItem(itemSel);
	//this->m_TCMain.CTreeCtrl::SetItemData(
	DWORD data = this->m_TCMain.CTreeCtrl::GetItemData(itemSel);
	//CString str;
	//str.Format("%ld", data);

	CMTSYSCategory * theSelObj = (CMTSYSCategory *)data;
	CString scguid;
	scguid.Format("%s", theSelObj->m_SCGUID);
	


	//DWORD

	//MessageBox(str);

	// 询问用户是否真要删除
	if (IDOK != MessageBox(_T("确认删除？"), _T("删除"), MB_OKCANCEL))	
	{
		return 0;
	}

	

	// 如果确实要删除，调用数据访问方法，如果出错，打印出来。
	CString msg;
	int delr = CDBTSYSCategory::DelCategory(scguid, &msg);

	if (delr < 0)
	{
		// 提示出错信息
		MessageBox(msg, _T("提示"), MB_OK);
	}
	else if (delr == 0)
	{
		//
		//MessageBox(_T("删除成功"));

		// 移除节点
		this->m_TCMain.CTreeCtrl::DeleteItem(itemSel);
	}

	return 0;
}

CLeftTab1::~CLeftTab1()
{
	//m_HeapDatas
	for(map<DWORD, BOOL>::iterator i = m_HeapDatas.map<DWORD, BOOL>::begin();
		i!=m_HeapDatas.end();
		i++)
		{
			//  cout<<iter->first <<"->"<<iter->second<<endl;
			if (i->second)
			{
				delete (CMTSYSCategory *)i->first;
				m_HeapDatas[i->second] = 0;
			}
		}

		//
		if (this->CLeftTab1::m_MdfDlg)
		{
			delete this->CLeftTab1::m_MdfDlg;
			this->CLeftTab1::m_MdfDlg = NULL;
		}
		if (this->CLeftTab1::m_CodeTabDlg)
		{
			delete this->CLeftTab1::m_CodeTabDlg;
			this->CLeftTab1::m_CodeTabDlg = NULL;
		}
}

void CLeftTab1::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
		  // 同步CScrollView的大小

      CRect rect;
      GetClientRect(&rect); // 获取当前客户区view大小

      CSize size;
      size.cx = rect.right - rect.left;
      size.cy = rect.bottom - rect.top;
      //SetScrollSizes(MM_HIMETRIC, size); // 将CScrollView的大小设置为当前客户区大小

	  // 同步Tree的布局
	  // TODO
	  CWnd * tab = this->CDialog::GetDlgItem(IDC_TREEMAIN);
	  if (tab)
	  {
		  // 使得CTabCtrl控件同步位置和大小
		  tab->MoveWindow(&rect, TRUE);
		
	  }	   	
	
}

int CLeftTab1::LoadTreeData()
{

	//CTreeCtrl * tree = (CTreeCtrl *)this->GetDlgItem(IDC_TREEMAIN);
	CTreeCtrl & tree = this->m_TCMain;
	// 这个函数好像只能在OnInitDialog中调用。
	/*
	HTREEITEM hItem = 
	HTREEITEM hIteml10 = tree.InsertItem("l1item", NULL, NULL, hItem);
	HTREEITEM hIteml11 = tree.InsertItem("l1item1", NULL, NULL, hItem);
	HTREEITEM hIteml12 = tree.InsertItem("l1item2", NULL, NULL, hItem);
	HTREEITEM hIteml13 = tree.InsertItem("l1item3", NULL, NULL, hItem);
	HTREEITEM hIteml14 = tree.InsertItem("l1item4", NULL, NULL, hItem);
	HTREEITEM hIteml2 = tree.InsertItem("l2item", NULL, NULL, hIteml12);
	*/
	tree.DeleteAllItems();


	// 声明用来使用的指针（当数组用）
	//CMTSYSCategory * syscategories = NULL;
	vector<CMTSYSCategory *> syscategories;
	int syscategories_len = 0;

	// 调用方法，获得数据和数量。
	int getr = CDBTSYSCategory::GetCategories(syscategories, &syscategories_len);

	// 加载树节点
	if (getr < 0)
	{
		MessageBox(_T("CLeftTab1.cpp LoadTreeData err!"));
		return -1;
	}

	// 释放指针。
	int i = 0;
	for(i = 0; i < syscategories_len; i++)
	{
		HTREEITEM item = tree.InsertItem(syscategories.at(i)->m_SCName, NULL, NULL);///root就是节点的标题
		tree.SetItemData(item, (DWORD)syscategories.at(i));

		// 想保存一个对象，是从堆中开辟的资源，那么如何掌握生命周期？
		// 当前类有一个map成员，在析构函数中，遍历这个map，如果value为1，就释放它，且置为0。
		this->CLeftTab1::m_HeapDatas.map<DWORD, BOOL>::insert(map<DWORD, BOOL>::value_type(/*heap*/
			(DWORD)syscategories.at(i), TRUE));

		

		//if (syscategories.at(i))
		//{
		//	delete syscategories.at(i);
		//	syscategories[i] = NULL;
		//}
	}

	//tree.SelectItem(NULL); 不管用


	return -1;
}

BOOL CLeftTab1::OnInitDialog() 
{
	CDialog::OnInitDialog();

	this->LoadTreeData();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLeftTab1::OnClickTreemain(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//CTreeCtrl & tree = this->m_TCMain;
	//HTREEITEM hItem = tree.InsertItem("root2",NULL,NULL);///root就是节点的标题
	
	*pResult = 0;
}



int CLeftTab1::Newcodetab()
{
	HTREEITEM selitem = this->CLeftTab1::m_TCMain.CTreeCtrl::GetSelectedItem();
	//this->CLeftTab1::m_TCMain
	/*HTREEITEM selitem = this->CLeftTab1::m_TCMain.CTreeCtrl::GetSelectedItem();
	CMTSYSCategory * theselcategory = (CMTSYSCategory *)selitem;
	CString strtest = theselcategory->m_SCGUID;
	MessageBox(strtest);*/
	DWORD pdata = this->CLeftTab1::m_TCMain.CTreeCtrl::GetItemData(selitem);
	CMTSYSCategory * theselcategory = (CMTSYSCategory *)pdata;
	CString scguidsel = theselcategory->m_SCGUID;
	//MessageBox(testdata + "is sel guid!");

	//CDialog dia;
	//dia.Create(2021, NULL);
	//dia.DoModal();
	this->CLeftTab1::m_CodeTabDlg->SetSelSCGUID(scguidsel);
	int dmr = this->CLeftTab1::m_CodeTabDlg->CDialog::DoModal();

	if (IDOK == dmr)
	{





		MessageBox(_T("CLeftTab1::Newcodetab()"));
	}
	else
	{
	}
		


	return 0;
}

void CLeftTab1::OnRclickTreemain(NMHDR* pNMHDR, LRESULT* pResult) 
{
	 CPoint   point(GetMessagePos());

    unsigned   int   nFlags   =   0;

 

    m_TCMain.ScreenToClient(&point);

    HTREEITEM   hItem   =   m_TCMain.HitTest(point,&nFlags);

    if  ((nFlags& TVHT_ONITEM) &&(hItem!=NULL))

    {

       m_TCMain.SetFocus();

       m_TCMain.SelectItem(   hItem   );

       CMenu MyMenu;

       MyMenu.LoadMenu(IDR_MENU1);//加载菜单资源

       CMenu* popup=MyMenu.GetSubMenu(0);

       GetCursorPos(&point);//获取当前光标的位置，以便使得菜单可以跟随光标这里也可以用m_tree.ClientToScreen(&point);

       popup->TrackPopupMenu(TPM_LEFTBUTTON|TPM_LEFTALIGN,point.x,point.y,this);

    }

    // TODO: 在此添加控件通知处理程序代码

    *pResult = 0;
}

void CLeftTab1::OnDblclkTreemain(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CConfig cfg;

	//MessageBox(_T("test1"));

	// 得到选中的节点
	HTREEITEM itemseled = this->CLeftTab1::m_TCMain.CTreeCtrl::GetSelectedItem();

	// 移除所有其子节点，开始
	HTREEITEM itemsomechild = NULL;
	BOOL has = FALSE;

	while (has = this->CLeftTab1::m_TCMain.CTreeCtrl::ItemHasChildren(itemseled))
	{
		/*hChildItem=m_Tree.GetChildItem(hItem);??
????????????m_Tree.DeleteItem(hChildItem);??*/

		itemsomechild = this->m_TCMain.GetChildItem(itemseled);
		this->m_TCMain.DeleteItem(itemsomechild);
	}





	// 移除所有其子节点，结束



	DWORD data = this->CLeftTab1::m_TCMain.CTreeCtrl::GetItemData(itemseled);
	CMTSYSCategory * cgseled = (CMTSYSCategory *)data;
	CString scguidsel = cgseled->m_SCGUID;
	//MessageBox(_T("根据分类得到该分类下的代码表") + scguidsel);

	// 声明集合
	std::vector<CMTSYSCodes *> plist;
	int len;

	// 调用方法
	CDBTSYSCodes::GetCodes(plist, scguidsel, &len);

	// 一边挂到树上一边加入到map中。以析构时释放
	int i = 0;
	for(i = 0; i < len; i++)
	{
		HTREEITEM item = this->CLeftTab1::m_TCMain.CTreeCtrl::InsertItem((plist.at(i))->m_SCTCHNNAME, itemseled, NULL);
		// 设置数据
		this->CLeftTab1::m_TCMain.CTreeCtrl::SetItemData(item, (DWORD)(plist.at(i)));

		// 控制生命周期
		this->CLeftTab1::m_HeapDatas.map<DWORD, BOOL>::insert(map<DWORD, BOOL>::value_type(/*heap*/
			(DWORD)plist.at(i), TRUE));
	}


	
	*pResult = 0;
}
