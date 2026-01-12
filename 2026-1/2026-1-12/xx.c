#define _CRT_SECURE_NO_WARNINGS
数组指针
#include <stdio.h>
void print1(int (*p)[5], int r, int c)
{
	int i = 0;
	for (i=0;i<r;i++)
	{
		int j = 0;
		for (j = 0; j < c; j++)
		{
			printf("%d ", *(*(p + i) + j));//二维数组的首元素是他的第一行,i表示行，j表示列,先+到i行然后解引用+到第j个元素
			printf("%d", p[i][j]);//等价写法
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
	print1(arr, 3, 5);
	return 0;
}
#include <stdio.h>
//小鱼的游泳时间
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int time1 = 0;
    int time2 = 0;
    //全部换算分钟
    time1 = a * 60 + b;
    time2 = c * 60 + d;
    //计算差值
    a = time2 - time1;
    //换回小时和分钟
    b = a / 60;
    c = a % 60;
    printf("%d %d", b, c);
    return 0;
}
#include <stdio.h>
//最多可以买多少只笔
int main()
{
    float a = 0.0f;
    float b = 0.0f;
    scanf("%f %f", &a, &b);
    //换算共多少钱
    float mony = a + (b / 10);
    int i = 1;
    while (1)
    {
        //每只笔1.9
        if (i * 1.9 > mony)
        {
            printf("%d", i -= 1);
            return 0;
        }
        i++;
    }
    return 0;
}
#include <stdio.h>
//平均分
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", ((a * 2) + (b * 3) + (c * 5))/10);//题目规定输入是十的倍数
    return 0;
}