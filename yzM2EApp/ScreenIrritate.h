#pragma once

#include "MyButton.h"
#include "MemDcWnd.h"
// CScreenIrritate �Ի���

class CScreenIrritate : public CDialogEx, public MemDcWnd
{
	DECLARE_DYNAMIC(CScreenIrritate)

public:
	CScreenIrritate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CScreenIrritate();

// �Ի�������
	enum { IDD = IDD_DIALOG_SCREEN_IRRITATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
