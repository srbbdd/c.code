#include <iostream>
#include <stack>
using namespace std;
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
void swa(int& p1, int& p2)
{
	int ret = p1;
	p1 = p2;
	p2 = ret;
}
void QuickSortNonR(int* a, int n)//非递归实现快速排序挖坑法
{
	stack<int>pq;
	pq.push(n - 1);
	pq.push(0);
	while (!(pq.empty()))
	{
		int left = pq.top();//注意入栈顺序
		pq.pop();
		int right = pq.top();
		pq.pop();
		int indexmin = GetMid(a, left, right);//三数取中
		swa(a[left], a[indexmin]);
		int key = a[left];
		int begin = left;
		int end = right;
		int index = left;//标记坑
		while (end > begin)
		{
			while (end > begin && a[end] >= key)//大于等于防止等于死循环
			{
				end--;
			}
			a[index] = a[end];
			index = end;//交换，更新坑
			while (begin < end && a[begin] <= key)
			{
				begin++;
			}
			a[index] = a[begin];
			index = begin;
		}
		index = begin;
		a[index] = key;//最后更新分割位置
		if (right > index + 1)
		{
			pq.push(right);//入栈左右区间
			pq.push(index + 1);
		}
		if (left < index - 1)
		{
			pq.push(index-1);
			pq.push(left);
		}
	}
}
int main()
{
	int a[] = {49,38,65,97,76,13,27,49};
	QuickSortNonR(a, 8);
	return 0;
}