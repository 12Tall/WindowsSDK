#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR szCmdLine,int iCmdShow)
{
	// 句柄，内容，标题，按钮风格
	// 压栈顺序：自右向左(⚠)
	MessageBox(NULL, TEXT("Hello World!"), TEXT("SayHi"), MB_OK);

	return 0;
}