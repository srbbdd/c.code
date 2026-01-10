#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//合并两个无序数组
int main()
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	int add1[n];
	int add2[m];
	int c = n + m;
	int add3[12];
	int i = 0;
	int b = 0;
	//输入合并
	for (i = 0; i < n ; i++)
	{
		scanf(" %d", &add1[i]);
		add3[b] = add1[i];
		b++;
	}
	for (i = 0; i < m; i++)
	{
		scanf(" %d", &add2[i]);
		add3[b] = add2[i];
		b++;
	}
	//冒泡排序在打印
	for (i = 0; i < c; i++)
	{
		int j = 0;
		int emp = 0;
		for (j = i + 1; j < c; j++)
		{
			if (add3[j] < add3[i])
			{
				emp = add3[j];
				add3[j] = add3[i];
				add3[i] = emp;
			}
		}
		printf("%d ", add3[i]);
	}
	return 0;
}
#include <stdio.h>
//字符指针
int main()
{
	char a = 'a';
	char* b = &a;
	*b = 'c';
	printf("%c\n", a);
    const char* p = "abcd";//吧字符串首字符a的地址赋值给p
	printf("%s\n", p);//p放的a的地址打印格式%s，从a开始打印到\0
	return 0;
}
#include <stdio.h>
int main()
{
	const char* p1 = "anbcdef";//常量字符串p1和p2在内存中指向的是同一个地址所以相等
	const char* p2 = "anbcdef";
	char arr1[] = "abcdef";//数组在创建会申请自己的空间存放数据，arr1和arr2各自创建了一个所以不相等
	char arr2[] = "abcdef";
	if (p1 == p2)
	{
		printf("p1==p2\n");
	}
	else
	{
		printf("p1!=p2\n");
	}
	if (arr1 == arr2)
	{
		printf("arr1==arr2\n");
	}
	else
	{
		printf("arr1!=arr2\n");
	}
	return 0;
}
#include <stdio.h>
//简易计算器
int main()
{
    double mount1 = 0.0;
    double mount2 = 0.0;
    char exert = 0;
    scanf("%lf %c %lf", &mount1, &exert, &mount2);
    switch (exert)
    {
    case '-':
    {
        printf("%.4f-%.4f=%.4f", mount1, mount2, mount1 - mount2);
        break;
    }
    case '+':
    {
        printf("%.4f+%.4f=%.4f", mount1, mount2, mount1 + mount2);
        break;
    }
    case'*':
    {
        printf("%.4f*%.4f=%.4f", mount1, mount2, mount1 * mount2);
        break;
    }
    case'/':
    {
        if (mount2 == 0.0)
        {
            printf("Wrong!Division by zero!\n");
            break;
        }
        printf("%.4f/%.4f=%.4f", mount1, mount2, mount1 / mount2);
        break;
    }
    default:
    {
        printf("Invalid operation!\n");
        break;
    }
    }
    return 0;
}
#include<stdio.h>
//判断是否有序
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int add[n];
    int max = 0;
    //输入n个数的数列
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &add[i]);
        //判断数列是否全部一致//一致视为有序
        if (max < add[i])
        {
            max = add[i];
        }
    }
    if (max == add[0])
    {
        printf("sorted");
    }
    else
    {
        //有序是变大的所以i比i+1
        for (i = 0; i < n - 1; i++)
        {
            //有一个前一项大于后一项就不是升序判断无序
            if (add[i] > add[i + 1])
            {
                printf("unsorted");
                return 0;
            }
        }
        //循环完程序不结束就是有序
        printf("sorted");
    }

    return 0;
}