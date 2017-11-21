// TestDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "TestDialog.h"
#include "afxdialogex.h"
#include "TestLogDialog.h"

// CTestDialog �Ի���
#define  TEST_LIST "ʵ���б�"

IMPLEMENT_DYNAMIC(CTestDialog, CDialogEx)

CTestDialog::CTestDialog(CWnd* pParent /*=NULL*/)
: CDialogEx(CTestDialog::IDD, pParent)
{
	MemDcWnd::m_bkImgName = "test_main_bk.png";
}

CTestDialog::~CTestDialog()
{
}

void CTestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_MIN, m_btnMin);
	DDX_Control(pDX, IDCANCEL, m_btnClose);
	DDX_Control(pDX, IDC_STATIC_PHOTO, m_staticPhoto);
	DDX_Control(pDX, IDC_LIST_NOT_COMPLETE_TASK, m_listNotCompleteTask);
	DDX_Control(pDX, IDC_LIST_COMPLETE_TASK, m_listCompleteTask);
	DDX_Control(pDX, IDC_LIST_DEVICE, m_listDevice);
	DDX_Control(pDX, IDC_LIST_EXPERI, m_listExperi);
	DDX_Control(pDX, IDC_BUTTON_FEEL, m_btnFeel);
	DDX_Control(pDX, IDC_BUTTON_RETURN_TEST, m_btnReturnTest);
}


BEGIN_MESSAGE_MAP(CTestDialog, CDialogEx)
	ON_WM_PAINT()
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, OnWndFileTreeViewDoubleClicked)
	ON_MESSAGE(WM_SHOW_TASK_DLG_MESSAGE, OnShowTaskDlg)
	ON_MESSAGE(WM_SHOW_EXPERI_DLG_MESSAGE, OnShowExperiDlg)
	ON_BN_CLICKED(IDCANCEL, &CTestDialog::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CTestDialog::OnBnClickedOk)
	ON_WM_NCHITTEST()
	ON_BN_CLICKED(IDC_BUTTON_MIN, &CTestDialog::OnBnClickedButtonMin)
	ON_BN_CLICKED(IDC_BUTTON_FEEL, &CTestDialog::OnBnClickedButtonFeel)
	ON_BN_CLICKED(IDC_BUTTON_RETURN_TEST, &CTestDialog::OnBnClickedButtonReturnTest)
END_MESSAGE_MAP()


// CTestDialog ��Ϣ�������


BOOL CTestDialog::OnInitDialog()
{
	__super::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	ModifyStyleEx(WS_EX_APPWINDOW, WS_EX_APPWINDOW);
	::SetWindowPos(this->GetSafeHwnd(), CWnd::wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	MemDcWnd::MDW_setSize(TEST_DLG_W, TEST_DLG_H);
	MemDcWnd::MDW_init(m_hWnd, GetDC(), true);
	UIInit();
	InitChildDlg();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

void CTestDialog::UIInit()
{
	m_btnMin.SetBtn(RESOURCE_PATH + CString("main_min_btn.png"), m_clientW - 45, 5, 19, 19);
	m_btnClose.SetBtn(RESOURCE_PATH + CString("main_close_btn.png"), m_clientW - 25, 5, 19, 19);
	m_staticPhoto.MoveWindow(10, 42, 50, 50);
	m_staticPhoto.LoadFile(RESOURCE_PATH+CString("photo.png"));

	//	m_pImgTask = new CImageList();
	//	m_pImgTask->Create(16, 16, ILC_COLOR32 | ILC_MASK, 2, 2);
	//	//���ͼ��  
	//	HICON icon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//	m_pImgTask->Add(icon);
	//
#define InitList(list, title, y, h) { \
	list.SetImageList(m_pImgTask, LVSIL_SMALL); \
	list.InsertColumn(0, title, LVCFMT_CENTER, TEST_DLG_W); \
	list.MoveWindow(0, y, TEST_DLG_W, h); \
				} 
	InitList(m_listExperi, TEST_LIST, 147, 400);
	m_listExperi.SetRowHeigt(25);
	m_listExperi.SetListName("ʵ���б�");


	InitList(m_listNotCompleteTask, "δ�������", 175, 100);
	m_listNotCompleteTask.SetRowHeigt(25);
	m_listNotCompleteTask.ShowWindow(SW_HIDE);

	InitList(m_listCompleteTask, "���������", 305, 100);
	m_listCompleteTask.SetRowHeigt(25);
	m_listCompleteTask.ShowWindow(SW_HIDE);

	InitList(m_listDevice, "�豸�б�", 445, 100);
	m_listDevice.SetRowHeigt(25);
	m_listDevice.ShowWindow(SW_HIDE);
	m_listDevice.SetIcon(RESOURCE_PATH+CString("online.ico"));
	m_btnFeel.SetBtn(".//resource//feel_btn.png", 172, 116, 19, 20);
	m_btnReturnTest.SetBtn(".//resource//return_test_btn.png", 56, 116, 19, 20);

	//m_btnFeel.SetBtnBk(".//resource//feel_bt.png");
	for (int i = 0; i < 100; i++){
		m_listExperi.InsertItem(i, (LPCTSTR)_T("ʵ��"), 0);
		m_listNotCompleteTask.InsertItem(i, (LPCTSTR)_T("��Ļ�̼�"), 0);
		m_listCompleteTask.InsertItem(i, (LPCTSTR)_T("2"), 0);
		m_listDevice.InsertItem(i, (LPCTSTR)_T("3"), 0);
	}
}


void CTestDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� __super::OnPaint()
	MDW_paint(&dc);
	Graphics graphics(this->GetDC()->m_hDC);

	SolidBrush brush(Color(255, 255, 255, 255));

	FontFamily fontfamily(L"����");
	Gdiplus::Font nameFont(&fontfamily, 20, FontStyleRegular, UnitPixel);
	Gdiplus::Font font(&fontfamily, 14, FontStyleRegular, UnitPixel);

	graphics.DrawString(L"����˹͡", -1, &nameFont, PointF(70, 55), &brush);

	brush.SetColor(Color(255, 0, 0, 0));
	graphics.DrawString(L"���������(", -1, &font, PointF(11, 286), &brush);
	graphics.DrawString(L"δ�������(", -1, &font, PointF(11, 153), &brush);
	graphics.DrawString(L"�ɼ��豸", -1, &font, PointF(37, 423), &brush);

	brush.SetColor(Color(255, 255, 0, 0));
	int i = 85;
	
	graphics.DrawString(L"85", -1, &font, PointF(90, 286), &brush);
	graphics.DrawString(L"88", -1, &font, PointF(90, 153), &brush);

	int end = 90;
	while (i)
	{
		i /= 10;
		end += 8;
	}
	brush.SetColor(Color(255, 0, 0, 0));
	graphics.DrawString(L")", -1, &font, PointF(end, 286), &brush);
	graphics.DrawString(L")", -1, &font, PointF(end, 153), &brush);


}

