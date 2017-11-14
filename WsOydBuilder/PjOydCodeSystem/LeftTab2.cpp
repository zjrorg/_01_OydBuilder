// LeftTab2.cpp : implementation file
//

#include "stdafx.h"
#include "PjOydCodeSystem.h"
#include "LeftTab2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftTab2 dialog


CLeftTab2::CLeftTab2(CWnd* pParent /*=NULL*/)
	: CDialog(CLeftTab2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLeftTab2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLeftTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeftTab2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeftTab2, CDialog)
	//{{AFX_MSG_MAP(CLeftTab2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftTab2 message handlers
