#include <iostream>
//函数模板
using namespace std;
template <typename T>//声明模板
void test(T &a, T &b)
{
	T p1;
	p1 = a;
	a = b;
	b = p1;
}
int main()
{
	int a = 100;
	int b = 200;
	//使用方法
	//1，自动类型推导 
	test(a, b);
	cout << a << "  " << b << "\n";
	//2，显式指定类型
	test<int>(a, b);//<>内指定类型
	cout << a << "  " << b << "\n";
	return 0;
}