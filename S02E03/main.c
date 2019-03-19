#include <windows.h>
#include <stdio.h>

typedef int(*Fun)(int, int);

int main(void)
{
	HINSTANCE hDll;  // dll 的句柄
	Fun Add;  // 函数的指针

	hDll = LoadLibrary(TEXT("S02E02.dll"));  // 不加TEXT 会报异常
	if (hDll==NULL)
	{
		printf("%s", "failed to load dll!\n");
	}else
	{
		printf("%s", "succeeded !\n");
		Add = (Fun)GetProcAddress(hDll, "add");  // 获取dll 中函数
		if (Add!=NULL)
		{
			int i, j;
			printf("%s", "input the first number:");
			scanf_s("%d", &i);
			printf("%s", "input the first number:");
			scanf_s("%d", &j);
			printf("sum = %d\n", Add(i, j));
		}
		FreeLibrary(hDll);  // 卸载dll

		system("pause");
		return 0;
	}
}