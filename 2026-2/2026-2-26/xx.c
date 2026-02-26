#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//int removeElement(int* nums, int numsSize, int val)
//{
//    int i = 0;
//    int* p1 = nums;
//    int* p2 = nums;
//    int k = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if ((*p1) != val)
//        {
//            p1++;
//            k++;
//        }
//        else if ((*p1) == val && (*p2) != val)
//        {
//            int ret = (*p2);
//            (*p2) = (*p1);
//            (*p1) = ret;
//            p1++;
//            k++;
//        }
//        p2++;
//    }
//    return k;
//}
//int removeElement(int* nums, int numsSize, int val)//ÓÅ»¯°æ 
//{
//    int i = 0;
//    int p1 = 0;
//    int p2 = 0;
//    while (p2 < numsSize)
//    {
//        if (nums[p2] != val)
//        {
//            nums[p1++] = nums[p2++];
//        }
//        else
//        {
//            p2++;
//        }
//    }
//    return p1;
//}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int ret = 0;
    int emp = 0;
    int i = 0;
    int* p1 = (int*)malloc(sizeof(int) * m + n);
    assert(p1);
    while (i< m + n)
    {
        if (nums1[ret] < nums2[emp]&&nums1[ret]!=0)
        {
            p1[i] = nums1[ret];
            ret++;
        }
        else
        {
            p1[i] = nums2[emp];
            emp++;
        }
        i++;
    }
    nums1 = p1;
}
int main()
{
    int add[] = { 1,2,3,0,0,0 };
    int arr[] = { 2,5,6 };
    merge(add, 6, 3, arr, 3, 3);

    return 0;
}