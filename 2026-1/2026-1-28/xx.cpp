#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//杨辉三角
int main()
{
	int arr[10][10] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0)//先将三角型两条全是1的边初始化
			{
				arr[i][j] = 1;
			}
			if (j == i)
		
			{
				arr[i][j] = 1;
			}
			if (i >= 2 && j >= 1)//在判断这个位置的数的i-1和i-1j-1有没有初始化，有，他们的和就是这个数的值
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int (*(*fun)(int ,int))(int)*//f是一个函数指针指向的函数两个int的参数，返回值是*也就是返回的是函数指针，返回的函数指针的形参是一个int，返回的函数指针的返回值是int
int (*a[10])(int)//函数指针数组，一个十个元素的数组元素类型是函数指针，他们的形参都是一个int返回值也是int
#include <stdio.h>
//左旋字符串
char* add(char* arr, int k)
{
	char* ret = arr;
	int n = 0;
	while (*ret++)
	{
		n++;//计算字符串长度
	}
	k %= n;//如果k大于字符串总个数那么前面的很多次交换都是浪费时间，所以总操作数取余总元素个数,剩下的就是最后一次操作的元素个数
	int i = 0;
	for (i = 0; i < k; i++)
	{
		int j = 0;
		char emp = arr[0];//每次吧第一个字符存起来
		for (j = 1; j < n; j++)//每次从第二个字符开始往前移//每次从二个字符往前移所以小于总字符串长度
		{
			arr[j - 1] = arr[j];//前移
		}
		arr[n-1] = emp;//字符串第一位从0开始所以＋n-1
	}
	return arr;
}
int main()
{
	char a[] = "abcdef";
	int k = 0;
	scanf("%d", &k);
	char* c = add(a, k);
	printf("%s", c);
	return 0;
}
#include <stdio.h>
#include <string.h>
void reverse(char* left , char* right)
{
	while (left < right)
	{
		char emp = *left;
		*left = *right;
		*right = emp;
		left++;
		right--;
	}
}
char* add(char* a, int k)
{
	int len = strlen(a);
	k %= len;//如果k大于字符串总个数那么前面的很多次交换都是浪费时间，所以总操作数取余总元素个数,剩下的就是最后一次操作的元素个数
	reverse(a,a+k-1);//将左旋部分倒叙
	reverse(a+k,a+len-1);//将剩余部分倒叙
	reverse(a,a+len-1);//整体倒叙
	return a;
}
int main()
{
	char a[] = "abcdef";
	int k = 0;
	scanf("%d", &k);
	char* b = add(a, k);
	printf("%s", b);
	return 0;
}
#include <stdio.h>
// 杨氏矩阵
int main()
{
	int add[3][4];
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		int j = 0;
		for (j = 0; j < 3; j++)// 一次循环初始化一列
		{
			if (i == 0)
			{
				add[j][i] = j;
			}
			else//到第二列的值就等于上一列+1
			{
				add[j][i] = add[j][i - 1] + 1;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			printf("%5d", add[i][j]);
		}
		printf("\n");
	}
	return 0;
}