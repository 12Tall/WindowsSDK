#include <windows.h>
#include <stdio.h>

typedef int(*Fun)(int, int);

int main(void)
{
	HINSTANCE hDll;  // dll �ľ��
	Fun Add;  // ������ָ��

	hDll = LoadLibrary(TEXT("S02E02.dll"));  // ����TEXT �ᱨ�쳣
	if (hDll==NULL)
	{
		printf("%s", "failed to load dll!\n");
	}else
	{
		printf("%s", "succeeded !\n");
		Add = (Fun)GetProcAddress(hDll, "add");  // ��ȡdll �к���
		if (Add!=NULL)
		{
			int i, j;
			printf("%s", "input the first number:");
			scanf_s("%d", &i);
			printf("%s", "input the first number:");
			scanf_s("%d", &j);
			printf("sum = %d\n", Add(i, j));
		}
		FreeLibrary(hDll);  // ж��dll

		system("pause");
		return 0;
	}
}