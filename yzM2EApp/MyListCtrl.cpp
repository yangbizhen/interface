// MyList.cpp : ʵ���ļ�
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
	//ModifyStyle(WS_HSCROLL , 0); //ȥ��ˮƽ����������ֱ������,��WM_NCCALCSIZE�е���
	//InitializeFlatSB(this->m_hWnd);    //����Windows���䴰�ڷ��Ĵ����ʱ,ModifyStyle�����ã�����Flat Scroll Api ����                                             
	//FlatSB_EnableScrollBar(this->m_hWnd, SB_VERT, ESB_DISABLE_RIGHT);
	LVITEM lvi = { 0 };
	lvi.mask = LVIF_STATE;//|LVIF_IMAGE; 
	lvi.stateMask = LVIS_FOCUSED | LVIS_SELECTED;
	lvi.iItem = lpMeasureItemStruct->itemID;
	BOOL bGet = GetItem(&lvi);
	//������ʾ
	BOOL bHighlight = ((lvi.state & LVIS_DROPHILITED) || ((lvi.state & LVIS_SELECTED) &&
		((GetFocus() == this) || (GetStyle() & LVS_SHOWSELALWAYS))));
	// ���ı����� 
	CRect rcBack = lpMeasureItemStruct->rcItem;
	pDC->SetBkMode(TRANSPARENT);

	if (bHighlight) //�����ѡ��
	{
		pDC->SetTextColor(RGB(255, 255, 255)); //�ı�Ϊ��ɫ
		pDC->FillRect(rcBack, &CBrush(RGB(15, 130, 216)/*RGB(179,183,181)*/));
	}
	else
	{
		pDC->SetTextColor(RGB(0, 0, 0));       //�ı�Ϊ��ɫ
		pDC->FillRect(rcBack, &CBrush(RGB(255, 255, 255)));
	}
	if (lpMeasureItemStruct->itemAction & ODA_DRAWENTIRE)
	{
		//д�ı� 
		CString szText;
		int nCollumn = GetHeaderCtrl()->GetItemCount();//����
		for (int i = 0; i < GetHeaderCtrl()->GetItemCount(); i++)
		{ //ѭ���õ��ı� 
			CRect rcItem;
			if (!GetSubItemRect(lpMeasureItemStruct->itemID, i, LVIR_LABEL, rcItem))
				continue;
			szText = GetItemText(lpMeasureItemStruct->itemID, i);
			rcItem.left += 10; rcItem.right -= 1;
			pDC->DrawText(szText, lstrlen(szText), &rcItem, DT_LEFT  | DT_VCENTER | DT_NOPREFIX | DT_SINGLELINE);
		}
	}
}




// CMyList ��Ϣ�������


void CMyListCtrl::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//ȥ��ˮƽ������,
	this->ModifyStyle(WS_HSCROLL , 0);
	CListCtrl::OnNcCalcSize(bCalcValidRects, lpncsp);
}

void CMyListCtrl::SetIcon(CString iconPath)
{
	m_listIcon = iconPath;
}

