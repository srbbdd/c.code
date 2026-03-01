//单链表
#include "test.h"
void test()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
}
int main()
{
	test();
	return 0;
}
//消失的数
int cmp(const void* a1, const void* a2)
{
    return ((*(int*)a1) - (*(int*)a2));
}
int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
    int* p1 = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    assert(p1);
    int* p2 = p1;
    int i = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int ret = 0;
    for (i = 0; i < numsSize; i++)
    {
        int emp = nums[i];
		if (ret == emp)//如果当前数和上一个数相同，说明这个数重复了
        {
            p2[0] = ret;
        }
		else if (emp - ret > 1)//增长超过1，说明中间有一个数没有出现
        {
            p2[1] = ret + 1;
        }
        ret = emp;
    }
	if (nums[numsSize - 1] != numsSize)//如果最后一个数不等于n，说明n没有出现
    {
        p2[1] = numsSize;
    }
    return p1;
}