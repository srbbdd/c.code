#include <iostream>
using namespace std;
//class Person
//{
//public:
//	Person()
//	{
//		a = 100;
//	}
//	void func()
//	{
//		cout << "Person\n";
//	}
//	void func(int a)
//	{
//		cout << "Person111111111111\n";
//	}
//	int a;
//};
//class Son :public Person
//{
//public:
//	Son()
//	{
//		a = 99;
//	}
//	void func()
//	{
//		cout << "Son\n";
//	}
//	int a;
//};
//int main()
//{
//	Son p1;
//	cout << p1.a<<"\n";
//	cout << p1.Person::a<<"\n";//同名的父类属性需要加作用域
//	p1.func();
//	p1.Person::func();//同名函数也一样
//	p1.Person::func(1);//有了同名重载也要作用域
//	return 0;
//}
//class Person
//{
//public:
//	static int a;
//	static void func()
//	{
//		cout << "Person\n";
//	}
//};
//class Son:public Person
//{
//public:
//	static int a;
//	static void func()
//	{
//		cout << "Son\n";
//	}
//};
//int Person::a = 100;
//int Son::a = 200;
//int main()
//{
//	Son p1;
//	cout << p1.a << "\n";
//	cout << p1.Person::a << "\n";//静态也一样
//	cout << Son::a << "\n";
//	cout << Son::Person::a << "\n";
//	p1.func();
//	p1.Person::func();
//	Son::func();
//	Son::Person::func();
//	return 0;
//}
//class Parent
//{
//public:
//	int a;
//	Parent()
//	{
//		a = 100;
//	}
//};
//class Son :public Parent
//{
//public:
//	int a;
//	Son()
//	{
//		a = 200;
//	}
//};
//class Parent2
//{
//public:
//	int a;
//	Parent2()
//	{
//		a = 300;
//	}
//};
//class Son2 :public Parent2, public Son
//{
//public:
//	int a;
//	Son2()
//	{
//		a = 400;
//	}
//};
//int main()
//{
//	Son2 p1;
//	cout << p1.Son::Parent::a << "\n";
//	cout << p1.Son::a << "\n";
//	cout << p1.Parent2::a << "\n";
//	cout << p1.a << "\n";
//	cout << sizeof(Son2)<<"\n";
//	return 0;
//}
class Animal
{
public :
	int age;
};
class Sheep:virtual public Animal//virtual是虚继承关键字Animal就是虚基类
{

};
class Tuo :virtual public Animal
{

}; 
class SheepTuo :public Sheep, public Tuo
{

};
int main()
{
	SheepTuo p1;
	p1.Sheep::age = 100;//p1无法直接访问age，因为继承了两份，不明确是哪一个,需要利用虚继承，虚继承后这两个数据就只被保留一份，在下面修改成200之后就全是200了
	p1.Tuo::age = 200;//virtual继承会继承一个虚继指针，指向虚继表，虚继表中记录偏移量，加上这个偏移量他们都会找到同一个数据，让这个数据独一份
	cout << p1.Sheep::age << "\n";
	cout << p1.Tuo::age << "\n";
	cout << p1.age << "\n";//虚继承之后就可以访问了
	return 0;
}