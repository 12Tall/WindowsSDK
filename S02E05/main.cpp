#include <windows.h>
#include <stdio.h>

typedef bool(*Fun)();

int main(void)
{

	MSG msg;
	HINSTANCE hDll;  // dll �ľ��
	Fun On,Off;  // ������ָ��

	hDll = LoadLibrary(TEXT("S02E04.dll"));  // ����TEXT �ᱨ�쳣
	if (hDll == NULL)
	{
		printf("%s", "failed to load dll!\n");
	}
	else
	{
		printf("%s", "succeeded !\n");
		On = (Fun)GetProcAddress(hDll, "OnHook");  // ��ȡdll �к���
		Off = (Fun)GetProcAddress(hDll, "UnHook");  // ��ȡdll �к���
		On();
		while (GetMessage(&msg,NULL,0,0))
		{
			
		}
		Off();
		FreeLibrary(hDll);  // ж��dll
		return 0;
	}
}