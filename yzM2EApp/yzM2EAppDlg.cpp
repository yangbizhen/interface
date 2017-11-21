
// yzM2EAppDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "yzM2EAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CyzM2EDlg �Ի���



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


// CyzM2EDlg ��Ϣ�������

BOOL CyzM2EDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	//ModifyStyleEx(WS_EX_DLGMODALFRAME, 0); // ȥ���߿�  
	SetWindowLong(this->m_hWnd, GWL_STYLE, GetWindowLong(this->m_hWnd, GWL_STYLE)&~WS_CAPTION);
	SetWindowPos(NULL, NULL, NULL, NULL, NULL, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);


	MemDcWnd::MDW_init(m_hWnd, GetDC());
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CyzM2EDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		MDW_paint(&CPaintDC(this));
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CyzM2EDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CyzM2EDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN   &&   pMsg->wParam == VK_ESCAPE)     return   TRUE;
	if (pMsg->message == WM_KEYDOWN   &&   pMsg->wParam == VK_RETURN)   return   TRUE;
	else  return __super::PreTranslateMessage(pMsg);
}

CyzM2EDlg::~CyzM2EDlg()
{
}


LRESULT CyzM2EDlg::OnNcHitTest(CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	LRESULT ret = CDialogEx::OnNcHitTest(point);
	return (ret == HTCLIENT) ? HTCAPTION : ret;
}


