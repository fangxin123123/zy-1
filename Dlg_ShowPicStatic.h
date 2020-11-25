#if !defined(AFX_DLG_SHOWPICSTATIC_H__197BBF8F_C3ED_40BE_B768_7D772C17BE6C__INCLUDED_)
#define AFX_DLG_SHOWPICSTATIC_H__197BBF8F_C3ED_40BE_B768_7D772C17BE6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_ShowPicStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_ShowPicStatic dialog

class CDlg_ShowPicStatic : public CDialog
{
// Construction
public:
	CDlg_ShowPicStatic(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_ShowPicStatic)
	enum { IDD = IDD_Dlg_ShowPicStatic };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_ShowPicStatic)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_ShowPicStatic)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_SHOWPICSTATIC_H__197BBF8F_C3ED_40BE_B768_7D772C17BE6C__INCLUDED_)
