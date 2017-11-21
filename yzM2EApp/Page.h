#pragma once


// CPage �Ի���

class CPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CPage)

public:
	CPage();
	virtual ~CPage();

// �Ի�������
	enum { IDD = IDD_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	void SetEndPage();
	void SetBeginPage();
private:
	bool m_isEndPage;
	bool m_isBeginPage;
};
