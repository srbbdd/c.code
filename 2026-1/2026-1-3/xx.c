#define _CRT_SECURE_NO_WARNINGS
//大小端
//数据正着存放叫，大端字节序存储
//倒着叫，小端字节序存储//以字节为单位所以叫字节序
//高位字节序的内容存放在低地址处，吧低位放在高位地址处，就是大端字节序存储
//高位字节序放在高地址，低位放在低地址处，就是小端字节序存储
//#include <stdio.h>
//int main()
//{
//	int a = 20;
//	return 0;
//}
//#include <stdio.h>
////判断大小端存储
// int add()
//{
//	int a = 1;
//	//拿到a的起始地址
//	return *(char*)&a;
//}
//int main()
//{
//	if (add())
//	{
//		printf("小端");
//	}
//	else
//	{
//		printf("大端");
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	char a = -1;//同signed
//	signed char b = -1;//内存中==11111111111111111111111111111111截断==11111111打印整形提升==11111111111111111111111111111111取反加一换源码10000000000000000000000000000001
//	unsigned char c = -1;//内存中==11111111111111111111111111111111截断==11111111打印整形提升无符号默认补零==00000000000000000000000011111111%d打印有符号数，符号位0为正==255
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
//#include <stdio.h>
////获取图像相同概率
//int main()
//{
//    int m = 0;
//    int n = 0;
//    scanf("%d %d", &m, &n);
//    //两个图像
//    int add[m][n];
//    int add2[m][n];
//    int i = 0;
//    //第一个图像输入
//    for (i = 0; i < m; i++)
//    {
//        int j = 0;
//        for (j = 0; j < n; j++)
//        {
//            scanf("%d ", &add[i][j]);
//        }
//    }
//    //第二个图像输入
//    for (i = 0; i < m; i++)
//    {
//        int j = 0;
//        for (j = 0; j < n; j++)
//        {
//            scanf("%d ", &add2[i][j]);
//        }
//    }
//    //获取图像每个像素的百分比
//    float bfb = 100.0 / (n * m);
//    //计数器
//    float count = 0.0f;
//    for (i = 0; i < m; i++)
//    {
//        int j = 0;
//        for (j = 0; j < n; j++)
//        {
//            //循环遍历对比
//            if (add[i][j] == add2[i][j])
//            {
//                count += bfb;
//            }
//        }
//    }
//    printf("%.2f", count);
//    return 0;
//}
#include <stdio.h>
//求素数和
int main()
{
    int l = 0;
    int r = 0;
    scanf("%d %d", &l, &r);
    int i = 0;
    int su = 0;
    for (i = l; i <= r; i++)
    {
        int j = 0;
        for (j = 2; j <= i; j++)
        {
            if (i % j == 0 && i != j)
            {
                break;
            }
            if (j == i)
            {
                su += i;
            }
        }
    }
    printf("%d", su);
    return 0;
}