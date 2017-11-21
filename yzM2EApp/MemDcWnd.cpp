#include "stdafx.h"
#include "MemDcWnd.h"
#include "boost.h"


MemDcWnd::MemDcWnd()
	:m_bkImgName("")
{
	m_clientW = 1000;
	m_clientH = 600;
	GdiplusStartup(&m_pGdiToken, &m_gdiplusStartupInput, NULL);
}


MemDcWnd::~MemDcWnd()
{
	GdiplusShutdown(m_pGdiToken);
}

void MemDcWnd::MDW_init(HWND hwnd, CDC* pClientDC, bool isMain/*=false*/)
{
	CRect rtDesk;
	CRect rtDlg;
	::GetWindowRect(::GetDesktopWindow(), &rtDesk);
	if (m_clientX == 0 && m_clientY == 0){
		if (isMain){
			m_clientX = rtDesk.Width() / 10*9 - m_clientW / 2;
		}
		else
		{
			m_clientX = rtDesk.Width() / 2 - m_clientW / 2;
		}
		m_clientY = rtDesk.Height() / 2 - m_clientH / 2;
		
	}
	
	::MoveWindow(hwnd, m_clientX, m_clientY, m_clientW, m_clientH, true);
	m_pClientDC = pClientDC;
	::GetClientRect(hwnd, m_clientRt);

}


//string_until
wchar_t* AnsiToUnicode(const char* szStr)
{
	int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szStr, -1, NULL, 0);
	if (nLen == 0)
	{
		return NULL;
	}
	wchar_t* pResult = new wchar_t[nLen];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szStr, -1, pResult, nLen);
	return pResult;
}

void MemDcWnd::MDW_paint(CPaintDC* paintDc)
{
	if (m_bkImgName.empty())
	{
		paintDc->FillSolidRect(m_clientRt, RGB(255, 255, 255));
	}
	else
	{
		Graphics  graphics(paintDc->m_hDC);
		ImageAttributes  imAtt;
		imAtt.SetWrapMode(WrapModeTile);    //À­ÉìÍ¼Æ¬
		string bkPath = RESOURCE_PATH + m_bkImgName;
		Bitmap  backgroundtop(AnsiToUnicode(bkPath.c_str()));   //¼ÓÔØPNGÍ¼Æ¬
		graphics.DrawImage(&backgroundtop, Rect(0, 0, m_clientW, m_clientH),
			0, 0, backgroundtop.GetWidth(), backgroundtop.GetHeight(), UnitPixel, &imAtt);
	}
	
}

void MemDcWnd::MDW_setBkImgName(string bkImgName)
{
	this->m_bkImgName = bkImgName;
}

void MemDcWnd::MDW_setSize(int w, int h, int x/*=0*/, int y/*=0*/)
{
	m_clientW = w;
	m_clientH = h;
	m_clientX = x;
	m_clientY = y;
}
