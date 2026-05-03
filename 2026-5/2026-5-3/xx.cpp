#include <iostream>
using namespace std;
//不要返回局部变量的引用!
//int& test()
//{
//	int a = 10;
//	return a;
//}
//int& test1()
//{
//	static int a1 = 20;//静态变量，全局区，程序结束自动释放
//	return a1;
//}
//void func(int& ret)//==int* const ret = &a
//{
//	;
//}
//int main()
//{
//    int& r = test();
//	cout << r<<"\n";
//	cout << r << "\n";
//	int& r1 = test1();
//	cout << r1 << "\n";
//	cout << r1 << "\n";
//	test1() = 1000;//返回值是引用，可以作为左值
//	cout << r1;
//	int a = 999;
//	//引用本质是int* const p1 = &a
//	int& p1 = a;
//	//p1 = 20 ==*p1 = 20;
//	p1 = 20;
//	func(a);
//	return 0;
//}
//void show(const int& a)
//{
//	//a = 1000;//const可以防止误操作
//	cout << a;
//}
//int main()
//{
//	//int a = 10;
//	//int& ref = a;
//	//const int& p1 = 10;// 编译器帮忙给了一块内存存入10然后int& p1 = 那块内存
//	//p1 = 10;//const修饰变成只读状态
//	int a1 = 100;
//	show(a1);
//	return 0;
//}
//int func(int a =10, int b = 20, int c= 30)//形参默认值，如果不传参就默认为这些数值
//{
//	return a + b + c;
//}
////int func1(int a, int b= 10, int c)//注意事项如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值
////{
////	;
////}
//// 如果函数声明有了默认参数，函数实现就不能有默认参数 
//int func2(int a = 10, int b = 10);//声明
//int func2(int a,int b)//实现
//{
//	return a + b;
//}
//int main()
//{
//	cout<<func()<<"\n";
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	cout << func(a, b, c)<<"\n";
//	cout << func(a) << "\n";
//	cout << func2(10,10) << "\n";
//	return 0;
//}
void func(int a ,int = 10)//只写一个数据类型是属于占位参数 ,占位操作是必须传参// 占位操作也可以有默认参数
{
	;
}
int main()
{
	int a = 10;
	func(a,10);
	return 0;
}