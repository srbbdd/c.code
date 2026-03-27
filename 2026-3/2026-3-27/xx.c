#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int cmp(const void* p1, const void* p2)
{
    return (*(int*)p1) - (*(int*)p2);
}
int main()
{
    int n = 0;
    int k = 0;
    int m = 0;
    scanf("%d %d %d", &n, &k, &m);
    float add[6];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        int max = 0;
        int small = 100;
        float ret = 0.0f;
        int j = 0;
        int c = 0;
        for (j = 0; j < k; j++)
        {
            scanf(" %d", &c);
            if (max < c)
            {
                max = c;
            }
            if (small > c)
            {
                small = c;
            }
            ret += c;
        }
        add[i] = (ret - max - small) / (k - 2);
    }
    qsort(add, n,sizeof(float), cmp);
    i = n - m;
    for (i; i < n; i++)
    {
        printf("%.3f ", add[i]);
    }
    return 0;
}