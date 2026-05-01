#include <iostream>
using namespace std;
int g = 10;
const int gg = 10;//const全局变量
int* func()
{
	int* a = new int(10);//开辟堆区int类型初始值为10的空间，并返回地址
	return a;
}
int main()
{
	int a = 10;
	cout << (long long int)&a<<"\n";
	cout << (long long int)&g<<"\n";
	static int c = 10;
	cout << (long long int)&c<<"\n";
	//字符串常量
	cout << (long long int) & "hello world" << "\n";
	const int aa = 10;//const局部变量
	cout << (long long int) & gg << "\n";
	cout << (long long int) & aa << "\n";
	int* p1 = func();
	cout << *p1 << "\n";
	free(p1);
	p1 = NULL;
	return 0;
}