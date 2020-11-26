// Car.cpp: implementation of the CCar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JiQiRenXunJian.h"
#include "Car.h"
#include "math.h"
#define PI 3.1415916

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCar::CCar()
{
	m_x = 220;
	m_y = 53;
	m_v = 10;
	m_vx = 0;
	m_vy = 0;
	m_H = 20;
	m_L = 40;
	m_r = 8;
	m_YD.x = 750;
	m_YD.y = 350;
	m_kx = 1500.0/1600;
	m_ky = -700.0/1000;

	m_nLX = 0;
	m_n = 0;

	m_CirGJ.ndMin = 1000;
	m_CirGJ.ndMax = 0;
	m_CirGJ.n =0;
	m_CirGJ.r = 60.0;
	
	m_CirGJ1[0].x = m_x;
	m_CirGJ1[0].y = m_y;
	m_CirGJ1[0].angle1 =0;
	m_CirGJ1[0].angle2 =90;
	m_CirGJ1[0].r = 60.0;
	m_nGJ = 0;

	m_t=0;
	m_nLCZ = 0;
	m_LCZ[0].x = m_x;
	m_LCZ[0].y = m_y;
	m_LCZ[0].angle1 = 0;
	m_LCZ[0].angle2 = 90;
	m_LCZr = 60;

	m_nMBD = 0;
}

CCar::~CCar()
{

}

void CCar::Draw(CDC *p)
{
	pDC=p;
	int x,y,r;
	CString str;
	CFont ft;
	ft.CreatePointFont(100,_T("黑体"),NULL);
	pDC->SelectObject(&ft);
	pDC->SetTextColor(RGB(0,0,0));

	DrawWaiXing();	
    DrawLuXian();

	CPen cPen;
	cPen.CreatePen(PS_SOLID,1,RGB(139,0,139));
	pDC->SelectObject(&cPen);
//	str.Format("小车最小浓度:%d,最大浓度:%d",m_CirGJ.ndMin,m_CirGJ.ndMax);
	str.Format("小车当前坐标:%.2f,%.2f",m_x,m_y);
	pDC->TextOut(1250,30,str);

	x = m_YD.x + m_CirGJ.ndMinPosx*m_kx;
	y = m_YD.y + m_CirGJ.ndMinPosy*m_ky;
	r = 8;
	pDC->Ellipse(x-r,y-r,x+r,y+r);

	x = m_YD.x + m_CirGJ.ndMaxPosx*m_kx;
	y = m_YD.y + m_CirGJ.ndMaxPosy*m_ky;
	r = 12;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	str.Format("小车查找泄露的时间为:%.2f",m_t);
	pDC->TextOut(1250,70,str);
/*	str.Format("小车最小浓度的x:%.2f,y:%.2f",m_CirGJ.ndMinPosx,m_CirGJ.ndMinPosy);
    pDC->TextOut(1250,70,str);
	str.Format("小车最大浓度的x:%.2f,y:%.2f",m_CirGJ.ndMaxPosx,m_CirGJ.ndMaxPosy);
    pDC->TextOut(1250,90,str);
	*/
}

void CCar::DrawWaiXing()
{
	int x,y,r,r1,r2;
	CPen cPen;
	cPen.CreatePen(PS_SOLID,2,RGB(123,255,0)) ;
	pDC->SelectObject(&cPen);
	x = m_YD.x + m_x *m_kx;
	y = m_YD.y + m_y *m_ky;
	r1=m_L/2*m_kx;
	r2=m_H/2*m_kx;
	pDC->Rectangle(x -r1,y-r2,x+r1,y+r2);

	x = m_YD.x + (m_x - m_L/4) *m_kx;
	y = m_YD.y + (m_y - m_H/2 -m_r) *m_ky;
	r = m_r*m_kx;
	pDC->Ellipse(x -r,y-r,x+r,y+r);

	x = m_YD.x + (m_x + m_L/4) *m_kx;
	pDC->Ellipse(x -r,y-r,x+r,y+r);

}

void CCar::ZhiNaDaoNa(CPoint point)
{
	m_x = (point.x -m_YD.x)/m_kx;
	m_y = (point.y -m_YD.y)/m_ky;
	if(m_v)
		YunSuDaoMuBiaoDian(m_temp);

}

