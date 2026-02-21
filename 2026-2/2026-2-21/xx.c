#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
{
	int count = 0;
	int n = 0;
	for (int k = 0; k < 2 * n; k++)//时间复杂度O（n） 只保留最高次项//如果最高次项存在且不是1，则去除与这个项目相乘的常数
	{
		++count;
	}
	return 0;
}
int main()
{
	int count = 0;
	int m = 0;
	int n = 0;
	int k = 0;
	for (k = 0; k < m; k++)
	{
		count++;
	}
	for (k = 0; k < n; k++)
	{
		count++;
	}
	//O(n+m) 都是未知数
	return 0;
}
void func(int n)//用常数1取代运行时间中的所有加法常数
{
	int count = 0;
	for (int k = 0; k < 100; k++)//确定的常数次=O（1），n怎么变都不会影响算法的效率
	{
		count++;
	}
}
const char* strchr(const char* str, char character)
{
	while (*str != '\0')//按最坏的情况是,O(n)
	{
		if (*str == character)
		{
			return str;
		}
		str++;
	}
	return NULL;
}
void bubblesort(int* a,int n)
{
	for (size_t end = 0; end < n; end++)
	{
		for (size_t i = end; i < n; i++)
		{
			if (a[i - 1] > a[i])//第一次排序=n，第二次=n-1，第三次n-2时间复杂度 = n（n+1）/2 = O（n^2）
			{
				;
			}
		}
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct qh
{
    int a;
    struct qh* index;
};
struct qh1
{
    int a;
    struct qh1* index;

};
void add(const int n, struct qh** p11, int* a)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        struct qh* p9 = (struct qh*)malloc(sizeof(struct qh));
        assert(p9);
        p9->index = NULL;
        (*p11)->a = a[i];
        (*p11)->index = p9;
        (*p11) = p9;
    }
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int a[n];
    int b[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    struct qh* p1 = (struct qh*)malloc(sizeof(struct qh));
    struct qh* p2 = (struct qh*)malloc(sizeof(struct qh));
    assert(p1);
    assert(p2);
    struct qh* p11 = p1;
    struct qh* p22 = p2;
    add(n, &p11, a);
    p11 = p1;
    add(n, &p22, b);
    p22 = p2;
    struct qh1* p3 = (struct qh1*)malloc(sizeof(struct qh1));
    struct qh1* p33 = p3;
    while (n--)
    {
        struct qh1* p9 = (struct qh1*)malloc(sizeof(struct qh1));
        assert(p9);
        p9->index = NULL;
        p33->a = (p22->a) + (p11->a);
        p11 = p11->index;
        p22 = p22->index;
        p33->index = p9;
        p33 = p9;
    }
    p33 = p3;
    while (p33->index != NULL)
    {
        printf("%d ", p33->a);
        p33 = p33->index;
    }
    return 0;
}