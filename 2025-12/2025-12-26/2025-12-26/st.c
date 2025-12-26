#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <math.h>
////求出1-100000的水仙花数
//int narcissistic(int i)//函数封装版
//{
//	int emp = 0;
//    int tmp = i;
//    while (tmp)
//    {
//	emp++;
//	tmp /= 10;
//    }
//    int j = 0;
//    tmp = i;
//    int mmm = 0;
//	for (j = 0; j < emp; j++)
//	{
//		int b = tmp % 10;
//		int p = 0;
//		int d = 1;
//		for (p = 0; p < emp; p++)
//		{
//			d *= b;
//		}
//		mmm += d;
//		tmp /= 10;
//	}
//	if (mmm == i)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//	//return mmm ==i;
//}
//int main ()
//{
//	int i = 0;
//	for (i = 1; i < 100000; i++)
//	{
//		if (narcissistic(i))
//		{
//			printf("%d\n", i);
//		}
//		//int emp = 0;
//		//int tmp = i;
//		//计算共几位数
//		//while (tmp)
//		//{
//		//	emp++;
//		//	tmp /= 10;
//		//}
//		//int j = 0;
//		// tmp = i;
//		//int mmm = 0;
//		//自己写的
//	/*	for (j = 0; j < emp; j++)
//		{
//			int b = tmp % 10;
//			int p = 0;
//			int d = 1;
//			for (p = 0; p < emp; p++)
//			{
//				d *= b;
//			}
//			mmm += d;
//			tmp /= 10;
//		}*/
//		//老师教的
//		//while (tmp)
//		//{
//		//	//pow库函数计算每位合的n次方
//		//	mmm += pow(tmp % 10, emp);
//		//	tmp /= 10;
//		//}
//		//if (mmm == i)
//		//{
//		//	printf("%d\n", mmm);
//		//}
//	}
//	return 0;
//}
#include <stdio.h>
//判断回文数
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    for (i = 1; i <= n; i++)
    {
        int tmp = i;
        int count = 0;
        //计算数位
        while (tmp)
        {
            count++;
            tmp /= 10;
        }
        //存入数组
        int add[count];
        int j = 0;
        tmp = i;
        for (j = 0; j < count; j++)
        {
            add[j] = tmp % 10;
            tmp /= 10;
        }
        int l = 0;
        int c = 0;
        int sz = sizeof(add) / sizeof(add[0]) - 1;
        //倒叙正序判断是否相等
        for (l = 0; l < count; l++)
        {
            if (add[l] == add[sz - l])
            {
                c++;
            }
        }
        if (c == count)
        {

            printf("%d\n", i);
        }

    }
    return 0;
}
#include <stdio.h>
//数列求和
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    float count = 0.0f;
    for (i = 1; i <= n; i++)
    {
        count += 1.0 / i;
    }
    printf("%f", count);
    return 0;
}