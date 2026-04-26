#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
void CountSort(int* a, int n)//非比较排序
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;//下标从零开始所以要加1
	int* count = (int*)malloc(sizeof(int) * range);
	assert(count);
	memset(count, 0, sizeof(int) * range);//初始化
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min] += 1;//相对映射节省空间
	}
	int j = 0;//记录a数组位置
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)//拷贝回去
		{
			a[j] = i + min;
			j++;
		}
	}
	free(count);
}
int main()
{
	int a[] = { 1,5,6,8,0,6,4,3,5,8 };
	CountSort(a, 10);

	return 0;
}