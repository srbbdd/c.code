#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//枚举
typedef enum 
{
	//枚举常量
	mon = 1,
	tues,
	wed,
	thur,
	fri,
	sat,
	sun
}day;
int main()
{
	day d = fri;
	printf("%d\n", mon);//如果不写=?，和数组下标类似
	printf("%d", tues);
	printf("%d", wed);


	return 0;
}
#include <stdio.h>
//联合
union un//联合体的大小是最大的那个成员的大小
{
	int a;
	char c;
};
struct st//结构体的空间是独立的
{
	int a;
	char c;
};
int main()
{
	union un u;
	printf("%d\n", sizeof(u));
	printf("%p\n", &u);//他们共用同于一块空间
	printf("%p\n", &u.a);
	printf("%p\n", &u.c);

	return 0;
}
#include <stdio.h>

int check_sys()
{/*
	int a = 1;
	return *(char*)&a;*/
	union //匿名的只使用一次
	{
		char c;
		int a;
	}u;
	u.a = 1;
	return u.c;
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端");
	}
	else
	{
		printf("大端");
	}
	return 0;
}
#include <stdio.h>
union un
{
	int i;
	//short arr[7];
	char a [7];//虽然数组的类型是char [7]但是，看对齐数的时候看的是元素类型char
};
int main()
{
	printf("%d", sizeof(union un));//存在对齐，最大对齐数是int所以最终大小是4的倍数，五个字节下个4的倍数是8
	return 0;
}
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int arr[10] = { 0 };
	int* p = (int*)malloc(LLONG_MAX);
	if (p == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p[i] = i;
		printf("%d", p[i]);
	}
	return 0;
}
#include <stdio.h>
//小红的魔法药剂
int main()
{
    int n = 0;
    scanf("%d", &n);
    int add[5];
    int i = 0;
    int ret = 0;
    int arr[5][2];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &add[i]);
    }
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        if (add[i] < add[arr[i][0]-1] + add[arr[i][1]-1])
        {
            ret += add[i];
        }
        else
        {
            ret += add[arr[i][0]-1] + add[arr[i][1]-1];
        }
    }
    printf("%d", ret);
    return 0;
}