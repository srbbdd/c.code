#include <iostream>
#include <string>
using namespace std;
//函数模板不是万能的，某些特定类型需要具体化方式做特殊实现
class Person
{
public:
	Person(int age, string name)
	{
		this->age = age;
		this->name = name;
	}
	int age;
	string name;
};
template<class T>
bool test(T &a,T &b)
{
	return a == b;
}
template<>bool test(Person& a, Person& b)//template<>函数模板重载类型
{
	if (a.age == b.age && a.name == b.name)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int a = 30;
	int b = 20;
	bool ret = test(a, b);
	if (ret)
	{
		cout << "1\n";
	}
	else
	{
		cout << "2\n";
	}
	Person p1(18, "jj");
	Person p2(18, "jj");
	ret = test(p1, p2);
	if (ret)
	{
		cout << "1\n";
	}
	else
	{
		cout << "2\n";
	}
	return 0;
}