void CCar::YunSuDaoMuBiaoDian(CPoint point)
{
	m_temp = point;

	float d;
	m_v = 40;

	m_MBDx = (point.x -m_YD.x)/m_kx;
	m_MBDy = (point.y -m_YD.y)/m_ky;
	
	d = sqrt( (m_x-m_MBDx)*(m_x-m_MBDx) +(m_y-m_MBDy)*(m_y-m_MBDy));
	m_vx = m_v*(m_MBDx-m_x)/d;
	m_vy = m_v*(m_MBDy-m_y)/d;

}

int CCar::YunSuDaoMuBiaoDian_Move(float deltat)
{
	float d;
	m_x += m_vx*deltat;
	m_y += m_vy*deltat;

	d = sqrt( (m_x-m_MBDx)*(m_x-m_MBDx) +(m_y-m_MBDy)*(m_y-m_MBDy));
	if(d<3)
		return 1;
	else 
		return 0;

}

void CCar::AnLuXian_SheDing(CPoint point)
{
	m_LuXian[m_nLX][0] = (point.x -m_YD.x)/m_kx;
	m_LuXian[m_nLX][1] = (point.y -m_YD.y)/m_ky;
	m_nLX++;

}

void CCar::DrawLuXian()
{
	int i,x,y;
	CPen cPen;
	cPen.CreatePen(PS_SOLID,2,RGB(150,255,237)) ;
	pDC->SelectObject(&cPen);
	x = m_YD.x + m_LuXian[0][0]*m_kx;
	y = m_YD.y + m_LuXian[0][1] *m_ky;
	pDC->MoveTo(x,y);
	for(i=1;i<m_nLX;i++)
	{
		x = m_YD.x + m_LuXian[i][0]*m_kx;
	    y = m_YD.y + m_LuXian[i][1] *m_ky;
	    pDC->LineTo(x,y);
	}
}

int CCar::AnLuXian_Move(float deltat)
{
	float d;
	m_v = 40;
	m_MBDx = m_LuXian[m_nMBDLX][0];
	m_MBDy = m_LuXian[m_nMBDLX][1];
	d = sqrt( (m_x-m_MBDx)*(m_x-m_MBDx) +(m_y-m_MBDy)*(m_y-m_MBDy));
	if(d<3)
	{
		m_nMBDLX++;
		if(m_nMBDLX==m_nLX)
		{
			m_nLX=0;
			return 1;
		}
	}
	else
	{
		m_vx = m_v*(m_MBDx-m_x)/d;
	    m_vy = m_v*(m_MBDy-m_y)/d;
		YunSuDaoMuBiaoDian_Move(deltat);
	}
	return 0;

}

void CCar::MoveChaZhaoXieLou(float deltat, int nd)
{
	m_t +=deltat;
	if(m_CirGJ.n < 30)
	{
		if(m_CirGJ.ndMin >nd)
		{
			m_CirGJ.ndMin = nd;
			m_CirGJ.ndMinPosx = m_x;
			m_CirGJ.ndMinPosy = m_y;
		}
		if(m_CirGJ.ndMax < nd)
		{
			m_CirGJ.ndMax = nd;
			m_CirGJ.ndMaxPosx = m_x;
			m_CirGJ.ndMaxPosy = m_y;
		}
		MoveChaZhaoXieLouCircle(deltat);
		m_CirGJ.n ++;
		if(m_CirGJ.n == 30)
		{
			float d;
			m_CirGJ.x -=(m_CirGJ.ndMinPosx -m_CirGJ.ndMaxPosx)/2;
			m_CirGJ.y -=(m_CirGJ.ndMinPosy -m_CirGJ.ndMaxPosy)/2;

			m_CirGJ.r *=0.9;

			m_CirGJ.ndMin = 10000;
			m_CirGJ.ndMax = -1;
			m_MBDx = m_CirGJ.x - m_CirGJ.r;
	        m_MBDy = m_CirGJ.y;
			
			d = sqrt( (m_x-m_MBDx)*(m_x-m_MBDx) +(m_y-m_MBDy)*(m_y-m_MBDy));
            m_vx = m_v*(m_MBDx  - m_x)/d;
	        m_vy = m_v*(m_MBDy  - m_y)/d;
		}
	}
	else
	{
		if(YunSuDaoMuBiaoDian_Move(deltat))
		{
			m_CirGJ.n=0;
		}
	}
}

