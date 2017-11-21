// ScreenIrritate.cpp : 实现文件
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "ScreenIrritate.h"
#include "afxdialogex.h"


// CScreenIrritate 对话框

IMPLEMENT_DYNAMIC(CScreenIrritate, CDialogEx)

CScreenIrritate::CScreenIrritate(CWnd* pParent /*=NULL*/)
	: CDialogEx(CScreenIrritate::IDD, pParent)
{
	MemDcWnd::m_bkImgName = "test_bk.png";
}

CScreenIrritate::~CScreenIrritate()
{
}

void CScreenIrritate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDCANCEL, m_cancel);
	DDX_Control(pDX, IDC_BUTTON_STRAT_IRRITATE, m_btnStartIrrtate);
}


BEGIN_MESSAGE_MAP(CScreenIrritate, CDialogEx)
	ON_WM_PAINT()
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// CScreenIrritate 消息处理程序


BOOL CScreenIrritate::OnInitDialog()
{
	__super::OnInitDialog();

	// TODO:  在此添加额外的初始化
	MemDcWnd::MDW_setSize(1036, 697);
	MemDcWnd::MDW_init(m_hWnd, GetDC());
	UIInit();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CScreenIrritate::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 __super::OnPaint()
	MemDcWnd::MDW_paint(&dc);
}

void CScreenIrritate::UIInit()
{
	m_cancel.SetBtn(RESOURCE_PATH + CString("close.png"), 988, 15, 19, 19); 
	m_btnStartIrrtate.SetBtn(RESOURCE_PATH + CString("start_irrtate_btn.png"), 470, 319, 97, 119);
	
	
}


LRESULT CScreenIrritate::OnNcHitTest(CPoint point)
{
	LRESULT ret = CDialogEx::OnNcHitTest(point);
	return (ret == HTCLIENT) ? HTCAPTION : ret;
}
