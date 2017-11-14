// PjAdoMFCTest.cpp : Defines the class behaviors for the application.
//

// 引入dll


#include "stdafx.h"
#include "PjAdoMFCTest.h"
#include "PjAdoMFCTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPjAdoMFCTestApp

BEGIN_MESSAGE_MAP(CPjAdoMFCTestApp, CWinApp)
	//{{AFX_MSG_MAP(CPjAdoMFCTestApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPjAdoMFCTestApp construction

CPjAdoMFCTestApp::CPjAdoMFCTestApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPjAdoMFCTestApp object

CPjAdoMFCTestApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPjAdoMFCTestApp initialization

void CPjAdoMFCTestApp::adotest()
{
	MessageBox(NULL, _T("adotest"), _T("TIP"), MB_OK);

// 初始化OLE/COM库环境 ，为访问ADO接口做准备
	::CoInitialize(NULL);	

	// 声明结果集对象和连接对象
	_RecordsetPtr m_pRecordset("ADODB.Recordset");
	_ConnectionPtr m_pConnection("ADODB.Connection");

	try
	{
		// 创建Connection对象  
		m_pConnection.CreateInstance("ADODB.Connection");
		//m_pConnection.CreateInstance("ADODB.Connection");

		// 设置连接字符串，必须是BSTR型或者_bstr_t类型  
		_bstr_t strConnect = "Provider=SQLOLEDB;Server=127.0.0.1;Database=VP_Oydbuilder; uid=sa; pwd=sql2000;";

		//用户sa和密码sql2005只是针对我的库  
		HRESULT hsre = m_pConnection->Open(strConnect, "", "", adModeUnknown);

		//select * From Test_t1 where TestAge > 2
		_CommandPtr cmd;
		cmd.CreateInstance(__uuidof(Command));
		// 将库连接赋予它
		cmd->ActiveConnection = m_pConnection;
		// 语句
		cmd->CommandText = "select * From Test_t1 where TestAge > ?";

		// 声明参数对象
		_ParameterPtr pGTTestAge;
		// 4? size		
		//pGTTestAge = cmd->CreateParameter(_bstr_t(""), DataTypeEnum::adInteger, ParameterDirectionEnum::adParamInput, 4);
		//pGTTestAge.CreateInstance(TEXT("ADODB.Parameter"));
		pGTTestAge = cmd->CreateParameter(_bstr_t(""), adInteger, adParamInput, 4);//8?
		_variant_t pGTestAgeVal((long)2);		//pGTestAgeVal.intVal = 2;
		pGTTestAge->Value = pGTestAgeVal;//_variant_t(2); // err!		
		cmd->Parameters->Append(pGTTestAge);

		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset = cmd->Execute(NULL, NULL, adCmdText);

		_variant_t guid;
		_variant_t testc1;
		_variant_t testc2;
		_variant_t testc3;
		_variant_t testage;

		while (!m_pRecordset->EndOfFile)
		{	
			//		em_id = m_pRecordset->GetCollect("EM_ID");
			guid = m_pRecordset->GetCollect("GUID");
			testc1 = m_pRecordset->GetCollect("TestC1");
			testc2 = m_pRecordset->GetCollect("TestC2");
			testc3 = m_pRecordset->GetCollect("TestC3");
			testage = m_pRecordset->GetCollect("TestAge");

			// guid
			const wchar_t * wstr = _bstr_t(guid);		
			size_t len = wcslen(wstr) + 1;
			size_t converted = 0;
			char *CStr;
			CStr = (char*)malloc(len*sizeof(char));
			//wcstombs_s(&converted, CStr, len, wstr, _TRUNCATE);
			wcstombs(CStr, wstr, len*sizeof(char));	
			cout << CStr << " | ";

			if (CStr)
			{
				free(CStr);
				CStr = NULL;
			}
			// //guid		
			
			// TestC1
			if (testc1.vt != VT_NULL)
			{
				// 把testc1中的字符串值取出来
				const wchar_t * wstrtestc1 = _bstr_t(testc1);		
				size_t len = wcslen(wstrtestc1) + 1;
				size_t converted = 0;
				char *CStrtestc1;
				CStrtestc1 = (char*)malloc(len*sizeof(char));
				//wcstombs_s(&converted, CStr, len, wstr, _TRUNCATE);
				wcstombs(CStrtestc1, wstrtestc1, len*sizeof(char));	
				cout << CStrtestc1 << " | ";

				if (CStrtestc1)
				{
					free(CStrtestc1);
					CStrtestc1 = NULL;
				}
	

			}
			else
			{
				cout << "<NULL>" << " | ";
			}
			// //TestC1

			// TestC2
			if (testc2.vt != VT_NULL)
			{
				// 把testc2中的字符串值取出来
				const wchar_t * wstrtestc2 = _bstr_t(testc2);		
				size_t len = wcslen(wstrtestc2) + 2;
				size_t converted = 0;
				char *CStrtestc2;
				CStrtestc2 = (char*)malloc(len*sizeof(char));
				//wcstombs_s(&converted, CStr, len, wstr, _TRUNCATE);
				wcstombs(CStrtestc2, wstrtestc2, len*sizeof(char));	
				cout << CStrtestc2 << " | ";

				if (CStrtestc2)
				{
					free(CStrtestc2);
					CStrtestc2 = NULL;
				}
	

			}
			else
			{
				cout << "<NULL>" << " | ";
			}
			// //TestC2

			// TestC3
			if (testc3.vt != VT_NULL)
			{
				DATE date = testc3.date;
				long   l   =   long(date); //天数 
				date   =   date   -   l; 
				date   =   date   *   24   *   60   *   60; 
				l   =   long(date);     //秒数 
				date   =   date   -   l; 
				date   =   date   *   1000; 
				l   =   long(date);     //毫秒数 

				COleDateTime oleTimeGet;  
				SYSTEMTIME sysTimeGet;
				CString strTimeGet;
				CString strTime;

				oleTimeGet=(COleDateTime)testc3;
				
				VariantTimeToSystemTime(oleTimeGet,&sysTimeGet);
				strTimeGet.Format(_T("%d-%d-%d %d:%d:%d.%03d"),sysTimeGet.wYear,sysTimeGet.wMonth,sysTimeGet.wDay,sysTimeGet.wHour,sysTimeGet.wMinute,sysTimeGet.wSecond,l);
				strTime = strTimeGet;
				MessageBox(NULL, strTime, _T("time"), MB_OK);

				//cout << "<Date>" << " | ";
			}
			else
			{
				cout << "<NULL>" << " | ";
			}
			// //TestC3

			// TestAge
			if (testage.vt != VT_NULL)
			{
				cout << testage.iVal;
			}
			else
			{
				cout << "<NULL>";
			}
			// //TestAge

			m_pRecordset->MoveNext();
			cout << endl;
		}

	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}



	// 关闭连接对象
	if (m_pConnection->State)
	{
		m_pConnection->Close();
	}
	::CoUninitialize();


























}

BOOL CPjAdoMFCTestApp::InitInstance()
{
	AfxEnableControlContainer();

	adotest();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CPjAdoMFCTestDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
