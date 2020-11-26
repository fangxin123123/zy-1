// JiQiRenXunJianDoc.cpp : implementation of the CJiQiRenXunJianDoc class
//

#include "stdafx.h"
#include "JiQiRenXunJian.h"

#include "JiQiRenXunJianDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJiQiRenXunJianDoc

IMPLEMENT_DYNCREATE(CJiQiRenXunJianDoc, CDocument)

BEGIN_MESSAGE_MAP(CJiQiRenXunJianDoc, CDocument)
	//{{AFX_MSG_MAP(CJiQiRenXunJianDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJiQiRenXunJianDoc construction/destruction

CJiQiRenXunJianDoc::CJiQiRenXunJianDoc()
{
	// TODO: add one-time construction code here

}

CJiQiRenXunJianDoc::~CJiQiRenXunJianDoc()
{
}

BOOL CJiQiRenXunJianDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CJiQiRenXunJianDoc serialization

void CJiQiRenXunJianDoc::Serialize(CArchive& ar)
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
// CJiQiRenXunJianDoc diagnostics

#ifdef _DEBUG
void CJiQiRenXunJianDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CJiQiRenXunJianDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJiQiRenXunJianDoc commands
