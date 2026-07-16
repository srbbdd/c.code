#include <iostream>
#include <set>
using namespace std;
void prints(set<int> s1)
{
	for (set<int>::iterator head = s1.begin(); head != s1.end(); head++)
	{
		cout << *head << ' ';
	}
	cout << '\n';
}
void printms(multiset<int> s1)
{
	for (multiset<int>::iterator head = s1.begin(); head != s1.end(); head++)
	{
		cout << *head << ' ';
	}
	cout << '\n';
}
void test()
{
	set<int>s1;
	multiset<int>ss1;//他们在插入时会自动排序，但set容器不允许有重复的元素，multiset可以
	s1.insert(1);//只有insert可以插入
	s1.insert(1);//无法重复插入
	s1.insert(5);
	s1.insert(9);
	s1.insert(4);
	s1.insert(3);
	prints(s1);//自动排序
	set<int>s2(s1);//拷贝构造
	prints(s2);
	set<int> s3;
	s3 = s2;//赋值也一样
	prints(s3);
	ss1.insert(1);
	ss1.insert(1);
	ss1.insert(5);
	ss1.insert(6);
	ss1.insert(3);
	ss1.insert(2);
	ss1.insert(1);
	printms(ss1);//自动排序可重复插入，
	multiset<int> ss2(ss1);//这都一样
	printms(ss2);
	multiset<int>ss3;
	ss3 = ss2;
	printms(ss3);
}
int main()
{
	test();
	return 0;
}