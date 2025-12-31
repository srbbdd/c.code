#include <stdio.h>
#include <string.h>
//2025 - 12- 30 //倒置字符串
void reverse(char* left,char* right)
{
	char emp = 0;
	while (left < right)
	{
		emp = *left;
		*left = *right;
		*right = emp;
		left++;
		right--;
	}
}
int main()
{
	char arr[101] = { 0 };
	//输入字符串中有空格，所以用gets
	gets(arr);
	int sz = strlen(arr);
	//整体逆序
	reverse(arr,arr+sz-1);
	char* sst = arr;
	while (*sst)
	{
		char* end = sst;
		//找到每一段单词
		while (*end != ' '&&*end!='\0')
		{
			end++;
		}
		//逆序
		reverse(sst, end - 1);
		if (*end != '\0')
		{
			end++;
		}
		sst = end;
	}
	printf("%s", arr);
	return 0;
}
#include <stdio.h>
//
int main()
{
	long n = 0;
	scanf("%ld", &n);
	long long i = 0;
	i = (n * (n + 1)) / 2;
	printf("%lld", i);
	return 0;
}
#include <stdio.h>
//1-2019所以含9的数字
int main()
{
	int i = 1;
	int emp = 0;
	int m = 0;
	for (i = 1; i <= 2019; i++)
	{
		m = i;
		while (m)
		{
			if (m % 10 == 9)
			{
				emp++;
				break;
			}
			m /= 10;
		}
	}
	printf("%d", emp);
	return 0;
}
#include <stdio.h>
//金字塔图案
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		for (i = 1; i <= n; i++)
		{
			int j = 0;
			for (j = 0; j < n - i; j++)
			{
				printf(" ");
			}
			for (j = 0; j < i; j++)
			{
				printf("* ");
			}
			printf("\n");
		}
	}
	return 0;
}
#include <stdio.h>
//翻转金字塔图案
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		for (i = 0; i < n; i++)
		{
			int j = 0;
			for (j = 0; j < i; j++)
			{
				printf(" ");
			}
			for (j = 0; j < n - i; j++)
			{
				printf("* ");
			}
			printf("\n");
		}
	}
	return 0;
}