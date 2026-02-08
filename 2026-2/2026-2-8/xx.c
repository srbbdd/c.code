#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a = 10;
	int* p = &a;
	free(p);//对非动态开辟内存使用free释放
	p = NULL;
	return 0;
}
int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		return 1;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*p= i;
		p++;//p的位置被改变
	}
	free(p);//这里释放空间已经找不到p的起始位置了，p必须要指向开辟空间的起始位置才能free
	p = NULL;
	return 0;
}
free 不能对同一块动态内存多次释放
int main()
{
	int* p = (int*)malloc(40);
	free(p);
	p = NULL;//置空如果写出了多次释放也不会有事
	free(p);
	return 0;
}
#include <stdio.h>
计算一年中的第几天
int main()
{
    int year = 0;
    int month = 0;
    int day = 0;
    while (scanf("%d %d %d", &year, &month, &day) != EOF)
    {
        int ret = 31;
        if (month > 2)
        {
            int i = 0;
            for (i = 3; i < month; i++)
            {
                if (i == 4 || i == 6 || i == 9 || i == 11)
                {
                    ret += 30;
                }
                else
                {
                    ret += 31;
                }
            }
        }
        if (year % 4 == 0 || year % 400 == 0 && year % 100 != 0)
        {
            printf("%d\n", ret + 29 + day);
        }
        else
        {
            printf("%d\n", ret + 28 + day);
        }
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compar(const void* a1, const void* a2)
{
    a1 = (char*)a1;
    a2 = (char*)a2;
    return strcmp(a1, a2);
}
int main()
{
    char add[10001];
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    fgets(add, 10000, stdin);
    qsort(add, sizeof(add), sizeof(add[0]), compar);
    int j = 1;
    int ret = 0;
    for (i = 1; i < 10001; i)
    {
        if (add[i] == add[i + j * 1])
        {
            ret++;
            i = j + 1;
        }
        j++;
    }
    printf("%d", ret);
    return 0;
}