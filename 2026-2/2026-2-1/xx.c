#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stddef.h>
#pragma pack (8)//可以修改默认对齐数
struct s1
{
	char c1;
	int i;
	char c2;
};
struct s2
{
	char c1;
	char c2;
	int i;
};
struct s5
{
	char c1;
	int c2;
	int i;
	struct s2 j;//结构体里有结构体,这里面的结构体的对齐数取它自身最大的对齐数s2的最大对齐数是4所以在偏移位置为12的位置存放，s2的大小是8个字节存到偏移值为19所以就是20字节
};
struct s6
{
	double d;// 第一个数据都是放在偏移数为0的位置，0-7
	char c;//8
	int i;//下个四的倍数是12，12-15//最终大小取最大对齐数的整数倍，现在是占16个字节正好是double大小的整数倍=16
};
struct s7
{
	char c1;//偏移值为0
	struct s6 s3;//取他自身最大的对齐数就是8他存在偏移值为8的位置8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 s3是16个字节
	double d;//24是8的整数倍所以存在24 25 26 27 28 29 30 31一共三十二个字节，算上结构体最大对齐数是8，32是8的整数倍=32 
};
struct s8
{
	struct s6 s3;
	char c1;
	double d;
};
int main()
{
	struct s1 s3;
	struct s2 s4;
	//如果编译器没有默认的对齐数那这个数据本身的大小就是对齐数
	printf("%d\n", sizeof(struct s1));//c1偏移值在0，int小于默认对齐数所以取4，他的位置在下一个四的倍数就是4567，然后c2小于默认对齐数取1，下一个1的倍数是8，到现在一个占了9个字节，最大的对齐数是4所以总大小取离9最近的四的倍数就是12
	printf("%d\n", sizeof(struct s2));
	printf("%d\n", sizeof(struct s5));
	printf("%d\n", sizeof(struct s6));
	printf("%d\n", sizeof(struct s7));


	printf("%d\n", offsetof(struct s1, c1));// 返回偏移值的宏
	printf("%d\n", offsetof(struct s1, i));
	printf("%d\n", offsetof(struct s1, c2));

	printf("%d\n", offsetof(struct s2, c1));
	printf("%d\n", offsetof(struct s2, c2));
	printf("%d\n", offsetof(struct s2, i));

	return 0;
}
//内存对齐是因为访问没有对齐的内存需要访问两次而对其的之需要一次，例如一个char和int连续存放32位一次能读32bit，4个字节第一次只能读取一大半的i所以还要在读一次，对齐的可以跳过四个字节直接正好读到读完i
//但是这样对齐会浪费一些空间，结构体内存对齐就是空间换时间
//所以在创建结构体要尽量让占用空间小的成员尽量集中在一起避免浪费空间
#include <stdio.h>
#pragma pack (4)
struct s1
{
	int i;//0-3;
	double d;//修改了默认对齐数8>4所以取4，从4位置存8个字节4-11；12个字节是最大对齐数的整数倍=12
};
#pragma pack ()
#pragma pack(1)
struct s
{
	char c1;
	int i;
	char c2;
};
int main()
{
	printf("%d", sizeof(struct s));
	return;
}
#include <stdio.h>
struct s
{
	int date[1000];
	int num;
};
void print1(struct s a)
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%d\n", a.date[i]);
	}
	printf("%d\n", a.num);
}
void print2(struct s* a)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", a->date[i]);
	}
	printf("%d", a->num);
}
int main()
{
	struct s a = { {1,2,3,4,5},100 };
	//print1(a);//传值调用，需要把数据在拷贝一份更浪费空间和时间
	print2(&a);//传址调用
	return 0;
}
#include <stdio.h>
#include <string.h>
int main()
{
    char a[20]="0";
    fgets(a, sizeof(a), stdin);
    printf("%d", strlen(a)-1);
    return 0;
}
#include <stdio.h>
void sort(int* add, int n)
{
    int i = 0;
    for (i = 0; i < n - 1; i++)
    {
        int j = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (add[j] > add[j+1])
            {
                int emp = add[j];
                add[j] = add[j+1];
                add[j+1] = emp;
            }
        }
    }
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int add[5];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &add[i]);
    }
    sort(add, n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", add[i]);
    }
    return 0;
}