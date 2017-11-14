// DBTSYSCodes.cpp: implementation of the CDBTSYSCodes class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PjOydCodeSystem.h"
#include "DBTSYSCodes.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int CDBTSYSCodes::AddNewCode(CString &eng, CString &chn, CString & selscguid)
{
	// 添加新代码表

	CDBUtil util;

	//::CoInitialize(NULL);

	//_ConnectionPtr m_pConnection("ADODB.Connection");
	CDBUtilPara paras[3] = {
		//CDBUtilPara(int CDBUTILPARA_TYPE, CString & csval, char * pcharval, int ival, int dblen);
		CDBUtilPara(CDBUtilPara::CDBUTILPARA_TYPE_CSTRING, eng, NULL, 0, 50),
		CDBUtilPara(CDBUtilPara::CDBUTILPARA_TYPE_CSTRING, chn, NULL, 0, 50),
		CDBUtilPara(CDBUtilPara::CDBUTILPARA_TYPE_CSTRING, selscguid, NULL, 0, 37),
	};
	std::vector<CDBUtilPara> vparas(paras, paras + 3);
	CString cmdstr;
		cmdstr += "create table [";
		cmdstr += (LPSTR)(LPCSTR)eng;
		cmdstr += "]\n";
		cmdstr += "(\n";
		cmdstr += "GUID uniqueidentifier primary key,\n";
		cmdstr += "Code nvarchar(50) null,\n";
		cmdstr += "Name nvarchar(50) null\n";
		cmdstr += ")\n";

		// sql 的第二部分，添加数据
		cmdstr += "Insert into TSYSCodes Values(newid(), ?, ?, ?)";
	util.ExecuteAuto("Provider=SQLOLEDB;Server=127.0.0.1;Database=VP_Oydbuilder; uid=sa; pwd=sql2000;"
		, cmdstr, vparas);

	return 0;
}

int CDBTSYSCodes::GetCodes(std::vector<CMTSYSCodes *> & parr, CString & scguidsel, int * len)
{
	CDBUtil util;
	CDBUtilPara paras[1] = {
		//CDBUtilPara(int CDBUTILPARA_TYPE, CString & csval, char * pcharval, int ival, int dblen);
		CDBUtilPara(CDBUtilPara::CDBUTILPARA_TYPE_CSTRING, scguidsel, NULL, 0, 37),
	};
	std::vector<CDBUtilPara> vparas(paras, paras + 1);
	util.CDBUtil::ExecuteAuto("Provider=SQLOLEDB;Server=127.0.0.1;Database=VP_Oydbuilder; uid=sa; pwd=sql2000;", CString("select SCTGUID, SCTENGNAME, SCTCHNNAME, SCGUID From TSYSCodes Where SCGUID = ?")
		, vparas);	

	/*CMTSYSCodes * c1 = new CMTSYSCodes;

	strcpy(c1->m_SCGUID, "00001111-2222-3333-4444-666655551111");
	strcpy(c1->m_SCTCHNNAME, "tab1");
	strcpy(c1->m_SCTENGNAME, "tab1");
	//strcpy(c1->m_SCTGUID 

	parr.push_back(c1);
	*len = 1;*/
	int retlen = 0;
	_variant_t sctguid;
	_variant_t sctengname;
	_variant_t sctchnname;
	_variant_t scguid;
	while (!util.m_pRecordset->EndOfFile)
	{
		// 声明 新的对象 
		CMTSYSCodes * c1 = new CMTSYSCodes;

		// 给对象赋值
		//c1->CMTSYSCodes::m_SCGUID


		util.CDBUtil::GetGUIDValue(sctguid, c1->CMTSYSCodes::m_SCTGUID, "SCTGUID");
		util.CDBUtil::GetPCharValue(sctengname, c1->CMTSYSCodes::m_SCTENGNAME, "SCTENGNAME");
		util.CDBUtil::GetPCharValue(sctchnname, c1->CMTSYSCodes::m_SCTCHNNAME, "SCTCHNNAME");
		util.CDBUtil::GetGUIDValue(scguid, c1->m_SCGUID, "SCGUID");

		// push 到数组
		parr.push_back(c1);

		// 游标移动
		util.m_pRecordset->MoveNext();
		retlen++; // 长度变化！
	}
	*len = retlen;

	return 0;
}