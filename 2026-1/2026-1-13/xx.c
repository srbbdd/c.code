#define _CRT_SECURE_NO_WARNINGS
函数指针
#include <stdio.h>
int add(int x, int y)
{
	return x + y;
}
int main()
{
	printf("%p\n", &add);
	printf("%p\n", add);
	//对于函数来说，&函数名和函数名都是函数的地址
	int (*p)(int, int) = &add;//括号的int代表指针指向函数，函数的参数类型是int，外面的int代表函数返回值类型
	//int a = (*p)(2, 3);//通过解引用指针找到函数并调用，(2,3)是传递的参数
	int a = p(2, 3);//也可以直接通过指针调用函数
	printf("%d\n", a);
	printf ("%d\n",(*p)(5, 3));//加*必须加括号，不然就是p调用函数然后对返回值解引用
	printf("%d\n", p(5, 3));//这里也一样可以不写*//因为int (*p)(int,int) = &add;和int (*p)(int,int) = add;一样，add调用函数可以直接(传参)那吧add赋给p，p也可以直接(传参)
	return 0;
}
#include <stdio.h>
int add(int x, int y)
{
	return x + y;
}
void calc(int (*p)(int, int))
{
	int a = 3;
	int b = 10;
	int c = p(a, b);
	printf("%d\n", c);
}
typedef void (* pf_t)(int);//吧void(*)(int)类型重命名为pf_t
int main()
{
	calc(add);
	(*(void (*)())0)(); // (void (*)())是指针函数的类型，后面一个0是将0强制转换为一个没有参数没有返回值的函数指针
	                    //然后再解引用调用这个函数，实际上就是调用了地址0处的函数，0地址里的函数没有传参所以0后面也没有传参
	void(*signal(int, void(*)(int)))(int);//signal是函数名，第一个参数是int，第二个参数void(*)(int)是函数指针类型，然后去掉函数名和两个参数剩下void(*)(int)是个函数指针
	                                      //所以signal这个函数的返回类型是void(*)(int)函数指针类型
 //这是个函数声明，signal第一个参数是int，第二个是函数指针，这个函数指针指向的函数参数是int返回值是void，signal函数的返回类型是函数指针，返回一个void类型参数是int的函数指针
	//void(*signal(int, void(*)(int)))(int)优化
	pf_t signal(int, pf_t);//signal返回类型为pf_t第一个参数是int型第二个参数是pf_t型
	return 0;
}
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int add[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &add[i]);
    }
    for (i = 0; i < n; i++)
    {
        int j = i + 1;
        int emp = 0;
        for (j; j < n; j++)
        {
            if (add[i] < add[j])
            {
                emp = add[i];
                add[i] = add[j];
                add[j] = emp;
            }
        }
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d ",add[i]);
    }
    return 0;
}
#include <stdio.h>
int main()
{
    int n = 100;//题目规定n的值<=100
    int add[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d ", &add[i]);
        if (add[i] == 0)
        {
            break;
        }
    }
    i--;
    for (i; i >= 0; i--)
    {
        printf("%d ", add[i]);
    }
    return 0;
}