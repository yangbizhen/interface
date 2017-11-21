#pragma once
#include "Page.h"
#include "Page2.h"


// CSheet

class CSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSheet)

public:
	CSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CSheet();

protected:
	DECLARE_MESSAGE_MAP()

public:
	void AddQuePages();
private:
	CPage pages[2];
};


