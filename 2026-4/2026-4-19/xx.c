#include <stdio.h>
int GetMid(int* a,int left,int right)
{
	int mid = (left + right) / 2;
	//int min = (left+right)>>1//也相当于除2效率会高一点
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left]>a[right])
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
	QuicklySort(add, left, Pivot - 1);//分割左右两段
	QuicklySort(add, Pivot + 1, right);
}
int main()
{
	int add[9] = { 6,3,5,2,7,8,9,4,1 };
	QuicklySort(add, 0, 8);
	return 0;
}