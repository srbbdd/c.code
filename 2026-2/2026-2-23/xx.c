#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//int missingNumber(int* a, int b)//小消失的数
//{
//    int ret = 0;
//    for (int i = 0; i <= b; i++)
//    {
//        ret ^= i;//相同的数异或=0；ret先和0—n异或，异或支持交换率不需要有顺序
//    }
//    for (int i = 0; i < b; i++)
//    {
//        ret ^= a[i];//不管顺序怎样最后只有数组中不存在的数会剩下来，其他的都被异或抵消
//    }
//    return ret;
//}
//void rotate(int* nums, int numsSize, int k)//转轮数组
//{
//    int i = 0;
//    int ret = 0;
//    k %= numsSize;
//    if (k != 0)
//    {
//        for (i = 0; i < (numsSize - k) / 2; i++)
//        {
//            ret = nums[numsSize - k - 1 - i];
//            nums[numsSize - k - 1 - i] = nums[i];
//            nums[i] = ret;
//        }
//        for (i = 0; i < (k / 2); i++)
//        {
//            ret = nums[(numsSize - k) + i];
//            nums[(numsSize - k) + i] = nums[(numsSize - i) - 1];
//            nums[(numsSize - i) - 1] = ret;
//        }
//        for (i = 0; i < numsSize / 2; i++)
//        {
//            ret = nums[i];
//            nums[i] = nums[numsSize - i - 1];
//            nums[numsSize - i - 1] = ret;
//        }
//    }
//}
int* getConcatenation(int* nums, int numsSize, int* returnSize)
{
    int* ans = (int*)malloc((sizeof(int) * (numsSize)) * 2);
    assert(ans);
    int* ans1 = ans;
    int i = 0;
    int ret = 0;
    for (i = 0; i < numsSize * 2; i++)
    {
        ans1[i] = nums[ret];
        ret++;
        if (ret == numsSize)
        {
            ret = 0;
        }
    }
    return ans;
}
int* shuffle(int* nums, int numsSize, int n, int* returnSize)
{
    *returnSize = n * 2;
    int* add = (int*)malloc(sizeof(int) * n * 2);
    int i = 0;
    int k = 1;
    int ret = 0;
    for (i = 0; i < numsSize; i += 2)
    {
        add[i] = nums[ret];
        ret++;
        add[k] = nums[n];
        n++;
        k += 2;
    }
    nums = add;
    return nums;
}
int main()
{
    int add[] = { 1,2,1};
    int* arr = getConcatenation(add, 3, 0);
   // rotate(add, 2, 0);
    int i = 0;
    for (i = 0; i < 6; i++)
    {
        printf("%d", arr[i]);
    }
	return 0;
}