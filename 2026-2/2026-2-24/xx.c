#include  "xx.h"
void testSeqlist1()
{
	sl s1 = { 1 };
	seqlistint(&s1);
	seqlistintPushback(&s1, 1);
}
int main()
{
	testSeqlist1();
	return 0;
}
int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int i = 0;
    int max = 0;
    int ret = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            ret ++;
        }
        else
        {
            if (max < ret)
            {
                max = ret;
            }
            ret = 0;
        }
    }
    if (max < ret)
    {
        max = ret;
    }
    return max;
}
int findMaxConsecutiveOnes(int* nums, int numsSize)//统计数组中1的长度
{
    int i = 0;
    int ret = 0;
    int max = 0;
    for (i = 0; i < numsSize; i++)
    {
        ret = (ret + 1) * nums[i];//如果为0会被清零
        max = ret > max ? ret : max;
    }
    return max;
}
int main()
{
    int add[] = { 1,1,0,0,1,1,1 };
    findMaxConsecutiveOnes(add, 7);
}