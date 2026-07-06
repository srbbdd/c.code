#include <iostream>
#include <deque>
using namespace std;
void printd(const deque<int> v1)
{
	for (deque<int>::const_iterator head = v1.begin(); head != v1.end(); head++)
	{
		cout << *head << ' ';
	}
	cout << '\n';
}
void test()
{
	deque<int> v1;
	v1.push_back(1);//尾
	v1.push_back(3);
	v1.push_front(2);//头
	v1.push_front(1);
	printd(v1);
	v1.pop_front();//头删
	v1.pop_back();//尾删
	printd(v1);
}
void test1()
{
	deque<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_front(3);
	v1.push_front(4);
	printd(v1);
	v1.insert(v1.begin(), 1000);//再v1.begin插入1000
	printd(v1);
	v1.insert(v1. begin(), 2, 10000);//在begin除插入两个一万
	printd(v1);
	deque<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v1.insert(v1.begin(), v2.begin(), v2.end());//在v1的begin处插入v2.begin到v2.end
	printd(v1);
	v1.erase(v1.begin());//删除v1.begin处
	printd(v1);
	v1.erase(v1.begin(), v1.end());//区间删除 
	printd(v1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.clear();//清空
	printd(v1);
}
void test2()
{
	deque<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << ' ';
	}
	cout << "\n";
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << ' ';
	}
	cout << '\n';
	cout << "第一个元素" << v1.front()<<'\n';
	cout << "最后一个" << v1.back() << '\n';
}
int main()
{
	//test();
	//test1();
	test2();
	return 0;
}