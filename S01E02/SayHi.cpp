#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR szCmdLine,int iCmdShow)
{
	// 句柄，内容，标题，按钮风格(或运算)
	// 压栈顺序：自右向左(⚠)
	// 按钮风格：MB_OK，查看定义就好了
	// 返回值：IDOK，查看定义就好了
	// TEXT("") 主要是为了兼容Unicode
	// 定义字符串可以用TCHAR  
	MessageBox(NULL, TEXT("Hello World!"), TEXT("SayHi"), MB_OK|MB_ICONINFORMATION);

	return 0;
}