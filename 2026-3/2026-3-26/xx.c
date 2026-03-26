//#include <stdio.h>
//void InsertSort(int* a, int n)
//{
//	int i = 0;
//	for (i = 0; i < n-1; i++)
//	{
//		int end = i;
//		int tmp = a[end + 1];
//		while (end >= 0)//这部分和希尔排序那里完全一样
//		{
//			if (a[end] > tmp)
//			{
//				a[end+1] = a[end];
//				end--;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end + 1] = tmp;
//	}
//}
//void ShellSort(int* a, int n)//希尔排序的预排序
//{
//	int gap = n;
//	while (gap > 1)//如果gap =1排序就是插入排序了无意义，等于0也一样，小于0会出错//时间复杂度o（log3为底n为对数）
//	{
//		gap = gap / 2;//每次给预排序分组，gap/2个组/3也可以但要保证最后会除成1，每组的元素间隔是gap个元素
//		int i = 0;
//		for (i = 0; i < n - gap; i++)//每次排序都是会和下一个元素比较，假设有三组第二组就和第三组已经比较了，所以n-gap
//		{//gap很大排序时间复杂度o（n）差不多每个元素都交换一次//gap很小就已经接近有序了差不多也是o（n），总体复杂度o（logN*N）//平均时间复杂度o（N^1.3）
//			int end = i;
//			int tmp = a[end + gap];//和本组的下一个元素比较
//			while (end >= 0)
//			{
//				if (a[end] > tmp)//如果大于就往前挪
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;//小于就要把这个元素下一个位置换成当前比较的元素了，
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}
//	InsertSort(a,n);
//}
//int main()
//{
//	int add[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	ShellSort(add,10);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", add[i]);
//	}
//	return 0;
//}
//堆排序
//堆的逻辑结构是一颗完全二叉树//堆的物理结构是一个数组
//计算左孩子的公式 = parent*2+1
//右孩子是=parent*2+2//这里的parent是计算左右孩子那个的节点本身
//父母 = parent = （child-1）/2
//最大堆，为大顶堆，大堆要求，树中所有的父亲都大于等于孩子
//最小堆，为小顶堆，小堆要求，树中所有的父亲都小于等于孩子
void HeapSort(int* a,int n)
{

	//向下调整算法，前提左右子树都是小堆，从根节点开始，选出左右孩子中小的那一个，跟父亲比较，如果比父亲小就交换，然后继续往下调，调到叶子节点就终止
}
int main()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	//HeapSort();
	return 0;
}