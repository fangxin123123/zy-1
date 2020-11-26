// WuRenJi.h: interface for the CWuRenJi class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WURENJI_H__3F415E20_0AE1_4FC9_9C42_F7A97B100121__INCLUDED_)
#define AFX_WURENJI_H__3F415E20_0AE1_4FC9_9C42_F7A97B100121__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Car.h"

class CWuRenJi : public CCar  
{
public:
	void DrawWaiXing();
	void Draw(CDC *p);
	CWuRenJi();
	virtual ~CWuRenJi();

};

#endif // !defined(AFX_WURENJI_H__3F415E20_0AE1_4FC9_9C42_F7A97B100121__INCLUDED_)
