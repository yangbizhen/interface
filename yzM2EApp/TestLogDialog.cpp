// TaskDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "TestLogDialog.h"
#include "afxdialogex.h"
#include "CvvImage.h"

// CTaskDialog 对话框

IMPLEMENT_DYNAMIC(CTestLogDialog, CDialogEx)

CTestLogDialog::CTestLogDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestLogDialog::IDD, pParent),
	m_pCapture(NULL)
{
	MemDcWnd::m_bkImgName = "test_bk.png";
}

CTestLogDialog::~CTestLogDialog()
{
	if (m_pCapture != NULL){
		cvReleaseCapture(&m_pCapture);
	}
}

void CTestLogDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_CAMERA, m_picCamera);
	DDX_Control(pDX, IDCANCEL, m_btnClose);
	DDX_Control(pDX, IDC_BUTTON_RECORD, m_btnRecord);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_btnStop);
	DDX_Control(pDX, IDC_MONTHCALENDAR_LOG, m_dataTimeCtrl);
	DDX_Control(pDX, IDC_EDIT_FEEL, m_editFeel);
	DDX_Control(pDX, IDC_BUTTON_SUBMIT_FEEL, m_btnSubmit);
}


BEGIN_MESSAGE_MAP(CTestLogDialog, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_RECORD, &CTestLogDialog::OnBnClickedOpenCamera)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDCANCEL, &CTestLogDialog::OnBnClickedCancel)
	ON_WM_NCHITTEST()
	ON_BN_CLICKED(IDC_BUTTON_RECORD, &CTestLogDialog::OnBnClickedButtonRecord)
END_MESSAGE_MAP()


// CTaskDialog 消息处理程序


BOOL CTestLogDialog::OnInitDialog()
{
	__super::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	MemDcWnd::MDW_setSize(1036, 697);
	MemDcWnd::MDW_init(m_hWnd, GetDC());
	
	UIInit();
	//opencv 
	
	m_hDC = m_picCamera.GetDC()->GetSafeHdc();
	m_picCamera.GetClientRect(&m_rect);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CTestLogDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 __super::OnPaint()
	MemDcWnd::MDW_paint(&dc);
}

void CTestLogDialog::UIInit()
{
	m_dataTimeCtrl.MoveWindow(24,80, 239, 189);
	m_picCamera.MoveWindow(285, 80, 733, 471);
	
	m_btnClose.SetBtn(RESOURCE_PATH + CString("close.png"), 988, 15, 19, 19);

	//m_ok.MoveWindow(10, 490, 50, 20);
	//m_cancel.MoveWindow(70, 490, 50, 20);
	//m_openCamera.MoveWindow(130, 490, 50, 20);

	m_btnRecord.SetBtn(RESOURCE_PATH + CString("record_btn.png"), 558, 294, 185, 48);
	m_btnStop.SetBtn(RESOURCE_PATH + CString("stop_btn.png"), 591, 487, 34, 34);
	
	m_editFeel.MoveWindow(288, 554, 645, 115);
	m_btnSubmit.SetBtn(RESOURCE_PATH + CString("submit_btn.png"), 930, 550, 88, 122);
}

void CTestLogDialog::SetTitle(CString title)
{
	this->m_strTitle = title;
}


void CTestLogDialog::OnBnClickedOpenCamera()
{
	// TODO:  在此添加控件通知处理程序代码
	if (!m_pCapture)
	{
		m_pCapture = cvCaptureFromCAM(0);
	}
	IplImage *pFrame;
	pFrame = cvQueryFrame(m_pCapture);
	CvvImage cvvImage;
	cvvImage.CopyOf(pFrame, 1);
	cvvImage.DrawToHDC(m_hDC, &m_rect);
	SetTimer(1, 10, NULL);
	
}



void CTestLogDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	IplImage *pFrame;
	pFrame = cvQueryFrame(m_pCapture);
	CvvImage cvvImage;
	cvvImage.CopyOf(pFrame, 1);
	cvvImage.DrawToHDC(m_hDC, &m_rect);
	__super::OnTimer(nIDEvent);
}


void CTestLogDialog::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	OnCloseCamera();
	__super::OnCancel();
}


BOOL CTestLogDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类

	if (pMsg->message == WM_KEYDOWN   &&   pMsg->wParam == VK_ESCAPE)     return   TRUE;
	if (pMsg->message == WM_KEYDOWN   &&   pMsg->wParam == VK_RETURN)   return   TRUE;
	else  return __super::PreTranslateMessage(pMsg);
}

void CTestLogDialog::OnCloseCamera()
{
	if (m_pCapture!=NULL){
		cvReleaseCapture(&m_pCapture);
		KillTimer(1);
	}
	
}


LRESULT CTestLogDialog::OnNcHitTest(CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	LRESULT ret = CDialogEx::OnNcHitTest(point);
	return (ret == HTCLIENT) ? HTCAPTION : ret;
}


void CTestLogDialog::OnBnClickedButtonRecord()
{
	// TODO:  在此添加控件通知处理程序代码
}
