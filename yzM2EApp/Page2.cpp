// CPage2 消息处理程序
// Page2.cpp : 实现文件
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "Page2.h"
#include "afxdialogex.h"


// CPage2 对话框

IMPLEMENT_DYNAMIC(CPage2, CPropertyPage)

CPage2::CPage2()
	: CPropertyPage(CPage2::IDD)
{

}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage2, CPropertyPage)
END_MESSAGE_MAP()


// CPage2 消息处理程序


BOOL CPage2::OnWizardFinish()
{
	// TODO:  在此添加专用代码和/或调用基类
	MessageBox(_T("使用说明向导已阅读完！"));
	return CPropertyPage::OnWizardFinish();
}
