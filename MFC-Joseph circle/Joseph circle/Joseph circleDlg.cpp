
// Joseph circleDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Joseph circle.h"
#include "Joseph circleDlg.h"
#include "afxdialogex.h"
#include "Child.h"
#include "Circle.h"
#include "Tip.h"
#include "Tip2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CJosephcircleDlg 对话框



CJosephcircleDlg::CJosephcircleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CJosephcircleDlg::IDD, pParent)
	, m_Large(0)
	, m_Startnumber(0)
	, m_jiange(0)
	, m_End(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJosephcircleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Large);
	DDV_MinMaxInt(pDX, m_Large, 1, 9999);
	DDX_Text(pDX, IDC_EDIT2, m_Startnumber);
	DDV_MinMaxInt(pDX, m_Startnumber, 1, 9999);
	DDX_Text(pDX, IDC_EDIT3, m_jiange);
	DDV_MinMaxInt(pDX, m_jiange, 0, 99999);
	DDX_Text(pDX, IDC_EDIT4, m_End);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_PROGRESS1, m_CPC);
	DDX_Control(pDX, IDC_SLIDER1, m_sliderctrl);
}

BEGIN_MESSAGE_MAP(CJosephcircleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CJosephcircleDlg::OnBnClickedOk)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CJosephcircleDlg::OnNMCustomdrawProgress1)
	ON_BN_CLICKED(IDCANCEL, &CJosephcircleDlg::OnBnClickedCancel)
	ON_WM_HSCROLL()
	ON_LBN_SELCHANGE(IDC_LIST1, &CJosephcircleDlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CJosephcircleDlg 消息处理程序

BOOL CJosephcircleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CJosephcircleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CJosephcircleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CJosephcircleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CJosephcircleDlg::OnBnClickedOk()
{
	m_list.ResetContent();
	INT_PTR tip;
	CTip ctip;
	tip = ctip.DoModal();
	if (IDCANCEL == tip)
		return;
	UpdateData(TRUE);
	this->m_CPC.SetRange(0, 100);
	this->m_CPC.SetStep(1);
	Circle A;
	A.CCircle(m_Large, m_Startnumber, m_jiange);
	A.run();
	m_End = A.last;
	CString A1, A2;

	for (int i = 0; i < A.b-1; i++)
	{
		int a=i*100/A.list[0]+20;
		this->m_CPC.SetPos(a);
		A1.Format(_T("%d"), A.list[i + 1]);
		A2.Format(_T("%d"), i + 1);
		CString CTemp = _T("第") + A2 + "个出圈孩子的序号为" + A1;
		m_list.AddString(CTemp);
	}

	UpdateData(FALSE);
}


void CJosephcircleDlg::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
}


void CJosephcircleDlg::OnBnClickedCancel()
{
	INT_PTR tip;
	CTip2 ctip;
	tip = ctip.DoModal();
	if (IDCANCEL == tip)
		return;
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CJosephcircleDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	UpdateData(TRUE);
	m_sliderctrl.SetRange(1, m_Large, FALSE);
	m_Startnumber = m_sliderctrl.GetPos();
	UpdateData(FALSE);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CJosephcircleDlg::OnLbnSelchangeList1()
{
	// TODO:  在此添加控件通知处理程序代码
}
