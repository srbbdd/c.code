#include <iostream>
using namespace std;
//构造函数
//class Person
//{
//public:
//	//构造和析构都必须实现，如果不写则会自动调用一个空实现
//	Person()//构造函数名与类名相同，不需要返回类型，可以有参数，可以发生重载,创建对象自动调用，并且只调用一次
//	{
//		cout << "11\n";
//	}
//	//析构函数，清理操作
//	~Person()//函数名与类名一致但要在左侧加~，没有返回类型，不能传参，不可以发生重载，对象销毁前自动调用，而且只会调用一次
//	{
//		cout << "22\n";
//	}
//};
//int main()
//{
//	Person p;
//	return 0;
//}
class Person
{
public:
	Person()//无参构造
	{
		cout << "11\n";
	}
	Person(int a)//有参构造
	{
		age = a;
		cout << "33\n";
	}
	Person(const Person& p)//拷贝构造函数,语法需要加const并且与引用传递
	{
		age = p.age;//将传入的值的属性全部拷贝过来
		cout << "拷贝\n";
	}
	int age;

	~Person()
	{
		cout << "22\n";
	}
};
int main()
{
	//调用
	//1.括号法
	//Person p;//默认构造函数调用
	//Person p2(10);//括号法调用有参构造函数
	//Person p3(p2);//调用拷贝构造函数
	////注意事项
	////调用默认构造函数不要加（）,Person p ()这样会变成函数声明;
	//cout << "p2  =  " << p2.age<<"\n";
	//cout << "p3  =  " << p3.age<<"\n";
	//2.显示法
	//Person p;
	//Person p2 = Person(10);//有参构造
	//Person p3 = Person(p2);//拷贝
	//Person(10);//匿名对象，如果Person p2 = Person(10)就相当于将这个匿名对象命名为p2//特点，当前行执行结束后，系统会立即回收匿名对象
	////注意事项，不要用拷贝构造函数初始化匿名函数
	////3.隐式转换法
	Person p4 = 10;// == Person p4 = Person(10)
	Person p5 = p4;//拷贝构造 == Person p5 = Person (p4)
	return 0;
}