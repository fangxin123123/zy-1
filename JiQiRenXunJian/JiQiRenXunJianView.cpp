// JiQiRenXunJianView.cpp : implementation of the CJiQiRenXunJianView class
//

#include "stdafx.h"
#include "JiQiRenXunJian.h"

#include "JiQiRenXunJianDoc.h"
#include "JiQiRenXunJianView.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJiQiRenXunJianView

IMPLEMENT_DYNCREATE(CJiQiRenXunJianView, CView)

BEGIN_MESSAGE_MAP(CJiQiRenXunJianView, CView)
	//{{AFX_MSG_MAP(CJiQiRenXunJianView)
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_M_Car_ZhiNaDaoNa, OnMCarZhiNaDaoNa)
	ON_COMMAND(ID_M_Car_YunSuDaoMuBiaoDian, OnMCarYunSuDaoMuBiaoDian)
	ON_COMMAND(ID_M_Car_AnLuXian, OnMCarAnLuXian)
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_M_WRJ_ZhiNaDaoNa, OnMWRJZhiNaDaoNa)
	ON_COMMAND(ID_M_WRJ_YunSuDaoMuBiaoDian, OnMWRJYunSuDaoMuBiaoDian)
	ON_COMMAND(ID_M_WRJ_AnLuXian, OnMWRJAnLuXian)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_M_MeiQiKaiShi, OnMMeiQiKaiShi)
	ON_COMMAND(ID_M_MeiQiZanTing, OnMMeiQiZanTing)
	ON_COMMAND(ID_M_Car_ChaZhaoXieLouDian, OnMCarChaZhaoXieLouDian)
	ON_COMMAND(ID_M_WRJ_ChaZhaoXieLouDian, OnMWRJChaZhaoXieLouDian)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJiQiRenXunJianView construction/destruction

CJiQiRenXunJianView::CJiQiRenXunJianView()
{
	// TODO: add construction code here
	m_BJ_LBD =0;
	m_BJ = CJKZ;

}

CJiQiRenXunJianView::~CJiQiRenXunJianView()
{
}

BOOL CJiQiRenXunJianView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CJiQiRenXunJianView drawing

void CJiQiRenXunJianView::OnDraw(CDC* pDC)
{
	CJiQiRenXunJianDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CDC MemDc;
	int width,height;
	CRect rect;
	CBitmap MemBitmap;   //缓冲的内存位图
	GetWindowRect(&rect);
	width = rect.Width();
	height = rect.Height();//记录当前屏幕大小
	MemDc.CreateCompatibleDC(NULL);  //建立兼容内存DC大小（设备上下文）
	MemBitmap.CreateCompatibleBitmap(pDC,width,height);
	CBitmap *pOldBit = MemDc.SelectObject(&MemBitmap);
	MemDc.FillSolidRect(0,0,width,height,RGB(255,255,255));
	MemDc.SetBkMode(TRANSPARENT);    //设置背景模式
//	GetClientRect(&m_rect);
    
	m_DT.Draw(&MemDc);
	m_car.Draw(&MemDc);
	m_WRJ.Draw(&MemDc);
	m_XieLou.Draw(&MemDc);

	pDC->BitBlt(0,0,width,height,&MemDc,0,0,SRCCOPY);
	MemBitmap.DeleteObject();
	MemDc.DeleteDC;

}

/////////////////////////////////////////////////////////////////////////////
// CJiQiRenXunJianView printing

BOOL CJiQiRenXunJianView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CJiQiRenXunJianView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CJiQiRenXunJianView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CJiQiRenXunJianView diagnostics

#ifdef _DEBUG
void CJiQiRenXunJianView::AssertValid() const
{
	CView::AssertValid();
}

void CJiQiRenXunJianView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJiQiRenXunJianDoc* CJiQiRenXunJianView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJiQiRenXunJianDoc)));
	return (CJiQiRenXunJianDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJiQiRenXunJianView message handlers

BOOL CJiQiRenXunJianView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	if(zDelta>0)
	{
		m_DT.m_kx *=1.1;
		m_DT.m_ky *= 1.1;
		
		m_car.m_kx =m_DT.m_kx;
	    m_car.m_ky =m_DT.m_ky;
		m_WRJ.m_kx =m_DT.m_kx;
	    m_WRJ.m_ky =m_DT.m_ky;
		m_XieLou.m_kx =m_DT.m_kx;
	    m_XieLou.m_ky =m_DT.m_ky;
	
	}
	if(zDelta<0)
	{
		m_DT.m_kx *=0.9;
		m_DT.m_ky *= 0.9;
		
		m_car.m_kx =m_DT.m_kx;
	    m_car.m_ky =m_DT.m_ky;
		m_WRJ.m_kx =m_DT.m_kx;
	    m_WRJ.m_ky =m_DT.m_ky;
		m_XieLou.m_kx =m_DT.m_kx;
	    m_XieLou.m_ky =m_DT.m_ky;
		
	}
	Invalidate(true);	
	
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}

