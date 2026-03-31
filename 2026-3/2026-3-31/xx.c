#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int mount(char* p1, char* add)
{
    int a = 0;
    int i = 0;
    int ret = 1;
    while (p1 >= add)
    {
        if (i > 0)
        {
            ret = pow(10, i);
        }
        ret *= (*p1) - '0';
        a += ret;
        i++;
        p1--;
    }
    return a;
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    char add [6] ;
    char* p1 = add+n-1;
    int b = 0;
    scanf("%s %d",add, &b);
    int a = mount(p1, add);
    while ((a % 100) % n != 0)
    {
        a++;
        add[n - 1] += 1;
    }
    if (a > b)
    {
        printf("No Solution");
        return 0;
    }
    for (a; a <= b; a+=n)
    {
        p1 = add;
        int j = 1;
        int c = 0;
        while (*p1)
        {
            c = mount(add + j - 1, add);
            if (c % j != 0)
            {
                break;
            }
            else
            {
                p1++;
                j++;
            }
        }
        if (*p1 == '\0')
        {
            printf("%d\n", a);
        }
        if (add[n - 1] + n - '0' >= 10)
        {
            add[n - 2] += 1;
            if (add[n - 1] + n - '0' == 10)
            {
                add[n - 1] = '0';
            }
            else
            {
                add[n - 1] = add[n - 1] +n-10;
            }
        }
        else
        {
            add[n - 1] += n;
        }
    }
    return 0;
}