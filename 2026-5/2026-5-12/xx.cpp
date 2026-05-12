#include <iostream>
#include <string>
using namespace std;
//class Person
//{
//public:
//	void show()
//	{
//		cout << "sss\n";
//	}
//	void showage()
//	{
//		cout <<"age = " << age << "\n";//age == this->age;
//	}
//	int age;
//};
//int main()
//{
//	Person* p = NULL;
//	p->show();
//	return 0;
//}
//class Person
//{
//public:
//	//常函数
//	void func()const//加const无法修改a
//	{
//		b = 200;
//		a = 100;
//		this = NULL;//this指针本质是指针常数
//	}
//	void func1()
//	{
//		;
//	}
//	int a;
//	mutable int b;// 加mutable在常函数也可以修改
//};
//int main()
//{
//	const Person p;//常对象 
//	p.a = 100;
//	p.b = 200;//mutable在常对象也可以修改
//	p.func();//常对象只能调用常函数,因为常对象不能修改属性而普通成员函数可以修改属性
//	p.func1();
//	return 0;
//}
//class Buiding
//{
//	friend void good(Buiding& b);//友元//可以访问私有内容
//public:
//	Buiding()
//	{
//		name = "11";
//		room = "22";
//	}
//	string name;
//private:
//	string room;
//};
//void good(Buiding& b)
//{
//	cout << b.name << "\n";
//	cout << b.room << "\n";
//}
//int main()
//{
//	Buiding p;
//	good(p);
//	return 0;
//}
class Person
{
	friend class Good;//友元类
public:
	Person()
	{
		a = 10;
		b = 20;
	}
	int a;
private:
	int b;
};
class Good
{
public:
	Good(Person* p1)
	{
		P = new Person;//Person会调用构造函数初始化
	}
	void visit()
	{
		cout << P->a<<"\n";
		cout << P->b<<"\n";
	}
	Person* P;
};
int main()
{
	Person p1;
	Good a(&p1);
	a.visit();
	return 0;
}