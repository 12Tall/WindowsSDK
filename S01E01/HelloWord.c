#include <stdio.h>

int main(int argc, char* argv[])
{
	// 这里要兼容汉语，需要setlocale()
	// 还需要宽字符wprintf()
	printf("hello world!");
	return 0;
}

