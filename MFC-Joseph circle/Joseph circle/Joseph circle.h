
// Joseph circle.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CJosephcircleApp: 
// �йش����ʵ�֣������ Joseph circle.cpp
//

class CJosephcircleApp : public CWinApp
{
public:
	CJosephcircleApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CJosephcircleApp theApp;