#include <iostream>
#include <vector>
using namespace std;
void printvector(vector<int> v1)
{
	for (vector<int>::iterator head = v1.begin(); head != v1.end(); head++)
	{
		cout << *head << ' ';
	}
	cout << '\n';
}
void test()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printvector(v1);
	if (v1.empty())//判空函数,为空返回true
	{
		;
	}
	else
	{
		cout << "不为空\n";
		cout << "v1capacity = " << v1.capacity()<<'\n';
		cout << "v1的大小 = " << v1.size() << "\n";
	}
	v1.resize(15,100);//重新指定大小,如果不填第二个参数会补0到十五个 
	printvector(v1);
	cout << "v1capacity = " << v1.capacity() << '\n';
	cout << "v1的大小 = " << v1.size() << "\n";
	v1.resize(5);//比原来短会截掉多出的部分
	printvector(v1);
	cout << "v1capacity = " << v1.capacity() << '\n';
	cout << "v1的大小 = " << v1.size() << "\n";
}
void test1()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printvector(v1);
	v1.pop_back();//尾删
	printvector(v1);
	v1.insert(v1.begin(), 100);//第一个参数是迭代器，在头插入100
	printvector(v1);
	v1.insert(v1.begin(), 2, 1000);//插入两个1000
	printvector(v1);
	v1.erase(v1.cbegin());//删头
	printvector(v1);
	v1.erase(v1.begin(), v1.end());//删除区间v1.begin()到v1.end()
	printvector(v1);
	vector<int> v2;
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);
	printvector(v2);
	v2.clear();//清空
	printvector(v2);
}
int main()
{
	//test();
	test1();
	return 0;
}