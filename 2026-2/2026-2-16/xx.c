#include <stdio.h>
#include <stdlib.h>
#include "txst.h"
//<>查找策略：直接去库目录下查找
//""查找策略：1，代码所在的路径下查找，2，路径找不到就去库目录下查找
#define print(N,FORMA) printf("the value of " #N " is "FORMA "\n",N)//例如传a = N=10 #N=a，传b = N = 10.0 #N = b;
int main()
{
	int a = 10;
	float b = 10.0f;
	print(a, "%d");
	print(b, "%f");
	return 0;
}
#define CAT(Class,NUM) Class##NUM
int main()
{
	int class106 = 100;
	printf("%d\n", CAT(class, 106));//将左右两边的符号合并==class106
	return 0;
}
#define MAX(a,b) ((a)>(b)?(a):(b))
int main()
{
	int m = MAX(2, 3);
	int a = 5;
	int b = 4;
	int m1 = MAX(a++, b++);//宏是替换的先a和b比较然后a++,b++返回a，a再++，a=7，m1 = 6 b = 5
	printf("%d\n", m1);
	return 0;
}
#define MAX(x,y) ((x)>(y)?(x):(y))
//宏替换比函数调用的效率更高
//宏的参数更广泛，函数参数必须是声明类型
//宏无法调试
//宏可能会有运算优先级的问题
int max(int x, int y)
{
	return (x > y ? x : y);
}
int main()
{

	return 0;
}
#define mall(NUM,CLASS) (CLASS*)malloc((NUM)*sizeof(CLASS))
#define M 100
int main()
{
	int* p = mall(10, int);
	printf("%d\n", M);
	#undef M//取消定义
	printf("%d\n", M);
} 
#define __DEBUF__//条件编译
int main()
{
	int i = 0;
	int add[10] = { 0 };
	for (i = 0; i < 10; i++)
	{
		add[i] = i;
#ifdef __DEBUF__//常量表达式，如果__DEBUG__未定义则不编译
		printf("%d", add[i]);
#endif //__DEBUF__
	}
	return 0;
}
#define M 5
int main()
{
#if M<5
	printf("111");//不符合条件的会在预处理阶段直接删掉
#elif M==5
	printf("2222");
#else
	printf("333");
#endif
	
	return 0;
}
#define MAX 100
int main()
{
//#if defined(MAX)//判断是否被定义 #if defined == #ifdef
//	printf("1");
//#endif
#ifdef MAX//#ifdef如果定义了MAX就执行  #ifndef MAX如果没有定义就执行
	printf("1");
#endif
	return 0;
}
