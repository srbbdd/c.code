#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
void test()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(false);
	v.push_back(true);
	for (vector<bool>::iterator head = v.begin(); head != v.end(); head++)
	{
		cout << *head << ' ';
	}
	vector<bool> v2;
	v2.resize(v.size());//搬运的目标容器必须提前开辟空间
	cout << '\n';
	transform/*搬运容器，将容器搬运到另一个容器*/(v.begin(), v.end(), v2.begin(), logical_not<bool>());//搬运开始位置，结束位置，搬运到目标，仿函数， 此处的是取反
	for (vector<bool>::iterator head = v2.begin(); head != v2.end(); head++)
	{
		cout << *head << ' ';
	}
}
class Print2
{
public:
	void operator()(int val)
	{
		cout << val << ' ';
	}
};
void print1(int val)
{
	cout << val<<" ";
}
void test2()
{
	vector<int> v;
	for (int i = 1; i <= 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print1);//遍历算法,开始位置，结束位置，函数
	cout << '\n';
	for_each(v.begin(), v.end(), Print2());
}
int main()
{
	//test();
	test2();
	return 0;
}