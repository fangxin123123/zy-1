// ChapterView.h : interface of the CChapterView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHAPTERVIEW_H__4E058092_F83E_4F3A_9430_308773ACD154__INCLUDED_)
#define AFX_CHAPTERVIEW_H__4E058092_F83E_4F3A_9430_308773ACD154__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Dlg_ShowPicDynamic.h"
#include "Dlg_ShowPicStatic.h"

class CChapterView : public CView
{
protected: // create from serialization only
	CChapterView();
	DECLARE_DYNCREATE(CChapterView)

// Attributes
public:
	CChapterDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChapterView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChapterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CChapterView)
	afx_msg void OnMShowPicStatic();
	afx_msg void OnMShowPicDynamic();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ChapterView.cpp
inline CChapterDoc* CChapterView::GetDocument()
   { return (CChapterDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHAPTERVIEW_H__4E058092_F83E_4F3A_9430_308773ACD154__INCLUDED_)
