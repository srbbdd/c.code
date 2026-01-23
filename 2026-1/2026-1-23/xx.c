#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//长度受限制的字符串函数
//strncpy
//strncat
//strncmp
char* my_strncpy(char* arr1,const char* arr2, const int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr1[i] = arr2[i];
		if (arr2[i] == '\0')
		{
			for (i = i + 1; i < sz; i++)
			{
				arr1[i] = '\0';
			}
		}
	}
	return arr1;
}
int main()
{
	char arr1[20] = "abcdef";
	char arr2[] = "bit";
	my_strncpy(arr1, arr2, 5);//arr1 是目标地址，arr2是拷贝源，5是拷贝5个字符
	printf("%s", arr1);
	return 0;
}
#include <stdio.h>
#include <string.h>
char* my_strncat(char* add1, const char* arr2, int sz)
{
	int ret = add1;
	while (*++add1)
	{
		;
	}
	while (sz)
	{
		*add1++ = *arr2++;
		if (*arr2 == '\0')
		{
			*add1 = '\0';
			return ret;
		}
		sz--;
	}
	*add1 = '\0';
	return ret;
}
int main()
{
	char arr1[20] = "hello ";
	char arr2[] = "world";
	my_strncat(arr1, arr2, 3);//arr1追加目标，arr2追加源，3追加三个字符// 和strncpy不同的是如果追加字符大于追加源的字符并不会补这么多次\0
	printf("%s", arr1);
	return 0;
 }
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abs";
	int a = strncmp(arr1, arr2,3);//比较三个字符
	if (a > 0)
	{
		printf(">");
	}
	else if (a < 0)
	{
		printf("<");
	}
	else
	{
		printf("=");
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
char* my_strstr(const char* add, const char* add2)
{
	while (*add)
	{
		if (*add == *add2)
		{
			int i = 0;
			while (add2[i])
			{
				if (add[i] != add2[i])
				{
					break;
				}
				i++;
			}
			if (add2[i] == '\0')
			{
				return add;
			}
		}
		add++;
	}
	return NULL;
}
int main()
{
	char ad[] = "abbbbbbcdef";
	char substr[] = "bbc";
	char* ret = my_strstr(ad, substr);
	if (ret == NULL)
	{
		printf("no");
	}
	else
	{
		printf("%s",ret);
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int compar(const void* a, const void* b)
{
    return (*(double*)a - *(double*)b);
}
int main()
{
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    int n1[n];
    char n2[n + 1];
    double n3[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &n1[i]);
    }
    scanf("%s", n2);
    for (i = 0; i < n; i++)
    {
        if (n2[i] == '1')
        {
            n3[i] = n1[i] * 0.95;
        }
        else
        {
            n3[i] = n1[i];
        }
    }
    qsort(n3, sizeof(n3) / sizeof(n3[0]), sizeof(n3[0]), compar);
    double ret = 0;
    for (i = 0; i < n; i++)
    {
        ret += n3[i];
        if (ret > k)
        {
            printf("%d", i);
            break;
        }
        else if (ret == k)
        {
            printf("%d", i + 1);
            break;
        }
    }
    return 0;
}