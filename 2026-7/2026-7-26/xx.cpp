#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;
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
class Mcompare
{
public:
	bool operator()(const Person& v1,const Person& v2)const
	{
		return v1.age > v2.age;
	}
};
void test1()
{
	//自定义数据类型需要指定排序规则
	set<Person,Mcompare> s1;

	/*Person p1("aa", 1);
	Person p2("bb", 2);
	Person p3("cc", 3);
	Person p4("dd", 4);
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);*/
	for (int i = 0; i < 4; i++)
	{
		s1.insert(Person("aa" + i, i));
	}
	for (set<Person,Mcompare>::iterator head = s1.begin(); head != s1.end(); head++)
	{
		cout << head->age<<' '<<head->name << ' ';
	}
}
void printm(map<int, int>& m)
{
	for (map<int, int>::iterator head = m.begin(); head != m.end(); head++)
	{
		cout << "key = " << head->first << " value = " << head->second << '\n';
	}
	cout << "Over\n";
}
void test2()
{
	//map的所有元素都是pair,pair第一个元素为key（键值）起索引作用，第二个为value（实值），所有元素都会根据元素键值自动排序
	//同样拥有map和multimap，map不允许拥有重复key，multimap可以
	map<int/*key*/, int/*实值*/> m;
	m.insert(/*匿名对组*/pair<int, int>(1, 10));//每个元素都是pair所以插入需要pair
	m.insert(pair<int, int>(2, 11));
	m.insert(pair<int, int>(5, 12));
	m.insert(pair<int, int>(4, 13));
	m.insert(pair<int, int>(3, 14));
	printm(m);
	map<int, int> m1(m);
	printm(m1);
	map<int, int> m2;
	m2 = m1;
	printm(m2);
}
int main()
{
	//test1();
	test2();
	return 0;
}