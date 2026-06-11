#include <iostream>
using namespace std;
//template <class T>//class/typename
//void test(T& a, T& b)
//{
//	T p1;
//	p1 = a;
//	a = b;
//	b = p1;
//}
//template <class T>
//void aa()
//{
//	cout << "hh\n";
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	test(a, b);
//	cout << a << "  " << b << "\n";
//	//aa();//函数模板必须要确定出T的数据类型才能使用
//	aa<int>();
//	return 0;
//}
template<class T>
void test(T* add,int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (add[i] > add[j])
			{
				T p1 = add[i];
				add[i] = add[j];
				add[j] = p1;
			}
		}
    }
}
int main()
{
	int add[10] = { 8,7,5,4,3,7,98,4,2,6 };
	test(add, 10);
	for(int i = 0; i < 10; i++)
	{
		cout << add[i] << "\n";
	}
	cout << "char\n";
	char arr[10] = { '2','3','4','1','6','4','9','9','5' };
	test(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << '\n';
	}
	char arr2[] = "dcba";
	test(arr2, (int)strlen(arr2));
	cout << arr2 << '\n';
	return 0;
}