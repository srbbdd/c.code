#define _CRT_SECURE_NO_WARNINGS
//突然想起的思路
//#include <stdio.h>
////打印菱形
//int main()
//
//{
//	int n = 0;
//	scanf("%d", &n);
//	//获得菱形的中间值
//	int center = n/2+1;
//	int left = center;
//	int right = center;
//	//左边为0停止打印
//		while(left)
//		{
//			int jsq = 1;
//			int j = 0;
//			for (j = 0; j < n; j++)
//			{
//				//左右中心打印
//				if (jsq >= left && jsq <= right)
//				{
//					printf("*");
//				}
//				else
//				{
//					printf(" ");
//				}
//				jsq++;
//			}
//			printf("\n");
//			left--;
//			right++;
//		}
//		//上个循环吧中心一排也打印了，左右重新赋值
//		right = n-1;//下半段两边开始减少所以最大值减一
//		left = 2;//同理下半段开始减少从左边第二个开始打印
//		while (left <= center)
//		{
//			int jsq = 1;
//			int j = 0;
//			for (j = 0; j <n; j++)
//			{
//				if (jsq >= left && jsq <= right)
//				{
//					printf("*");
//				}
//				else
//				{
//					printf(" ");
//				}
//				jsq++;
//			}
//			printf("\n");
//			left++;
//			right--;
//		}
//	return 0;
//}
#include <stdio.h>
//同样打印菱形
//刷题的思路
int main()
{
    int a = 0;
    while (scanf("%d", &a) != EOF)
    {
        int i = 0;
        for (i = a; i > 0; i--)
        {
            int j = 0;
            int n = 0;
            for (j = 0; j < i; j++)
            {
                printf(" ");
            }
            for (n = 0; n <= a - i; n++)
            {
                printf("* ");
            }
            printf("\n");
        }
        for (i = 0; i < a + 1; i++)
        {
            printf("* ");
        }
        printf("\n");
        for (i = 1; i <= a; i++)
        {
            int j = 0;
            int n = 0;
            for (j = 0; j < i; j++)
            {
                printf(" ");
            }
            for (n = 0; n <= a - i; n++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    return 0;
}