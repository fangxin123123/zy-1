// Dlg_ShowPicDynamic.cpp : implementation file
//

#include "stdafx.h"
#include "Chapter.h"
#include "Dlg_ShowPicDynamic.h"
#include "Dlg_ShowPicStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_ShowPicDynamic dialog


CDlg_ShowPicDynamic::CDlg_ShowPicDynamic(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_ShowPicDynamic::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_ShowPicDynamic)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_ShowPicDynamic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_ShowPicDynamic)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_ShowPicDynamic, CDialog)
	//{{AFX_MSG_MAP(CDlg_ShowPicDynamic)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_ShowPicDynamic message handlers

void CDlg_ShowPicDynamic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP3);
	BITMAP bmpinfo;
	bmp.GetBitmap(&bmpinfo);
	CDC memDc;
	memDc.CreateCompatibleDC(&dc);
	CBitmap * poldBitmap = memDc.SelectObject(&bmp);
	
	dc.StretchBlt(0,0,bmpinfo.bmWidth,bmpinfo.bmHeight,&memDc,0,0,bmpinfo.bmWidth,bmpinfo.bmHeight,SRCCOPY);

	memDc.SelectObject(poldBitmap);
	memDc.DeleteDC();
	
	// Do not call CDialog::OnPaint() for painting messages
}


