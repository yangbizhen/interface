// QuestionDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "QuestionDialog.h"
#include "afxdialogex.h"
#include "Sheet.h"

// CQuestionDialog �Ի���

IMPLEMENT_DYNAMIC(CQuestionDialog, CDialogEx)

CQuestionDialog::CQuestionDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CQuestionDialog::IDD, pParent)
{

}

CQuestionDialog::~CQuestionDialog()
{
}

void CQuestionDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CQuestionDialog, CDialogEx)
	ON_WM_PAINT()
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// CQuestionDialog ��Ϣ�������


BOOL CQuestionDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CQuestionDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}



LRESULT CQuestionDialog::OnNcHitTest(CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	LRESULT ret = CDialogEx::OnNcHitTest(point);
	return (ret == HTCLIENT) ? HTCAPTION : ret;
}
