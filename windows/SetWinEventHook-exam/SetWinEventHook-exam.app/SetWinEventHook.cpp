// file-path-spy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SetWinEventHook.h"
#include <conio.h>
#include <ctype.h>  
#include <sstream>
#include <iostream>

using namespace std;


HWINEVENTHOOK g_hook;

void CALLBACK HandleWinEvent(HWINEVENTHOOK hook, DWORD event, HWND hwnd,
	LONG idObject, LONG idChild,
	DWORD dwEventThread, DWORD dwmsEventTime)
{
	IAccessible* pAcc = NULL;
	VARIANT varChild;
	HRESULT hr = AccessibleObjectFromEvent(hwnd, idObject, idChild, &pAcc, &varChild);
	if ((hr == S_OK) && (pAcc != NULL))
	{
		BSTR bstrName;
		HRESULT r = pAcc->get_accName(varChild, &bstrName);
		if (r == S_OK && event == EVENT_OBJECT_FOCUS)
		{
			BSTR bstrValue = NULL;;
			pAcc->get_accValue(varChild, &bstrValue);
			BSTR bstrDescription = NULL;;
			pAcc->get_accDescription(varChild, &bstrDescription);

			wostringstream stringStream;
			stringStream 
				<< " name: " << bstrName
				<< " event: " << event
				<< " hwnd: " << hwnd
				<< " idObject: " << idObject
				<< " idChild: " << idChild
				<< " dwEventThread: " << dwEventThread
				<< " dwmsEventTime: " << dwmsEventTime << endl;

			if (bstrValue != NULL)
				stringStream << " value: " << bstrValue << endl;

			if (bstrDescription != NULL)
				stringStream << " description: " << bstrDescription << endl;
			else
				stringStream << " description: null" << endl;


			OutputDebugString(stringStream.str().c_str());
			
			
			SysFreeString(bstrValue);
			SysFreeString(bstrName);
		}
		else {
			wostringstream stringStream;
			stringStream << "focus: " << "**unknown**"
				<< " event: " << event
				<< " hwnd: " << hwnd
				<< " idObject: " << idObject
				<< " idChild: " << idChild
				<< " dwEventThread: " << dwEventThread
				<< " dwmsEventTime: " << dwmsEventTime << endl;
			OutputDebugString(stringStream.str().c_str());
		}

		pAcc->Release();
	}
}

HWINEVENTHOOK install_event_hook() 
{
	CoInitialize(NULL);
	return SetWinEventHook(
		EVENT_OBJECT_FOCUS, EVENT_OBJECT_FOCUS,  // Range of events (4 to 5).
		NULL,                                          // Handle to DLL.
		HandleWinEvent,                                // The callback.
		0, 0,              // Process and thread IDs of interest (0 = all)
		WINEVENT_OUTOFCONTEXT | WINEVENT_SKIPOWNPROCESS); // Flags.
}

void uninstall_event_hook(HWINEVENTHOOK hook) 
{
	UnhookWinEvent(hook);
	CoUninitialize();
}
