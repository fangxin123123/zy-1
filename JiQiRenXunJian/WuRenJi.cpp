// WuRenJi.cpp: implementation of the CWuRenJi class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JiQiRenXunJian.h"
#include "WuRenJi.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWuRenJi::CWuRenJi()
{
	m_x = -200;
	m_y = -50;
	m_v = 10;
	m_vx = 0;
	m_vy = 0;
	
	m_H = 30;
	m_L = 5;
	m_r = 20;
	
	m_YD.x = 750;
	m_YD.y = 350;

	m_LCZ[0].x = m_x;
	m_LCZ[0].y = m_y;

}

CWuRenJi::~CWuRenJi()
{

}

void CWuRenJi::Draw(CDC *p)
{
	pDC=p;
	int x,y,r;
	CString str;

	DrawWaiXing();
    CPen cPen,cPen1;
	cPen1.CreatePen(PS_SOLID,2,RGB(146,255,237)) ;
	pDC->SelectObject(&cPen1);
	DrawLuXian();

//	str.Format("无人机最小浓度:%d,最大浓度:%d",m_CirGJ.ndMin,m_CirGJ.ndMax);
    str.Format("无人机当前坐标:%.2f,%.2f",m_x,m_y);
	pDC->TextOut(1250,50,str);
	cPen.CreatePen(PS_SOLID,1,RGB(139,0,139));
	pDC->SelectObject(&cPen);

	x = m_YD.x + m_CirGJ.ndMinPosx*m_kx;
	y = m_YD.y + m_CirGJ.ndMinPosy*m_ky;
	r = 8;
	pDC->Ellipse(x-r,y-r,x+r,y+r);

	x = m_YD.x + m_CirGJ.ndMaxPosx*m_kx;
	y = m_YD.y + m_CirGJ.ndMaxPosy*m_ky;
	r = 12;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	
	str.Format("无人机查找泄露的时间为:%.2f",m_t);
	pDC->TextOut(1250,90,str);

}

void CWuRenJi::DrawWaiXing()
{
	int x,y,r;
	CPen cPen;
	cPen.CreatePen(PS_SOLID,2,RGB(5,255,0)) ;
	pDC->SelectObject(&cPen);
	x = m_YD.x + m_x *m_kx;
	y = m_YD.y + m_y *m_ky;
	r = m_r*m_kx;

	pDC->Ellipse(x -r,y-r,x+r,y+r);

	x = x- m_H*m_kx ;
	pDC->MoveTo(x,y);
	x = x + 2*m_H*m_kx;
	pDC->LineTo(x,y);

	x = x - 2*m_H*m_kx - m_L*m_kx;
	y = y - m_L*m_kx ;
	pDC->MoveTo(x,y);
	x = x + 2*m_L*m_kx;
	y = y + 2*m_L*m_kx ;
	pDC->LineTo(x,y);

	x = x-2*m_L*m_kx;
	pDC->MoveTo(x,y);
	x = x+2*m_L*m_kx;
	y = y -2* m_L*m_kx ;
	pDC->LineTo(x,y);

	x = x + 2*m_H*m_kx -m_L*m_kx;
	pDC->MoveTo(x,y);
	x = x + 2*m_L*m_kx;
	y = y + 2* m_L*m_kx ;
	pDC->LineTo(x,y);

	x = x-2*m_L*m_kx;
	pDC->MoveTo(x,y);
	x = x+2*m_L*m_kx;
	y = y -2* m_L*m_kx ;
	pDC->LineTo(x,y);

	x = x  -m_L*m_kx- m_H*m_kx;
	y = y  + m_L*m_kx- m_H*m_kx;
	pDC->MoveTo(x,y);
	y = y + 2*m_H*m_kx+ m_L*m_kx;
	pDC->LineTo(x,y);

	x = x - m_L*m_kx;
	y = y + m_L*m_kx ;
	pDC->MoveTo(x,y);
	x = x + 2*m_L*m_kx;
	y = y - 2*m_L*m_kx ;
	pDC->LineTo(x,y);

	y = y+2*m_L*m_kx;
	pDC->MoveTo(x,y);
	x = x - 2*m_L*m_kx;
	y = y - 2*m_L*m_kx ;
	pDC->LineTo(x,y);

//	x = x + m_L*m_kx;
	y = y -2*m_H*m_kx-m_L*m_kx;
	pDC->MoveTo(x,y);
	x = x + 2*m_L*m_kx;
	y = y + 2*m_L*m_kx ;
    pDC->LineTo(x,y);

	x = x - 2*m_L*m_kx;
	pDC->MoveTo(x,y);
	x = x + 2*m_L*m_kx;
	y = y - 2*m_L*m_kx ;
	pDC->LineTo(x,y);

}
