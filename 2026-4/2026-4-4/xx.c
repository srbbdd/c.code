#include <stdio.h>
void swa(int* add, int child,int root)
{
	int ret = 0;
	ret = add[child];
	add[child] = add[root];
	add[root] = ret;
}////////////////////////////////h为高度
void sort(int* add, int n,int root)//堆排序的时间复杂度为，首先每一次的节点个数是2^h-1，然后每层的调整次数为，本层节点个数乘以下面的高度，因为一个节点往下调只会调整高度次
{//所以时间复杂度为1*（h-1）+2*（h-2）+4*（h-3）最后加上最后一次的是+2的h次方-x的高度，因为最后一次调整只会吧每个元素交换一次+2的h次方-x的高度算出的元素个数
	//假设每层节点个数为ni每高度为hi高度为h就是=i = 1每次+ni*hi加到h-1
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && add[child] > add[child+1])
		{
			child += 1;
		}
		if (add[root] > add[child])
		{
			swa(add,child,root);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}

}
void heart(int* add, int n)
{
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--) 
	{
		sort(add, n,i);
	}
}
int main()
{
	int add[] = { 3,5,2,7,8,6,1,9,4,0 };
	heart(add, 10);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", add[i]);
	}
	return 0;
}