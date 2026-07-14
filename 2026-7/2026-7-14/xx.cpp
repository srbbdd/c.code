#include <iostream>
#include <list>
using namespace std;
bool mycompare(int v1,int v2)
{
	return v1 > v2;//降序
	//return v1 < v2;//升序
}
void printl(list<int>& l1)
{
	for (list<int>::iterator head = l1.begin(); head != l1.end(); head++)
	{
		cout << *head << ' ';
	}
	cout << '\n';
}
void test()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	cout << l1.front()<<'\n';//list存储结构不支持随机访问
	cout << l1.back() << '\n';
	list<int>::iterator head = l1.begin();
	head++;
	cout << *head<<'\n';
	head++;
	cout << *head << '\n';
	head--;//支持双向访问 
	//head++1;//不支持随机访问
}
void test1()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	printl(l1);
	l1.reverse();
	printl(l1);
	l1.sort();//所有不支持随机访问的迭代器的容器，不可以用标准算法sort(l1.begin(),l1.end())不行，但是它有自己的成员函数,默认排序是从小到大
	printl(l1);
	l1.sort(mycompare);
	printl(l1);
}
int main()
{
	//test();
	test1();
	return 0;
}