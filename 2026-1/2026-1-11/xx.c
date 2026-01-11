#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//指针数组是数组，是用来存放指针的数组
int main()
{
	int b = 0;
	int* p =&b;
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };
	int* arr[] = {arr1,arr2,arr3};//存放整形指针的数组
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			//printf("%d ", (*arr[i])++);
			//printf("%d", *(arr[i] + j));
			printf("%d", arr[i][j]);//arr加i解引用然后加j，[]操作符相当于*(arr+i)
		}
		printf("\n");
	}
	return 0;
}
//数组指针--指向数组的指针
#include<stdio.h>
int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);//数组起始位置一样所以地址一样
	printf("%p\n", arr+1);

	printf("%p\n", &arr[0]);//数组名通常表示的都是数组首元素的地址
	printf("%p\n", &arr[0]+1);

	printf("%p\n", &arr);
	printf("%p\n", &arr+1);//整个数组加一十个元素整形所以加40

	int sz = sizeof(arr);//但是有两个例外1.sizeof(数组名)2.&数组名，
	printf("%d", sz);
	int* p = arr;
	int (*p2)[10] =  &arr ;//int类型10个元素(*p2)数组指针，他的类型是int(*)[10]数组指针类型
	return 0;
}
#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//int (*p)[10] = &arr;
	int i = 0;
	int* p = arr;
	for (i = 0; i < 10; i++)
	{
		printf("%d", p[i]);
	}
	//别扭的写法
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d ", *(*p+i));
	//}
	return 0;
}
#include <stdio.h>
//上学最晚时间
int main()
{
    int s = 0;
    int u = 0;
    scanf("%d %d", &s, &u);
    int time = 0;
    if (s % u != 0)
    {
        time = s / u + 1;
    }
    else
    {
        time = s / u;
    }
    time += 10;
    int h = 0;
    if (time < 60)
    {
        while (1)
        {
            if (h + time == 60)
            {
                printf("07:%02d", h);
                return 0;
            }
            h++;
        }
    }
    else
    {
        h = 7;
        h -= time / 60;
        time %= 60;
        printf("%02d:%02d", h, 60 - time);
    }
    return 0;
}
