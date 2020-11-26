// JiQiRenXunJian.h : main header file for the JIQIRENXUNJIAN application
//

#if !defined(AFX_JIQIRENXUNJIAN_H__1DAB565E_7FD2_4837_AD98_1375B4DDA7D6__INCLUDED_)
#define AFX_JIQIRENXUNJIAN_H__1DAB565E_7FD2_4837_AD98_1375B4DDA7D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CJiQiRenXunJianApp:
// See JiQiRenXunJian.cpp for the implementation of this class
//

class CJiQiRenXunJianApp : public CWinApp
{
public:
	CJiQiRenXunJianApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJiQiRenXunJianApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CJiQiRenXunJianApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIQIRENXUNJIAN_H__1DAB565E_7FD2_4837_AD98_1375B4DDA7D6__INCLUDED_)
