#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
//__FILE__    //进行编译的源文件
//__LINE__    //文件当前的行号
//__DATE__    //文件编译日期
//__TIME__    //文件编译的时间
//__STDC__    //如果编译器遵循ANSI C其值为1否则未定义
int main()
{
	FILE* p1 = fopen("test.txt", "w");
	assert(p1);
	fprintf(p1, "%s %d %s %s",\
		__FILE__,\
        __LINE__,\
		__TIME__,\
		__DATE__);//\转译回车续行
	fclose(p1);
	p1 = NULL;
	return 0;
}
/// /宏
#define square(x) x*x//square宏名（x）参数  x*x宏体//宏名必须和括号靠在一起
#define square1(x) ((x)*(x))
int main()
{
	int r = square(5);//5的平方
	//int r = square(5+1);
	//==  r =5+1*5+1;
	printf("%d\n", r);
	return 0;
}
#define doubl(x) (x)+(x)
#define doubl1(x) ((x)+(x))
#define m 100
int main()
{
	int r = 10 * doubl(3);
	// ==  r = 10*(3)+(3);
	doubl1(m + 2);//先替换m然后x((100+2)+(100+2))
	//"m"字符串不会被替换
	return 0;
}
#include <stdio.h>
int main()
{
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    int i = 0;
    int add[n][m];
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            scanf("%d", &add[i][j]);
        }
    }
    int rep = 0;
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            scanf(" %d ", &rep);
            if (rep != add[i][j])
            {
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes");
    return 0;
}
#define pppr(N)printf("the value of " #N " is %d\n",N);//#可以将传进来的参数转换成他对应的字符串 pppr（a）==("the value of " “a” " is %d",a==10)
int main()
{
	int a = 10;
	pppr(a);
	int b = 20;
	pppr(b);
	return 0;
}