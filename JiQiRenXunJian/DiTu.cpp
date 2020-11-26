// DiTu.cpp: implementation of the CDiTu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JiQiRenXunJian.h"
#include "DiTu.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDiTu::CDiTu()
{
	m_kx = 1500.0/1600;
	m_ky = -700.0/1000;
	m_YD.x = 750.0;
	m_YD.y = 350.0;
	
	m_nJZ = 0;
	m_nML = 0;

	ChuShiHuaJianZhu();
	ChuShiHuaMaLu();

}

CDiTu::~CDiTu()
{

}

void CDiTu::Draw(CDC *p)
{
	pDC=p;
	int x,y,r;
	x = m_YD.x;
	y = m_YD.y; 
	r = 10;
	pDC->Ellipse(x-r,y-r,x+r,y+r);

	DrawJianZhu();
	DrawMaLu();
}

void CDiTu::DrawJianZhu()
{
	int x,y,i,j;
	for(i=0;i<m_nJZ;i++)
	{
		x = m_YD.x + m_JZ[i].DD[3][0]*m_kx;
		y = m_YD.y + m_JZ[i].DD[3][1]*m_ky;
		pDC->MoveTo(x,y);
		for(j=0;j<4;j++)
		{
			x = m_YD.x + m_JZ[i].DD[j][0]*m_kx;
		    y = m_YD.y + m_JZ[i].DD[j][1]*m_ky;
			pDC->LineTo(x,y);

			x = m_YD.x + m_JZ[i].Pos[0]*m_kx;
		    y = m_YD.y + m_JZ[i].Pos[1]*m_ky;
	    	pDC->TextOut(x,y,m_JZ[i].Name);
		}
	}	
}

void CDiTu::DrawMaLu()
{
	int x,y,i,j;
	for(i=0;i<m_nML;i++)
	{
		x = m_YD.x + m_kx*m_ML[i].DD1[0][0];
      	y = m_YD.y + m_ky*m_ML[i].DD1[0][1];
	    pDC->MoveTo(x,y);
	    for(j=1;j<m_ML[i].n;j++)
		{
	    	x = m_YD.x + m_kx*m_ML[i].DD1[j][0];
	    	y = m_YD.y + m_ky*m_ML[i].DD1[j][1];
	    	pDC->LineTo(x,y);
		}
	
	    x = m_YD.x + m_kx*m_ML[i].DD2[0][0];
	    y = m_YD.y + m_ky*m_ML[i].DD2[0][1];
	    pDC->MoveTo(x,y);
	    for(j=1;j<m_ML[i].n;j++)
		{
	    	x = m_YD.x + m_kx*m_ML[i].DD2[j][0];
	    	y = m_YD.y + m_ky*m_ML[i].DD2[j][1];
	    	pDC->LineTo(x,y);
		}
     	x = m_YD.x + m_kx*m_ML[i].Pos[0];
    	y = m_YD.y + m_ky*m_ML[i].Pos[1];
    //	pDC->TextOut(x,y,m_ML[i].Name);
	}

}

void CDiTu::ChuShiHuaJianZhu()
{
	int i=0;
	FILE *fp;
	fp = fopen("e:\\JZzgh.txt","r");
	while(1)
	{
		if(fscanf(fp,"%s %f %f %f %f %f %f %f %f %f %f",m_JZ[i].Name,&m_JZ[i].Pos[0],&m_JZ[i].Pos[1],\
			&m_JZ[i].DD[0][0],&m_JZ[i].DD[0][1],&m_JZ[i].DD[1][0],&m_JZ[i].DD[1][1],&m_JZ[i].DD[2][0],\
			&m_JZ[i].DD[2][1],&m_JZ[i].DD[3][0],&m_JZ[i].DD[3][1]) != EOF)
			i++;
		else 
			break;
	}
	m_nJZ = i;
}

void CDiTu::ChuShiHuaMaLu()
{
	int i=0,j;
	int n;
	CStdioFile f;
	CString str,temp;
	f.Open("e:\\LMzgh.txt",CFile::modeReadWrite);
	while(f.ReadString(str))
	{
		n = str.Find(':');
		m_ML[i].Name = str.Left(n);
		str.Delete(0,n+2);

		n = str.Find(' ');
		temp = str.Left(n);	
		m_ML[i].n = atoi(temp);

		str.Delete(0,n+1);
		n = str.Find(' ');
		temp = str.Left(n);
		m_ML[i].Pos[0] = atof(temp);
		
		str.Delete(0,n+1);
		n = str.Find(' ');
		temp = str.Left(n);
		m_ML[i].Pos[1] = atof(temp);

		for(j=0;j<m_ML[i].n;j++)
		{
			str.Delete(0,n+1);
			n = str.Find(' ');
			temp = str.Left(n);
			m_ML[i].DD1[j][0] = atof(temp);

			str.Delete(0,n+1);
			n = str.Find(' ');
			if(n==-1)
				temp = str;
			else 
				temp = str.Left(n);
			m_ML[i].DD1[j][1] = atof(temp);
		}
		for(j=0;j<m_ML[i].n;j++)
		{
			str.Delete(0,n+1);
			n = str.Find(' ');
			temp = str.Left(n);
			m_ML[i].DD2[j][0] = atof(temp);

			str.Delete(0,n+1);
			n = str.Find(' ');
			if(n==-1)
				temp = str;
			else 
				temp = str.Left(n);
			m_ML[i].DD2[j][1] = atof(temp);
		}
		i++;
	}
	m_nML = i;
}
