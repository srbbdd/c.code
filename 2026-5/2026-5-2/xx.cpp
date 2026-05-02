#include <iostream>
using namespace std;
//int main()
//{
//	/*int* a = new int(10);
//	char* arr = new char('a');
//	delete (a);
//	delete (arr);
//	int* add = new int[10];
//	for (int i = 1; i <= 10; i++)
//	{
//		add[i-1] = i;
//	}
//	for (int i = 1; i <= 10; i++)
//	{
//		cout << add[i-1]<<" ";
//	}
//	delete[] (add);*/
//	//int test = 10;
//	//int& other = test;
//	//other = 99;
//	//cout << test;
//	//int test1 = 10;
//	//int* test2 = &test1;
//	//int*& other1 = test2;// 数据类型 &别名 = 原名
//	//*other1 = 999;
//	//cout << test1;
//	//引用必须初始化,并且一旦初始化就不能更改成其他变量的引用了
//	//int a1 = 10;
//	//int& b = a1;
//	//b = 99;
//	//cout << a1<<"\n";
//	//int c = 20;
//	//b = c;//无法更改引用变量，只会赋值 
//	//cout << a1;
//	return 0;
//}
void mySwap(int& a, int& b)
{
	int ret = a;
	a = b;
	b = ret;
}
int main()
{
	int a = 10;
	int b = 20;
	mySwap(a, b);
	cout <<"a = "<< a <<"\n" << "b = " << b;
	return 0;
}