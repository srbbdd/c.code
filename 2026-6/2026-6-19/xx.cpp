//#include "Person.cpp"//类模板的成员函数一开始不会创建,只会在调用时创建,如果包含.h他并不会创建类中的函数，在链接阶段就会报错
//但是如果包含cpp他就先生成cpp的文件，然后cpp文件引用了.h又会生成.h的代码然后生成.cpp的代码
//或者可以将.h和.cpp的内容合并，并将后缀改为.hpp
//#include "Person.hpp"
//int main()
//{
//	Person <string, int>p1("mm", 12);
//	p1.print();
//	return 0;
//}
#include <iostream>
#include <string>
using namespace std;
template <class T,class T1>
class Person;
template<class T,class T1>
void print1(Person<T, T1> p)//类内实现 ,提前声明,而这里还需要提前声明Person,Person是模板类也要写上
{
	cout << p.name << '\n';
	cout << p.age << '\n';
}
template<class T,class T1>
class Person
{
	//friend void print(Person<T, T1> p)//类内实现 
	//{
	//	cout << p.name << '\n';
	//	cout << p.age << '\n';
	//}
	//需要加<>因为外部实现要写成模板的类型，而这不是模板类型会报错，并且类外实现需要提前声明
	friend void print1<>(Person<T, T1>p);
public:
	Person(T name, T1 age)
	{
		this->name = name;
		this->age = age;
	}
private:
	T name;
	T1 age;
};
int main()
{
	Person<string,int> p1("saa",44);
	print1(p1);
	return 0;
}