#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
////矩阵转置
//int main()
//{
//    int m = 0;
//    int n = 0;
//    scanf("%d %d", &m, &n);
//    int add[n][m];//先将矩阵大小改成转置后的大小
//    int i = 0;
//    for (i = 0; i < m; i++)
//    {
//        int j = 0;
//        for (j = 0; j < n; j++)
//        {
//            scanf("%d", &add[j][i]);//在输入的时候直接将行的输入存到列里
//        }
//    }
//    for (i = 0; i < n; i++)
//    {
//        int j = 0;
//        for (j = 0; j < m; j++)
//        {
//            printf("%d ", add[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
//# include <stdio.h>
////KiKi判断上三角矩阵
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int add[n][n];
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        int j = 0;
//        for (j = 0; j < n; j++)
//        {
//            scanf("%d", &add[i][j]);
//            if ((j < i && add[i][j] != 0) || (j >= i && add[i][j] == 0))//输入的时候直接判断上三角是否有为0的和下三角是否有不为0的
//            {
//                printf("NO");
//                return 0;
//            }
//        }
//    }
//    printf("YES");
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int add[n];
//    for (i = 0; i < n; i++)
//    {
//        scanf(" %d", &add[i]);
//    }
//    if (add[0] - add[n - 1] > 0)//判断正序还是倒叙 
//    {
//        for (i = 0; i < n - 1; i++)
//        {
//            if (add[i] < add[i + 1])
//            {
//                printf("unsorted");
//                return 0;
//            }
//        }
//        printf("sorted");
//    }
//    else
//    {
//        for (i = 0; i < n - 1; i++)
//        {
//            if (add[i] > add[i + 1])
//            {
//                printf("unsorted");
//                return 0;
//            }
//        }
//        printf("sorted");
//    }
//    return 0;
//}
#include<stdio.h>
//判断有序2
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int flag = 1;
    int flag1 = 1;
    int add[5];
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &add[i]);
        if (i > 0 && add[i - 1] > add[i])//只有有一次前面大于后面那就不可能是升序
        {
            flag = 0;
        }
        else if (i > 0 && add[i] > add[i - 1])//有一次前面那个小于后面一位就不可能是倒叙
        {
            flag1 = 0;
        }
    }
    if (flag1 || flag)//全是相同的数也可以判断
    {
        printf("sorted");
    }
    else
    {
        printf("unsorted");
    }

    return 0;
}