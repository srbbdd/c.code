#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stt
{
	int age;
	char name[20];
};
int name(const void* e1, const void* e2)
{
	return strcmp(((struct stt*)e1)->name, ((struct stt*)e2)->name);
}
int agg(const void* e1, const void* e2)
{
	return ((struct stt*)e1)->age - ((struct stt*)e2)->age;
}
int main()
{
	struct stt s[] = { {12,"zhangs"},{32,"liuli"},{23,"hello"}, };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), agg);
	return 0;
}
#include <stdio.h>
#include <string.h>
struct stt
{
	int age;
	char name[20];
};
void Swap(char* e1, char* e2, int beadth)//获得要交换的两个元素的地址和元素的宽度
{
	int i = 0;
	for (i = 0; i < beadth; i++)//按照字节交换
	{
		char emp = *e1;
		*e1 = *e2;
		*e2 = emp;
		e1++;
		e2++;
	}
}
void imitate_qsort(void* arr,int sz,int beadth, int(*sss)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (sss((char*)arr + j * beadth, (char*)arr + (j + 1) * beadth) > 0)//由于不知道arr的类型，所以强制换char类型然后乘以宽度就可以找到对应元素的地址
			{
				Swap((char*)arr + j * beadth, (char*)arr + (j + 1) * beadth, beadth);//交换
				flag = 0;
			}
		}
		if (flag == 1)//一次没有交换，说明已经有序
		{
			break;
		}
	}
}
int ace(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
int aaa(const void* e1, const void* e2)
{
	return strcmp(((struct stt*)e1)->name, ((struct stt*)e2)->name);//以结构体中的name成员进行比较
}
int bbb(const void* e1, const void* e2)
{
	return ((struct stt*)e1)->age - ((struct stt*)e2)->age;//以结构体中的age成员进行比较
}
int ccc(const void* e1, const void* e2)
{
	return *(char*)e1 - *(char*)e2;
}
int main()
{
	//int arr[] = { 23,12,45,67,89,34,22 };
	//char arr[] = { 'z','a','s','d','e','b','c' };
	//char arr[] = { "zdasbec" };
	struct stt arr[] = { {12,"zhangs"},{32,"liuli"},{23,"hello"}, };
	//printf("%p\n%p\n%p\n",&arr[0].age,&arr[1].age,&arr[2].age);
	int sz = sizeof(arr) / sizeof(arr[0]);
	imitate_qsort(arr, sz, sizeof(arr[0]),aaa);
	return 0;
}
#include <stdio.h>
//记数问题
int main()
{
	int n = 0;
	int x = 0;
	int digit = 0;
	int i = 0;
	scanf("%d %d", &n, &x);
	for (i = 1; i <= n; i++)
	{
		int a = i;
		while (a)
		{
			if (a % 10 == x)
			{
				digit++;
			}
			a /= 10;
		}
	}
	printf("%d ", digit);
	return 0;
}
#include <stdio.h>
// 约瑟夫环
int main()
{
    int n = 0;
    int k = 0;
    int m = 0;
    scanf("%d %d %d", &n, &k, &m);
    int add[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        add[i] = i;
    }
    int a = 1;
    int j = k;
	for (i = 0; i < n - 1; i++)//要删除n-1次，最后剩下一个
    {
		while (1)
        {
			if (j >= n)//j从k开始，如果超过n就要减去n继续从头开始
            {
                j -= n;
            }
			while (add[j] == -1)//如果该位置已经被删除，就继续往后找
            {
                j++;
                if (j >= n)
                {
                    j -= n;
                }
            }
			if (a == m)//找到了第m个就删除
            {
                a = 1;
                add[j] = -1;
                j++;
                break;
            }
            j++;
            a++;
        }
    }
	for (i = 0; i < n; i++)//输出最后剩下的那个
    {
        if (add[i] != -1)
        {
            printf("%d", add[i]);
        }
    }
    return 0;
}