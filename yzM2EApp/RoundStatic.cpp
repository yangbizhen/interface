// RoundStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RoundStatic.h"


// CRoundStatic

IMPLEMENT_DYNAMIC(CRoundStatic, CStatic)
CRoundStatic::CRoundStatic()
{
	m_pic=0;
}

CRoundStatic::~CRoundStatic()
{
}


BEGIN_MESSAGE_MAP(CRoundStatic, CStatic)
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CRoundStatic ��Ϣ�������


BOOL CRoundStatic::OnEraseBkgnd(CDC* pDC)
{
	if(m_pic)
	{
		CRect rect;
		GetWindowRect(&rect);//<-----******
		Graphics go(pDC->m_hDC);
		go.DrawImage(m_pic, 0,0, rect.Width(), rect.Height());
		return 0;
	}

	return CStatic::OnEraseBkgnd(pDC);
}

bool CRoundStatic::LoadFile(CString szDile)
{
	if(m_pic)
	{
		::delete m_pic;
		m_pic=0;
	}
	CString file=szDile;
	Image image(L".///resource//photo.png");
	m_pic=::new Bitmap(image.GetWidth(),image.GetHeight());
	Graphics g(m_pic);
	g.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality); 
	GraphicsPath p(FillModeAlternate);
	p.AddEllipse(0, 0, image.GetWidth(), image.GetHeight());
	g.FillPath(&TextureBrush(&image), &p);
	this->Invalidate();
	return true;

}


void CRoundStatic::OnDestroy()
{
	if(m_pic)
	{
		::delete m_pic;
		m_pic=0;
	}
	CStatic::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
}

void CRoundStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()
}
