
// file-path-spy-app.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CfilepathspyappApp:
// See file-path-spy-app.cpp for the implementation of this class
//

class CfilepathspyappApp : public CWinApp
{
public:
	CfilepathspyappApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CfilepathspyappApp theApp;
