#pragma once

#include "MyButton.h"
#include "MemDcWnd.h"
// CScreenIrritate 对话框

class CScreenIrritate : public CDialogEx, public MemDcWnd
{
	DECLARE_DYNAMIC(CScreenIrritate)

public:
	CScreenIrritate(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CScreenIrritate();

// 对话框数据
	enum { IDD = IDD_DIALOG_SCREEN_IRRITATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	CMyButton m_btnStratIrrtate;

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	void UIInit();

private:
	CMyButton m_cancel;
	CMyButton m_btnStartIrrtate;
public:
	afx_msg LRESULT OnNcHitTest(CPoint point);
};
