// LeftTab3.cpp : implementation file
//

#include "stdafx.h"
#include "PjOydCodeSystem.h"
#include "LeftTab3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftTab3 dialog


CLeftTab3::CLeftTab3(CWnd* pParent /*=NULL*/)
	: CDialog(CLeftTab3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLeftTab3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLeftTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeftTab3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeftTab3, CDialog)
	//{{AFX_MSG_MAP(CLeftTab3)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftTab3 message handlers
