#pragma once


// CQuestionDialog �Ի���

class CQuestionDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CQuestionDialog)

public:
	CQuestionDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CQuestionDialog();

// �Ի�������
	enum { IDD = IDD_QUESTION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg LRESULT OnNcHitTest(CPoint point);
};
