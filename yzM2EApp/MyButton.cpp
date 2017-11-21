// MyButton.cpp : 实现文件
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "MyButton.h"


// CMyButton

IMPLEMENT_DYNAMIC(CMyButton, CWnd)

CMyButton::CMyButton()
{

}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CWnd)
END_MESSAGE_MAP()

void CMyButton::SetImagePath(CString strImgPath)
{
	m_strImgPath = strImgPath;
}

bool CMyButton::InitMyButton(int nX/*左上角X坐标*/, int nY/*左上角Y坐标*/, int nW/*图像宽*/, int nH/*图像高*/, bool bIsPng/*是否是PNG图片*/)
{
	HRESULT hr = 0;
	if (m_strImgPath.IsEmpty())
		return false;
	hr = m_imgButton.Load(m_strImgPath);

	if (FAILED(hr))
		return false;
	if (bIsPng)
	{
		if (m_imgButton.GetBPP() == 32)
		{
			int i = 0;
			int j = 0;
			for (i = 0; i < m_imgButton.GetWidth(); i++)
			{
				for (j = 0; j < m_imgButton.GetHeight(); j++)
				{
					byte * pbyte = (byte *)m_imgButton.GetPixelAddress(i, j);
					pbyte[0] = pbyte[0] * pbyte[3] / 255;
					pbyte[1] = pbyte[1] * pbyte[3] / 255;
					pbyte[2] = pbyte[2] * pbyte[3] / 255;
				}
			}
		}
	}
	MoveWindow(nX, nY, nW, nH);

	return true;
}

void CMyButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	if (!lpDrawItemStruct)
		return;
	HDC hMemDC;
	HBITMAP bmpMem;
	HGDIOBJ hOldObj;
	bmpMem = CreateCompatibleBitmap(lpDrawItemStruct->hDC, lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left, lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top);
	if (!bmpMem)
		return;
	hMemDC = CreateCompatibleDC(lpDrawItemStruct->hDC);
	if (!hMemDC)
	{
		if (bmpMem)
		{
			::DeleteObject(bmpMem);
			bmpMem = NULL;
		}
		return;
	}

	hOldObj = ::SelectObject(hMemDC, bmpMem);

	RECT rectTmp = { 0 };

	rectTmp = lpDrawItemStruct->rcItem;

	MapWindowPoints(GetParent(), &rectTmp);

	int nW = lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left;

	int nH = lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top;

	

		//默认状态  
		CImage imgParent;

		imgParent.Load(m_strImgPath);

		imgParent.Draw(hMemDC, 0, 0, nW, nH, rectTmp.left, rectTmp.top, nW, nH);

		m_imgButton.AlphaBlend(hMemDC, 0, 0, nW, nH, 0, 0, nW, nH);

		imgParent.Destroy();

	


	::BitBlt(lpDrawItemStruct->hDC, 0, 0, nW, nH, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, hOldObj);

	if (bmpMem)
	{
		::DeleteObject(bmpMem);
		bmpMem = NULL;
	}

	if (hMemDC)
	{
		::DeleteDC(hMemDC);
		hMemDC = NULL;
	}
	return;
}

void CMyButton::SetBtn(CString strImgPath, int nX/*左上角X坐标*/, int nY/*左上角Y坐标*/, int nW/*图像宽*/, int nH/*图像高*/, bool bIsPng /*= false/*是否是PNG图片*/)
{
	SetImagePath(strImgPath);
	InitMyButton(nX, nY, nW, nH);
}



// CMyButton 消息处理程序


