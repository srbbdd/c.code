#include <iostream>
#include <string>
#include <stack>//栈,先入后出
#include <queue>//队列,先进先出,队尾入数据，队头出数据
//栈和队列都无法遍历
using namespace std;
class Person
{
public:
	Person(int age, string name)
	{
		this->age = age;
		this->name = name;
	}
	int age;
	string name;
};
void test()
{
	stack<int>s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	cout << s1.size();
	while (!s1.empty())//empty判断是否为空
	{
		cout << s1.top() << ' ';
		s1.pop();
	}
	cout << s1.size();
}
void test1()
{
	queue<Person> q1;
	Person s(18, "aa");
	Person s1(19, "bb");
	Person s2(20,"cc");
	q1.push(s);
	q1.push(s1);
	q1.push(s2);
	while (!q1.empty())
	{
		cout << q1.front().age << ' ' << q1.front().name << ' ';
		q1.pop();
	}
}
int main()
{
	//test();
	test1();
	return 0;
}