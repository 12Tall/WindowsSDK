#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>

typedef int(*Fun)(int, int);     //��������һ������ָ�룬typedef �ؼ����Ǳ���ģ�����Ҫ��ʾ����dll�еĺ���������Ҫ�����ú���ָ���������

int main()
{
	HINSTANCE hDll;
	Fun Add;
	hDll = LoadLibrary("dll.dll");
	if (hDll == NULL)
	{
		printf("%s", "failed to load dll!\n");
	}
	else
	{
		printf("%s", "succeeded in loading dll\n");
		Add = (Fun)GetProcAddress(hDll, "add");
		if (Add != NULL)
		{
			int i, j;
			printf("%s", "input the first number:");
			scanf("%d", &i);
			printf("%s", "input the first number:");
			scanf("%d", &j);
			printf("sum = %d\n", Add(i, j));
		}
	}
	FreeLibrary(hDll);

	system("pause");
	return 0;
}