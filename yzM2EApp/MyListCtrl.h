#pragma once
#include "afxcmn.h"
#include "MyMessage.h"
#include <iostream>
using namespace std;
// CMyListCtrl

class CMyListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CMyListCtrl)

public:
	CMyListCtrl();
	virtual ~CMyListCtrl();
	void SetRowHeigt(int nHeight);
	void SetListName(string name);
	
protected:
	DECLARE_MESSAGE_MAP()

	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	void DrawItem(LPDRAWITEMSTRUCT lpMeasureItemStruct);
	void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	
	
private:
	int m_nRowHeight;
	string m_ListName;
	string m_item;
	CString m_listIcon;
public:
	afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
	void SetIcon(CString iconPath);
};


