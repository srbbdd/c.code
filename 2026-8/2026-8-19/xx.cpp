#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	int age;
	string name;
};
class Great5
{
public:
	bool operator()(Person p1)
	{
		return p1.age == 5;
	}
};
class Great
{
public:
	bool operator()(int i)
	{
		return i == 5;
	}
};
void test1()
{
	vector <int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>::iterator test = find_if(v1.begin(), v1.end(), Great()/*查找规则*/);
	if (test != v1.end())
	{
		cout << *test << '\n';
	}
	else
	{
		cout << "no\n";
	}
}
void test2()
{
	vector<Person> v;
	Person p1("aa", 1);
	Person p2("bb", 2);
	Person p3("cc", 3);
	Person p4("dd", 4);
	Person p5("ee", 5);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	vector<Person>::iterator test = find_if(v.begin(), v.end(),Great5());
	if (test != v.end())
	{
		cout << test->name << ' ' << test->age << '\n';
	}
	else
	{
		cout << "no\n";
	}
}
void test3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(1);
	vector<int> ::iterator test = adjacent_find(v.begin(), v.end());//会查找是否存在相同的相邻元素，如果有会返回第一个相邻元素的迭代器
	if (test != v.end())
	{
		cout << *test << '\n';
	}
	else
	{
		cout << "no\n";
	}
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}