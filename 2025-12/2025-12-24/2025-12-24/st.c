#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
////判断三角形
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	//多组输入 scanf 读到几个数据就会返回几
//	while (scanf("%d %d %d", &a, &b, &c) == 3);
//	{
//		//判断是否为三角形
//		if (a + b > c && a + c > b && b + c > a)
//		{
//			if (a == b && b == c)
//			{
//				printf("等边三角形");
//			}
//			else if (a == b || b == c || a == c)
//			{
//				printf("等腰三角形");
//			}
//			else
//			{
//				printf("普通三角形");
//			}
//		}
//		else
//		{
//			printf("NO");
//		}
//	}
//	return 0;
//}
//使用指针打印数组
//#include <stdio.h>
//void print(int* p,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *p++);
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr,sz);
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//#include <time.h>
//#include <stdlib.h>
//int main()
//{
//	//设置随机值
//	srand ((unsigned int)time(NULL));
//	while (1)
//	{
//		char a[5] = "";
//		scanf("%s", &a);
//		char b[5] = "萝卜";
//		char c[5] = "纸巾";
//		int p = rand()%2+1;
//		if (p==1)
//		{
//			printf("windows:%s\n", b);
//			if (strcmp(a, b) == 0)
//			{
//				printf("真棒\n");
//			}
//		}
//		if (p == 2)
//		{
//			printf("windows:%s\n", c);
//			if (strcmp(a, c) == 0)
//			{
//				printf("真棒\n");
//			}
//		}
//
//	}
//	return 0;
//}
#include <stdio.h>
int main()
{
    int n = 0;
    int m = 0;
    //输入n行m列
    scanf("%d %d", &n, &m);
    int add[10][10] = { 0 };
    int i = 0;
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            scanf("%d", &add[i][j]);
        }
    }
    //输出n行m列
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            if (add[i][j] != 0)
            {
                printf("%d ", add[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}