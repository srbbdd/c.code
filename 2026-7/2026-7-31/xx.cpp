#include <iostream>
#include <map>
using namespace std;
void printm(map<int, int> m1)
{
	for (map<int, int>::iterator head = m1.begin(); head != m1.end(); head++)
	{
		cout << head->first << ' ' << head->second << '\n';
	}
	cout << "OVER\n";
}
void test1()
{
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	if (m1.empty())
	{
		cout << "K\n";
	}
	else
	{
		cout << "else\n";
		cout << m1.size() << '\n';
	}
	map<int, int> m2;
	m2.insert(pair<int, int>(4, 40));
	m2.insert(pair<int, int>(5, 50));
	m2.insert(pair<int, int>(6, 60));
	printm(m1);
	printm(m2);
	m1.swap(m2);
	printm(m1);
	printm(m2);
}
void test2()
{
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(make_pair(5, 6));
	m1.insert(make_pair(6, 7));
	m1.insert(make_pair(7, 8));
	//printm(m1);
	m1[10] = 100;
	//printm(m1);
	cout << m1[11]/*会创建这个元素*/ << '\n';
	cout << m1[1]<<'\n';//可以直接访问key处的实值
	printm(m1);
	m1.erase(m1.begin());
	printm(m1);
	m1.erase(5);//删除key为5的元素
	printm(m1);
	m1.erase(m1.begin(), m1.end());
	printm(m1);
	map<int, int> m2;
	m2.insert(pair<int, int>(4, 40));
	m2.insert(pair<int, int>(5, 50));
	m2.insert(pair<int, int>(6, 60));
	printm(m2);
	m2.clear();
	printm(m2);
}
int main()
{
	//test1();
	test2();
	return 0;
}