void CJiQiRenXunJianView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_BJ_LBD = 1;
	int nd;
	nd = m_XieLou.NongDu(point);
	m_NDstr.Format("浓度为:%d",nd);
	
	m_P_LBD = point;
	m_TempYD = m_DT.m_YD;
	if(m_BJ == CarZNDN)
	{
		m_car.ZhiNaDaoNa(point);
		Invalidate(true);
	}
	if(m_BJ == CarYSDMBD)
	{
		m_car.YunSuDaoMuBiaoDian(point);
		SetTimer(CarYSDMBD,100,NULL);
		Invalidate(true);
	}
	if(m_BJ == CarALX)
	{
		m_car.AnLuXian_SheDing(point);
		Invalidate(true);
	}
	if(m_BJ == WRJZNDN)
	{
		m_WRJ.ZhiNaDaoNa(point);
		Invalidate(true);
	}
	if(m_BJ == WRJYSDMBD)
	{
		m_WRJ.YunSuDaoMuBiaoDian(point);
		SetTimer(WRJYSDMBD,100,NULL);
		Invalidate(true);
	}
	if(m_BJ == WRJALX)
	{
		m_WRJ.AnLuXian_SheDing(point);
		Invalidate(true);
	}
	
	CView::OnLButtonDown(nFlags, point);
}

void CJiQiRenXunJianView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_BJ_LBD = 0;

	CView::OnLButtonUp(nFlags, point);
}

void CJiQiRenXunJianView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_BJ_LBD )
	{
		m_DT.m_YD.x = m_TempYD.x + (point.x - m_P_LBD.x);
		m_DT.m_YD.y = m_TempYD.y + (point.y - m_P_LBD.y);
		
		m_car.m_YD = m_DT.m_YD;
		m_WRJ.m_YD = m_DT.m_YD;
		m_XieLou.m_YD = m_DT.m_YD;

		Invalidate(true);
	}	
	CView::OnMouseMove(nFlags, point);
}

void CJiQiRenXunJianView::OnMCarZhiNaDaoNa() 
{
	// TODO: Add your command handler code here
	m_BJ = CarZNDN;
	KillTimer(CarYSDMBD);
	KillTimer(CarALX);
	
}

void CJiQiRenXunJianView::OnMCarYunSuDaoMuBiaoDian() 
{
	// TODO: Add your command handler code here
	m_BJ = CarYSDMBD;
	KillTimer(CarALX);
	
}

void CJiQiRenXunJianView::OnMCarAnLuXian() 
{
	// TODO: Add your command handler code here
	m_BJ = CarALX;
	m_car.m_nLX =0;		
}

void CJiQiRenXunJianView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	int i;
	switch(nIDEvent)
	{
	case CarYSDMBD:
		if(m_car.YunSuDaoMuBiaoDian_Move(0.1))
			KillTimer(CarYSDMBD);
		break;
	case CarALX:
		if(m_car.AnLuXian_Move(0.1))
			KillTimer(CarALX);
		else
		{
			int nd;
			nd = m_XieLou.NongDu(m_car.m_x,m_car.m_y);
			m_NDstr.Format("浓度为:%d",nd);
		}
		break;
	case WRJYSDMBD:
		if(m_WRJ.YunSuDaoMuBiaoDian_Move(0.1))
			KillTimer(WRJYSDMBD);
		break;
	case WRJALX:
		if(m_WRJ.AnLuXian_Move(0.1))
			KillTimer(WRJALX);
	case LIZI:
		m_XieLou.CreateLiZi(0.1);
		m_XieLou.Move(0.1);
		break;	
	case CarCZXLD:
		int nd;
		nd = m_XieLou.NongDu(m_car.m_x,m_car.m_y);
		m_car.MoveChaZhaoXieLou1(0.1,nd);  
//		int i;
  /*      m_car.ChaZhaoMove();
		i = m_car.m_n - 1;
		if(i<11)
			m_car.m_LCZ[m_car.m_nLCZ].Line1[i][2] = m_XieLou.NongDu(m_car.m_x,m_car.m_y);
		else
		{
			i = i - 11;
			m_car.m_LCZ[m_car.m_nLCZ].Line2[i][2] = m_XieLou.NongDu(m_car.m_x,m_car.m_y);
		}
		if(m_car.m_nLCZ == 5)
		{
			m_car.XunZhaoXieLouDian();
			m_car.m_MBD[m_car.m_nMBD-1][2] = m_XieLou.NongDu(m_car.m_x,m_car.m_y);
			if(m_car.m_nMBD == 11)
		//	int nd;
		//	nd = m_XieLou.NongDu(m_WRJ.m_x,m_WRJ.m_y);
		//	if(fabs(nd- 600)<10)
				KillTimer(CarCZXLD);
		}*/
		break;	
	case WRJCZXLD:
	//	int nd;
	//	nd = m_XieLou.NongDu(m_WRJ.m_x,m_WRJ.m_y);
	//	m_WRJ.MoveChaZhaoXieLou(0.1,nd);
	//	int i;
        m_WRJ.ChaZhaoMove();
		i = m_WRJ.m_n - 1;
		if(i<11)
			m_WRJ.m_LCZ[m_WRJ.m_nLCZ].Line1[i][2] = m_XieLou.NongDu(m_WRJ.m_x,m_WRJ.m_y);
		else
		{
			i = i - 11;
			m_WRJ.m_LCZ[m_WRJ.m_nLCZ].Line2[i][2] = m_XieLou.NongDu(m_WRJ.m_x,m_WRJ.m_y);
		}
		if(m_WRJ.m_nLCZ == 5)
		{
			m_WRJ.XunZhaoXieLouDian();
			m_WRJ.m_MBD[m_WRJ.m_nMBD-1][2] = m_XieLou.NongDu(m_WRJ.m_x,m_WRJ.m_y);
			if(m_WRJ.m_nMBD == 11)
		//	int nd;
		//	nd = m_XieLou.NongDu(m_WRJ.m_x,m_WRJ.m_y);
		//	if(fabs(nd- 600)<10)
				KillTimer(WRJCZXLD);
		}
		break;		
	}
	Invalidate(true);
	
	CView::OnTimer(nIDEvent);
}

