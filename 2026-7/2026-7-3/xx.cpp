#include <iostream>
#include <deque>
using namespace std;
void printd(const deque<int> v1)
{
	for (deque<int>::const_iterator head = v1.begin(); head != v1.end();head++)
	{
		cout << *head << ' ';
	}
	cout << "\n";
}
void test()
{
	deque<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printd(v1);
	if (v1.empty())
	{
		cout << "空\n";
	}
	else
	{
		cout << "不空\n";
	}
	cout << v1.size() << '\n';
	// deque没有容量的概念
	v1.resize(15,1);//重新指定大小15用1填充
	printd(v1);
	v1.resize(5);
	printd(v1);
	cout << v1.size() << '\n';
}
int main()
{
	test();
	return 0;
}