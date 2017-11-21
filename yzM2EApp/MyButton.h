#pragma once


// CMyButton

class CMyButton : public CButton
{
	DECLARE_DYNAMIC(CMyButton)

public:
	CMyButton();
	virtual ~CMyButton();

	//设置按钮背景图片路径，父窗口背景图片路径  
	void SetBtn(CString strImgPath, int nX/*左上角X坐标*/, int nY/*左上角Y坐标*/, int nW/*图像宽*/, int nH/*图像高*/, bool bIsPng = false/*是否是PNG图片*/);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
protected:
	DECLARE_MESSAGE_MAP()
private:
	void SetImagePath(CString strImgPath);
	//初始化按钮，主要是调整按钮的位置，处理透明色  
	bool InitMyButton(int nX/*左上角X坐标*/, int nY/*左上角Y坐标*/, int nW/*图像宽*/, int nH/*图像高*/, bool bIsPng = true/*是否是PNG图片*/);
	//自绘制函数 
private:
	//按钮背景图像  
	CImage m_imgButton;
	//按钮png路径，包括焦点，正常，按下3个状态  
	CString m_strImgPath;
};


