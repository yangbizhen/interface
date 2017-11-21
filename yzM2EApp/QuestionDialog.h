#pragma once


// CQuestionDialog 对话框

class CQuestionDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CQuestionDialog)

public:
	CQuestionDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CQuestionDialog();

// 对话框数据
	enum { IDD = IDD_QUESTION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg LRESULT OnNcHitTest(CPoint point);
};
