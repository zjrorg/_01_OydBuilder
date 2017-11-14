// DialogNewCateGory.cpp : implementation file
//

#include "stdafx.h"
#include "PjOydCodeSystem.h"
#include "DialogNewCateGory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogNewCateGory dialog


CDialogNewCateGory::CDialogNewCateGory(BOOL isModify, CWnd* pParent /*=NULL*/)
	: CDialog(CDialogNewCateGory::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogNewCateGory)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	//this->AdjustType//
	this->m_IsModify = isModify;
}


void CDialogNewCateGory::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogNewCateGory)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogNewCateGory, CDialog)
	//{{AFX_MSG_MAP(CDialogNewCateGory)
	ON_BN_CLICKED(ID_OK, OnOK)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogNewCateGory message handlers

void CDialogNewCateGory::OnOK() 
{
	CEdit * txt = (CEdit *)this->GetDlgItem(IDC_TXTNEWCATEGORYNAME);
	CString strVal;
	txt->GetWindowText(strVal);

	// TODO: Add your control notification handler code here
	if (this->m_IsModify)
	{
		//MessageBox(_T("CDialogNewCateGory::OnOK() TODO: ��ɹ��ܣ� �����˸��ô��룡"));

		int mdfret = CDBTSYSCategory::MdfCategory(this->m_ModifySCGUID, strVal);

		if (mdfret < 0)
		{
			//MessageBox(_T("�÷��������Ѵ��ڣ�"));
			MessageBox(strVal);

			// �������뽹��
			this->GetDlgItem(IDC_TXTNEWCATEGORYNAME)->SetFocus();
		}
		else
		{
			CDialog::OnOK();
		}
	}
	else
	{
		//15601299777

		// �õ��ı����е�ֵ����Ϊ�·������ơ�


		CString pre = "new cata name:";
		//MessageBox(pre + strVal);

		//xxxxxxxxx::newname(pre+strVal, CATA, NEWCATA);
		int diaret = CDBTSYSCategory::AddNewCategory(strVal);
		if (NEWCATE_NOTEXISTS == diaret)
		{
			CDialog::OnOK();
		}
		else if(NEWCATE_EXISTS == diaret)
		{
			MessageBox(_T("�÷��������Ѵ��ڣ�"));

			// �������뽹��
			this->GetDlgItem(IDC_TXTNEWCATEGORYNAME)->SetFocus();

			//CDialog::OnCancel();
		}
	}

}

void CDialogNewCateGory::OnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}



BOOL CDialogNewCateGory::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if (this->m_IsModify)
	{
		this->CDialog::SetWindowText(_T("�޸Ĵ�������"));
		CWnd * txt = this->GetDlgItem(IDC_TXTNEWCATEGORYNAME);
		txt->CWnd::SetWindowText(this->m_ModifySCName);
		//MessageBox(_T("CDialogNewCateGory::OnInitDialog Ҫ���л��ԣ�"));
	}
	else
	{
	}



	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
