#include <iostream>
using namespace std;
//多态
//静态多态：函数重载，运算符重载,编译阶段确定函数地址
//动态多态：派生类和虚函数实现运行时多态，运行阶段确定函数地址
//动态多态条件：1.继承关系 2.子类重写父类的虚函数
//重写是返回类型相同，函数名相同，形参列表全部相同
//动态多态使用需要父类的指针或引用指向子类对象
class Animal
{
public:
	//加virtual会获得一个vfptr虚函数指针，它指向虚函数表vftable，表的内部记录虚函数的地址也就是&Animal::test，当子类重写父类虚函数，子类的虚函数表内部会替换成子类的虚函数地址
	//覆盖之后当Cat/Dog调用add函数时，他收到的参数数Animal& p1 = Cat/Dog，，这时引用就指向了Cat/Dog，然后他就会从Cat/Dog的虚函数表中找这个函数
	virtual void test()//virtual 虚函数，可以让地址晚绑定
	{
		cout << "测试\n";
	}
	virtual void e()
	{
		cout << "e\n";
	}
};
class Cat:public Animal
{
public:
	void test()//子类virtual可写可不写，父类必须写
	{
		cout << "CatTest\n";
	}
	void e()
	{
		cout << "Cate\n";
	}
};
class Dog :public Animal
{
public:
	void test()
	{
		cout << "DogTest\n";
	}
	void e()
	{
		cout << "Doge\n";
	}
};
void add(Animal& p1)//支持父子之间的类型转换，地址早绑定，编译阶段确定函数地址，传什么参数都是调用Animal的函数，
{
	p1.test();
	p1.e();
}
int main()
{
	Cat p1;
	add(p1);
	Dog p2;
	add(p2);
	return 0;
}