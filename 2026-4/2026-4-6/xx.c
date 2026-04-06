#include <stdio.h>
void BubbleSort(int* a, int n)//时间复杂度为o（n^2）
{
	int i = 0;
	for (i = n-1; i > 0; i--)
	{
		int j = 0;
		int exchange = 0;
		for (j; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int ret = a[j];
				a[j] = a[j + 1];
				a[j + 1] = ret;
				exchange = 1;
			}
		}
		if (exchange)
		{
			return ;
		}
	}
}
int main()
{
	int a[] = {1,6,5,3,2,7,8,9,10,6,76,433,89,56,3,4,6543,9};
	BubbleSort(a, 18);
	int i = 0;
	for (i = 0; i < 18; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}