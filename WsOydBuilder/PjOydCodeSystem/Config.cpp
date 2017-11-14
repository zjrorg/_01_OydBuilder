// Config.cpp: implementation of the CConfig class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PjOydCodeSystem.h"
#include "Config.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CString CConfig::m_ConfigFilePath = "";

CConfig::CConfig()
{
	// 通过当前程序的位置找到配置文件的位置（稍后使用其它文件夹）
	TCHAR exeFullPath[MAX_PATH];
	int len = GetModuleFileName(NULL, exeFullPath, MAX_PATH);
	PTCHAR last = strrchr(exeFullPath, '\\');
	*last = '\0';	
	CString cfginipath = "\\cfg.ini";
	this->m_ConfigFilePath = exeFullPath + cfginipath;
}

void CConfig::GetValue(CString & app, CString & key, CString & value)
{
	GetPrivateProfileString((LPSTR)(LPCSTR)app, (LPSTR)(LPCSTR)key, "", value.GetBuffer(MAX_PATH), MAX_PATH, m_ConfigFilePath);
}

void CConfig::SetValue(CString & app, CString & key, CString & value)
{
	WritePrivateProfileString((LPSTR)(LPCSTR)app, (LPSTR)(LPCSTR)key, (LPSTR)(LPCSTR)value, m_ConfigFilePath);
}

CConfig::~CConfig()
{

}
