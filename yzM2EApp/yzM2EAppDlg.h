
// yzM2EAppDlg.h : ͷ�ļ�
//

#pragma once
#include "MemDcWnd.h"
#include <gdiplus.h>
#include "TestDialog.h"
#include "RoundStatic.h"
// CyzM2EDlg �Ի���
class CyzM2EDlg : public CDialogEx, public MemDcWnd
{
// ����
public:
	CyzM2EDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CyzM2EDlg();
// �Ի�������
	enum { IDD = IDD_YZM2EAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
