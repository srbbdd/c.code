#include <stdio.h>
void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)//这部分和希尔排序那里完全一样
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
int GetMid(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	//int min = (left+right)>>1//也相当于除2效率会高一点
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
void QuicklySort(int* add, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int index = GetMid(add, left, right);//三数取中，防止本就有序的数列将时间复杂度退化成n^2
	Swap(&add[left], &add[index]);//由于不知道三数取中取到的是最左边还是最右边，所以我们依然默认左边为Key然后和index交换位置
	int begin = left;
	int end = right;
	int key = add[begin];
	int Pivot = begin;
	while (begin < end)//每次循环n次循环log以2为底n为对数次，时间复杂度为O（nlong2n）
	{
		while (begin < end && add[end] >= key)//右边找小的
		{
			end--;
		}
		add[Pivot] = add[end];//放到坑位
		Pivot = end;//坑位更新
		while (begin < end && add[begin] <= key)//左边找大
		{
			begin++;
		}
		add[Pivot] = add[begin];
		Pivot = begin;
	}
	Pivot = begin;
	add[Pivot] = key;
	if (Pivot - 1 - left>10)//小区间优化减少递归次数,如果剩下的元素少于十就不用递归了直接插入排序可以减少递归次数
	{
		QuicklySort(add, left, Pivot - 1);//分割左右两段
	}
	else
	{
		InsertSort(add+left,Pivot-1-left+1);//Pivot是下标但是插入排序接的是元素数量所以要+1而add+left是起始位置下标传入的
	}
	if (right - (Pivot + 1) > 10)
	{
		QuicklySort(add, Pivot + 1, right);
	}
	else
	{
		InsertSort(add + Pivot + 1, right - (Pivot + 1) + 1);
	}
}
void QuicklySort2(int* a, int left, int right)//挖坑法二指针
{
	if (left > right)
	{
		return 0;
	}
	int index = GetMid(a, left, right);
	Swap(&a[left], &a[index]);
	int begin = left;
	int end = right;
	int key = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= a[key])
		{
			end--;
		}
		
		while (begin < end && a[begin] <= a[end])
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[key]);//最后吧相遇位置交换一次
	QuicklySort2(a, left, begin - 1);
	QuicklySort2(a, begin + 1, right);
}
int main()
{
	int add[10] = {49,38,65,97,13,27,49,13,27,49};
	QuicklySort2(add, 0, 9);
	return 0;
}