// #include <stdio.h>
// ������C ��dll
// visual C++ -> Windows���� -> Windows�����򵼣����Գɹ�
#include "dll.h" //�ղ��½���ͷ�ļ�һ��Ҫ����
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

