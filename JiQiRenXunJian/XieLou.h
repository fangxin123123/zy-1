// XieLou.h: interface for the CXieLou class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XIELOU_H__8BE5896C_BCF6_4EF7_84F5_D1C25DA3A38F__INCLUDED_)
#define AFX_XIELOU_H__8BE5896C_BCF6_4EF7_84F5_D1C25DA3A38F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
typedef struct
{
	float x,y;   
	float vx,vy;
	float size;
	int color;
	float scT;   //生存期
	float czT;    //当前存在的时间
}SLiZi;
class CXieLou  
{
public:
	int NongDu(float x, float y);
	int NongDu(CPoint point);
	void DeleteLiZi(int n);
	void Draw(CDC *p);
	void Move(float deltat);
	void CreateLiZi(float deltat);
	CXieLou();
	virtual ~CXieLou();
	CDC *pDC;

	SLiZi m_LZ[100000];
	int m_nLZ; //当前粒子数
	float m_x,m_y;//泄露点
	CPoint m_YD;
    float m_kx,m_ky;
	int nd;

};

#endif // !defined(AFX_XIELOU_H__8BE5896C_BCF6_4EF7_84F5_D1C25DA3A38F__INCLUDED_)
