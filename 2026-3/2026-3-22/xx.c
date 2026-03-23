//插入排序
#include <stdio.h>
void InsertSort(int* a, int n)
{
    //时间复杂度为o（n^2），最坏的情况要1+2+3......+n-1等差数列求和
    for (int i = 0; i < n - 1; i++)
    {
        int end = i;
        int tmp = a[end + 1];// 保存下一个插入的值
        while (end >= 0)
        {
            if (a[end] > tmp)//如果目前的最后一个值大于要插入的值，那要插入的值就比较小所以最后的这个值要往后挪
            {
                a[end + 1] = a[end];
                end--;//和前一个值比
            }
            else
            {
                break;
            }
        }
        a[end + 1] = tmp;//比end大插入到end下一个位置
    }
}
void PrintfArray(int* a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int a[] = { 3,2,5,6,7,8,9,22,3,55 };
    InsertSort(a, 10);
    PrintfArray(a, sizeof(a) / sizeof(int));
}
                                                                                                                                                