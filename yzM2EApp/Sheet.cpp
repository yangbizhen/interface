// Sheet.cpp : 实现文件
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "Sheet.h"

// CSheet

IMPLEMENT_DYNAMIC(CSheet, CPropertySheet)

CSheet::CSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	pages[0].SetBeginPage();
	pages[1].SetEndPage();
	AddPage(&pages[0]);
	AddPage(&pages[1]);
}

CSheet::CSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	pages[0].SetBeginPage();
	pages[1].SetEndPage();
	AddPage(&pages[0]);
	AddPage(&pages[1]);
}

CSheet::~CSheet()
{
}


BEGIN_MESSAGE_MAP(CSheet, CPropertySheet)
END_MESSAGE_MAP()

void CSheet::AddQuePages()
{

}


// CSheet 消息处理程序
