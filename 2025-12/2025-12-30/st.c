#define _CRT_SECURE_NO_WARNINGS
//求最小公倍数
#include <stdio.h>
int main()
{
	int a = 0; 
	int b = 0;
	scanf("%d %d", &a, &b);
	int max = (a > b )? a:b;
	//while (1)
	//{
	//	if (max % a == 0 && max % b == 0)
	//	{
	//		printf("%d", max);
	//		break;
	//	}
	//	max++;
	//}
	int i = 1;
	while (a * i % b)
	{
		i++;
	}
	printf("%d", a * i);
	return 0;
}
#include <stdio.h>
#include <string.h>
//字符串倒置
void add(char* a, int sz)
{
	//不支持变长数组所以放了一百
	char ac[100];
	int right = sz -1 ;
	int i = 0;
	int o = 0;
	for (i = sz-1; i >=0; i--)
	{
		//判断空格存储空格后的数据
		if (a[i] == ' ')
		{
			int j = i + 1;
			for (j = i + 1; j <= right; j++)
			{
				ac[o] = a[j];
				o++;
			}
			right = i;
		}
		//存储最后一段数据
		if (i == 0)
		{
			int j = 0;
			for (j = 0; j < right; j++)
			{
				ac[o] = a[j];
				o++;
			}
			ac[o] = '\0';
		}
	}
	//覆盖原来的数组
	for (i = 0; i < sz; i++)
	{
		a[i] = ac[i];
	}
}
int main()
{
	char a[] = "hello worde ";
	int sz = strlen(a);
	add(a, sz);
	printf("%s", a);
	return 0;
}