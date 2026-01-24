#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char* my_strstr(char* str1, char* str2)
{
	const char* s1 = str1;
	const char* s2 = str2;
	const char* p = str1;
	while (*p)
	{
		s2 = str2;
		s1 = p;
		while (*s1!='\0'&&*s2!='\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return p;
		}
		p++;
	}
	return NULL;
}
int main()
{
	char ad[] = "abbbbbbcdef";
	char substr[] = "def";
	char* ret = my_strstr(ad, substr);
	if (ret == NULL)
	{
		printf("no");
	}
	else
	{
		printf("%s", ret);
	}
	return 0;
}
strtok 函数
#include <stdio.h>
#include <string.h>
int main()
{
	char* p = "@.";//分割符
	char ema[] = "zhangsan@niubi.co@dassad.m";//分割函数
	//strtok第一个参数如果不是NULL，函数将找到一个标记分割，然后返回分割出字符串的首地址
	//如果是NULL，他会继续从上个字符串分割的位置继续找
	//如果没有找到标记符，则返回空指针
	char cp[40];
	strcpy(cp, ema);
	char* ret = NULL;
	for (ret = strtok(cp, p); ret != NULL; ret = strtok(NULL, p))//for循环初始化只有第一次，返回值不是NULL代表字符串每找完，第二次循环就传空指针
	{
		printf("%s\n", ret);
	}
	//char* ret = strtok(cp, p);
	//printf("%s\n", ret);
	//ret = strtok(NULL, p);
	//printf("%s\n", ret);
	//ret = strtok(NULL, p);
	//printf("%s\n", ret);
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <errno.h>
//strerror错误报告函数//返回错误码对应的错误信息的字符串的首地址
int main()
{
	/*printf("%s\n", strerror(0));
	printf("%s\n", strerror(1));
	printf("%s\n", strerror(2));
	printf("%s\n", strerror(3));*/
	FILE* pf = fopen("D:\\java\\.minecraft","r");//如果打开失败他会把错误码记录在errno变量中，errno是c语言设置的全局的错误码存放的变量
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
	}
	return 0;
}
#include <stdio.h>
// 分数线划定
int main()
{
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    int i = 0;
    int n1[n];
    int n2[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &n1[i], &n2[i]);
    }
    int r = m * 1.5;
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = i + 1; j < n; j++)
        {
            if (n2[i] < n2[j])
            {
                int emp = n2[i];
                n2[i] = n2[j];
                n2[j] = emp;
                emp = n1[i];
                n1[i] = n1[j];
                n1[j] = emp;
            }
        }
    }
    r = n2[r - 1];
    for (i = 1; i <= n; i++)
    {
        if (n2[i] < r)
        {
            printf("%d %d\n", r, i);
            break;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (n2[i] >= r)
        {
            int j = i + 1;
            while (n2[i] == n2[j])
            {
                if (n1[i] > n1[j])
                {
                    int emp = n1[i];
                    n1[i] = n1[j];
                    n1[j] = emp;
                }
                j++;
            }
            printf("%d %d\n", n1[i], n2[i]);
        }
        else
        {
            return 0;
        }

    }
    return 0;
}