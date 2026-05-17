#include <iostream>
using namespace std;
// 继承
//class C
//{
//public:
//	void header()
//	{
//		cout << "头\n";
//	}
//	void footrt()
//	{
//		cout << "底\n";
//	}
//	void left()
//	{
//		cout << "左\n";
//	}
//	void content()
//	{
//		cout << "c\n";
//	}
//};
//class Python :public C//继承C里面的公共内容//class 子类 ：继承方式 父类
//{
//public:
//	void content()
//	{
//		cout << "python\n";
//	}
//};
//class CPP :public C
//{
//public:
//	void content()
//	{
//		cout << "CPP\n";
//	}
//};
//int main()
//{
//	C c;
//	c.content();
//	c.footrt();
//	c.header();
//	c.left();
//	CPP cpp;
//	cpp.content();
//	cpp.footrt();
//	cpp.header();
//	cpp.left();
//	Python P;
//	P.content();
//	P.footrt();
//	P.header();
//	P.left();
//	return 0;
//}
class A
{
public:
	int a;
protected:
	int b;
private:
	int c;
};
class p1 :public A
{
public:
	void func()
	{
		a = 10;//公共还是公共
		b = 10;//保护还是保护
		//c = 10;//私有还是私有
	}
};
class p2 :protected A//保护权限继承除私有全部变为保护权限
{
	void func()
	{
		a = 100;
		b = 100;
		c = 100;
	}
};
class p3 :private A//私有继承除已有私有其他也全部改为私有
{
	void func()
	{
		a = 100;//私有权限类内可访问
		b = 100;
		c = 100;//父类的私有不可访问
	}
};
class p3son:public p3
{
public:
	void func()
	{
		a = 1000;//public继承私有依然私有
		b = 1000;
		c = 1000; 
	}
}
int main()
{
	p1 s1;
	s1.a = 100;
	s1.b = 100;//保护权限无法再类外访问 
	s1.c = 100;
	p2 s2;
	s2.a = 100;//保护权限
	s2.b = 100;//保护权限
	s2.c = 100;
	p3 s3;
	s3.a = 100;//私有权限不可访问
	s3.b = 100;
	s3.c = 100;
	return 0;
}