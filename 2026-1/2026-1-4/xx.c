#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <windows.h>
//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//		Sleep(2000);
//	}
//	return 0;
//}
#include <stdio.h>
#include <string.h>
int main()
{
	char a[1000];//char类型到127再加=10000000被解读为-128一直循环/减也是一样的先减到-128在-1=127
	int i = 0;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));//strlen遇到0会停从-1减到-128-1=127减到0=255
	return 0;
}