void CCar::MoveChaZhaoXieLouCircle(float deltat)
{
	float jd;

	jd = m_CirGJ.n *12 +180;
	m_x = m_CirGJ.x + cos(jd/180*PI)*m_CirGJ.r;
	m_y = m_CirGJ.y + sin(jd/180*PI)*m_CirGJ.r;

}
void CCar::MoveChaZhaoXieLouLine(float deltat)
{
	float angle;

	angle = (m_CirGJ1[m_nGJ].angle1 + m_CirGJ1[m_nGJ].angle2)/2;;
	m_CirGJ1[m_nGJ].x = m_CirGJ1[m_nGJ -1].x + 2*m_LCZr*cos(angle/180*PI);
	m_CirGJ1[m_nGJ].y = m_CirGJ1[m_nGJ -1].y + 2*m_LCZr*sin(angle/180*PI);
	m_CirGJ1[m_nGJ].angle1 = angle;
	m_CirGJ1[m_nGJ].angle2 = m_CirGJ1[m_nGJ].angle1 +90;
	m_nGJ++;

}

void CCar::MoveChaZhaoXieLou1(float deltat, int nd)
{
	m_t +=deltat;
	int i,j=0;
	m_CirGJ1[m_nGJ].ndMax1 = nd;
	for(i=0;i<15;i++)
	{
	//	m_CirGJ1[m_nGJ].ndMax1 = nd;
		if(m_CirGJ1[m_nGJ].Dian1[i][2] > nd)
			j++;
		if( m_CirGJ1[m_nGJ].Dian1[i][2] >nd)
			m_CirGJ1[m_nGJ].ndMax1 = m_CirGJ1[m_nGJ].Dian1[i][2];
		
	}
	if(j<3)
		m_CirGJ1[m_nGJ].ndMax = -1;
	j = 0;
	m_CirGJ1[m_nGJ].ndMax2 = m_CirGJ1[m_nGJ].Dian2[0][2];
	for(i=0;i<15;i++)
	{
		if(m_CirGJ1[m_nGJ].Dian2[i][2] > m_CirGJ1[m_nGJ].Dian2[0][2])
			j++;
		if(m_CirGJ1[m_nGJ].ndMax2 < m_CirGJ1[m_nGJ].Dian2[i][2])
			m_CirGJ1[m_nGJ].ndMax2 = m_CirGJ1[m_nGJ].Dian2[i][2];
	}
	if(j<3)
		m_CirGJ1[m_nGJ].ndMax2 = -1;
	
	MoveChaZhaoXieLouLine(deltat);
	m_CirGJ1[m_nGJ].n ++;
	if(m_CirGJ1[m_nGJ].n == 30)
	{
		if(fabs(m_CirGJ1[m_nGJ].angle1 - m_CirGJ1[m_nGJ].angle2)<10)
		{
			m_CirGJ1[m_nGJ].angle3 = (m_CirGJ1[m_nGJ].angle1 + m_LCZ[m_nGJ].angle2)/2;
			m_nLCZ++;
			m_CirGJ1[m_nGJ].x = m_CirGJ1[m_nGJ-1].x + 2*m_LCZr*cos(m_CirGJ1[m_nGJ-1].angle3/360 * 2*PI);
			m_CirGJ1[m_nGJ].y = m_CirGJ1[m_nGJ-1].y + 2*m_LCZr*sin(m_CirGJ1[m_nGJ-1].angle3/360 * 2*PI);
			m_CirGJ1[m_nGJ].angle1 = m_CirGJ1[m_nGJ-1].angle3;
		    m_CirGJ1[m_nGJ].angle2 = m_CirGJ1[m_nGJ-1].angle1 +90;
		}
	}
	else
	{
		if(YunSuDaoMuBiaoDian_Move(deltat))
		{
			m_CirGJ1[m_nGJ].n=0;
		}
	}

}

void CCar::NDMinMax()
{
	int i,j;
	j = 0;
	m_LCZ[m_nLCZ].ndMax1 = m_LCZ[m_nLCZ].Line1[0][2];
	for(i=0;i<11;i++)
	{
		if(m_LCZ[m_nLCZ].ndMax1 < m_LCZ[m_nLCZ].Line1[i][2])
			m_LCZ[m_nLCZ].ndMax1 = m_LCZ[m_nLCZ].Line1[i][2];
		if(m_LCZ[m_nLCZ].Line1[i][2] > m_LCZ[m_nLCZ].Line1[0][2])
			j++;
	}
	if(j<4)
		m_LCZ[m_nLCZ].ndMax1 = -1;

	j = 0;
	m_LCZ[m_nLCZ].ndMax2 = m_LCZ[m_nLCZ].Line2[0][2];
	for(i=0;i<11;i++)
	{
		if(m_LCZ[m_nLCZ].ndMax2 < m_LCZ[m_nLCZ].Line2[i][2])
			m_LCZ[m_nLCZ].ndMax2 = m_LCZ[m_nLCZ].Line2[i][2];
		if(m_LCZ[m_nLCZ].Line2[i][2] > m_LCZ[m_nLCZ].Line2[0][2])
			j++;
	}
	if(j<4)
		m_LCZ[m_nLCZ].ndMax2 = -1;
}

