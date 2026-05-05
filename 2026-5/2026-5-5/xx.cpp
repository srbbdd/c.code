#include <iostream>
#include <string>
using namespace std;
// 访问权限
//公共权限 public    成员类内可以访问，类外也可以访问
//保护权限 protected 成员类内可以访问，类外不可以访问，子类可以访问父类的保护内容
//私有权限 private   成员类内可以访问，类外不可以访问，子类不可以访问父类的私有内容
//class Person
//{
//public://公告内容
//	string name;
//protected://保护内容
//	string m_car;
//private://私有内容
//	int password;
//	void func()
//	{
//		name = "zhang";
//		m_car = "拖拉机";
//		password = 123456;//均属于类内操作，可以访问
//	}
//};
//class c1//class默认权限是私有
//{
//	int m;
//};
//struct c2//默认公共
//{
//	int a;
//};
//int main()
//{
//	Person p1;
//	p1.name = "lisi";
//	//p1.m_car = "a";//无法访问
//	//p1.password = 123;//无法访问
//	//p1.func();
//	c1 a1;
//	a1.m = 10;
//	c2 a2;
//	a2.a = 10;
//	return 0;
//}
//class person
//{
//public:
//	//设置姓名
//	void setName(string M_name)
//	{
//		name = M_name;
//	}
//	string getname()
//	{
//		return name;
//	}
//	int getage()
//	{
//		return age;
//	}
//	void setidol(string Idol)
//	{
//		idol = Idol;
//	}
//	void setage(int Age)
//	{
//		if (Age >= 0 && Age <= 150)
//		{
//			age = Age;
//		}
//		else
//		{
//			cout << "1\n";
//			return;
//		}
//	}
//private:
//	string name;
//	int age = 18;
//	string idol;
//};
//int main()
//{
//	person p1;
//	p1.setName("张");
//	p1.setidol("hh");
//	p1.setage(160);
//	cout << p1.getname() <<"  "<< p1.getage() << "\n";
//	return 0;
//}
class cube
{
public:
	void setbianc(int a)
	{
		bianc = a;
	}
	int gettiji()
	{
		return (bianc * bianc * bianc);
	}
	int getmj()
	{
		return 6 * (bianc * bianc);
	}
	int getbianc()
	{
		return bianc;
	}
	bool pd(int a)
	{
		return a == bianc;
	}
private:
	int bianc;
};
int main()
{
	cube p1;
	p1.setbianc(10);
	cube p2;
	p2.setbianc(10);
	cout << p1.getmj() << "  " << p1.gettiji() << "\n";
	cout << p1.pd(p2.getbianc());
	return 0;
}