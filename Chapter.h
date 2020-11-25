// Chapter.h : main header file for the CHAPTER application
//

#if !defined(AFX_CHAPTER_H__0E509F67_1C23_467E_ABFE_566AB9323BC5__INCLUDED_)
#define AFX_CHAPTER_H__0E509F67_1C23_467E_ABFE_566AB9323BC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CChapterApp:
// See Chapter.cpp for the implementation of this class
//

class CChapterApp : public CWinApp
{
public:
	CChapterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChapterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CChapterApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHAPTER_H__0E509F67_1C23_467E_ABFE_566AB9323BC5__INCLUDED_)
