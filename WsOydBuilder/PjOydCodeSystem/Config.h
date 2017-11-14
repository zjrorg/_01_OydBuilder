// Config.h: interface for the CConfig class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONFIG_H__A325B680_7F45_44BE_91BA_25E4008B23FF__INCLUDED_)
#define AFX_CONFIG_H__A325B680_7F45_44BE_91BA_25E4008B23FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CConfig  
{
public:
	CConfig();
	virtual ~CConfig();

	static CString m_ConfigFilePath;

	static void GetValue(CString & app, CString & key, CString & value);
	static void SetValue(CString & app, CString & key, CString & value);

};

#endif // !defined(AFX_CONFIG_H__A325B680_7F45_44BE_91BA_25E4008B23FF__INCLUDED_)
