#pragma once


// CTip �Ի���

class CTip : public CDialogEx
{
	DECLARE_DYNAMIC(CTip)

public:
	CTip(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTip();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
