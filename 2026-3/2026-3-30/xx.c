#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int cmp(const void* p1, const void* p2)
{
    return (*(int*)p1) - (*(int*)p2);
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int add[10];
    int i = 0;
    int ret = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &add[i]);
    }
    qsort(add, n, sizeof(int), cmp);
    int emp = n / 2;
    int tmp = 0;
    for (i = 0; i < n; i++)
    {
        if (i < emp)
        {
            tmp += add[i];
        }
        else
        {
            ret += add[i];
        }
    }
    printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d", n - emp, emp, ret-tmp);
    return 0;
}
#include <stdio.h>
#include <stdbool.h>
int main()
{
    bool add[256] = { false };//布尔数组过滤相同数据
    char a[10000];
    char b[10000];
    scanf("%s %s", a, b);
    char* a1 = a;
    char* b1 = b;
    while (*b1)
    {
        add[*b1] = true;//将这个字符ascll作为下标在数组中改为true
        b1++;
    }
    while (*a1)
    {
        if (!add[*a1])//取反为false的打印
        {
            printf("%c", *a1);
        }
        a1++;
    }
    return 0;
}
void swa(int* parent, int* child)
{
	int ret = *parent;
	*parent = *child;
	*child = ret;
}
void AdjustDwon(int* a, int n, int root)//向下调整算法，建小堆，前提左右子树都是小堆
{
	int parent = root;
	int child = (root * 2) + 1;//默认是左孩子
	while (child <n)
	{
		if (child+1<n&&a[child + 1] > a[child])//找出左右孩子大的那一个//循环结束条件可能会有只有左节点的情况所以这里加上child+1<n
		{
			child += 1;
		}
		if (a[child] > a[parent])//如果要建大堆把这两个小于改成大于，大于交换就是大堆
		{
			swa(&a[parent], &a[child]);
			parent = child;
			child = (parent * 2) + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{

	//向下调整算法，前提左右子树都是小堆，从根节点开始，选出左右孩子中小的那一个，跟父亲比较，如果比父亲小就交换，然后继续往下调，调到叶子节点就终止
	//如果左右子树不是小堆可以倒着从最后一个非叶子的子树开始调整//只需要找到最后一个非叶子的节点，也就是最后一个元素的父亲，n-1，找父亲的公式 = （child-1）/2，所以=（n-1-1）/2
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//堆排序是一层一层放入数组的所以每次-1就能找到前一个非叶子节点
	{
		AdjustDwon(a, n, i);
	}
	//排序
	//升序需要建大堆，因为小堆的堆顶就是最小的，而其他的数再去选数关系就乱了
	//建大堆的话只是第一个和最后一个换结构不会变，最大的和最小的交换后最大的在最后面，任何前n-1个数向下调整选出次大的数在跟倒数第二个位置交换
	int end = n - 1;
	while(end>0)//只有一个值就不需要交换了
	{
		swa(&a[0], &a[end]);//第一个和最后end-1...2.3.4....n交换
		AdjustDwon(a, end, 0);//然后选出下一个最大的上数在a[0]
		end--;
	}
}
int main()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	//HeapSort();
	HeapSort(a, 10);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}