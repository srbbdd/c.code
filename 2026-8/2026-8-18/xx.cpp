#include <iostream>
#include <functional>
#include <vector>
#include <string>
using namespace std;
class Person
{
public:
	bool operator== (const Person& v1)
	{
		if (this->name == v1.name && this->age== v1.age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int age;
	string name;
	Person(string name, int age)
	{
		this-> name = name;
		this->age = age;
	}
};
void test()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator test =find(v.begin(), v.end(), 5);
	if (test != v.end())
	{
		cout << *test<<'\n';
	}
	else
	{
		cout << "no\n";
	}
	Person p1("aa", 1);
	Person p2("bb", 2);
	Person p3("cc", 3);
	Person p4("dd", 4);
	vector<Person> v1;
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	vector<Person>::iterator test2 = find(v1.begin(), v1.end(), p2);
	if (test2 == v1.end())
	{
		cout << "no\n";
	}
	else
	{
		cout << test2->age << ' ' << test2->name << '\n';
	}
}
int main()
{
	test();
	return 0;
}