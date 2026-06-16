#include <iostream>
#include <string>
using namespace std;
//class Person
//{
//public:
//	void aa()
//	{
//		cout << "person\n";
//	}
//};
//class Person1
//{
//public:
//	void aa1()
//	{
//		cout << "person\n";
//	}
//};
//template <class T>
//class Myclass
//{
//public:
//	T obj;
//	void func()//类模板中的成员函数在调用时才去创建
//	{
//		obj.aa();
//	}
//	void func1()
//	{
//		obj.aa1();
//	}
//};
//int main()
//{
//	Myclass <Person> p1;
//	p1.func();
//	p1.func1();
//	return 0;
//}
template<class T,class T1>
class Person
{
public:
	Person(T name, T1 age)
	{
		this->name = name;
		this->age = age;
	}
	void show()
	{
		cout << this->name<<'\n';
		cout << this->age << '\n';
	}
	T name;
	T1 age;
};
void test(Person<string, int>& p1)//指定传入类型
{
	p1.show();
}
template<class T, class T1>
void test1(Person<T, T1>& p1)//参数模板化
{
	p1.show();
	cout << "T = " << typeid(T).name() << "\n";//打印T/T1类型
	cout << "T1 = " << typeid(T1).name() << "\n";
}
template<class T>
void test2(T & p1)//整个类模板化
{
	p1.show();
	cout << "T = " << typeid(T).name() << "\n";
}
int main()
{
	Person<string,int>p1("hh", 11);
	test(p1);
	test1(p1);
	test2(p1);
	return 0;
}