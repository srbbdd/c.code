#include<iostream>
#include<fstream>
using namespace std;
class Person
{
public:
	char name[20];
	int age;
};
int main()
{
	//ofstream p1;
	//p1.open("text.txt", ios::out|ios::binary);//打开位置text.txt，打开方式 ios::out写入，写入方式ios::binary二进制
	//Person p = { "hhh",18 };
	//p1.write((const char*)&p, sizeof(Person));//写入数据&p，写入必须是const char*，第二个为数据大小
	//p1.close();
	ifstream p2;
	p2.open("text.txt", ios::in | ios::binary);//二进制读取
	if (!p2.is_open())
	{
		cout << "1";
	}
	Person p3;
	p2.read((char*)&p3, sizeof(Person));//读取p3，读取类型必须是char*，读取大小为 sizeof(Person)
	cout << p3.age <<" " << p3.name << "\n";
	p2.close();
	return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
int main() {

	// write your code here.....
	for (int i = 100; i < 1000; i++)
	{
		int a = i;
		int add = 0;
		while (a)
		{
			int j = a % 10;
			add += pow(j, 3);
			a /= 10;
		}
		if (add == i)
		{
			cout << i << "\n";
		}
	}
	return 0;
}