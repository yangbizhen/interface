#pragma once


// CMyButton

class CMyButton : public CButton
{
	DECLARE_DYNAMIC(CMyButton)

public:
	CMyButton();
	virtual ~CMyButton();

	//���ð�ť����ͼƬ·���������ڱ���ͼƬ·��  
	void SetBtn(CString strImgPath, int nX/*���Ͻ�X����*/, int nY/*���Ͻ�Y����*/, int nW/*ͼ���*/, int nH/*ͼ���*/, bool bIsPng = false/*�Ƿ���PNGͼƬ*/);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
protected:
	DECLARE_MESSAGE_MAP()
private:
	void SetImagePath(CString strImgPath);
	//��ʼ����ť����Ҫ�ǵ�����ť��λ�ã�����͸��ɫ  
	bool InitMyButton(int nX/*���Ͻ�X����*/, int nY/*���Ͻ�Y����*/, int nW/*ͼ���*/, int nH/*ͼ���*/, bool bIsPng = true/*�Ƿ���PNGͼƬ*/);
	//�Ի��ƺ��� 
private:
	//��ť����ͼ��  
	CImage m_imgButton;
	//��ťpng·�����������㣬����������3��״̬  
	CString m_strImgPath;
};


