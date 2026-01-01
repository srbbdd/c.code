#define _CRT_SECURE_NO_WARNINGS
 圣诞树
#include <stdio.h>
int main()
{
    int h = 0;
    scanf("%d", &h);
    int i = 0;
    //层数
    for (i = 0; i < h; i++)
    {
        int j = 0;
        //每个三角形三次
        for (j = 1; j <= 3; j++)
        {
            int o = 0;
            //空格
            for (o = 0; o < (h * 3) - (i * 3) - j; o++)
            {
                printf(" ");
            }
            int k = 0;
            //打印三角形
            for (k = 0; k <= i; k++)
            {
                for (o = 0; o < j; o++)
                {
                    printf("* ");
                }
                //第一轮循环没有空格
                if (i > 0 && (h * 3) - (i * 3) - j != 0)
                {
                    int o = 0;
                    //空格一排四个，第二排两个，第三排没有
                    for (o = 0; o < (3 - j) * 2; o++)
                    {
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }

    }
    //树根
    for (i = 0; i < h; i++)
    {
        int j = 0;
        for (j = 0; j < (h * 3) - 1; j++)
        {
            printf(" ");
        }
        printf("*\n");
    }
    return 0;
}
#include <stdio.h>
//最高身高
int main()
{
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    int add[n][m];
    int i = 0;
    int max = 0;
    int x = 0;
    int y = 0;
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            scanf("%d", &add[i][j]);
            if (add[i][j] > max)
            {
                max = add[i][j];
                x = i + 1;
                y = j + 1;
            }
        }
    }
    printf("%d %d", x, y);
    return 0;
}
