#include <stdio.h>
#include <stdlib.h>
void MergeSortNonR(int* a,int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;//每组数据个数
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)//每次跳过当前组和下一个已经比较过的组
		{
			int begin1 = i;
			int end1 = i + gap - 1;//定义左右区间
			int begin2 = i + gap;
			int end2 = i + (2 * gap) - 1;
			int index = i;
			if (begin2 >= n)//归并过程右半区间不存在
			{
				break;
			}
			if (end2 >= n)//右半区间算多 
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])//比较左右区间
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1)//剩余为比完的，由于前面几次排序可以确定是升序所以直接放入就行
			{
				tmp[index++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}
			for (int j = i; j <= i+(2*gap)-1; j++)//拷贝回原数组
			{
				a[j] = tmp[j];
			}
		}
		gap *= 2;//第一次一一一组第二次二二一组第三次四四一组
	}
	free(tmp);
}
int main()
{
	int a[] = { 10,6,7,1,3,9,4,2,8};
	MergeSortNonR(a, 9);
	return 0;
}