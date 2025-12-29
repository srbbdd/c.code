#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//计算单位阶跃函数
int main()
{
    int t = 0;
    while (scanf("%d", &t) != EOF)
    {
        if (t > 0)
        {
            printf("1\n");
        }
        else if (t == 0)
        {
            printf("0.5\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
//数列求和
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int emp = 0;
    for (i = 1; i <= n; i++)
    {
        int j = 0;
        for (j = 1; j <= i; j++)
        {
            emp += j;
        }
    }
    printf("%d", emp);
    return 0;
}