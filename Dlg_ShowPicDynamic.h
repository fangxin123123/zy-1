#if !defined(AFX_DLG_SHOWPICDYNAMIC_H__F9980A4B_9A5A_4A42_AA4F_CEC39EBE4D35__INCLUDED_)
#define AFX_DLG_SHOWPICDYNAMIC_H__F9980A4B_9A5A_4A42_AA4F_CEC39EBE4D35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_ShowPicDynamic.h : header file
//
#include "Dlg_ShowPicDynamic.h"
#include "Dlg_ShowPicStatic.h"

/////////////////////////////////////////////////////////////////////////////
// CDlg_ShowPicDynamic dialog

class CDlg_ShowPicDynamic : public CDialog
{
// Construction
public:
	CDlg_ShowPicDynamic(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_ShowPicDynamic)
	enum { IDD = IDD_Dlg_ShowPicDynamic };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_ShowPicDynamic)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_ShowPicDynamic)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_SHOWPICDYNAMIC_H__F9980A4B_9A5A_4A42_AA4F_CEC39EBE4D35__INCLUDED_)
