#include <iostream>
using namespace std;
//普通函数调用可以发生隐式类型转换
//函数模板用自动类型推导不可以发生隐式类型转换
//函数模板用显示指定类型可以发生隐式类型转换
//int test1(int a, int b)
//{
//	return a + b;
//}
//template<class T>
//T test2(T a, T b)
//{
//	return a + b;
//}
//int main()
//{
//	int ret = test1(10, 20);
//	cout << ret<<'\n';
//	int a1 = 10;
//	int a2 = 20;
//	char a = 'c';
//	cout << test1(a, 10)<<'\n';//可以隐士转换 
//	cout << test2(a1,a2)<<'\n';
//	//cout << test2(a1, a);//不会隐士转换 
//	cout << test2<int>(a1, a)<<'\n';//指定就可以了
//	return 0;
//}
//普通函数和函数模板
//如果函数模板和普通函数都可以调用，优先调用普通函数
//可以通过空模板参数列表强制调用函数模板
//函数模板也可以发生函数重载
//如果函数模板匹配更好优先调用函数模板
void myprint(int a, int b)
{
	cout << "普通\n";
}
template <class T>
void myprint(T a,T b)
{
	cout << "模板\n";
}
template <class T>
void myprint(T a, T b,T c)
{
	cout << "模板重载\n";
}
int main()
{
	int a = 10;
	int b = 10;
	int c = 10;
	myprint(a, b);//优先普通
	myprint<>(a, b);//空模板参数列表强制调用模板
	myprint('a', 'b');//模板契合度更高
	myprint('a', 'b', 'c');//可以重载
	myprint(a, b, c);

	return 0;
}