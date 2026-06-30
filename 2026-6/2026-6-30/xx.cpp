#include <iostream>
#include <vector>
using namespace std;
void printv(vector<int>v1)
{
	for (vector<int>::iterator head = v1.begin(); head != v1.end(); head++)
	{
		cout << *head << ' ';
	}
	cout << '\n';
}
void test()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
    printv(v1);
	cout << v1.front() << '\n';//front获取第一个元素
	cout << v1.back() << '\n';//back获取最后一个元素
}
void test1()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printv(v1);
	printv(v2);
	v1.swap(v2);//v1与v2交换
	printv(v1);
	printv(v2);
}
void test2()
{
	vector<int> v1;
	for (int i = 0; i < 1000; i++)
	{
		v1.push_back(i);
	}
	cout << "大小" << v1.size() << '\n';
	cout<<"容量" << v1.capacity() << '\n';
	v1.resize(3);//重新指定大小 
	cout << "大小" << v1.size() << '\n';
	cout << "容量" << v1.capacity() << '\n';
	vector<int>(v1).swap(v1);//用v1创建一个匿名对象，然后他会拷贝v1的三个元素，因为前面重新指定大小只剩三个元素了，然后再和v1交换，然后交换前的浪费一千多个空间的v1就被交换给了匿名对象，匿名对象当前行执行结束就会被回收，新的v1就只有三个元素了
	cout << "大小" << v1.size() << '\n';
	cout << "容量" << v1.capacity() << '\n';
}
int main()
{
	//test();
	//test1();
	test2();
	return 0;
}