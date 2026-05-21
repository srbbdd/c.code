#include<iostream>
#include <string>
using namespace std;
//class Calculator
//{
//public:
//	virtual int getResult() = 0;//纯虚函数，有了纯虚函数这个类也被叫做抽象类，抽象类不能实例化，并且子类必须重写抽象类中的纯虚函数，否则也属于抽象类
//	int a;
//	int b;
//};
//class Add:public Calculator
//{
//	int getResult()
//	{
//		return a + b;
//	}
//};
//class Sub :public Calculator
//{
//	int getResult()
//	{
//		return a - b;
//	}
//};
//class Mul :public Calculator
//{
//	int getResult()
//	{
//		return a * b;
//	}
//};
//int main()
//{
//	Calculator* p1 = new Add;//创建Add并让父类指向子类发生多态,此时p1的虚函数表已经被覆盖为Add的函数
//	p1->a = 10;
//	p1->b = 10;
//	cout << p1->getResult()<<"\n";
//	delete p1;
//	Calculator* p2 = new Sub;
//	p2->a = 100;
//	p2->b = 99;
//	cout << p2->getResult()<<'\n';
//	delete p2;
//	Calculator* p3 = new Mul;
//	p3->a = 2;
//	p3->b = 2;
//	cout << p3->getResult() << '\n';
//	delete p3;
//	return 0;
//}
class AbstractDrink
{
public:
	virtual void Boil() = 0;
	virtual void Brew() = 0;
	virtual void PourInCup() = 0;
	virtual void PutSomething() = 0;
	void maleDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};
class coffee:public AbstractDrink
{
	void Boil()
	{
		cout << "coffee1\n";
	}
	void Brew()
	{
		cout << "coffee2\n";
	}
	void PourInCup()
	{
		cout << "coffee3\n";
	}
	void PutSomething()
	{
		cout << "coffee4\n";
	}
};
class Tea :public AbstractDrink
{
	void Boil()
	{
		cout << "Tea1\n";
	}
	void Brew()
	{
		cout << "Tea2\n";
	}
	void PourInCup()
	{
		cout << "Tea3\n";
	}
	void PutSomething()
	{
		cout << "Tea4\n";
	}
};
int main()
{
	AbstractDrink* p1 = new coffee;
	AbstractDrink* p2 = new Tea;
	p1->maleDrink();
	p2->maleDrink();
	delete p1;
	delete p2;
	return 0;
}