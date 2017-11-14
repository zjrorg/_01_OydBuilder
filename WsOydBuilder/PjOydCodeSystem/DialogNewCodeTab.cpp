// DialogNewCodeTab.cpp : implementation file
//

#include "stdafx.h"
#include "PjOydCodeSystem.h"
#include "DialogNewCodeTab.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogNewCodeTab dialog

//#include "DBTSYSCodes.h"


CDialogNewCodeTab::CDialogNewCodeTab(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogNewCodeTab::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogNewCodeTab)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CDialogNewCodeTab::SetSelSCGUID(CString & selscguid)
{
	this->CDialogNewCodeTab::m_SelSCGUID = selscguid;
}

void CDialogNewCodeTab::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogNewCodeTab)
	DDX_Control(pDX, IDC_NEWCODEENGNAME, m_TxtNewEngName);
	DDX_Control(pDX, IDC_TXTNEWCATEGORYNAME, m_TxtNewChnName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogNewCodeTab, CDialog)
	//{{AFX_MSG_MAP(CDialogNewCodeTab)
	ON_BN_CLICKED(ID_OK, OnOK)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogNewCodeTab message handlers


void CDialogNewCodeTab::OnOK() 
{
	// TODO: Add your control notification handler code here

	// 得到新的英文名称和中文名称
	CString eng;
	CString chn;
	this->m_TxtNewEngName.GetWindowText(eng);
	this->m_TxtNewChnName.CWnd::GetWindowText(chn);


	//int addr = CDBTSYSCodes::AddNewCode(eng, chn);
	int addr = CDBTSYSCodes::AddNewCode(eng, chn, this->m_SelSCGUID);





	MessageBox(eng + CString(" - ") + chn);

	CDialog::OnOK();
	
}

void CDialogNewCodeTab::OnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
