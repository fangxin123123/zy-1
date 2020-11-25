// ChapterDoc.cpp : implementation of the CChapterDoc class
//

#include "stdafx.h"
#include "Chapter.h"

#include "ChapterDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChapterDoc

IMPLEMENT_DYNCREATE(CChapterDoc, CDocument)

BEGIN_MESSAGE_MAP(CChapterDoc, CDocument)
	//{{AFX_MSG_MAP(CChapterDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChapterDoc construction/destruction

CChapterDoc::CChapterDoc()
{
	// TODO: add one-time construction code here

}

CChapterDoc::~CChapterDoc()
{
}

BOOL CChapterDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CChapterDoc serialization

void CChapterDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CChapterDoc diagnostics

#ifdef _DEBUG
void CChapterDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CChapterDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChapterDoc commands
