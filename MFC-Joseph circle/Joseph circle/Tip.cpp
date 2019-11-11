// Tip.cpp : 实现文件
//

#include "stdafx.h"
#include "Joseph circle.h"
#include "Tip.h"
#include "afxdialogex.h"


// CTip 对话框

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


// CTip 消息处理程序
