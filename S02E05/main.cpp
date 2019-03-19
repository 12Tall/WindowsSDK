#include <windows.h>
#include <stdio.h>

typedef bool(*Fun)();

int main(void)
{

	MSG msg;
	HINSTANCE hDll;  // dll 的句柄
	Fun On,Off;  // 函数的指针

	hDll = LoadLibrary(TEXT("S02E04.dll"));  // 不加TEXT 会报异常
	if (hDll == NULL)
	{
		printf("%s", "failed to load dll!\n");
	}
	else
	{
		printf("%s", "succeeded !\n");
		On = (Fun)GetProcAddress(hDll, "OnHook");  // 获取dll 中函数
		Off = (Fun)GetProcAddress(hDll, "UnHook");  // 获取dll 中函数
		On();
		while (GetMessage(&msg,NULL,0,0))
		{
			
		}
		Off();
		FreeLibrary(hDll);  // 卸载dll
		return 0;
	}
}