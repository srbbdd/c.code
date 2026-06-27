#include <iostream>
#include <vector>
using namespace std;
void printvector(vector<int>& v1)
{
	for (vector<int>::iterator head = v1.begin(); head != v1.end(); head++)
	{
		cout << *head <<' ';
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
	printvector(v1);
	vector<int> v2(v1.begin(), v1.end());//区间初始化，范围是[v1.begin(),v1.end())
	printvector(v2);
	vector<int>v3(10, 100);//10个100
	printvector(v3);
	vector<int>v4(v3);
	printvector(v4);
}
void test1()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2 = v1;
	printvector(v2);
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printvector(v3);
	vector<int>v4;
	v4.assign(10, 100);
	printvector(v4);
}
int main()
{
	//test();//构造
	test1();//赋值
	return 0;
}