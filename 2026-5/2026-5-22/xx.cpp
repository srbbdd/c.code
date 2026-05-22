#include <iostream>
#include <string>
using namespace std;
//虚析构和纯虚析构
//如果是纯虚析构，该类属于抽象类，无法实例化
class Animal
{
public:
	Animal()
	{
		cout << "父构造\n";
	}
	virtual void test() = 0;
	//virtual ~Animal()//调用原理类似虚函数
	//{
	//	cout << "父析构\n";
	//}
	virtual ~Animal() = 0;//纯虚析构，和虚析构只能存在一个，
};
Animal::~Animal()//纯虚析构也需要代码实现
{
	cout << "纯虚\n";
}
class Cat :public Animal
{
public:
	Cat(string p1)
	{
		cout << "构造\n";
		name = new string(p1);
	}
	virtual void test()
	{
		cout <<*name << "111\n";
	}
	string* name;
	~Cat()
	{
		cout << "析构\n";
		if (name != NULL)
		{
			delete name;
			cout << "222\n";
		}
	}
};
int main()
{
	Animal* p1 = new Cat("a");
	p1->test();
	delete p1;//父类指针指向子类的时候，delete父类指针的时候并不会执行子类析构，只需要改为虚析构
 	return 0;
}