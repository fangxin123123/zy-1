// ChapterDoc.h : interface of the CChapterDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHAPTERDOC_H__51123FDF_F728_4F70_BF5B_ECC56D31EB5C__INCLUDED_)
#define AFX_CHAPTERDOC_H__51123FDF_F728_4F70_BF5B_ECC56D31EB5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CChapterDoc : public CDocument
{
protected: // create from serialization only
	CChapterDoc();
	DECLARE_DYNCREATE(CChapterDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChapterDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChapterDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CChapterDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHAPTERDOC_H__51123FDF_F728_4F70_BF5B_ECC56D31EB5C__INCLUDED_)
