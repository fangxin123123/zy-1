// DiTu.h: interface for the CDiTu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DITU_H__735D8B03_EDCB_4F75_B9F1_CA43F22E0576__INCLUDED_)
#define AFX_DITU_H__735D8B03_EDCB_4F75_B9F1_CA43F22E0576__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
typedef struct{
	float DD[4][2];
	float Pos[2];
	char Name[100];
}MyJianZhu;
typedef struct{
	float DD1[10][2],DD2[10][2];
	int n;
	float Pos[2];
//	char Name[100];
	CString Name;
}MyMaLu;
class CDiTu  
{
public:
	void ChuShiHuaMaLu();
	void ChuShiHuaJianZhu();
	void DrawMaLu();
	void DrawJianZhu();
	void Draw(CDC *p);
	CDiTu();
	virtual ~CDiTu();

	CDC *pDC;
	float m_kx,m_ky;
	CPoint m_YD;

	MyJianZhu m_JZ[100];
	int m_nJZ;
	MyMaLu m_ML[100];
	int m_nML;
};

#endif // !defined(AFX_DITU_H__735D8B03_EDCB_4F75_B9F1_CA43F22E0576__INCLUDED_)
