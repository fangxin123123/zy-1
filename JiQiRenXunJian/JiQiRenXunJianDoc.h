// JiQiRenXunJianDoc.h : interface of the CJiQiRenXunJianDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JIQIRENXUNJIANDOC_H__C8FC71C7_B2AC_4241_9CD5_96C704D4460B__INCLUDED_)
#define AFX_JIQIRENXUNJIANDOC_H__C8FC71C7_B2AC_4241_9CD5_96C704D4460B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CJiQiRenXunJianDoc : public CDocument
{
protected: // create from serialization only
	CJiQiRenXunJianDoc();
	DECLARE_DYNCREATE(CJiQiRenXunJianDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJiQiRenXunJianDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CJiQiRenXunJianDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJiQiRenXunJianDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIQIRENXUNJIANDOC_H__C8FC71C7_B2AC_4241_9CD5_96C704D4460B__INCLUDED_)
