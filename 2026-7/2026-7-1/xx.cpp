#include <iostream>
#include <vector>
#include <deque>
using namespace std;
void test()
{
	vector<int> v1;
	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		if (p != &v1[0])//统计扩展内存 次数
		{
			p = &v1[0];
			num++;
		}
	}
	cout <<"num = " << num << '\n';
	vector <int>v2;
	v2.reserve(10);//可以预留20个元素的空间，减少扩容次数,不会初始化
	num = 0;
	p = NULL;
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(i);
		if (p != &v2[0])//统计扩展内存 次数
		{
			p = &v2[0];
			num++;
		}
	}
	cout <<"num = " << num << '\n';
	cout << v2.capacity()<<'\n';
}
void printd(const deque<int>& d1)//加const不可修改
{
	for (deque<int>::const_iterator/*这里也要加const*/ head = d1.begin(); head != d1.end(); head++)
	{
		cout << *head << ' ';
	}
	cout << "\n";
}
void test1()
{
	deque<int> d1;//deque是双端数组，可以对头和尾插入删除
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printd(d1);
	deque<int> d2(d1.begin(), d1.end());//区间初始化
	printd(d2);
	deque<int>d3(10, 100);//初始化十个一百
	printd(d3);
	deque<int>d4(d3);//拷贝构造
	printd(d4);
}
int main()
{
	test();
	test1();
	return 0;
}