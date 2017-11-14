// DBTSYSCategory.cpp: implementation of the CDBTSYSCategory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PjOydCodeSystem.h"
#include "DBTSYSCategory.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "DBUtil1.h"

using namespace ::std;



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int CDBTSYSCategory::AddNewCategory(CString &catename)
{
	int retval = 0;

	//cmd->CommandText = "exec SPSYSCategoryAdd ?"; catename 50

	CDBUtil util;
	util.Init();
	util.Open("Provider=SQLOLEDB;Server=127.0.0.1;Database=VP_Oydbuilder; uid=sa; pwd=sql2000;");
	util.InitCommand("exec SPSYSCategoryAdd ?");
	//util.InitCommand("if exists(select 1 From TSYSCategory Where SCDataState = 1 And SCName = ?) begin select 1 Ret end else begin insert into TSYSCategory values(newid(), ?, 1)  select 2 Ret end;");
	/*
	SET NOCOUNT ON if exists(select 1 From TSYSCategory Where SCDataState = 1 And SCName = @SCName) begin select 1 Ret end else begin insert into TSYSCategory values(newid(), @SCName, 1)  select 2 Ret end;
	*/
	//
	util.AddCStringParameter(catename, 50);
	util.Execute();	

	_variant_t ret;
	while (!util.m_pRecordset->EndOfFile)
	{
		ret=util.m_pRecordset->GetCollect("Ret");
		retval = ret.iVal;

		util.m_pRecordset->MoveNext();		
	}

	return retval;
}

int CDBTSYSCategory::DelCategory(CString & scguid, CString * pmsg)
{
	// 跟据scguid把这一条数据从库中删除！
	int ret = 0;

	//"Delete From TSYscategory Where SCGUID = ?"
	CDBUtil util;
	util.Init();
	util.Open("Provider=SQLOLEDB;Server=127.0.0.1;Database=VP_Oydbuilder; uid=sa; pwd=sql2000;");
	util.InitCommand("Delete From TSYscategory Where SCGUID = ?");
	util.AddCStringParameter(scguid, 36);
	util.Execute();

	return ret;
}

int CDBTSYSCategory::MdfCategory(char * scguid, CString & scname)
{
	if (!scguid  || strlen(scguid) != 36)
	{
		return -1;
	}

	CDBUtil util;
	CDBUtilPara paras[2] = {
		//CDBUtilPara(int CDBUTILPARA_TYPE, CString & csval, char * pcharval, int ival, int dblen);
		CDBUtilPara(CDBUtilPara::CDBUTILPARA_TYPE_CSTRING, scname, NULL, 0, 50),
		CDBUtilPara(CDBUtilPara::CDBUTILPARA_TYPE_PCHAR, CString(""), scguid, 0, 36),
	};
	std::vector<CDBUtilPara> vparas(paras, paras + 2);
	util.ExecuteAuto("Provider=SQLOLEDB;Server=127.0.0.1;Database=VP_Oydbuilder; uid=sa; pwd=sql2000;"
		, "Update TSYSCategory Set SCName = ? Where SCGUID = ? And SCDataState = 1"
		, vparas);

	return 0;
}

int CDBTSYSCategory::GetCategories(vector<CMTSYSCategory *> & parr, int * len)
{
	if (!len)
	{
		return -1;
	}
	int i = 0;
	int retlen = 0; 
	CDBUtil util;	
	CString parascnamelike = "%%";
	CDBUtilPara paras[2] = {
		CDBUtilPara(CDBUtilPara::CDBUTILPARA_TYPE_INT, CString(""), NULL, 1, 4),
		CDBUtilPara(CDBUtilPara::CDBUTILPARA_TYPE_CSTRING, parascnamelike, NULL, 0, 50),
	};
	std::vector<CDBUtilPara> vparas(paras, paras + 2);
	util.ExecuteAuto((LPSTR)(LPCSTR)CDBUtil::m_ConStr
		, "select * From TSYscategory Where SCDataState = ? and SCName like ?"
		, vparas);

		// 声明返回临时对象
		_variant_t scguid;
		_variant_t scname;
		_variant_t scdatastate;

		while (!util.m_pRecordset->EndOfFile)
		{
			scdatastate = util.m_pRecordset->GetCollect("scdatastate");

			// 新数据的插入
			CMTSYSCategory * model = new CMTSYSCategory;
			parr.push_back(model);	
			util.CDBUtil::GetGUIDValue(scguid, model->m_SCGUID, "SCGUID");
			util.CDBUtil::GetPCharValue(scname, model->m_SCName, "SCName");
			util.m_pRecordset->MoveNext();
			retlen++; // 长度变化！
		}

	*len = retlen;
	return 0;
}
