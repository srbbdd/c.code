#include <iostream>
#include <string>
using namespace std;
//class Person
//{
//public:
//	Person(int age1)
//	{
//		age= new int(age1);
//	}
//	Person& operator= (Person& p1)//深拷贝 
//	{
//		if (age != NULL)
//		{
//			delete(age);
//		}
//		age = new int(*p1.age);
//		return *this;
//	}
//	~Person()
//	{
//		if (age != NULL)
//		{
//			delete(age);
//		}
//	}
//	int* age;
//};
//int main()
//{
//	Person p1(18);
//	Person p2(20);
//	cout << *p1.age<<"\n";
//	cout << *p2.age << "\n";
//	p2 = p1;//浅拷贝,指针会指向同一空间
//	cout << *p2.age<<"\n";
//	Person p3(99);
//	p1 = p2 = p3;
//	cout << *p1.age << "\n" << *p2.age << "\n" << *p3.age << "\n";
//	return 0;
//}
//关系运算符重载
//class Person
//{
//public:
//	int age;
//	string name;
//	Person(int p,string name1)
//	{
//		age = p;
//		name = name1;
//	}
//	bool operator<(Person p)
//	{
//		if (this->name < p.name && this->age < p.age)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	bool operator==(Person p)
//	{
//		if (this->name == p.name && this->age == p.age)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//};
//int main()
//{
//	Person p1(20,"a");
//	Person p2(100,"b");
//	if (p1 < p2)
//	{
//		cout << "<\n";
//	}
//	Person p3(1, "1");
//	Person p4(1, "1");
//	if (p3 == p4)
//	{
//		cout << "==\n";
//	}
//	return 0;
//}
//调用函数运算符重载
class Print
{
public:
	void operator()(string test)
	{
		cout << test;
	}
	void operator()(int p)
	{
		cout << p;
	}
};
class Add
{
public:
	int operator()(int a, int b)//函数运算符重载没有固定写法，按需求写
	{
		return a + b;
	}
};
int main()
{
	Print p1;
	p1("hello\n");
	Add p2;
	p1(p2(10, 20));
	cout <<"\n" << Add()(100, 100) << "\n";// Add()匿名对象，计算完后就会被销毁
	return 0;
}