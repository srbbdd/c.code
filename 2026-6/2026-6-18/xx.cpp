#include <iostream>
#include <string>
using namespace std;
template <class T>
class base
{
public:
	T m;
};
//class Son :public base//当子类继承父类是一个类模板的时候子类在声明的时候必须要指定出父类中的类型
class Son :public base<int>//指定类型
{

};
//如果想灵活指定父类中的T，子类也需要变成类模板
template<class T1,class T2>
class Son2 :public base<T2>//T2指定父类的类型
{
public:
	Son2()
	{
		cout << "t1类型=" << typeid(T1).name() << "\n";
		cout << "t2类型=" << typeid(T2).name() << "\n";
	}
};
template<class T1,class T2>
class Person
{
public:
	T1 name;
	T2 age;
	Person(T1 name, T2 age);
	void print();
};
//类模板成员函数类外实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
	this->name = name;
	this->age = age;
}
template<class T1,class T2>
void Person<T1,T2>:: print()//类模板成员函数类外实现需要在作用域后声明模板的参数列表
{
	cout << name << '\n';
	cout << age << '\n';
}
int main()
{
	Son p1;
	Son2<int, char>s1;//这里T2接收的是char,父类就被指定为char类型
	Person<string,int> p("hh",18);
	p.print();
	return 0;
}