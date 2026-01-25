#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
int main()
{
	int a = isspace('\n');
	int a = isdigit('7');

	printf("%d\n", a);
	printf("%c\n", tolower('A'));//转换小写
	printf("%c\n", toupper('d'));//转换大写
	return 0;
}
#include <stdio.h>
#include <string.h>
void* my_memcpy(void* arr2, const void* arr1, size_t sz)
{
	/*char* p2 = (char*)arr2;
	char* p1 = (char*)arr1;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		*p2++ = *p1++;
	}*/
	//return arr2;
	void* ret = arr2;
	while (sz--)
	{
		*(char*)arr2 = *(char*)arr1;
		arr2 = (char*)arr2+1;
		arr1 = (char*)arr1 + 1;
	}
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };
	//memcpy(arr2, arr1, 28);//内存拷贝//arr2拷贝目标，arr1拷贝源头，28拷贝字节数//memcpy不能拷贝例如arr1的12345到34567的位置
	my_memcpy(arr2, arr1,40);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
void* my_memmove(void* arr1, const void* arr2, int sz)
{
    void* ret = arr1;
    if (arr1<arr2)
    {
        while (sz--)
        {
            *(char*)arr1 = *(char*)arr2;
            arr1 = (char*)arr1 + 1;
            arr2 = (char*)arr2 + 1;
        }
        return ret;
    }
    else if (arr1>arr2)
    {
        while (sz--)
        {
            *((char*)arr1 + sz) = *((char*)arr2 + sz);//每次sz--每次就少加一个字节就实现了倒着拷贝
        }
        return ret;
    }
    return ret;
}
int main()
{
    int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
    //memmove(arr1 + 2, arr1, 20);
    my_memmove(arr1 , arr1+2, 20);
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr1[i]);//memmove可以拷贝重叠的情况
    }
    return 0;
}
#include <stdio.h>
// 讨厌鬼进货
int main()
{
    int n = 0;
    int x = 0;
    scanf("%d %d", &n, &x);
    int add[n];
    int add2[n];

    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &add[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &add2[i]);
    }
    int ret = 0;
    for (i = 0; i < n; i++)
    {
        if (add[i] > add2[i])
        {
            ret += add2[i];
        }
        else
        {
            ret += add[i];
        }
    }
    if (ret <= x)
    {
        printf("%d", ret);
    }
    else
    {
        printf("%d", x);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
//灵异背包
int comper(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int main()
{
    int red = 0;
    int n = 0;
    scanf("%d", &n);
    int add[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &add[i]);
        red += add[i];
    }
    if (red % 2 == 0)
    {
        printf("%d", red);
        return 0;
    }
    qsort(add, n, sizeof(int), comper);
    for (i = 0; i < n; i++)
    {
        int j = i;
        for (j = i; j < n; j++)
        {
            red = 0;
            int p = 0;
            for (p = i; p < n; p++)
            {
                if (p != j)
                {
                    red += add[p];
                }
            }
            if (red % 2 == 0)
            {
                printf("%d", red);
                return 0;
            }
        }
    }
    return 0;
}