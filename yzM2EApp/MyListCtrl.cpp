// MyList.cpp : 实现文件
//

#include "stdafx.h"
#include "yzM2EApp.h"
#include "MyListCtrl.h"
#include "MemDcWnd.h"
// CMyList

IMPLEMENT_DYNAMIC(CMyListCtrl, CListCtrl)

CMyListCtrl::CMyListCtrl()
	:m_listIcon("")
{

}

CMyListCtrl::~CMyListCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyListCtrl, CListCtrl)
	ON_WM_MEASUREITEM_REFLECT()
	ON_WM_MEASUREITEM()
	ON_WM_DRAWITEM()
	ON_NOTIFY_REFLECT(NM_DBLCLK, &CMyListCtrl::OnNMDblclk)
	ON_WM_NCCALCSIZE()
END_MESSAGE_MAP()

void CMyListCtrl::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	if (m_nRowHeight > 0)
	{
		lpMeasureItemStruct->itemHeight = m_nRowHeight;
		lpMeasureItemStruct->itemWidth = 100;
	}
}

void CMyListCtrl::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	CListCtrl::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}

void CMyListCtrl::SetRowHeigt(int nHeight)
{
	m_nRowHeight = nHeight;
	CRect rcWin;
	GetWindowRect(&rcWin);
	WINDOWPOS wp;
	wp.hwnd = m_hWnd;
	wp.cx = rcWin.Width();
	wp.cy = rcWin.Height();
	wp.flags = SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER;
	SendMessage(WM_WINDOWPOSCHANGED, 0, (LPARAM)&wp);
}



void CMyListCtrl::DrawItem(LPDRAWITEMSTRUCT lpMeasureItemStruct)
{
	CDC* pDC = CDC::FromHandle(lpMeasureItemStruct->hDC);
	//ModifyStyle(WS_HSCROLL , 0); //去掉水平滚动条和竖直滚动条,在WM_NCCALCSIZE中调用
	//InitializeFlatSB(this->m_hWnd);    //链接Windows经典窗口风格的代码库时,ModifyStyle不能用，需用Flat Scroll Api 隐藏                                             
	//FlatSB_EnableScrollBar(this->m_hWnd, SB_VERT, ESB_DISABLE_RIGHT);
	LVITEM lvi = { 0 };
	lvi.mask = LVIF_STATE;//|LVIF_IMAGE; 
	lvi.stateMask = LVIS_FOCUSED | LVIS_SELECTED;
	lvi.iItem = lpMeasureItemStruct->itemID;
	BOOL bGet = GetItem(&lvi);
	//高亮显示
	BOOL bHighlight = ((lvi.state & LVIS_DROPHILITED) || ((lvi.state & LVIS_SELECTED) &&
		((GetFocus() == this) || (GetStyle() & LVS_SHOWSELALWAYS))));
	// 画文本背景 
	CRect rcBack = lpMeasureItemStruct->rcItem;
	pDC->SetBkMode(TRANSPARENT);

	if (bHighlight) //如果被选中
	{
		pDC->SetTextColor(RGB(255, 255, 255)); //文本为白色
		pDC->FillRect(rcBack, &CBrush(RGB(15, 130, 216)/*RGB(179,183,181)*/));
	}
	else
	{
		pDC->SetTextColor(RGB(0, 0, 0));       //文本为黑色
		pDC->FillRect(rcBack, &CBrush(RGB(255, 255, 255)));
	}
	if (lpMeasureItemStruct->itemAction & ODA_DRAWENTIRE)
	{
		//写文本 
		CString szText;
		int nCollumn = GetHeaderCtrl()->GetItemCount();//列数
		for (int i = 0; i < GetHeaderCtrl()->GetItemCount(); i++)
		{ //循环得到文本 
			CRect rcItem;
			if (!GetSubItemRect(lpMeasureItemStruct->itemID, i, LVIR_LABEL, rcItem))
				continue;
			szText = GetItemText(lpMeasureItemStruct->itemID, i);
			rcItem.left += 10; rcItem.right -= 1;
			pDC->DrawText(szText, lstrlen(szText), &rcItem, DT_LEFT  | DT_VCENTER | DT_NOPREFIX | DT_SINGLELINE);
		}
	}
}




// CMyList 消息处理程序


void CMyListCtrl::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;

	if (-1 != pNMListView->iItem)
	{
		m_item = GetItemText(pNMListView->iItem, 0);
		HWND p = GetParent()->GetSafeHwnd();
		::PostMessage(GetParent()->GetSafeHwnd(), WM_SHOW_EXPERI_DLG_MESSAGE, (WPARAM)m_item.c_str(), 0);
	}
	*pResult = 0;
}

void CMyListCtrl::SetListName(string name)
{
	m_ListName = name;
}


void CMyListCtrl::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//去掉水平滚动条,
	this->ModifyStyle(WS_HSCROLL , 0);
	CListCtrl::OnNcCalcSize(bCalcValidRects, lpncsp);
}

void CMyListCtrl::SetIcon(CString iconPath)
{
	m_listIcon = iconPath;
}

