
// Joseph circleDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CJosephcircleDlg �Ի���



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


// CJosephcircleDlg ��Ϣ�������

BOOL CJosephcircleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CJosephcircleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
		CString CTemp = _T("��") + A2 + "����Ȧ���ӵ����Ϊ" + A1;
		m_list.AddString(CTemp);
	}

	UpdateData(FALSE);
}


void CJosephcircleDlg::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CJosephcircleDlg::OnBnClickedCancel()
{
	INT_PTR tip;
	CTip2 ctip;
	tip = ctip.DoModal();
	if (IDCANCEL == tip)
		return;
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CJosephcircleDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	UpdateData(TRUE);
	m_sliderctrl.SetRange(1, m_Large, FALSE);
	m_Startnumber = m_sliderctrl.GetPos();
	UpdateData(FALSE);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CJosephcircleDlg::OnLbnSelchangeList1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
