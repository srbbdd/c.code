#include "test.h"
Person::Person(string name)
{
	this->name = name;
}
void mount(deque<Person>& p1)
{
	for (int i = 0; i < p1.size(); i++)
	{
		for (deque<int>::iterator head = (p1.at(i).score.begin()); head != p1.at(i).score.end(); head++)
		{
			p1.at(i).zong += *head;
		}
		p1.at(i).zong /= 2;
	}
}
bool cmp(Person v1, Person v2)
{
	return v1.zong < v2.zong;
}
void printv(deque<Person> v1)
{
	for (deque<Person>::iterator head = v1.begin(); head != v1.end(); head++)
	{
		cout << "name = " << head->name << " ×Ü·Ö" << head->zong << '\n';
	}
}