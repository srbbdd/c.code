#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char a[20] = "aaaaaaaaa";
	strcpy(a, "hell");//\0也会被拷贝
	printf("%s", a);
	//char* p = "abcdef";//常量字符串
	//char arr[] = "ada";
	//strcpy(p, arr);//strcmp的目标空间必须是可变的
	return 0;
}
#include <stdio.h>
char* my_strcpy(char* arr2, const char* arr)
{
	char* ret = arr2;
	while (*arr2++=*arr++)
	{
		;
	}
	//*arr2 ='\0';
	return ret;
}
int main()
{
	char arr[] = "abcdef";
	char arr2[20] = { 0 };
	my_strcpy(arr2, arr);
	printf("%s", arr2);
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <assert.h>
//字符串追加
char* my_strcat(char* arr, const char* ret)
{
	assert(arr && ret);
	int a = arr;
	while (*++arr)
	{
		;
	}
	while (*arr++ = *ret++)
	{
		;
	}
	return a;
}
int main()
{
	char arr[20] = "hello ";
	//strcat(arr, "world");
	my_strcat(arr, "world");
	printf("%s", arr);
	return 0;
}
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[20] = "zhangsan";
	char arr2[] = "zhangsanfeng";
	if (strcmp(arr1, arr2)>0)//arr1>arr返回>0等于返回0小于返回<0的数
	{
		printf("==");
	}
	return 0;
}
#include <stdio.h>
int my_strcmp(const char* a, const char* b)
{
	while(*a!='\0' || *b != '\0')
	{
		if (*a>*b)
		{
			return *a - *b;
		}
		else if (*a < *b)
		{
			return *a - *b;
		}
		a++;
		b++;
	}
	return 0;
}
int main()
{
	char a[] = "assd";
	char b[] = "assd";
	int c=my_strcmp(a, b);
	if (c > 0)
	{
		printf(">");
	}
	if (c < 0)
	{
		printf("<");
	}if (c == 0)
	{
		printf("=");
	}
	return 0;
}
