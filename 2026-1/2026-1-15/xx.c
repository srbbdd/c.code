#define _CRT_SECURE_NO_WARNINGS
//回调函数
//通过函数指针调用的函数叫回调函数
#include <stdio.h>
//void sort(int* p, int sz)
//{
//	int flag = 1;
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j <sz-1-i ; j++)
//		{
//			if (p[j]> p[j + 1])
//			{
//				int tmp = p[j];
//				p[j] = p[j + 1];
//				p[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag)
//		{
//			break;
//		}
//	}
	//for (i = 0; i < sz; i++)
	//{
	//	int j = 0;
	//	for (j = i + 1; j < sz; j++)
	//	{
	//		if (p[i] > p[j])
	//		{
	//			int tmp = p[i];
	//			p[i] = p[j];
	//			p[j] = tmp;
	//		}
	//	}
	//}
//}
//qsort函数--可以排序任意类型的数据
//void qsort(void* base, size_t num, size_t width, int(_cdecl* cmp)(const void* e1, const void* e2));
//void* base//指向要排序的数组的起始地址
//size_t num//待排序的数组元素个数
//size_t width//待排序的数据元素的大小
//int(_cdecl* cmp)(const void* e1, const void* e2);//函数指针-比较函数
//_cdecl函数调用约定
//int acc(const void* e1, const void* e2)//为qsort函数提供的比较函数
//{
//	//void是无具体类型的指针不能直接解引用，也不能+-整数//这种类型的指针可以接收任意类型的地址
//	return (*(int*)e1 - *(int*)e2);//void类型解引用需要强制类型转换，因为我要比较的数组是int类型所以强制转换为int*
//	//qsort规定如果e1>e2返回正数，如果e1==e2返回0，如果e1<e2返回负数
//}
//int ace(const void* e1, const void* e2)
//{
//	return (*(char*)e1) - (*(char*)e2);
//}
//int main()
//{
//	int arr[] = { 6,5,4,3,2,1, };//如果想要排成降序，只需要吧比较函数里的e1-e2改成e2-e1即可
//	char arr2[] = { 'd','c','b','a','f','e', };//字符也一样只把比较函数的参数强制类型转换改成char*
//	int sz = sizeof(arr2) / sizeof(arr2[0]);
//	qsort(arr2, sz,sizeof(arr2[0]),ace);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%c ", arr2[i]);
//	}
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
////结构体排序
//struct stu
//{
//	char name[20];
//	int age;
//};
//int name(const void* e1, const void* e2)
//{
//	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);//strcmp返回值和qsort要求的返回值一致
//}
//void test2()
//{
//	struct stu s[] = { {"zhangsan",15},{"lisi",30},{"wangwu",10}, };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]),name);
//}
//int main()
//{
//	test2();
//	return 0;
//}