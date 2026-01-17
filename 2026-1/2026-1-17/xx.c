#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int a[] = { 1,2,3,4};
//	printf("%d\n",sizeof(a));
//	//sizeof（数组名）==整个数组大小
//	printf("%d\n", sizeof(a+0));
//	//数组名不是单独在sizeof里所以a是说首元素地址，地址+0还是首元素所以四个字节
//	printf("%d\n", sizeof(*a));
//	//首元素地址解引用就是首元素所以四个字节
//	printf("%d\n", sizeof(a+1));
//	//a是首元素地址+1是第二个元素地址，所以四个字节
//	printf("%d\n", sizeof(a[1]));
//	//a[1]是第二个元素的大小所以四个字节
//	printf("%d\n", sizeof(&a));
//	//&a是整个数组的地址，地址占四个字节或八个字节
//	printf("%d\n", sizeof(*&a));
//	//取地址是整个数组，解引用访问的也是整个数组所以是16个字节
//	printf("%d\n", sizeof(&a+1));
//	//&a是整个数组的地址，+1是跳过整个数组，所以下个地址占四或者八个字节
//	printf("%d\n", sizeof(&a[0]));
//	//&a[0]是取首元素地址，占四或者八个字节
//	printf("%d\n", sizeof(&a[0]+1));
//	//&a[0]是取首元素地址+1到第二个元素地址，占四或者八个字节
//	return 0;
//}
//#include <stdio.h>
////明天星期几
//int main()
//{
//	int d = 0;
//	scanf("%d", &d);
//	printf("%d", (d % 7) + 1);
//	return 0;
//}
#include <stdio.h>
//田忌赛马
int add(int* u, int* a)
{
    int i = 0;
	for (i = 0; i < 3; i++)//3匹马进行比较
    {
        if ((*a) > u[i])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int cont = 0;
    int u[3];
    int a[3];
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &u[i]);
    }
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 3; i++)
    {
        if (add(u, &a[i]) == 1)
        {
            cont++;
        }
    }
    if (cont >= 2)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}