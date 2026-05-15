#include <iostream>
using namespace std;
//递增运算符重载
class My
{
	friend ostream& operator<<(ostream& cout, My p);
public:
	My()
	{
		num = 0;
	}
	 My& operator++()//要返回引用，因为++会改变原来的值，如果返回拷贝,连续调用就会加到返回的形参上
	{
		num++;
		return *this;
	}
	//后置递增
	 My operator++(int)//int占位参数，区分函数,不能返回引用，函数结束局部数据会被销毁后续操作非法
	 {
		 My temp = *this;
		 num++;
		 return temp;//后置++返回++之前
	 }
private:
	int num;
};
ostream& operator<<(ostream& cout, My p)//后置++返回的是临时变量，这里第二个参数如果传引用会报错，语法规定加const就可以绑定到了
{
	cout << p.num;
	return cout;
}
int main()
{
	My p;
	//cout << ++(++p) << "\n";
	cout << p++<<"\n";
	cout << p;
	return 0;
}