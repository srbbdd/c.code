#include <stdio.h>
int main()
{
	unsigned char;//能存储0-255
	unsigned char a = 200;
	 //截断后=11001000
	unsigned char b = 100;
	//截断=01100100
	unsigned char c = 0;
	c = a + b;
	//整形提升unsigned补0//一个表达式的操作数的大小达不到一个整型会发生整形提升  
	//相加==100101100但char只能存下00101100就是44
	//a+b直接打印就是正常相加然后整形打印不会发生截断，首位是0原码反码补码相同就是300
	printf("%d %d", a + b, c);
	return 0;
}
#include <stdio.h>
int main()
{
	unsigned int a = 0X1234;
	unsigned char b = *(unsigned char*)&a;//以大端存储32位a存入的是0x00001234，unsigned char取一个字节就是00
	return 0;
}
#include <stdio.h>
int main()
{
	char a[1000] = { 0 };//char的范围是-128-127；
	int i = 0;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;//-1-128 =101111111存下011111111就成了正数，当i=255正好减到0所以strlen在255处停下
	}
	printf("%d", strlen(a));
	return 0;
}
#include <stdio.h>
// 猜名次
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if ((b == 2) + (a == 3) == 1
							&& ((b == 2) + (e == 4) == 1)//题目规定每个选手只说对了一半，一共五个选手
							&& ((c == 1) + (d == 2) == 1)
							&& ((c == 5) + (d == 3) == 1)
							&& ((e == 4) + (a == 1) == 1))
						{
							if (a * b * c * d * e == 120&&a+b+c+d+e==15)//过滤有排名重复的情况
							{
								printf("a=%d b=%d c=%d d=%d e=%d", a, b, c, d, e);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
#include <stdio.h>
int main()
{
	int killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)//题目规定三人说了真话
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)//吧a，b，c，d是凶手全部遍历一次
		{
			printf("%c", killer);
		}
	}
	return 0;
}
#include <stdio.h>
//杨辉三角
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int add[n][n];
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j <= i; j++)
        {
            if (i - 1 > -1 && j - 1 > -1 && j - 1 < i - 1)//判断i-1和j-1和i-1的位置有没有越界，j-1如果小于i-1就代表这个数的上方和左上方在上一行定义了数字
            {
                add[i][j] = (add[i - 1][j - 1]) + (add[i - 1][j]);//杨辉三角这个数字就等于上方和左上方的和
            }
            else//如果没有就代表i-1或者j-1i+1会越界，也代表这个数左上方或者上方在上一行没有定义数字，所以初始化为1
            {
                add[i][j] = 1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j <= i; j++)
        {
            printf("%5d", add[i][j]);
        }
        printf("\n");
    }
    return 0;
}