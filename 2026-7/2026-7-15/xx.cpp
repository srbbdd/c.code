#include <iostream>
#include <string>
#include <list>
using namespace std;
class Person
{
public:
	Person(string name, int age, int high)
	{
		this->name = name;
		this->age = age;
		this->high = high;
	}
	string name;
	int age;
	int high;
};
bool compare(Person& p1, Person& p2)
{
	if (p1.age != p2.age)
	{
		return p1.age < p2.age;
	}
	else
	{
		return p1.high < p2.high;
	}
}
void printl(list < Person> l1)
{
	for (list<Person>::iterator head = l1.begin(); head != l1.end(); head++)
	{
		cout << head->name << ' ' << head->age << ' ' << head->high<<'\n';
	}
	cout << "OVER\n";
}
int main()
{
	list<Person> l1;
	Person p1("a", 18, 210);
	Person p2("c", 20, 130);
	Person p3("b", 19, 120);
	Person p4("d", 21, 140);
	Person p5("e", 18, 180);
	Person p6("f", 18, 130);
	l1.push_back(p1);
	l1.push_back(p2);
	l1.push_back(p3);
	l1.push_back(p4);
	l1.push_back(p5);
	l1.push_back(p6);
	printl(l1);
	l1.sort(compare);
	printl(l1);
	return 0;
}