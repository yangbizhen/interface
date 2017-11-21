#pragma once


// CDialogButton

class CDialogButton : public CButton
{
	DECLARE_DYNAMIC(CDialogButton)

public:
	CDialogButton();
	virtual ~CDialogButton();

	void SetImagePath(CString strImagePath, CString strImageParentPath);
	bool InitBtn(int x, int y, int w, int h, bool isPng);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

protected:
	DECLARE_MESSAGE_MAP()
private:
	CImage m_imgBtn;
	CString m_strImgPath;
	CString m_strImgParentPath;
};


