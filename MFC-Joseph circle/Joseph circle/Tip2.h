#pragma once


// CTip2 对话框

class CTip2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTip2)

public:
	CTip2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTip2();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