void CCar::ChaZhaoMove()
{
	m_t +=0.1;
	int i;
	float r,angle1,angle2;
	float nd1,nd2;
	if(m_n == 22)
	{
		if(fabs(m_LCZ[m_nLCZ].angle1 - m_LCZ[m_nLCZ].angle2)<10)
		{
			m_LCZ[m_nLCZ].angle3 = (m_LCZ[m_nLCZ].angle1 + m_LCZ[m_nLCZ].angle2)/2;
			m_nLCZ++;
			m_LCZ[m_nLCZ].x = m_LCZ[m_nLCZ-1].x + 2*m_LCZr*cos(m_LCZ[m_nLCZ-1].angle3/360 * 2*PI);
			m_LCZ[m_nLCZ].y = m_LCZ[m_nLCZ-1].y + 2*m_LCZr*sin(m_LCZ[m_nLCZ-1].angle3/360 * 2*PI);
			m_LCZ[m_nLCZ].angle1 = m_LCZ[m_nLCZ-1].angle3;
		    m_LCZ[m_nLCZ].angle2 = m_LCZ[m_nLCZ-1].angle1 +90;
		}
		else
		{
			NDMinMax();
			nd1 = m_LCZ[m_nLCZ].ndMax1;
			nd2 = m_LCZ[m_nLCZ].ndMax2;
			if(nd1<0)
			{
				m_LCZ[m_nLCZ].angle1 += 180 ;
				if(m_LCZ[m_nLCZ].angle1 >360)
					m_LCZ[m_nLCZ].angle1 -= 360;
			}
			if(nd2<0)
			{
				m_LCZ[m_nLCZ].angle2 += 180 ;
				if(m_LCZ[m_nLCZ].angle2 >360)
					m_LCZ[m_nLCZ].angle2 -= 360;
			}
			if(nd2>0 && nd1>0 && nd1<nd2)
				m_LCZ[m_nLCZ].angle1 = (m_LCZ[m_nLCZ].angle1 + m_LCZ[m_nLCZ].angle2)/2;
			if(nd2>0 && nd1>0 && nd1>nd2)
				m_LCZ[m_nLCZ].angle2 = (m_LCZ[m_nLCZ].angle1 + m_LCZ[m_nLCZ].angle2)/2;
		}
		m_n = 0;

	}
	angle1 = m_LCZ[m_nLCZ].angle1/360 * 2*PI;
	angle2 = m_LCZ[m_nLCZ].angle2/360 * 2*PI;
	if(m_n<11)
	{
		m_LCZ[m_nLCZ].Line1[m_n][0] = m_LCZ[m_nLCZ].x + m_LCZr*cos(angle1)*m_n/10;
		m_LCZ[m_nLCZ].Line1[m_n][1] = m_LCZ[m_nLCZ].y + m_LCZr*sin(angle1)*m_n/10;
		m_x = m_LCZ[m_nLCZ].Line1[m_n][0];
		m_y = m_LCZ[m_nLCZ].Line1[m_n][1];
	}
	else
	{
		i = m_n - 11;
		m_LCZ[m_nLCZ].Line2[i][0] = m_LCZ[m_nLCZ].x + m_LCZr*cos(angle2)*i/10;
		m_LCZ[m_nLCZ].Line2[i][1] = m_LCZ[m_nLCZ].y + m_LCZr*sin(angle2)*i/10;
		m_x = m_LCZ[m_nLCZ].Line2[i][0];
		m_y = m_LCZ[m_nLCZ].Line2[i][1];
	}
	m_n++;
}

void CCar::XunZhaoXieLouDian()
{
	float angle3;
	angle3 = m_LCZ[m_nLCZ-1].angle3/360 * 2*PI;
	m_MBD[m_nMBD][0] = m_LCZ[m_nLCZ-1].x + 2*m_LCZr*cos(angle3)*m_nMBD/10;
	m_MBD[m_nMBD][1] = m_LCZ[m_nLCZ-1].y + 2*m_LCZr*sin(angle3)*m_nMBD/10;
	m_x = m_MBD[m_nMBD][0];
	m_y = m_MBD[m_nMBD][1];
	m_nMBD++;
}



