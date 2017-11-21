#pragma once
#include <comdef.h>//初始化一下com口 
#ifndef ULONG_PTR 
#define ULONG_PTR unsigned long* 
#include "GdiPlus.h" 
using namespace Gdiplus; 
#endif 
#pragma comment(lib,"gdiplus.lib")

// CRoundStatic

class CRoundStatic : public CStatic
{
	DECLARE_DYNAMIC(CRoundStatic)

public:
	CRoundStatic();
	virtual ~CRoundStatic();

protected:
	Bitmap *m_pic;
	DECLARE_MESSAGE_MAP()

public:
	bool LoadFile(CString szDile);
	
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
};	