void CTestDialog::OnWndFileTreeViewDoubleClicked(NMHDR *pNMHDR, LRESULT *pResult)
{

}

LRESULT CTestDialog::OnShowTaskDlg(WPARAM wParam, LPARAM lParam)
{
	char *nodeName = (char*)wParam;


	delete nodeName;
	return 0;
}

LRESULT CTestDialog::OnShowExperiDlg(WPARAM wParam, LPARAM lParam)
{

	//m_experiDlg.ShowWindow(SW_SHOW);
	char *nodeName = (char*)wParam;
	if (strcmp(nodeName, "ʵ��") == 0){
		m_listExperi.ShowWindow(SW_HIDE);
		m_listNotCompleteTask.ShowWindow(SW_SHOW);
		m_listCompleteTask.ShowWindow(SW_SHOW);
		m_listDevice.ShowWindow(SW_SHOW);
	}
	else if (strcmp(nodeName, "��Ļ�̼�") == 0){
		m_screenIrritate.ShowWindow(SW_SHOW);
	}

	return 0;
}


BOOL CTestDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �ڴ����ר�ô����/����û���

	if (pMsg->message == WM_KEYDOWN   &&   pMsg->wParam == VK_ESCAPE)     return   TRUE;
	if (pMsg->message == WM_KEYDOWN   &&   pMsg->wParam == VK_RETURN)   return   TRUE;
	else  return __super::PreTranslateMessage(pMsg);
}


void CTestDialog::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CloseAllDialog();
	__super::OnOK();
}


void CTestDialog::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CloseAllDialog();
	__super::OnCancel();
}

void CTestDialog::CloseAllDialog()
{

	m_testLogDlg.OnCloseCamera();
	m_testLogDlg.DestroyWindow();

	m_queDlg.DestroyWindow();
	exit(0);
}


LRESULT CTestDialog::OnNcHitTest(CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	LRESULT ret = CDialogEx::OnNcHitTest(point);
	return (ret == HTCLIENT) ? HTCAPTION : ret;
}


void CTestDialog::OnBnClickedButtonMin()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	ShowWindow(SW_MINIMIZE);
}





void CTestDialog::OnBnClickedButtonFeel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_testLogDlg.ShowWindow(SW_SHOW);
}

void CTestDialog::InitChildDlg()
{
	m_testLogDlg.Create(CTestLogDialog::IDD);

	m_screenIrritate.Create(CScreenIrritate::IDD);
}


void CTestDialog::OnBnClickedButtonReturnTest()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_listExperi.ShowWindow(SW_SHOW);
	m_listNotCompleteTask.ShowWindow(SW_HIDE);
	m_listCompleteTask.ShowWindow(SW_HIDE);
	m_listDevice.ShowWindow(SW_HIDE);
}


