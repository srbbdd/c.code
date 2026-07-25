#include <iostream>
#include <set>
#include <string>
using namespace std;
void test1()
{
	set<int> s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.insert(1);
	set<int>::iterator test = s1.find(4);//查找4并且返回该元素的迭代器
	cout << *test << '\n';
	int r = s1.count(1);//统计1出现的个数但对set作用不大，set不允许插入重复元素，这里查找要么1要么0
	cout << r << '\n';
}
void test2()
{
	set<int> s1;
	pair<set<int>::iterator, bool> ret = s1.insert(10);//pair是对组，set容器插入后会返回pair类型的数据，一个是迭代器一个是bool类型
	if (ret.second)//second就是bool类型的返回数据，如果为真就是插入成功了
	{
		cout << "成功\n";
	}
	else
	{
		cout << "失败\n";
	}
	ret = s1.insert(10);
	if (ret.second)//set不允许插入重复数据
	{
		cout << "成功\n";
	}
	else
	{
		cout << "失败\n";
	}
	multiset<int>m1;
	m1.insert(10);//multiset可以插入重复的，并且不会返回pair而是返回一个迭代器
	m1.insert(10);
	for (multiset<int>::iterator head = m1.begin(); head != m1.end(); head++)
	{
		cout << *head << '\n';
	}
}
void test3()
{
	//利用对组可以返回两个值
	pair<string, int> p("hh", 18);//pair（数据类型1，数据类型2）命名（初始值1，初始值2）;
	cout << p.first << ' ' << p.second << '\n';
	pair<string, int>p2 = make_pair("aa", 19);//方式二
	cout << p2.first << ' ' << p2.second << '\n';
}
class Mycompare
{
public:
	bool operator()(int v1,int v2)const
	{
		return v1 > v2;
	}
};
void test4()
{
	//指定排序规则，
	//要在插入前更改
	set<int,Mycompare>s1;//会按照反函数的排序规则排序
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.insert(5);
	for (set<int, Mycompare>::iterator head = s1.begin(); head != s1.end(); head++)
	{
		cout << *head << ' ';
	}
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}