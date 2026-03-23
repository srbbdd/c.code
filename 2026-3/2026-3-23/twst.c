#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//计算数有几个二
int main()
{
    char add[51];
    scanf("%s", add);
    char* p1 = add;
    float ret = 0;
    float size = 0;
    while (*p1)
    {
        if (*p1 == '2')
        {
            ret++;
        }
        p1++;
        size++;
    }
    if (add[0] == '-')//题目是负数或偶数会加概率
    {
        size--;
    }
    if (*(--p1) % 2 == 0)
    {
        if (add[0] == '-')
        {
            printf("%.2f%%", ret / size * 1.5 * 2.0 * 100);
        }
        else
        {
            printf("%.2f%", ret / size * 2.0 * 100);
        }
    }
    else
    {
        if (add[0] == '-')
        {
            printf("%.2f%", ret / size * 1.5 * 100);
        }
        else
        {
            printf("%.2f%", ret / size * 100);
        }
    }


    return 0;
}
#include <stdio.h>//谁先倒
int main()
{
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    int ac = a;
    int bc = b;//拷贝一份留着计算喝了几碗酒
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        int a1[2];
        int b1[2];
        scanf("%d %d %d %d", &a1[0], &a1[1], &b1[0], &b1[1]);
        if (a1[0] + b1[0] == a1[1])
        {
            a--;
        }
        else if (a1[0] + b1[0] == b1[1])
        {
            b--;
        }
        if (b == 0 || a == 0)
        {
            break;
        }
    }
    printf("%c\n%d", a == 0 ? 'A' : 'B', a == 0 ? bc - b : ac - a);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int cmp(const void* p1, const void* p2)
{
    return (*(int*)p2) - (*(int*)p1);
}
int main()//出租
{
    char add[12];
    int index[11];
    int* index1 = index;
    char* p1 = add;
    scanf("%s", add);
    int* date = (int*)malloc(sizeof(int));
    int i = 0;
    while (*p1)
    {
        int j = 0;
        for (j = 0; j < i; j++)
        {
            if ((*p1 - '0') == date[j])
            {
                break;
            }
        }
        if (j == i)
        {
            date[i] = (*p1) - '0';
            i++;
            date = (int*)realloc(date, sizeof(int) * (i + 1));
        }
        p1++;
    }
    qsort(date, i, sizeof(int), cmp);
    p1 = add;
    while (*p1)
    {
        int j = 0;
        for (j = 0; j < i; j++)
        {
            if ((*p1) - '0' == date[j])
            {
                (*index1) = j;
                break;
            }
        }
        index1++;
        p1++;
    }
    int j = 0;
    printf("int[] arr = new int[]{");
    for (j = 0; j < i - 1; j++)
    {
        printf("%d,", date[j]);
    }
    printf("%d};\n", date[i - 1]);
    printf("int[] index = new int[]{");
    for (j = 0; j < 10; j++)
    {
        printf("%d,", index[j]);
    }
    printf("%d};", index[j]);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int cmp(const void* p1, const void* p2)
{
    return (*(int*)p1) - (*(int*)p2);
}
int main()
{
    int n = 0;
    scanf(" %d", &n);
    int i = 0;
    int* date = (int*)malloc(sizeof(int));
    while (scanf("%d" ,&date[i]) != EOF)
    {
        i++;
        date = (int*)realloc(date,sizeof(int) * (i + 1));
    }
    qsort(date, i, sizeof(int), cmp);
    int j = 0;
    int max = 0;
    int remeber = 0;
    for (j = 0; j < i; j++)
    {
        int ret = 1;
        if (date[j] == date[j + 1])
        {
            int p = j + 1;
            while (date[j] == date[p])
            {
                ret++;
                p++;
            }
        }
        if (ret > max)
        {
            max = ret;
            remeber = date[j];
        }
        j += ret - 1;
    }
    printf("%d %d", remeber, max);
    return 0;
}