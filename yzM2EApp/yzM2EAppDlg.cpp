
// yzM2EAppDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "yzM2EAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CyzM2EDlg 对话框



CyzM2EDlg::CyzM2EDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CyzM2EDlg::IDD, pParent)
{
	MemDcWnd::MDW_setBkImgName("login_bk.png");
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CyzM2EDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CyzM2EDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CyzM2EDlg::OnBnClickedOk)
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// CyzM2EDlg 消息处理程序

BOOL CyzM2EDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	//ModifyStyleEx(WS_EX_DLGMODALFRAME, 0); // 去掉边框  
	SetWindowLong(this->m_hWnd, GWL_STYLE, GetWindowLong(this->m_hWnd, GWL_STYLE)&~WS_CAPTION);
	SetWindowPos(NULL, NULL, NULL, NULL, NULL, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);


	MemDcWnd::MDW_init(m_hWnd, GetDC());
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CyzM2EDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		MDW_paint(&CPaintDC(this));
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CyzM2EDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CyzM2EDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	CTestDialog testDlg;
	if (testDlg.DoModal() == IDOK){
		this->ShowWindow(SW_SHOW);
	}
	else{
		__super::OnCancel();
	}
}


BOOL CyzM2EDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN   &&   pMsg->wParam == VK_ESCAPE)     return   TRUE;
	if (pMsg->message == WM_KEYDOWN   &&   pMsg->wParam == VK_RETURN)   return   TRUE;
	else  return __super::PreTranslateMessage(pMsg);
}

CyzM2EDlg::~CyzM2EDlg()
{
}


LRESULT CyzM2EDlg::OnNcHitTest(CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	LRESULT ret = CDialogEx::OnNcHitTest(point);
	return (ret == HTCLIENT) ? HTCAPTION : ret;
}


