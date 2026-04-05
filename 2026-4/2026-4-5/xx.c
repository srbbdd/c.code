#include <stdio.h>
void swa(int* p1, int* p2)
{
	int ret = *p1;
	*p1 = *p2;
	*p2 = ret;
}
void SelectSort(int* a, int n)//直接选择排序
{
	int begin = 0;
	int end = n-1 ;
	while (begin < end)
	{
		int mini = begin;
		int max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])//找出更小的
			{
				mini = i;
			}
			if (a[i] > a[max])//找出更大的
			{
				max = i;
			}
		}
		swa(&a[begin], &a[mini]);//交换
		if (begin == max)//防止begin和max在同一位置先交换了最小导致max要换的值被换走了
		{
			max = mini;
		}
		swa(&a[end], &a[max]);
		begin++;
		end--;
	}
}
int main()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0,-1 };
	SelectSort(a,11);
	int i = 0;
	for (i = 0; i < 11; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}