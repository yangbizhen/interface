// Page.cpp : 实现文件
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "Page.h"
#include "afxdialogex.h"


// CPage 对话框

IMPLEMENT_DYNAMIC(CPage, CPropertyPage)

CPage::CPage()
	: CPropertyPage(CPage::IDD),
	m_isBeginPage(false),
	m_isEndPage(false)
{

}

CPage::~CPage()
{
}

void CPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage, CPropertyPage)
END_MESSAGE_MAP()


// CPage 消息处理程序


BOOL CPage::OnSetActive()
{
	// TODO:  在此添加专用代码和/或调用基类
	CPropertySheet* psheet = (CPropertySheet*)GetParent();
	if (m_isBeginPage){
		psheet->SetWizardButtons(PSWIZB_NEXT);
	}
	else if (m_isEndPage){
		psheet->SetWizardButtons(PSWIZB_BACK);
	}
	else{
		psheet->SetWizardButtons(PSWIZB_BACK | PSWIZB_NEXT);
		
	}
	
	return CPropertyPage::OnSetActive();
}

void CPage::SetEndPage()
{
	m_isEndPage = true;
}

void CPage::SetBeginPage()
{
	m_isBeginPage = true;
}
