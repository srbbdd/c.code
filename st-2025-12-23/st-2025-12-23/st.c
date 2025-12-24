#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int y = 0;
    int m = 0;
    int d = 0;
    //输入学习日期
    scanf("%d %d %d", &y, &m, &d);
    int y1 = 0;
    int m1 = 0;
    int d1 = 0;
    //输入当前日期
    scanf("%d %d %d", &y1, &m1, &d1);
    //判断是否开始学习
    if (y1 == y)
    {
        if (m1 == m)
        {
            if (d1 == d)
            {
                printf("yes");
            }
            if (d1 < d)
            {
                printf("no");
            }
            if (d1 > d)
            {
                printf("yes");
            }
        }
        if (m1 < m)
        {
            printf("no");
        }
        if (m1 > m)
        {
            printf("yes");
        }
    }
    if (y1 < y)
    {
        printf("no");
    }
    if (y1 > y)
    {
        printf("yes");
    }
    return 0;
}
#include <stdio.h>
int main()
{
    int x = 0;
    int y = 0;
    //输入坐标
    scanf("%d %d", &x, &y);
    int x1 = 0;
    int y1 = 0;
    //输入金币坐标
    scanf("%d %d", &x1, &y1);
    //判断金币位置
    if (x == x1 && y1 - 1 == y)
    {
        printf("u");
    }
    if (x == x1 && y1 + 1 == y)
    {
        printf("d");
    }
    if (x1 - 1 == x && y1 == y)
    {
        printf("r");
    }
    if (x1 + 1 == x && y1 == y)
    {
        printf("l");
    }

    return 0;
}