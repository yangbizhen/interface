// ScreenIrritate.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "ScreenIrritate.h"
#include "afxdialogex.h"


// CScreenIrritate �Ի���

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


// CScreenIrritate ��Ϣ�������


BOOL CScreenIrritate::OnInitDialog()
{
	__super::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	MemDcWnd::MDW_setSize(1036, 697);
	MemDcWnd::MDW_init(m_hWnd, GetDC());
	UIInit();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CScreenIrritate::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� __super::OnPaint()
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
