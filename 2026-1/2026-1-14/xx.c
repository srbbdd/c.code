#define _CRT_SECURE_NO_WARNINGS
//函数指针很学习
#include <stdio.h>
//函数指针的使用
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div(int a, int b)
{
	return a / b;
}
void cas(int (*p)(int, int))
{
	int x = 0;
	int y = 0;
	printf("输入两个数");
	scanf("%d %d", &x, &y);
	printf("%d\n", p(x, y));
}
int main()
{
	int a = 0;
	do
	{
		printf("输入1加法2减法3乘法4除法");
		scanf("%d", &a);
		switch (a)
		{
		   case 1 :
			   cas(add);
			   break;
		   case 2:
			   cas(sub);
			   break;
		   case 3:
			   cas(mul);
			   break;
		   case 4:
			   cas(div);
			   break;
		}

	} while (a);
	return 0;
}
//函数指针数组
//吧函数指针放在数组中，就是函数指针的数组
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div(int a, int b)
{
	return a / b;
}
#include <stdio.h>
int main()
{
	int (*p[4])(int, int) = { add,sub,mul,div };
	for (int i = 0; i < 4; i++)
	{
		//printf("%d\n",(*p[i])(2, 3));
		printf("%d\n", p[i](2, 3));//等价写法

	}
	return 0;
}
//通过函数指针数组更改上面的代码
//转移表
#include <stdio.h>
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div(int a, int b)
{
	return a / b;
}
int main()
{
	int a = 0;
	do
	{
		printf("输入1加法2减法3乘法4除法\n");
		scanf("%d", &a);
		if (a >= 1 && a <= 4)
		{
			int (*p[4])(int, int) = { add,sub,mul,div };
			int x = 0;
			int y = 0;
			scanf("%d %d", &x, &y);
			printf("%d\n", p[a - 1](x, y));
		}
		else
		{
			printf("输入错误\n");
			return 0;
		}

	} while (a);
	return 0;
}
//指向函数指针数组的指针
#include <stdio.h>
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div(int a, int b)
{
	return a / b;
}
int main()
{
	int(*p[4])(int,int) = {add,sub,mul,div};
	int(*(*c)[4])(int, int) = &p;//*c是个指针然后和[4]结合说明指向的是个数组，指向数组的元素类型是int(*)(int,int)函数指针
	return 0;
}
#include <stdio.h>
//BFS
int main()
{
    char s[100];
    scanf("%s", &s[0]);
    int i = 0;
    for (i = 0; i < 100; i++)
    {
        if (s[i] == 'b' || s[i] == 'B')
        {
            if (s[i + 1] == 'o' || s[i + 1] == 'O')
            {
                if (s[i + 2] == 'b' || s[i + 2] == 'B')
                {
                    printf("%d", i);
                    return 0;
                }
            }
        }
    }
    printf("-1");
    return 0;
}