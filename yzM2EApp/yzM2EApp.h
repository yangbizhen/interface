
// yzM2EApp.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CyzM2E: 
// �йش����ʵ�֣������ yzM2EApp.cpp
//

class CyzM2E : public CWinApp
{
public:
	CyzM2E();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CyzM2E theApp;