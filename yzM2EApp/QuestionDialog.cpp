// QuestionDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "QuestionDialog.h"
#include "afxdialogex.h"
#include "Sheet.h"

// CQuestionDialog 对话框

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


// CQuestionDialog 消息处理程序


BOOL CQuestionDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CQuestionDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
}



LRESULT CQuestionDialog::OnNcHitTest(CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	LRESULT ret = CDialogEx::OnNcHitTest(point);
	return (ret == HTCLIENT) ? HTCAPTION : ret;
}
