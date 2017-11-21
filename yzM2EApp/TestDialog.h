#pragma once
#include "MemDcWnd.h"
#include "TestLogDialog.h"
#include "QuestionDialog.h"
#include "DialogButton.h"
#include "MyListCtrl.h"
#include "MyButton.h"
#include "ScreenIrritate.h"
#include "RoundStatic.h"
// CTestDialog 对话框

#include "MyMessage.h"


#define TEST_DLG_W 252
#define TEST_DLG_H 550

class CTestDialog : public CDialogEx, public MemDcWnd
{
	DECLARE_DYNAMIC(CTestDialog)

public:
	CTestDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTestDialog();

// 对话框数据
	enum { IDD = IDD_TEST_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void UIInit();

private:
	void CloseAllDialog();
	
private:
	CTestLogDialog m_testLogDlg;
	CScreenIrritate m_screenIrritate;
	CQuestionDialog m_queDlg;
	CMyListCtrl m_listNotCompleteTask;
	CMyListCtrl m_listCompleteTask;
	CMyListCtrl m_listDevice;
	CMyListCtrl m_listExperi;
	CMyButton m_btnMin;
	CMyButton m_btnClose;
	CRoundStatic m_staticPhoto;
	CMyButton m_btnReturnTest;
	CMyButton m_btnFeel;
	CImageList *m_pImgTask;

	//控件
	
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnWndFileTreeViewDoubleClicked(NMHDR *pNMHDR, LRESULT *pResult);
	LRESULT OnShowTaskDlg(WPARAM wParam, LPARAM lParam);
	LRESULT OnShowExperiDlg(WPARAM wParam, LPARAM lParam);

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnBnClickedButtonMin();

	afx_msg void OnBnClickedButtonFeel();

private:
	void InitChildDlg();
public:
	afx_msg void OnBnClickedButtonReturnTest();

};
