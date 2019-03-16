#include <Windows.h>

// 回调函数
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR szCmdLine,int iCmdShow)
{
	// 窗口类的名字
	static TCHAR szAppName[] = TEXT("MyWindow");
	// handler window
	HWND hwnd;
	// message
	MSG msg;
	// 窗口类结构⚠
	WNDCLASS wndclass;
	// 调整宽高是否重绘窗口
	// class style redraw
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	// 扩展属性，无用
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;

	// 应用程序实例句柄
	wndclass.hInstance = hInstance;
	// 加载图标、鼠标、背景
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	// 菜单、窗口类
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	// 注册窗口类
	if(!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("注册失败"), szAppName, MB_ICONERROR);
		return 0;
	}
	// 创建窗口的具体特征
	hwnd = CreateWindow(
		szAppName,  // 窗口类名称，窗口基于哪个类创建
		TEXT("12Tall"),
		// window style
		WS_OVERLAPPEDWINDOW,
		// create window
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


	return 0;

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, TEXT("Hi"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}