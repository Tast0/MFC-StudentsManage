
// OOPxe4.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// COOPxe4App: 
// �йش����ʵ�֣������ OOPxe4.cpp
//

class COOPxe4App : public CWinApp
{
public:
	COOPxe4App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern COOPxe4App theApp;