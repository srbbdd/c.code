#include <iostream>
#include <list>//list的迭代器只能前移或后移
using namespace std;
void printlist(const list<int>& l1)
{
	for (list<int>::const_iterator head = l1.begin(); head != l1.end(); head++)
	{
		cout << *head << ' ';
	}
	cout << '\n';
}
void test()
{
	list <int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	printlist(l1);
	list <int>l2(l1.begin(), l1.end());
	printlist(l2);
	list<int> l3(l2);
	printlist(l3);
	list<int> l4(10, 1000);
	printlist(l4);
}
void test1()
{
	list<int> l1;
	l1.assign(10, 100);
	printlist(l1);
	list<int> l2 = l1;
	printlist(l2);
	list<int> l3;
	l3.assign(l1.begin(), l1.end());
	printlist(l3);
	list<int> l4;
	l4.push_back(1);
	l4.push_back(2);
	l4.push_back(3);
	l4.push_back(4);
	l4.swap(l1);
	printlist(l1);
	printlist(l4);

}
void test2()
{
	list <int> l1(10, 3);
	printlist(l1);
	if (l1.empty())
	{
		;
	}
	else
	{
		cout << l1.size()<<'\n';
	}
	l1.resize(5);
	printlist(l1);
	l1.resize(15, 0);
	printlist(l1);
}
void test3()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_front(100);
	printlist(l1);
	l1.pop_back();
	printlist(l1);
	l1.pop_front();
	printlist(l1);
	l1.insert(l1.begin(), 10000);
	printlist(l1);
	list<int>::iterator head = l1.begin();
	l1.insert(++head, 10000000);
	printlist(l1);
	head = l1.begin();
	l1.erase(head);
	printlist(l1);
	head = l1.begin();
	l1.erase(++head);
	printlist(l1);
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(1);
	printlist(l1);
	l1.remove(1);//remove删除所有相同的节点
	printlist(l1);
	l1.clear();
	printlist(l1);
	cout << "1";
}
int main()
{
	//test();
	//test1();
	//test2();
	test3();
	return 0 ;
}