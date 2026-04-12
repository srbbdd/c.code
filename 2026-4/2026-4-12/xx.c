//快速排序-挖坑法
#include <stdio.h>
void QuicklySort(int* add, int left,int right)
{
	if (left>=right)
	{
		return;
	}
	int begin = left;
	int end = right;
	int key = add[begin];
	int Pivot = begin;
	while (begin < end)
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
	QuicklySort(add,left,Pivot-1);//分割左右两段
	QuicklySort(add,Pivot+1,right);
}
int main()
 {
	int add[9] = { 6,3,5,2,7,8,9,4,1};
	QuicklySort(add,0,8);
	return 0; 
}