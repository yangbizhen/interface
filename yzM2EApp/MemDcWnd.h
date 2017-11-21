#pragma once
#ifndef _MEMDCWND_H_
#define _MEMDCWND_H_
#include <iostream>
#pragma comment(lib,"gdiplus.lib")
using namespace Gdiplus;
using namespace  std;
#define RESOURCE_PATH "./resource/"
class MemDcWnd
{
public:
	MemDcWnd();
	~MemDcWnd();
	virtual void MDW_init(HWND hwnd, CDC* pClientDC, bool isMain=false);
	virtual void MDW_paint(CPaintDC* paintDc);
	void MDW_setBkImgName(string bkImgName);
	void MDW_setSize(int w, int h, int x=0, int y=0);
protected:
	CRect m_clientRt;			//客户区域
	CDC* m_pClientDC;			//客户区DC
	string m_resPath;			//资源路径
	string m_bkImgName;			//窗口背景图片
	int m_clientX;			//窗口的宽度
	int m_clientY;			//窗口的高度
	int m_clientW;			//窗口的宽度
	int m_clientH;			//窗口的高度

	//使用GDI+
	GdiplusStartupInput m_gdiplusStartupInput; 
	ULONG_PTR m_pGdiToken;
};

#endif // _MEMDCWND_H_

