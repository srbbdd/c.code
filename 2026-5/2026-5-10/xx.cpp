#include <iostream>
using namespace std;
//class Person
//{
//public:
//	int c;
//	static int m;//类内声明，类外初始化
//	//所有对象共享同一个函数
//	//静态成员函数只能访问静态成员变量
//	static void func()
//	{
//		m = 999;
//		c = 100;//非静态成员不能访问
//		cout << "静态\n";
//	}
//private:
//	static int b;//静态成员也有访问权限,静态函数也一样
//	static void func2()
//	{
//		cout << "静态2\n";
//	}
//};
//int Person::m = 10;//作用域Person不是全局
//int Person::b = 20;
//int main()
//{
//	Person p;
//	p.m = 10;
//	Person p1;
//	cout << p1.m<<"\n";
//	p.m = 200;
//	cout << p1.m<<"\n";
//	cout << Person::m<<"\n";//静态不属于某个对象上，所有对象都共享同一份数据，因此可以用类名访问
//	p1.func();//通过对象
//	Person::func();//通过类名
//	cout << p1.m << "\n";
//	Person::func2();
//	return 0;
//}
class Person//成员变量和成员函数分开存储
{
public:
	int a;//当有了成员变量，这个对象的大小会由内存对齐决定
	char b;
	int age;
	static int m;//一个不属于对象上，加上他对象大小不变
	Person(int age)
	{
		this->age = age;//this指针会指向调用函数的值,可以解决名称冲突
	}
	Person& PersonAddAge(Person& p)//要返回本体就要引用不然是形参返回
	{
		this->age += p.age;//比如p2调用那就p2.age+=p.age
		return *this;//比如p2调用this指向p2，然后解引用得到p2,返回
	}
	void func()//成员函数也不属于类的对象上
	{
		;
	}
	static void func1()//也一样不属于
	{
		;
	}
};
int Person::m = 10;
int main()
{
	Person p (10);
	cout << sizeof(p) << "\n";//空对象内存占用为1//c++编译器会给每个空对象分配一个字节，是为了区分空对象占内存的位置
	cout << p.age << "\n";
	Person p2(10);
	p2.PersonAddAge(p).PersonAddAge(p2).PersonAddAge(p2);//如果返回值不加&那么第二次调用函数的对象是一个拷贝的p2没有办法改变p2本身
	cout << p2.age << "\n";
	return 0;
}