#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
int main()
{
	//vector<Person> p1;
	//Person p2("aa", 11);
	//Person p3("bb", 12);
	//Person p4("cc", 13);
	//Person p5("dd", 14);
	//Person p6("ee", 15);
	//p1.push_back(p2);
	//p1.push_back(p3);
	//p1.push_back(p4);
	//p1.push_back(p5);
	//p1.push_back(p6);
	//for (vector<Person>::iterator head = p1.begin(); head != p1.end(); head++)
	//{
	//	cout << head->age << '\n' << head->name << '\n';//返回的是Person*
	//}
	//vector<Person*> pp;
	//pp.push_back(&p2);
	//pp.push_back(&p3);
	//pp.push_back(&p4);
	//pp.push_back(&p5);
	//pp.push_back(&p6);
	//for (vector<Person*>::iterator head = pp.begin(); head != pp.end(); head++)
	//{
	//	cout <<':' << (*head)->age << '\n'<<':' << (*head)->name << '\n';//返回的Person**
	//}
	//vector嵌套
	vector<vector<int>> p1;
	vector <int>v1;
	vector <int>v2;
	vector <int>v3;
	vector <int>v4;
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	p1.push_back(v1);
	p1.push_back(v2);
	p1.push_back(v3);
	p1.push_back(v4);
	for (vector<vector<int>>::iterator head =p1.begin();head!=p1.end(); head++)//head 是vector<int>的指针
	{
		for (vector<int>::iterator head1 = (*head).begin(); head1 != (*head).end(); head1++)//head1 是vector<int>嵌套容器的起始位置,是int*类型
		{
			cout << *head1<<' ';
		}
		cout << '\n';
	}
	return 0;
}