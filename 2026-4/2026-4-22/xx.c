#include <stdio.h>
#include <stdlib.h>
void _MergeSort(int* a, int left, int right,int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) >>1;//相当于除2找中
	_MergeSort(a, left, mid,tmp);//分割左右区间
	_MergeSort(a, mid + 1, right, tmp);
	int begin1 = left;//定义左右区间的结束和起始位置
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int index = left;//分割还有右区间排序所以存放位置是在区间起始位置
	while (begin1 <= end1 && begin2 <= end2)//按升序归并
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin2 <= end2)//将剩下没有归并的归并
	{
		tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	for (int i = left; i <= right; i++)//right是以下标传参过来所以<=
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a, int n)//归并排序
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1,tmp);
	for (int i = 0; i < n; i++)
	{
		a[i] = tmp[i];
	}
	free(tmp);
}
int main()
{
	int add[10] = { 49,38,65,97,13,27,49,13,27,49 };
	MergeSort(add, 10);
	return 0;
}