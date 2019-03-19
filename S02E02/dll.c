// #include <stdio.h>
// 创建纯C 的dll
// visual C++ -> Windows桌面 -> Windows桌面向导，可以成功
#include "dll.h" //刚才新建的头文件一定要包含
#include <windows.h>

__declspec(dllexport) int add(int a, int b)

{
	return a + b;

}

BOOL WINAPI DllMain(HINSTANCE hInstance,DWORD reason,LPVOID lpReserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	default:
		break;
	}
	return TRUE;
}

