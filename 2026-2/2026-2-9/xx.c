#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void getmemory(char**/*修改*/ p)//这里是一级指针不会改变外面的str
{
	*p = (char*)malloc(100);//给p开辟了空间但没有吧空间返回去，而出了函数p也被销毁了
	//内存泄漏
}
void test(void)
{
	char* str = NULL;
	getmemory(&str);//str还是空指针
	strcpy(str, "hello word");//空指针解引用会崩溃
	printf(str);
	free(str);
	str = NULL;
}
int main()
{
	test();
	return 0;
}
int* f1(void)
{
	int x = 10;
	return &x;//函数调用结束会销毁，如果有指针接收它就会变成野指针
}
int* f2(void)
{
	int* ptr;//没有初始化随机值//野指针
	*ptr = 10;//随机访问
	return ptr;
}
char* getmemory(void)
{
 返回栈空间地址的问题
	char p[] = "hello word";//函数调用结束内容被销毁，str接收就是野指针
	return p;
}
void test(void)
{
	char* str = NULL;
	str = getmemory;
	printf(str);
}
int main()
{
	test();
	return 0;
}
int globalvar = 1;//数据段
void test()
{
	static int a = 1;//数据段
	int loca = 1;//局部变量是栈区
	int num[10] = 0;//局部变量是栈区
	char char2[] =//局部变量是栈区/*"abcd";代码段*/;
	char* char3[] =//局部变量是栈区 /*"abcd";代码段*/;
	int* ptr =//局部变量是栈区 /*(int*)malloc(sizeof(int) * 4);堆区*/
	int* ptr2 = //局部变量是栈区/*(int*)calloc(4,sizeof(int));堆区*/
	int* ptr3 = //局部变量是栈区/*(int*)realloc(ptr3,sizeof(int) * 4);堆区*/
	free(ptr);//局部变量是栈区
	free(ptr2);//局部变量是栈区
	free(ptr3);//局部变量是栈区
}
#include <stdio.h>
//空心正方形图案
int main()
{
    int a = 0;
    while (scanf("%d", &a) != EOF)
    {
        int i = 0;
        int j = 0;
        for (i = 0; i < a; i++)
        {
            for (j = 0; j < a; j++)
            {
                if (j == 0 || j == a - 1 || i == 0 || i == a - 1)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
#include <stdio.h>
//矩阵交换
int main()
{
    int n = 0;
    int m = 0;
    scanf("%d %d ", &n, &m);
    int add[n][m];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            scanf("%d ", &add[i][j]);
        }
    }
    int k = 0;
    scanf("%d ", &k);
    char t = '0';
    int a = 0;
    int b = 0;
    while (k--)
    {
        t= getchar();
        scanf(" %d %d",&a,&b);
        int i = 0;
        if (t == 'r')
        {
            for (i = 0; i < m; i++)
            {
                int emp = add[a-1][i];
                add[a-1][i] = add[b-1][i];
                add[b-1][i] = emp;
            }
        }
        else if (t == 'c')
        {
            for (i = 0; i < n; i++)
            {
                int emp = add[i][a-1];
                add[i][a-1] = add[i][b-1];
                add[i][b-1] = emp;
            }
        }
        getchar();
    }
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            printf("%d ", add[i][j]);
        }
        printf("\n");
    }
    return 0;
}