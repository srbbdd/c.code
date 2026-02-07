#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// ¹¹ÔìCµÄÍá
int main()
{
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    int c = a > b ? a - b : b - a;
    printf("%d", a > b ? a + c : b + c);
    return 0;
}
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int add[195];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &add[i]);
    }
    int ret = 0;
    for (i = 0; i < n;)
    {
        if (add[i] > add[i + 1] && i + 2 <= n)
        {
            ret += add[i + 1];
            i += 2;
        }
        else
        {
            ret += add[i];
            i += 1;
        }
    }
    printf("%d", ret);
    return 0;
}