#include "dll.h"
#include <Windows.h>

__declspec(dllexport) int add(int i, int j)
{
	return i + j;
	
}


BOOL WINAPI DllMain(
	HINSTANCE hInstance , 
	DWORD fdwReason,
	LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	// true for success,false for failed
	return TRUE;
	
}