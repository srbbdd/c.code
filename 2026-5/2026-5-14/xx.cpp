#include <iostream>
using namespace std;
//class Bilding;//注意顺序否则Bilding无法识别good
//class good
//{
//public:
//	good();
//	void visit();
//	void visit2();
//	Bilding* b;
//};
//class Bilding
//{
//	friend void good::visit2();
//public:
//	Bilding();
//	int m;
//private:
//	int a;
//};
//Bilding::Bilding()
//{
//	m = 100;
//	a = 200;
//}
//good::good()
//{
//	b = new Bilding;
//}
//void good:: visit()
//{
//	cout << b->m;
//	cout << "\n";
//}
//void good:: visit2()
//{
//	cout << b->a;
//	cout << "\n";
//}
//int main()
//{
//	good p1;
//	p1.visit();
//	p1.visit2();
//	return 0;
//}
//运算符重载
//class Person1
//{
//public:
//	//Person1 operator+(Person1& Person)//重载加号//如果起名为operator+只需要p3 = p2+p1即可，否则例如名称为Per写法就是Person p3 = p2.Per(p1)
//	//{
//	//	Person1 p1;
//	//	p1.a = this->a + Person.a;
//	//	p1.b = this->b + Person.b;
//	//	return p1;
//	//}
//	int a = 10;
//	int b = 10;
//};
//Person1 operator+(Person1& p1,Person1& p2)//全局写法// 但是不能更改内置的数据类型的表达式的运算符
//{
//	Person1 p3;
//	p3.a = p1.a + p2.a;
//	p3.b = p1.b + p2.b;
//	return p3;
//}
//Person1 operator+(Person1& p1,int a)
//{
//	Person1 p4;
//	p4.a = p1.a + a;
//	p4.b = p1.b + a;
//	return p4;
//}
//int main()
//{
//	Person1 p1;
//	Person1 p2;
//	//Person1 p3 = p2 + p1;
//	//cout << p3.a << "\n" << p3.b << "\n";
//	Person1 p4 = p1+p2;//全局调用//==Person p4 = operator+(p1,p2),也可以发生函数重载
//	cout << p4.a << "\n" << p4.b << "\n";
//	p4 = p1 + 10;
//	cout << p4.a << "\n" << p4.b << "\n";
//	return 0;
//}
//左移运算符重载
class Person
{
	friend ostream& operator<<(ostream& cout, Person p);
public:
	Person(int a,int b)
	{
		this->a = a;
		this->b = b;
	}
private:
	//void operator<<(ostream cout)//本质是p.operator(cout)简化p<<cout所有必须在全局重载
	//{
	//	;
	//}
	int a;
	int b;
};
ostream& operator<<(ostream& cout, Person p)//本质是operator(cout,p) 简化= cout<<p,,cout是ostream标准输出流，并且只有一个必须传引用不能拷贝,引用本身是可以名字不一样的，不一定非要写成cout
{
	cout << p.a << " " << p.b << "\n";
	return cout;
}
int main()
{
	Person p(10,20);
	cout << p<< "44";//cout连续输出是链式访问但是如果重载返回类型是void那就无法继续调用
	return 0;
}