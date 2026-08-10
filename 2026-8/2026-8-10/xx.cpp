#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//class Myadd//函数对象（仿函数）
//{
//public:
//	int operator()(int v1, int v2)
//	{
//		return v1 + v2;
//	}
//};
//void test1()
//{
//	Myadd myadd;
//	cout << myadd(10, 10);
//}
////函数对象可以有自己的状态
//class Myprint
//{
//public:
//	void operator()(string test)
//	{
//		cout << test << '\n';
//		ret++;
//	}
//	int ret = 0;
//};
//void test2()
//{
//	Myprint myprint;
//	myprint("aaa");
//	myprint("aaa");
//	cout << myprint.ret<<'\n';//可以有自己的状态
//	myprint("aaa");
//	myprint("aaa");
//	myprint("aaa");
//	cout << myprint.ret<<'\n';
//}
//void test4(Myprint& myprint,string test)
//{
//	myprint(test);
//	cout<<myprint.ret<<'\n';
//}
//void test3()
//{
//	Myprint myprint;
//	test4(myprint, "hello C++\n");//可以作为参数传递
//}
//int main()
//{
//	//test1();
//	test2();
//	test3();
//	return 0;
//}
//谓词
//返回bool类型的反函数称谓词
//如果operator接受一个参数叫一元谓词，两个就叫二元谓词
class One
{
public:
	bool operator()(int v1)
	{
		return v1 > 5;
	}
};
void test()
{
	vector<int> v;
	for (int i = 0; i < 4; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator n = find_if(v.begin(), v.end(), One());//find_if查找一个值是否存在，第三个是谓词 匿名的函数对象，并返回迭代器
	if (n == v.end())
	{
		cout << "wu\n";
	}
	else
	{
		cout<<"you\n";
	}
}
int main()
{
	test();
	return 0;
}