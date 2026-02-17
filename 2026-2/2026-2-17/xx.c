#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define MY_OFFSETOF(TYP,NUM) (int)&(((TYP*)0)->NUM)//将0强转为结构体类型指针，这个元素的地址就是偏移量
//struct s
//{
//	char c1;
//	int i;
//	char c2;
//};
//int main()
//{
//	struct s s1 = { 0 };
//	printf("%d\n", MY_OFFSETOF(struct s,c2));
//	return 0;
//}
//#include <stdio.h>
//// 箭型图案
//int main()
//{
//    int n = 0;
//    int i = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (i = 0; i <= n; i++)
//        {
//            int j = 0;
//            for (j = 0; j < (n - i) * 2; j++)
//            {
//                printf(" ");
//            }
//            for (j = 0; j <= i; j++)
//            {
//                printf("*");
//            }
//            printf("\n");
//        }
//        for (i = 1; i <= n; i++)
//        {
//            int j = 0;
//            for (j = 0; j < i * 2; j++)
//            {
//                printf(" ");
//            }
//            for (j = 0; j < n - (i - 1); j++)
//            {
//                printf("*");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}
//#include <stdio.h>
////小乐乐定闹钟
//int main()
//{
//    int hour = 0;
//    int minute = 0;
//    char c = 0;
//    int k = 0;
//    scanf("%d %c %d %d", &hour, &c, &minute, &k);
//    int a = (hour * 60) + minute + k;
//    printf("%02d:%02d", (a / 60) % 24, a % 60);
//    return 0;
//}
 