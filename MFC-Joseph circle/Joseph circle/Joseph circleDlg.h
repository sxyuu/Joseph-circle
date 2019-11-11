
// Joseph circleDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CJosephcircleDlg 对话框
class CJosephcircleDlg : public CDialogEx
{
// 构造
public:
	CJosephcircleDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_JOSEPHCIRCLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_Large;
	int m_Startnumber;
	int m_jiange;
	afx_msg void OnBnClickedOk();
	int m_End;
	CListBox m_list;
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
	CProgressCtrl m_CPC;
	afx_msg void OnBnClickedCancel();
	CSliderCtrl m_sliderctrl;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLbnSelchangeList1();
};
