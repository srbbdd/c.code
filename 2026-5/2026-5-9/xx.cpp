#include <iostream>
#include <string>
using namespace std;
//class Person
//{
//public:
//	////Person()
//	////{
//	////	cout << "默认\n";
//	////}
//	Person(int age1)//如果写了有参构造就不会再提供默认构造,但依然会提供拷贝
//	{
//		cout << "有参\n";
//		age = age1;
//	}
//	////Person(const Person& p1)//如果写了拷贝构造编译器就不会在提供其他的构造函数了
//	////{
//	////	cout << "拷贝\n";
//	////	age = p1.age;
//	////}
//	~Person()
//	{
//		cout << "析构\n";
//	}
//	int age;
//};
//int main()
//{
//	Person p1;
//	p1.age = 18;
//	Person p2(p1);//如果没写拷贝构造编译器会提供一个拷贝，拷贝每个属性的值
//	cout << p2.age<<"\n";
//	Person p;
//	return 0;
//}
//深浅拷贝 
//class Person
//{
//public:
//	Person()
//	{
//		cout << "默认\n"; 
//	}
//	Person(int age1,int high1)
//	{
//		cout << "有参\n";
//		age = age1;
//		high  = new int(high1);
//	}
//	Person(const Person& p1)
//	{
//		cout << "拷贝\n";
//		age = p1.age;
//		high = new int (*p1.high);
//	}
//	~Person()
//	{
//		cout << "析构\n";
//		if (high != NULL)
//		{
//			delete high;
//		}
//		high = NULL;
//	}
//	int age;
//	int* high;
//};
//int main()
//{
//	Person p1(18,160);
//	cout << p1.age <<"  " << *p1.high << "\n";
//	Person p2(p1);//浅拷贝，p1和p2指向的同一个位置，当有一个执行析构被释放后另一个就会报错//深拷贝是在堆区创建一个新的空间将值拷贝过去
//	cout << p2.age <<"  " << *p2.high << "\n";
//	return 0;
//}
//class Person
//{
//public:
//	//初始化列表
//	Person(int a1,int b1, int c1) :a(a1), b(b1), c(c1)
//	{
//		;
//	}
//	int a;
//	int b;
//	int c;
//};
//int main()
//{
//	Person p1(30,20,10);
//	cout << p1.a << "  " << p1.b << "  " << p1.c << "\n";
//	return 0;
//}
class Phone
{
public:
	Phone(string p1)
	{
		Pname = p1;
	}
	string Pname;
	~Phone()
	{
		cout << "2\n";
	}
};
class Person
{
public:
	Person(string name1, string pname1) :name(name1), phone(pname1)//phone（pname1） === Phone phone = pname1 === Phone phone（pname1）然后就调用构造函数
	{
		;
	}
	~Person()//析构则与构造相反
	{
		cout << "1\n";
	}
	Phone phone;//对象作为成员 
	string name;// 当其他类对象作为本类成员，构造函数先构造类对象，在构造自身

};
int main()
{
	Person p("张", "iphone");
	cout << p.name << "  " << p.phone.Pname << "\n";
	return 0;
}