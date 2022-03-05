#include <windows.h>
#include "listplug.h"

HINSTANCE gInstanceHandle = NULL;

BOOL APIENTRY DllMain(HANDLE hDLL, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		gInstanceHandle = (HMODULE)hDLL;
	}
    return TRUE;
}

HWND __stdcall ListLoad(HWND ParentWin,char* FileToLoad,int ShowFlags)
{
	size_t fileToLoadLen = strlen(FileToLoad);
	if (FileToLoad[fileToLoadLen-1] == '\\')
	{
		return CreateWindow ("STATIC", FileToLoad, WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, ParentWin, NULL, gInstanceHandle, NULL);		
	}
	else
	{
		return NULL;
	}
}
