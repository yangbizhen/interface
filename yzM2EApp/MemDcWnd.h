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
	CRect m_clientRt;			//�ͻ�����
	CDC* m_pClientDC;			//�ͻ���DC
	string m_resPath;			//��Դ·��
	string m_bkImgName;			//���ڱ���ͼƬ
	int m_clientX;			//���ڵĿ��
	int m_clientY;			//���ڵĸ߶�
	int m_clientW;			//���ڵĿ��
	int m_clientH;			//���ڵĸ߶�

	//ʹ��GDI+
	GdiplusStartupInput m_gdiplusStartupInput; 
	ULONG_PTR m_pGdiToken;
};

#endif // _MEMDCWND_H_

