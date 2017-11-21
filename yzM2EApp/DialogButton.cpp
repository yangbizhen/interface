// DialogButton.cpp : 实现文件
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "DialogButton.h"


// CDialogButton

IMPLEMENT_DYNAMIC(CDialogButton, CButton)

CDialogButton::CDialogButton()
{

}

CDialogButton::~CDialogButton()
{
}


BEGIN_MESSAGE_MAP(CDialogButton, CButton)
END_MESSAGE_MAP()

void CDialogButton::SetImagePath(CString strImagePath, CString strImageParentPath)
{
	m_strImgPath = strImagePath;
	m_strImgParentPath = strImageParentPath;
}

bool CDialogButton::InitBtn(int x, int y, int w, int h, bool isPng)
{
	HRESULT hr = 0;
	if (m_strImgPath.IsEmpty()){
		return false;
	}
	hr = m_imgBtn.Load(m_strImgPath);
	if (FAILED(hr)){
		return false;
	}
	if (isPng)
	{
		if (m_imgBtn.GetBPP() == 32)
		{
			int i = 0;
			int j = 0;
			for (i = 0; i < m_imgBtn.GetWidth(); i++)
			{
				for (j = 0; j < m_imgBtn.GetHeight(); j++)
				{
					byte * pbyte = (byte *)m_imgBtn.GetPixelAddress(i, j);
					pbyte[0] = pbyte[0] * pbyte[3] / 255;
					pbyte[1] = pbyte[1] * pbyte[3] / 255;
					pbyte[2] = pbyte[2] * pbyte[3] / 255;
				}
			}
		}
	}
	MoveWindow(x, y, w, h);
	return true;
}

void CDialogButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	if (!lpDrawItemStruct){
		return;
	}
	HDC hMemDc;
	HBITMAP bmpMem;
	HGDIOBJ hOldObj;
	int w = lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left;
	int h = lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top;
	bmpMem = CreateCompatibleBitmap(lpDrawItemStruct->hDC, w,h);
	hMemDc = CreateCompatibleDC(lpDrawItemStruct->hDC);
	hOldObj = ::SelectObject(hMemDc, bmpMem);
	RECT rectTmp = lpDrawItemStruct->rcItem;
	MapWindowPoints(GetParent(), &rectTmp);
	if (lpDrawItemStruct->itemState & ODS_SELECTED){
		m_imgBtn.BitBlt(hMemDc, 0, 0, w, h, w*2 , 0, SRCCOPY);
	}
	else if (lpDrawItemStruct->itemState & ODS_FOCUS){
		m_imgBtn.BitBlt(hMemDc, 0, 0, w, h, w , 0, SRCCOPY);
	}
	else
	{
		CImage imgParent;
		imgParent.Load(m_strImgParentPath);
		imgParent.Draw(hMemDc, 0, 0, w, h, rectTmp.left, rectTmp.top, w, h);
		//m_imgBtn.AlphaBlend(hMemDc, 0, 0, w, h, 0, 0, w, h);
		m_imgBtn.BitBlt(hMemDc, 0, 0, w, h, w, 0, SRCCOPY);
		imgParent.Destroy();
	}
	::BitBlt(lpDrawItemStruct->hDC, 0, 0, w, h, hMemDc, 0, 0, SRCCOPY);

	SelectObject(hMemDc, hOldObj);
	
	::DeleteObject(bmpMem);
	bmpMem = NULL;

	::DeleteDC(hMemDc);
	hMemDc = NULL;
	return;
}



// CDialogButton 消息处理程序


