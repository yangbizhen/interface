// Page.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "Page.h"
#include "afxdialogex.h"


// CPage �Ի���

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


// CPage ��Ϣ�������


BOOL CPage::OnSetActive()
{
	// TODO:  �ڴ����ר�ô����/����û���
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
