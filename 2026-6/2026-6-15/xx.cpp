#include <iostream>
#include <string>
using namespace std;
template<class Name,class Age>
class Person
{
public:
	Person(Name p1, Age p2)
	{
		this->p1 = p1;
		this->p2 = p2;
	}
	Name p1;
	Age p2;
	void printf()
	{
		cout << this->p1<<"\n";
		cout << this->p2<<"\n";
	}
};
template<class Name1, class Age1 = int>//类模板在模板参数列表中可以有默认参数
class Person1
{
public:
	Person1(Name1 p1, Age1 p2)
	{
		this->p1 = p1;
		this->p2 = p2;
	}
	Name1 p1;
	Age1 p2;
	void printf()
	{
		cout << this->p1 << "\n";
		cout << this->p2 << "\n";
	}
};
int main()
{
	Person<string, int> p1("zz", 11);
	p1.printf();
	//Person p2("ss", 11);//类模板没有自动类型推导
	Person1<string> p("hhh", 888);//有默认参数可以不用指定
	p.printf();
	return 0;
}