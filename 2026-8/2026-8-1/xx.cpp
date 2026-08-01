#include <iostream>
#include <map>
using namespace std;
void test()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	map<int, int>::iterator pos = m.find(4);
	if (pos != m.end())//end是最后一个元素的下一个
	{
		cout << "yes\n";
	}
	else
	{
		cout << "no\n";
	}
	size_t ret = m.count(1);//map不能重复只能是1或0 ，mutimap可以重复
	cout << ret << '\n';
}
class Person
{
public:
	Person(string name, int age)
	{
		this->age = age;
		this->name = name;
	}
	string name;
	int age;
};
class Mcopare
{
public:
	bool operator()(int v1,int v2)const
	{
		return v1 > v2;
	}
};
class Com
{
public:
	bool operator()(Person p1, Person p2)const
	{
		return p1.age > p2.age;
	}
};
void test1()
{
	map<int, int,Mcopare/*排序规则*/> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	for (map<int, int,Mcopare>::iterator head = m.begin(); head != m.end(); head++)
	{
		cout << head->first << ' ' << head->second << '\n';
	}
	Person p1("a",1);
	Person p2("b", 2);
	Person p3("c", 3);
	Person p4("d", 4);
	map<Person, Person,Com> m1;
	m1.insert(pair<Person, Person>(p1, p2));
	m1.insert(pair<Person, Person>(p3, p4));
	for (map<Person, Person, Com>::iterator head = m1.begin(); head != m1.end(); head++)
	{
		cout << head->first.age /*这里不能用->，first不是指针*/ << ' ' << head->first.name << " 2 " << head->second.age << ' ' << head->second.name << '\n';
	}
}
int main()
{
	//test();
	test1();
	return 0;
}