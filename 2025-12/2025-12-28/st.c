#define _CRT_SECURE_NO_WARNINGS
////2025-12-27打印菱形老师思路
//#include <stdio.h>
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	//上半
//	for (i = 0; i < line; i++)
//	{
//		int j = 0;
//		//空格
//		for (j = 0; j < line - 1-i; j++)//至少打印一个*所以减一//随着行数空格在变少所以减i
//		{
//			printf(" ");
//		}
//		//*
//		for (j = 0; j < 2 * i+1;  j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//下半
//	for (i = 0; i < line - 1; i++)//上半打印了中间那行所以下半-1
//	{
//		int j = 0;
//		for (j = 0; j <=i ; j++)//下半的空格在每行都在增多所以小于i
//		{
//			printf(" ");
//		}
//		for (j = 0; j <2*(line-1-i)-1 ; j++)//总行数减一然后减去打印过的行数//每行多两个*所以乘2//但是有一行只有一个*所以要减去一个1
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
//#include <stdio.h>
////结构体复习
//struct ppo
//{
//	int num;
//	char cc[2];
//};
//int main()
//{
//	struct ppo stu = { 22,"h" };
//	struct ppo* a = &stu;//结构体指针
//	struct ppo c = { 11,"o" };
//	printf("%d\n", c.num);
//	printf("%c\n", (*a).cc);
//	printf("%c\n", *a->cc);
//	printf("%d", stu.num);
//	//*a.cc//.的优先级比解引用高
//	//*a.cc//对a.里面的cc解引用
//	return 0;
//}
//int* arr[10];//指针数组，数组的每个元素都是指针
//int (*arr)[10];//数组指针，指向数组，十个元素，每个元素是int
//#include <stdio.h>
//喝汽水
// 我的思路
//int main()
//{
//	int mony = 0; 
//	int remain = 0;
//	scanf("%d", &mony);
//	每瓶汽水一元
//	int beverage = mony;
//	每两瓶空瓶可以换一瓶 
//	while (mony)
//	{
//		beverage += mony / 2;
//		remain += mony % 2;
//		取下换后剩下的数
//		if (remain == 2)
//		{
//			beverage++;
//			重现赋值
//			remain = 1;
//		}
//		mony /= 2;
//	}
//	printf("%d", beverage);
//	return 0;
//}
//老师思路
#include <stdio.h>
int main()
{
	int mony = 0;
	scanf("%d", &mony);
	//已经喝的汽水
	int total = mony;
	//空瓶数量
	int empty = mony;
	//置换
	while (empty >= 2)
	{
		total += empty / 2;
		empty=empty / 2 + empty % 2;//%2加上上次的空瓶
	}
	if (mony > 0)
	{
		printf("%d\n", total);
	}
	else
	{
		printf("0");
	}
	//数学推导，价值交换//一个空瓶五毛钱20块钱可以换40个空瓶
	//printf ("%d",2*mony-1);
	return 0;
}