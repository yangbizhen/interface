// CPage2 ��Ϣ�������
// Page2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "Page2.h"
#include "afxdialogex.h"


// CPage2 �Ի���

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


// CPage2 ��Ϣ�������


BOOL CPage2::OnWizardFinish()
{
	// TODO:  �ڴ����ר�ô����/����û���
	MessageBox(_T("ʹ��˵�������Ķ��꣡"));
	return CPropertyPage::OnWizardFinish();
}
