// JiQiRenXunJianView.h : interface of the CJiQiRenXunJianView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JIQIRENXUNJIANVIEW_H__36500BA7_A4A8_4619_8784_9AA2D2CC562D__INCLUDED_)
#define AFX_JIQIRENXUNJIANVIEW_H__36500BA7_A4A8_4619_8784_9AA2D2CC562D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DiTu.h"
#include "Car.h"
#include "WuRenJi.h"
#include "XieLou.h"

enum BiaoJi{CJKZ,CarZNDN,CarYSDMBD,CarALX,WRJZNDN,WRJALX,WRJYSDMBD,LIZI,CarCZXLD,WRJCZXLD};

class CJiQiRenXunJianView : public CView
{
protected: // create from serialization only
	CJiQiRenXunJianView();
	DECLARE_DYNCREATE(CJiQiRenXunJianView)

// Attributes
public:
	CJiQiRenXunJianDoc* GetDocument();
	CDiTu m_DT;
	CCar m_car;
	CWuRenJi m_WRJ;
	CXieLou m_XieLou;
	int m_BJ_LBD;
	CPoint m_P_LBD;
	CPoint m_TempYD; 
	int m_BJ;
	CString m_NDstr;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJiQiRenXunJianView)
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
	virtual ~CJiQiRenXunJianView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJiQiRenXunJianView)
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMCarZhiNaDaoNa();
	afx_msg void OnMCarYunSuDaoMuBiaoDian();
	afx_msg void OnMCarAnLuXian();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMWRJZhiNaDaoNa();
	afx_msg void OnMWRJYunSuDaoMuBiaoDian();
	afx_msg void OnMWRJAnLuXian();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMMeiQiKaiShi();
	afx_msg void OnMMeiQiZanTing();
	afx_msg void OnMCarChaZhaoXieLouDian();
	afx_msg void OnMWRJChaZhaoXieLouDian();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in JiQiRenXunJianView.cpp
inline CJiQiRenXunJianDoc* CJiQiRenXunJianView::GetDocument()
   { return (CJiQiRenXunJianDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIQIRENXUNJIANVIEW_H__36500BA7_A4A8_4619_8784_9AA2D2CC562D__INCLUDED_)
