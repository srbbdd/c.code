#define _CRT_SECURE_NO_WARNINGS
////字符串逆序
//#include <stdio.h>
//#include <string.h>
//void contrary(char* he, int zf)
//{
//	int left = 0;
//	int right = zf;
//	int tmp = 0;
//	while (left < right)
//	{
//		tmp = he[left];
//		he[left] = he[right];
//		he[right] = tmp;
//		left++;
//		right--;
//	}
//	return 0;
//}
//int main()
//{
//	char he[10001] = "0";
//	gets(he);
//	//获得最大下标元素
//	int zf = strlen(he)-1;
//	contrary(he, zf);
//	printf("%s", he);
//	return 0;
//}
#include <stdio.h>
//计算求和
int main()
{
	int a = 0;
	int n = 0;
	scanf("%d %d", &a, &n);
	int i = 0;
	int tmp = 0;
	int emp = a;
	int k = 0;
	for (i = 1; i <= n; i++)
	{
		//我的方法
		tmp +=a;
		a = (a*10) + emp;
		//老师方法
		// 例如a==2//l0*10==0+a==2//2*10+a==22//22*10+a==222
		//k=k*10+a;
		//tmp+=k;
	}
	printf("%d", tmp);
	return 0;
}