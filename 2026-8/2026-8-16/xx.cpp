#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>//内建函数对象头文件
using namespace std;
void printv(vector<int> v1)
{
	for (vector<int>::iterator head = v1.begin(); head != v1.end(); head++)
	{
		cout << *head << '\n';
	}
}
class T
{
public:
	bool operator()(int a,int b)//二元谓词
	{
		return a > b;
	}
};
void test()
{
	vector<int> v1;
	v1.push_back(4);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(2);
	v1.push_back(1);
	sort(v1.begin(), v1.end());
	printv(v1);
	sort(v1.begin(), v1.end(), T());
	cout << "==========================================\n";
	printv(v1);
}
void test1()
{
	negate<int> n;//内建函数，一元仿函数，取反函数
	cout<<n(50)<<'\n';
	plus<int>p;//二元仿函数，加法函数,除此之外还有minus  multiplies  divides  modulus分别是减法  乘法  除法  取模
	cout << p(1, 2)<<'\n';
	vector<int> v1;
	v1.push_back(4);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(1);
	cout << "========================\n";
	sort(v1.begin(), v1.end());//这里不填第三个函数默认是less<T>是否小于，仿函数
	printv(v1);
	cout << "========================\n";
	sort(v1.begin(), v1.end(), greater<int>()/*是否大于,仿函数*/);
	printv(v1);
}
int main()
{
	//test();
	test1();
	return 0;
}