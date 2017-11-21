#pragma once


// CPage 对话框

class CPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CPage)

public:
	CPage();
	virtual ~CPage();

// 对话框数据
	enum { IDD = IDD_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	void SetEndPage();
	void SetBeginPage();
private:
	bool m_isEndPage;
	bool m_isBeginPage;
};
