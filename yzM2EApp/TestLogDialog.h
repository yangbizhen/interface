#pragma once
#include "MemDcWnd.h"
#include "opencv2/opencv.hpp"
#include "MyButton.h"
#include "DLEdit.h"
using namespace cv;


// CTaskDialog 对话框

class CTestLogDialog : public CDialogEx,public MemDcWnd
{
	DECLARE_DYNAMIC(CTestLogDialog)

public:
	CTestLogDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTestLogDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_TASK_LOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	void SetTitle(CString title);

private: 
	void UIInit();


	
private:
	CRect m_rect;
	HDC m_hDC;
	CString m_strTitle;
	CvCapture *m_pCapture;
	CMyButton m_btnRecord;
	CMyButton m_btnStop;
	CDateTimeCtrl m_dataTimeCtrl;

	//控件
	CStatic m_staticTitle;
	CStatic m_picCamera;
	CButton m_ok;
	CMyButton m_btnClose;
	CButton m_openCamera;
	CDLEdit m_editFeel;
	CMyButton m_btnSubmit;
	
public:
	afx_msg void OnBnClickedOpenCamera();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedCancel();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	void OnCloseCamera();
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnBnClickedButtonRecord();
};
