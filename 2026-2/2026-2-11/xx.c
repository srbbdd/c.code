#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
struct s
{
	char arr[10];
	int age;
	float so;
};
//int main()
//{
//	FILE* p1 =fopen("C:\\Users\\Administrator\\Desktop\\代码记事本.txt", "r");//打开文件会返回一个FILE类型的文件信息区的指针，test文件名"w"是打开的模式
//	assert(p1);//如果没有这个文件用 "r"打开会返回NULL
//	fclose(p1); //关闭文件;
//	p1 = NULL;
//	return 0;
//}
int main()
{
	FILE* p1 = fopen("test.txt", "w");
	assert(p1);
	//字符输入函数，写入a到p1
	int i = 0;
	for ( i = 'a'; i < 'z'; i++)
	{
		fputc(i, p1);
	}
	fclose(p1);
	p1 = NULL;
	//读文件
	FILE* p1 = fopen("test.txt", "r");
	assert(p1);
	int ch = 0;
	while ((ch =fgetc(p1)) != EOF)//读取p1,读取失败会返回EOF	
	{
		printf("%c", ch);
	}
	fclose(p1);
	p1 = NULL;
	//写一行
	FILE* p1 = fopen("test.txt", "a");//"w"写文件的时候如果文件有内容，会被清空,"a"不会清空a是追加
	assert(p1);
	fputs("hello word\n", p1);
	fclose(p1);
	p1 = NULL;
	// 读一行
	FILE* p1 = fopen("test.txt", "r");
	assert(p1);
	char arr[20];
	fgets(arr,11, p1);//从p1读5个字符到arr，，最终值能读取到4个有一个空间需要给\0 
	printf("%s",arr),
	fclose(p1);
	p1 = NULL;
	//格式写入
	FILE* p1 = fopen("test.txt", "w");
	assert(p1);
	struct s p = { "zhangsan",20 ,50.5 };
	fprintf(p1,"%s %d %f", p.arr, p.age, p.so);//%s %d %f写入的数据类型，arr age so数据 ，p1写入位置
	fclose(p1);
	p1 = NULL;
	//格式读取
	FILE* p1 = fopen("test.txt", "r");
	assert(p1);
	struct s s = { 0 };
	fscanf(p1, "%s %d %f", s.arr, &(s.age), &(s.so));//整形变量要取地址，字符串数组地址就是他们本身,将p1按格式读取到s
	printf("%s %d %f", s.arr, s.age, s.so);
	fclose(p1);
	p1 = NULL;
	return 0;
}
#include <stdio.h>
//数列
	int main()
	{
		int a = 0;
		scanf("%d", &a);
		int i = 1;
		int ret = 0;
		while (a)
		{
			int c = i;
			while (c)
			{
				ret += i;
				a--;
				c--;
				if (a == 0)
				{
					printf("%d", ret);
					return 0;
				}
			}
			i++;
		}
		return 0;
	}
#include <stdio.h>
//逆序输出
void add()
{
	int i = 0;
	if (scanf("%d", &i) != EOF)
	{
		add();
		printf("%d ", i);
	}
}
int main()
{
	add();
	return 0;
}
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 判断出现最多字母是不是质数
int compar(const void* a1, const void* a2)
{
	return (*(char*)a1 - *(char*)a2);
}
int main()
{
	char add[100];
	int maxn = 0;
	int minn = 100;
	scanf("%s", add);
	qsort(add, strlen(add), 1, compar);
	int i = 0;
	int ret = 1;
	while (add[i] != '\0')
	{
		if (add[i] == add[i + 1])
		{
			ret++;
		}
		else
		{
			if (ret > maxn)
			{
				maxn = ret;
			}
			if (ret < minn)
			{
				minn = ret;
			}
			ret = 1;
		}
		i++;
	}
	if (maxn - minn <= 1)
	{
		printf("No Answer\n0");
		return 0;
	}
	for (i = 2; i <= sqrt(maxn - minn); i++)//如果不是质数那么，a*b=x ，如果a，b>根号x那么a*b>根号x*根号x也就是大于x，所以如果x是合数那他的一个因数一定小于根号x
	{
		if (maxn - minn % i == 0)
		{
			printf("No Answer\n0");
			return 0;
		}
	}
	printf("Lucky Word\n%d", maxn - minn);
	return 0;
}