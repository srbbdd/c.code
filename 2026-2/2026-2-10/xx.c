#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct st_type
{
	int i;//柔性数组成员前面必须至少一个其他成员
	int a[];//柔性数组成员
}type_a;
int main()
{
	int sz = sizeof(type_a);
	printf("%d\n", sz);//sizeof不会计算柔性数组的大小
	type_a s;//4
	type_a* ps = (type_a*)malloc(sizeof(type_a) + 40);//原结构体大小加上40，是给柔性数组的
	assert(ps);
	ps->i = 100;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ps->a[i] = i+1;
	}
	type_a* ps1 = (type_a*)realloc(ps, sizeof(type_a) + 80);
	assert(ps1);
	ps = ps1;
	ps1 = NULL;
	for (i = 10; i < 20; i++)
	{
		ps->a[i] = i+1;	
	}
	printf("%d\n", ps->i);
	for (i = 0; i < 20; i++)
	{
		printf("%d ", ps->a[i]);
	}
	free(ps);
	ps = NULL;
	return 0;
}
struct s
{
	int n;
	int* arr;
};
int main()
{
	struct s* ps = malloc(sizeof(struct s));
	assert(ps);
	ps->n = 100;
	ps->arr = (int*)malloc(40);
	assert(ps->arr);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ps->arr[i] = i + 1;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
	int* ptr = (int*)realloc(ps->arr, 80);
	assert(ptr);
	ps->arr = ptr;
	for (i = 10; i < 20; i++)
	{
		ps->arr[i] = i + 1;
	}
	for (i = 0; i < 20; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	free(ps->arr);
	free(ps);
	ps = NULL;
	return 0; 
//}
#include <stdio.h>
#include <math.h>
//判断质数
int main()
{
    int i = 0;
    int cont = 0;
    for (i = 101; i < 1000; i += 2)//质数只在奇数中
    {
        int j = 0;
        int flag = 1;
        for (j = 2; j <= sqrt(i); j++)//开方是因为如果i是合数那么就有a*b=i,假设a，b>根号i那么a*b也>根号i*根号i也就是>i，所以如果i不是质数一定有一个因数是小于根号i的
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            cont++;
        }
    }
    printf("%d", cont);
    return 0;
}
#include <stdio.h>
//转换六进制
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int ret = 0;
    int add[10] = { 0 };
    while (n >= 6)
    {
        add[i] = n % 6;//算出每一位取模6后的余数
        add[i + 1] = n / 6;
        n /= 6;//剩下的是需要进位的数
        i++;
    }
    for (i; i >= 0; i--)
    {
        printf("%d", add[i]);
    }
    return 0;
}
#include <stdio.h>
//筛选法求素数
int su(int* add, int i, int n)
{
    int ret = 0;
    int j = i + 1;
    for (j; j < n; j++)
    {
        if (add[j] % i == 0 && add[j] != 0)
        {
            add[j] = 0;
            ret++;
        }
    }
    return ret;
}
int main()
{
    int n = 0;
    int ret = 1;//1算质数所以初始1
    scanf("%d", &n);
    int add[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        add[i] = i;
    }
    for (i = 2; i <= n; i++)
    {
        ret += su(add, i, n);
    }
    for (i = 0; i < n; i++)
    {
        if (add[i] != 0 && add[i] != 1)
        {
            printf("%d ", add[i]);
        }
    }
    printf("\n");
    printf("%d", ret);
    return 0;
}