#pragma once


// CTip2 �Ի���

class CTip2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTip2)

public:
	CTip2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTip2();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
