// Tip.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Joseph circle.h"
#include "Tip.h"
#include "afxdialogex.h"


// CTip �Ի���

IMPLEMENT_DYNAMIC(CTip, CDialogEx)

CTip::CTip(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTip::IDD, pParent)
{

}

CTip::~CTip()
{
}

void CTip::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTip, CDialogEx)
END_MESSAGE_MAP()


// CTip ��Ϣ�������
