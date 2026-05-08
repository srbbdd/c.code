#include <iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		cout << "默认\n";
	}
	Person(int age1)
	{
		age = age1; 
		cout << "有参构造\n";
	}
	Person(const Person& p)
	{
		age = p.age;
		cout << "拷贝\n";
	}
	~Person()
	{
		cout << "析构\n";
	}
	int age;
};
void dowork(Person p)
{
	;
}
Person d2()
{
	Person p1;
	cout << (int*)&p1 << "\n";
	return Person (p1);//这里返回的不是p1本身，而是一个值，所以在返回的时候会创建一个新的对象返回
}
void test()
{
	Person p3 = d2();
	cout << (int*)&p3 << "\n";
}
int main()
{
	//Person p1(20);
	//Person p2(p1);
	//cout << p2.age<<"\n";
	//Person p;
	//dowork(p);// == Person p = p的隐式的调用拷贝
	test();
	return 0;
}