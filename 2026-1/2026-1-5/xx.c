#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <limits.h>
//#include <float.h>
//unsigned char i = 0;//unsigned char 取值范围0~255，死循环
//int main()
//{
//	/*for (i = 0; i <= 255; i++)
//	{
//		printf("hello world");
//	}*/
//	printf("%d\n", INT_MAX);
//	printf("%f", FLT_MAX);
//	return 0;
//}
//浮点型的存储
//#include <stdio.h>
//int main()
//{
//	int n = 9;
//	float* pfloat = (float*)&n;
//	printf("n的值%d\n", n);
//	printf("*pfloat的值为%f\n", *pfloat);
//	*pfloat = 9.0;
//	printf("n的值%d\n", n);
//	printf("*pfloat的值为%f\n", *pfloat);
//	return 0;
// }
#include <stdio.h>
//判断字母
int main()
{
    char a = 0;
    while (scanf(" %c", &a) != EOF)
    {
        if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z')
        {
            printf("%c is an alphabet.\n", a);
        }
        else
        {
            printf("%c is not an alphabet.\n", a);
        }
    }
    return 0;
}
#include <stdio.h>
//N个数之和
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int add[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &add[i]);
    }
    int num = 0;
    for (i = 0; i < n; i++)
    {
        num += add[i];
    }
    printf("%d", num);
    return 0;
}
#include <stdio.h>
//有序插入
int main()
{
    int n = 0;
    scanf("%d", &n);
    int add[n + 1];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &add[i]);
    }
    //插入值
    int b = 0;
    scanf("%d", &b);
	//从后往前找位置插入//将不是插入位置的值后移
    for (i = n; i >= 0; i--)
    {
        if (add[i - 1] < b)
        {
            add[i] = b;
            b = add[n];
            break;
        }
        else
        {
            add[i] = add[i - 1];
        }
    }
    for (i = 0; i < n + 1; i++)
    {
        printf("%d ", add[i]);
    }
    return 0;
}