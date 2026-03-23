//希尔排序
#include <stdio.h>
//先进性预排序接近有序，在插入排序
//预排序分成gap组，每组的每个元素间隔也为gap个，对每组进行插入排序
void ShellSort(int* a, int n)
{
	int gap;
	int end;
	int tmp = a[end + gap];
	for (int i = 0; i < n - gap; i++)//每组的间隔是gap第一次循环是第一组第一个和第二个交换，第二次循环是第二组第一个和第二组第二个交换，第三次就是第三组第一个和第二个交换，假设有9个元素gap为3，当执行到i=4的时候就开始交换第一组第二个和第三个，所以循环要小于n-gap，也就在i=4次循环就和最后一组进行过交换了，在i接近 n-gap的时候交换第一组和第一组最后一个，最小下标从0开始，所以最后落到的位置是n-gap-1所以i<n-gap
	{
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			else
			{
				break;
			}
		}
		a[end + gap] = tmp;
	}
}
int main()
{

	return 0;
}