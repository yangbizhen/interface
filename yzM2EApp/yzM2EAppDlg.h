
// yzM2EAppDlg.h : 头文件
//

#pragma once
#include "MemDcWnd.h"
#include <gdiplus.h>
#include "TestDialog.h"
#include "RoundStatic.h"
// CyzM2EDlg 对话框
class CyzM2EDlg : public CDialogEx, public MemDcWnd
{
// 构造
public:
	CyzM2EDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CyzM2EDlg();
// 对话框数据
	enum { IDD = IDD_YZM2EAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg LRESULT OnNcHitTest(CPoint point);

};
