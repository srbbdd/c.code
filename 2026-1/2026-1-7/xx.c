#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	int i = 0;//内存从低到高创建
//	int add[] = { 1,2,3,4,5,6,7,8,9,10 };//数组从高到低访问
//	for (i = 0; i <= 12; i++)//循环到第12次数组越界，从高到低访问正好覆盖到i变量//所以死循环//在×86环境下死循环
//	{
//		add[i] = 0;
//		printf("hello word\n");
//	}
//	return 0;
//}
//#include <stdio.h>
////将偶数排放在奇数后面
//void adjust(int add[], int sz)
//{
//	int a1 = 0;
//	int i = 0;
//	int emp = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (add[i] % 2 != 0)
//		{
//			emp = add[i];
//			add[i] = add[a1];
//			add[a1] = emp;
//			a1++;
//		}
//	}
//}
//老师方法
//void adjust(int add[], int sz)
//{
//	int left = 0;
//	int right = 0;
//	while (left < right)
//	{
//		//从左向右找一个偶数
//		while (add[left] % 2 == 1&& ( left < right ) )
//		{
//			left++;
//		}
//		//从右向左找一个奇数
//		while (add[right] % 2 == 0&& ( right > left ) )//并且防止全是奇数或偶数 越界
//		{
//			right--;
//		}
//		//交换奇偶数
//		if (left < right)
//		{
//			int emp = add[left];
//			add[left] = add[right];
//			add[right] = emp;
//			left++;
//			right--;
//		}
//	}
//}
//int main()
//{
//	int add[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &add[i]);
//	}
//	int sz = sizeof(add) / sizeof(add[0]);
//	adjust(add, sz);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", add[i]);
//	}
//	return 0;
//}
//#include <stdio.h>
////方法二
//int main()
//{
//	int n = 0;
//	int a = 0;
//	int add[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(add) / sizeof(add[0])-1;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &n);
//		if (n % 2 != 0)
//		{
//			add[a] = n;
//			a++;
//		}
//		else
//		{
//			add[sz] = n;
//			sz--;
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", add[i]);
//	}
//	return 0;
//}
#include <stdio.h>
//合并两个有序数组
int main()
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	int add1[n];
	int add2[m];
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf(" %d", &add1[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf(" %d", &add2[i]);
	}
	int add3[10] = { 0 };
	int a = 0;
	int a1 = 0;
	for (i = 0; i < n + m; i++)
	{
		if (add1[a] <= add2[a1] && a < n || a1 == m)
		{
			add3[i] = add1[a];
			a++;
		}
		else
		{
			add3[i] = add2[a1];
			a1++;
		}
		printf("%d ", add3[i]);
	}
	return 0;
}