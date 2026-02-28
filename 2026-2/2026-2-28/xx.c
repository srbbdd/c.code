void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int p1 = m - 1;
    int p2 = n - 1;
    while (p2 >= 0 && p1 >= 0)
    {
        nums1Size--;
        if (nums1[p1] > nums2[p2])
        {
            nums1[nums1Size] = nums1[p1];
            p1--;
        }
        else
        {
            nums1[nums1Size] = nums2[p2];
            p2--;
        }
    }
	while (p2 >= 0)//p1>=0时，nums1已经在原地了，不需要移动了
    {
        nums1Size--;
        nums1[nums1Size] = nums2[p2];
        p2--;
    }
}
int main()
{
    int add[] = { 1,2,3,0,0,0 };
    int add2[] = { 2,5,6 };
    merge(add, 6, 3, add2, 3, 3);
    return 0;
}