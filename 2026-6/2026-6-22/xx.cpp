#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void myprint(int val)
{
	cout << val << '\n';
}
int main()
{
	vector<int> p1;
	p1.push_back(10);
	p1.push_back(20);
	p1.push_back(30);
	p1.push_back(40);
	//通过迭代器访问容器数据
	//vector<int>::iterator begin = p1.begin();//起始迭代器，指向容器的第一个元素
	//vector<int>::iterator end = p1.end();//结束迭代器，指向最后一个元素的下一个位置
	//while (begin != end)
	//{
	//	cout << *begin << '\n';
	//	begin++;
	//}
	//第二种遍历
	//for (vector<int>::iterator p2 = p1.begin(); p2 != p1.end(); p2++)
	//{
	//	cout << *p2 << '\n';
	//}
	//第三种,SLT提供的遍历算法
	for_each(p1.begin(), p1.end(), myprint//打印函数);
	return 0;
}