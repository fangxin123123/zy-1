// Car.h: interface for the CCar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAR_H__D8549171_7EDA_4607_9838_9DDFE7715088__INCLUDED_)
#define AFX_CAR_H__D8549171_7EDA_4607_9838_9DDFE7715088__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
typedef struct{
	float x,y;
	float r;
	int ndMin,ndMax,ndMax1,ndMax2;
	float ndMinPosx,ndMinPosy;
	float ndMaxPosx,ndMaxPosy;

	float Dian1[30][3];
	float Dian2[30][3];
	float angle1,angle2,angle3;
	int n;
}SCircleGuiJi;
typedef struct
{
	float x,y;
	float ndMax1,ndMax2;
	float angle1,angle2,angle3;
	float Line1[15][3];
	float Line2[15][3];
	int n;
}SLineChaZhao;
class CCar  
{
public:
	void MoveChaZhaoXieLouLine(float deltat);
	void XunZhaoXieLouDian();
	void ChaZhaoMove();
	void NDMinMax();
	void MoveChaZhaoXieLou1(float deltat, int nd);
	void MoveChaZhaoXieLouCircle(float deltat);
	void MoveChaZhaoXieLou(float deltat, int nd);
	int AnLuXian_Move(float deltat);
	void DrawLuXian();
	void AnLuXian_SheDing(CPoint point);
	int YunSuDaoMuBiaoDian_Move(float deltat);
	void YunSuDaoMuBiaoDian(CPoint point);
	void ZhiNaDaoNa(CPoint point);
	void DrawWaiXing();
	void Draw(CDC *p);
	CCar();
	virtual ~CCar();

	CDC *pDC;
	float m_x,m_y;
	float m_vx,m_vy,m_v;
	float m_L,m_H,m_r;  
    float m_kx,m_ky;
	CPoint m_YD,m_temp;
	float m_MBDx,m_MBDy;
	int m_nLX;
	float m_LuXian[100][2];
	int m_nMBDLX;

	SCircleGuiJi m_CirGJ;
	SCircleGuiJi m_CirGJ1[100];
	int m_nGJ;
	float m_t;
	int m_n;
	
	int nd;
	SLineChaZhao m_LCZ[100];
	int m_nLCZ;
	float m_LCZr;
	float m_MBD[100][2];
	int m_nMBD;

};

#endif // !defined(AFX_CAR_H__D8549171_7EDA_4607_9838_9DDFE7715088__INCLUDED_)
