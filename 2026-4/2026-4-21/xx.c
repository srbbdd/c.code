#include<stdio.h>
int GetMid(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
void Swap(int* p1, int* p2)
{
	int ret = *p1;
	*p1 = *p2;
	*p2 = ret;
}
void QuicklySort3(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int index = GetMid(a, left, right);
	Swap(&a[left], &a[index]);
	int key = left;
	int prev = left;//标记交换位置
	int cur = left + 1;//找小于key的
	while (cur <= right)
	{
		if (a[cur] < a[key]&& ++prev!=cur)//找到小的就交换，并且更新prev的位置
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[key]);//最后在最后一次和key交换，一样吧小的排在左大的在右
	QuicklySort3(a, left, prev - 1);
	QuicklySort3(a, prev + 1, right);
}
int main()
{
	int add[10] = { 49,38,65,97,13,27,49,13,27,49 };
	QuicklySort3(add, 0, 9);
	return 0;
}