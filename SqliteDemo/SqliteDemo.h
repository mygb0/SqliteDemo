
// SqliteDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSqliteDemoApp: 
// �йش����ʵ�֣������ SqliteDemo.cpp
//

class CSqliteDemoApp : public CWinApp
{
public:
	CSqliteDemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSqliteDemoApp theApp;