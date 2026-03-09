#include <stdio.h>
//寻找环形链表的入口点
//结论一个指针从meet点开始走，一个指针从链表开始走他们会在入口点相遇
//slow(慢指针)
//fast(快指针)
//slow进环之后，在一圈以内快指针一定能追上慢指针，因为满指针走一圈快指针已经走了两圈
//假设slow进环之后走了x，进环之前的距离假设叫L
//slow走的路程为L+x
//假设环的长度为c
//fast走的路程是L+n*c+x//n代表圈数，fast不一定只走完一圈，快指针先进环想和满指针相遇那快指针最少走一圈追上慢指针
//L + n * c + x = 2(L+x)快指针是慢指针的二倍
//两边减去L+x = n*c = L+x == n*c-x = L；
//代码实现
struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    //先找到相遇的位置
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            slow = head;
            //一个指针从相遇点走一个从头走最终他们相遇的位置就是环的入口位置
            while (fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    return NULL;
}
int compar(const void* a1, const void* a2)
{
    return ((*(int*)a1) - (*(int*)a2));
}
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    qsort(nums, numsSize, 4, compar);
    int ret = 0;
    int i = 0;
    *returnSize = 0;
    for (i = 0; i < numsSize; i++)
    {
        int emp = nums[i];
        if (emp - ret > 1)
        {
            int j = 0;
            for (j = 0; j < emp - ret - 1; j++)
            {
                nums[(*returnSize)] = ret + 1 + j;
                (*returnSize) += 1;
            }
        }
        ret = emp;
    }
    if (numsSize - nums[numsSize - 1])
    {
        nums[(*returnSize)] = numsSize;
        (*returnSize) += 1;
    }
    return nums;
}
int main()
{
    int add[] = { 1,1 };
    int a = 0;
    findDisappearedNumbers(add, 2, &a);
    int i = 0;
    for (i = 0; i < a; i++)
    {
        printf("%d", add[i]);
    }
}