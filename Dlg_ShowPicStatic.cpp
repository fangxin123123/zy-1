// Dlg_ShowPicStatic.cpp : implementation file
//

#include "stdafx.h"
#include "Chapter.h"
#include "Dlg_ShowPicStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_ShowPicStatic dialog


CDlg_ShowPicStatic::CDlg_ShowPicStatic(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_ShowPicStatic::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_ShowPicStatic)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_ShowPicStatic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_ShowPicStatic)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_ShowPicStatic, CDialog)
	//{{AFX_MSG_MAP(CDlg_ShowPicStatic)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_ShowPicStatic message handlers
