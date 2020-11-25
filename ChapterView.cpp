// ChapterView.cpp : implementation of the CChapterView class
//

#include "stdafx.h"
#include "Chapter.h"

#include "ChapterDoc.h"
#include "ChapterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChapterView

IMPLEMENT_DYNCREATE(CChapterView, CView)

BEGIN_MESSAGE_MAP(CChapterView, CView)
	//{{AFX_MSG_MAP(CChapterView)
	ON_COMMAND(ID_M_ShowPicStatic, OnMShowPicStatic)
	ON_COMMAND(ID_M_ShowPicDynamic, OnMShowPicDynamic)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChapterView construction/destruction

CChapterView::CChapterView()
{
	// TODO: add construction code here

}

CChapterView::~CChapterView()
{
}

BOOL CChapterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CChapterView drawing

void CChapterView::OnDraw(CDC* pDC)
{
	CChapterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CChapterView printing

BOOL CChapterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CChapterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CChapterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CChapterView diagnostics

#ifdef _DEBUG
void CChapterView::AssertValid() const
{
	CView::AssertValid();
}

void CChapterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChapterDoc* CChapterView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChapterDoc)));
	return (CChapterDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChapterView message handlers

void CChapterView::OnMShowPicStatic() 
{
	// TODO: Add your command handler code here
	CDlg_ShowPicStatic dlg_ShowPicStatic;
	dlg_ShowPicStatic.DoModal();

	
}

void CChapterView::OnMShowPicDynamic() 
{
	// TODO: Add your command handler code here
	CDlg_ShowPicDynamic dlg_ShowPicDynamic;
	dlg_ShowPicDynamic.DoModal();
	
}
