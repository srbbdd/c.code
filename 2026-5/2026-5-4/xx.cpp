#include <iostream>
#include <string>
using namespace std;
//函数重载//可以让函数重名提高复用性
//函数重载条件
//1.在同一作用域
//2.函数名称相同
//3.函数参数类型不同，或个数不同，或顺序不同
//void func()
//{
//	cout << "1\n";
//}
//void func(int a)
//{
//	cout << "2\n";
//}
//void func(double a)
//{
//	cout << "3\n";
//}
//void func(int a,double b)
//{
//	cout << "4\n";
//}
//void func(double a, int b)
//{
//	cout << "5\n";
//}
//// 函数的返回值不可以作为函数重载的条件
////int func(int a, double b)
////{
////	cout << "4\n";
////}
//int main()
//{
//	func();
//	func(1);
//	func(3.14);
//	func(1, 3.14);
//	func(3.14, 1);
//	return 0;
//}
// 引用作为重载的条件
//void func(int& a)
//{
//	cout << "1\n";
//}
//void func(const int& a)
//{
//	cout << "2\n";
//}
////函数重载默认参数
//void func1(int a,int b = 10)
//{
//	cout << "func1<<1\n";
//}
//void func1(int a)
//{
//	cout << "func1<<2\n";
//}
//int main()
//{
//	int a = 10;
//	func(a);//a为变量可读可写所以会调用打印1的函数
//	func(10);
//	func1(10);//当函数重载碰到默认参数，出现二义性，只能避免
//	return 0;
//}
//类和对象
const double PI = 3.14;
//class 类名 
class Circle
{
	//访问权限；public为公共权限
public:
	// 类中的属性和行为，我们统称为成员
	// //属性 成员属性  成员变量
	// //行为 成员函数  成员方法
	//属性 
	int r;
    //行为
	//获取圆的周长
	double calculateZC()//返回类型double函数名calculateZC
	{
		return 2 * PI * r;
	}
};
class Student
{
public:
	int number;
	string name;
	void Name(string a)
	{
		name = a;
	}
	void Number(int a)
	{
		number = a;
	}
	void PrintStudentInformation()
	{
		cout << name <<"\n" << number << "\n";
	}
	int StudentNumber()
	{
		return number;
	}
};
int main()
{
	//通过圆类创建一个具体的圆（对象）
	Circle c1;
	c1.r = 10;//属性赋值
	cout << c1.calculateZC()<<"\n";//调用行为打印
	Student p1;
	p1.Name("uuuu");
	p1.Number(99);
	p1.PrintStudentInformation();
	cout << p1.StudentNumber() << "\n";
	return 0;
}