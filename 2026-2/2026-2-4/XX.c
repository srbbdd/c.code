#define _CRT_SECURE_NO_WARNINGS
//小乐乐算多少人被请家长
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int a = 0;
    int i = 0;
    int ret = 0;
    for (i = 0; i < n; i++)
    {
        int emp = 0;
        int j = 0;
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a);
            emp += a;
        }
        if (emp / 3 < 60)
        {
            ret++;
        }
    }
    printf("%d", ret);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
//公务员面试
int compar(const void* a1, const void* a2)
{
    return ((*(int*)a1) - (*(int*)a2));
}
int main()
{
    int add[7] = { 0 };
    int i = 0;
    while (scanf("%d", &add[i]) != EOF)
    {
        for (i = 1; i < 7; i++)
        {
            scanf("%d", &add[i]);
        }
        qsort(add, sizeof(add) / sizeof(add[0]), sizeof(add[0]), compar);
        float ret = 0;
        for (i = 1; i < 7 - 1; i++)
        {
            ret += add[i];
        }
        printf("%.2f\n", ret / 5);
        i = 0;
    }
    return 0;
}
#include <stdio.h>
//反向输出一个四位数
int add(int a)
{
    printf("%d", a%10);
    if (a > 9)
    {
        add(a / 10);
    }
    return 0;
}
int main()
{
    int a = 0;
    scanf("%d", &a);
    add(a);
    return 0;
}
#include <stdio.h>
// 序列中整数去重
int main()
{
    int n = 0;
    scanf("%d", &n);
    int add[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &add[i]);
    }
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = i + 1; j < n; j++)
        {
            if (add[i] == add[j])
            {
                add[j] = -1;
            }
        }
        if (add[i] >= 0)
        {
            printf("%d ", add[i]);
        }
    }
    return 0;
}