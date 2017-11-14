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
		MessageBox(_T("��ѡ����ȷ�Ĵ����"));
		//strcpy(codem->m_SCGUID, "");
		//strcpy(codem->m_SCTCHNNAME, "");
		//strcpy(codem->)
		memset(codem, 0, sizeof(*codem));
	}
	else
	{
		//MessageBox(_T("ѡ�е�ȷʵ�Ǵ����"));
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
	// ��ȡѡ�еĽڵ㣬���û�У���ʾ�����ء�
	HTREEITEM itemSel = this->m_TCMain.CTreeCtrl::GetSelectedItem();
	if (!itemSel)
	{
		MessageBox(_T("û��ѡ���κνڵ㣡"));
		return 0;
	}

	// �õ�ѡ�У�����Ҫ�޸ĵ����ݣ��ڶ��� theSelObj��CMTSYSCategory *�� �У�
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
	// ��ȡѡ�еĽڵ�

	// ɾ����
	// 	BOOL DeleteItem(HTREEITEM hItem);
	//this->m_TCMain.DeleteItem(NULL);
	//this->m_TCMain.CTreeCtrl::DeleteItem(
	HTREEITEM itemSel = this->m_TCMain.CTreeCtrl::GetSelectedItem();

	if (!itemSel)
	{
		MessageBox(_T("û��ѡ���κνڵ㣡"));
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

	// ѯ���û��Ƿ���Ҫɾ��
	if (IDOK != MessageBox(_T("ȷ��ɾ����"), _T("ɾ��"), MB_OKCANCEL))	
	{
		return 0;
	}

	

	// ���ȷʵҪɾ�����������ݷ��ʷ��������������ӡ������
	CString msg;
	int delr = CDBTSYSCategory::DelCategory(scguid, &msg);

	if (delr < 0)
	{
		// ��ʾ������Ϣ
		MessageBox(msg, _T("��ʾ"), MB_OK);
	}
	else if (delr == 0)
	{
		//
		//MessageBox(_T("ɾ���ɹ�"));

		// �Ƴ��ڵ�
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
		  // ͬ��CScrollView�Ĵ�С

      CRect rect;
      GetClientRect(&rect); // ��ȡ��ǰ�ͻ���view��С

      CSize size;
      size.cx = rect.right - rect.left;
      size.cy = rect.bottom - rect.top;
      //SetScrollSizes(MM_HIMETRIC, size); // ��CScrollView�Ĵ�С����Ϊ��ǰ�ͻ�����С

	  // ͬ��Tree�Ĳ���
	  // TODO
	  CWnd * tab = this->CDialog::GetDlgItem(IDC_TREEMAIN);
	  if (tab)
	  {
		  // ʹ��CTabCtrl�ؼ�ͬ��λ�úʹ�С
		  tab->MoveWindow(&rect, TRUE);
		
	  }	   	
	
}

int CLeftTab1::LoadTreeData()
{

	//CTreeCtrl * tree = (CTreeCtrl *)this->GetDlgItem(IDC_TREEMAIN);
	CTreeCtrl & tree = this->m_TCMain;
	// �����������ֻ����OnInitDialog�е��á�
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


	// ��������ʹ�õ�ָ�루�������ã�
	//CMTSYSCategory * syscategories = NULL;
	vector<CMTSYSCategory *> syscategories;
	int syscategories_len = 0;

	// ���÷�����������ݺ�������
	int getr = CDBTSYSCategory::GetCategories(syscategories, &syscategories_len);

	// �������ڵ�
	if (getr < 0)
	{
		MessageBox(_T("CLeftTab1.cpp LoadTreeData err!"));
		return -1;
	}

	// �ͷ�ָ�롣
	int i = 0;
	for(i = 0; i < syscategories_len; i++)
	{
		HTREEITEM item = tree.InsertItem(syscategories.at(i)->m_SCName, NULL, NULL);///root���ǽڵ�ı���
		tree.SetItemData(item, (DWORD)syscategories.at(i));

		// �뱣��һ�������ǴӶ��п��ٵ���Դ����ô��������������ڣ�
		// ��ǰ����һ��map��Ա�������������У��������map�����valueΪ1�����ͷ���������Ϊ0��
		this->CLeftTab1::m_HeapDatas.map<DWORD, BOOL>::insert(map<DWORD, BOOL>::value_type(/*heap*/
			(DWORD)syscategories.at(i), TRUE));

		

		//if (syscategories.at(i))
		//{
		//	delete syscategories.at(i);
		//	syscategories[i] = NULL;
		//}
	}

	//tree.SelectItem(NULL); ������


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
	//HTREEITEM hItem = tree.InsertItem("root2",NULL,NULL);///root���ǽڵ�ı���
	
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

       MyMenu.LoadMenu(IDR_MENU1);//���ز˵���Դ

       CMenu* popup=MyMenu.GetSubMenu(0);

       GetCursorPos(&point);//��ȡ��ǰ����λ�ã��Ա�ʹ�ò˵����Ը���������Ҳ������m_tree.ClientToScreen(&point);

       popup->TrackPopupMenu(TPM_LEFTBUTTON|TPM_LEFTALIGN,point.x,point.y,this);

    }

    // TODO: �ڴ���ӿؼ�֪ͨ����������

    *pResult = 0;
}

void CLeftTab1::OnDblclkTreemain(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CConfig cfg;

	//MessageBox(_T("test1"));

	// �õ�ѡ�еĽڵ�
	HTREEITEM itemseled = this->CLeftTab1::m_TCMain.CTreeCtrl::GetSelectedItem();

	// �Ƴ��������ӽڵ㣬��ʼ
	HTREEITEM itemsomechild = NULL;
	BOOL has = FALSE;

	while (has = this->CLeftTab1::m_TCMain.CTreeCtrl::ItemHasChildren(itemseled))
	{
		/*hChildItem=m_Tree.GetChildItem(hItem);??
????????????m_Tree.DeleteItem(hChildItem);??*/

		itemsomechild = this->m_TCMain.GetChildItem(itemseled);
		this->m_TCMain.DeleteItem(itemsomechild);
	}





	// �Ƴ��������ӽڵ㣬����



	DWORD data = this->CLeftTab1::m_TCMain.CTreeCtrl::GetItemData(itemseled);
	CMTSYSCategory * cgseled = (CMTSYSCategory *)data;
	CString scguidsel = cgseled->m_SCGUID;
	//MessageBox(_T("���ݷ���õ��÷����µĴ����") + scguidsel);

	// ��������
	std::vector<CMTSYSCodes *> plist;
	int len;

	// ���÷���
	CDBTSYSCodes::GetCodes(plist, scguidsel, &len);

	// һ�߹ҵ�����һ�߼��뵽map�С�������ʱ�ͷ�
	int i = 0;
	for(i = 0; i < len; i++)
	{
		HTREEITEM item = this->CLeftTab1::m_TCMain.CTreeCtrl::InsertItem((plist.at(i))->m_SCTCHNNAME, itemseled, NULL);
		// ��������
		this->CLeftTab1::m_TCMain.CTreeCtrl::SetItemData(item, (DWORD)(plist.at(i)));

		// ������������
		this->CLeftTab1::m_HeapDatas.map<DWORD, BOOL>::insert(map<DWORD, BOOL>::value_type(/*heap*/
			(DWORD)plist.at(i), TRUE));
	}


	
	*pResult = 0;
}
