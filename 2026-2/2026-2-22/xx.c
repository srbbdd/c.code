#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int add[10] = { 1,2,3,4,5,6,7,8,9,10 };//时间复杂度,Olog以2为底n的对数//算法的复杂度计算经常省略简写底数，写成 O logN
//	int left = 0;
//	int right = 9;
//	while (left <= right)
//	{
//		int min = left + ((right -left) >> 1);
//		if (add[min] < n)
//		{
//			left = min + 1;
//		}
//		else if (add[min] > n)
//		{
//			right = min - 1;
//		}
//		else
//		{
//			printf("%d",add[min]);
//			return 0;
//		}
//	}
//	return 0;
//}
//long long factorial(size_t n)
//{
//	//如果加上for(i=0;i<n;i++)那就是n^2每次O(N)调用n次就是O(N^2)
//	return n < 2 ? n : factorial(n - 1) * n;//O(n)，每次递归运算三次，而常数次就是O（1）
//	//空间复杂度共创建n个栈帧每个栈帧常数个变量所以是O(N)，和时间复杂度一样看最坏的时候
//}
//int fibo(int n)
//{
//	if (n <= 1)
//	{
//		return 0;
//	}
//	return fibo(n - 1) + fibo(n + 2);//递归n次每次产生两个新的节点0(2^N);
//}
//void bubblesort(int* a, int n)
//{
//	for (size_t end = 0; end < n; end++)//时间复杂度累计，空间复杂度不累计
//	{
//		int exchange = 0;//一个定义5个变量，常数项，空间复杂度是O(1)
//		for (size_t i = end; i < n; i++)
//		{
//			if (a[i - 1] > a[i])
//			{
//				exchange = 1;
//			}
//		}
//	}
//	return 0;
//}
long long* fibonacci(size_t n)
{
	if (n == 0)
	{
		return 0;
	}
	long long* fibarray = (long long*)malloc((n + 1) * sizeof(long long));//开了n+1空间，忽略掉常数 = 空间复杂度= O(N)
	fibarray[0];
	fibarray[1];
	for (int i = 2; i <= n; i++)
	{
		fibarray[i] = fibarray[i - 1] + fibarray[i - 2];
	}
	return fibarray;
}