void CJiQiRenXunJianView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_BJ == CarALX)
	{
		m_car.m_x = m_car.m_LuXian[0][0];
	    m_car.m_y = m_car.m_LuXian[0][1] ;
		
		SetTimer(CarALX,100,NULL);
		m_car.m_nMBDLX=0;
		m_BJ = CJKZ;
	}	
	if(m_BJ == WRJALX)
	{
		m_WRJ.m_x = m_WRJ.m_LuXian[0][0];
	    m_WRJ.m_y = m_WRJ.m_LuXian[0][1] ;
		
		SetTimer(WRJALX,100,NULL);
		m_WRJ.m_nMBDLX=0;
		m_BJ = CJKZ;
	}		
	Invalidate(true);
	
	CView::OnLButtonDblClk(nFlags, point);
}

void CJiQiRenXunJianView::OnMWRJZhiNaDaoNa() 
{
	// TODO: Add your command handler code here
	m_BJ = WRJZNDN;
	KillTimer(WRJYSDMBD);
	KillTimer(WRJALX);
	
}

void CJiQiRenXunJianView::OnMWRJYunSuDaoMuBiaoDian() 
{
	// TODO: Add your command handler code here
	m_BJ = WRJYSDMBD;
	
}

void CJiQiRenXunJianView::OnMWRJAnLuXian() 
{
	// TODO: Add your command handler code here
	m_BJ = WRJALX;
	m_WRJ.m_nLX =0;	
	
}

BOOL CJiQiRenXunJianView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return true;
	return CView::OnEraseBkgnd(pDC);
}

void CJiQiRenXunJianView::OnMMeiQiKaiShi() 
{
	// TODO: Add your command handler code here
	m_BJ = LIZI;
	SetTimer(LIZI,100,NULL);
	
}

void CJiQiRenXunJianView::OnMMeiQiZanTing() 
{
	// TODO: Add your command handler code here
	KillTimer(LIZI);
	
}

void CJiQiRenXunJianView::OnMCarChaZhaoXieLouDian() 
{
	// TODO: Add your command handler code here
	m_car.m_CirGJ.x = m_car.m_x + m_car.m_CirGJ.r;
	m_car.m_CirGJ.y = m_car.m_y;
	m_BJ = CarCZXLD;
	SetTimer(CarCZXLD,100,NULL);
//	KillTimer(WRJCZXLD);
//	int nd;
//	nd = m_XieLou.NongDu(m_car.m_x,m_car.m_y);
//	if(fabs(nd - 600)<5)
//		KillTimer(CarCZXLD);
		
}

void CJiQiRenXunJianView::OnMWRJChaZhaoXieLouDian() 
{
	// TODO: Add your command handler code here
//	m_WRJ.m_CirGJ.x = m_WRJ.m_x + m_WRJ.m_CirGJ.r;
//	m_WRJ.m_CirGJ.y = m_WRJ.m_y;

	SetTimer(WRJCZXLD,100,NULL);
//	KillTimer(CarCZXLD);
//	if(fabs(m_WRJ.m_CirGJ.ndMax - 580)<5)
//		KillTimer(WRJCZXLD);
	
}
