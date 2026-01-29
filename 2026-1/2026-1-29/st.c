#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//// 杨氏矩阵
//struct point
//{
//	int x;
//	int y;
//};
//struct point seek(int(*arr)[3], int a, int b,/*int* ps,int* py*/ int n)
//{
//	int i = 0;
//	struct point p = { -1,-1 };
//	for (i = 0; i < b; i++)
//	{
//		int min = 0;
//		int left = 0;
//		int right = b - 1;
//		while (left <= right)
//		{
//			min = (left + right) / 2;
//			if (arr[i][min] < n)
//			{
//				left = min + 1;
//			}
//			else if (arr[i][min]>n)
//			{
//				right = min - 1;
//			}
//			else
//			{
//				p.x = i;
//				p.y = min;
//				//*ps = i;
//				//*py = min,
//				return p;
//			}
//		}
//	}
//	//*ps = -1;
//	//*py = -1,
//	return p;
//}
//int main()
//{
//	int add[3][3];
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 3; j++)// 一次循环初始化一列
//		{
//			if (i == 0)
//			{
//				add[j][i] = j;
//			}
//			else//到第二列的值就等于上一列+1
//			{
//				add[j][i] = add[j][i - 1] + 1;
//			}
//		}
//	}
//	int n = 0;
//	scanf("%d", &n);
//	//int x = 3;行
//	//int y = 3;列
//	struct point c = seek(add, 3, 3,/*&x,&y*/ n);
//	//int hang = 2;
//	//int lie = 0;
//	//while (hang >= 0  && lie <= 2 )
//	//{
//	//	if (add[hang][lie] < n)
//	//	{
//	//		lie++;
//	//	}
//	//	else if (add[hang][lie] > n)
//	//	{
//	//		hang--;
//	//	}
//	//	else
//	//	{
//	//		printf("在%d %d",hang,lie);
//	//		return 0;
//	//	}
//	//}
//	printf("%d %d",c.x,c.y);
//	return 0;
//}
#include <stdio.h>
#include <string.h>
//判断一个字符串左旋能不能得出另一个字符串
int add(char* a, char* b)
{
	/*int i = 0;
	int len = strlen(a);
	for (i = 0; i < len; i++)
	{
		char tmp = a[0];
		int j = 0;
		for (j = 0; j < len; j++)
		{
			a[j] = a[j + 1];
		}
		a[len - 1] = tmp;
		if (strcmp(a, b) == 0)
		{
			return 1;
		}
	}
	return 0;*/
	int len = strlen(a);
	int len2 = strlen(b);
	if (len != len2)//长度不同不肯相同
	{
		return 0;
	}
	strncat(a, a, len);//在a字符串追加一个a字符串那从第二个字符开始就得到了所以字符左旋后的子串
	char* ret = strstr(a, b);
	if (ret == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	//char a[6];
	//char b[6];
	//scanf("%s %s", &a, &b);
	char a[20] = "abcdef";
	char b[7] = "abcde";
	int ret = add(a, b);
	if (ret==1)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	return 0;
}