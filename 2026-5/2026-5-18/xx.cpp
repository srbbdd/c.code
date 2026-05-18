#include <iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		cout << "父构造\n";
	}
	~Person()
	{
		cout << "父析构\n";
	}
	int a;
protected:
	int b;
private:
	int c;
};
class Son :public Person
{
public:
	Son()
	{
		cout << "子构造\n";
	}
	~Son()
	{
		cout << "子析构\n";
	}
	int ddd;
};
int main()
{ 
	cout << sizeof(Son)<<"\n";//父类的所有非静态成员属性都会被子类继承
	Son p1;//父类先构造，子类先析构
	return 0;
}