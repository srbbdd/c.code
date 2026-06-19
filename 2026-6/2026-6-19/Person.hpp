#include <iostream>
using namespace std;
#pragma once
template <class T, class T1>
class Person
{
public:
	Person(T name, T1 age);
	T name;
	T1 age;
	void print();
};
#include "Person.h"
template<class T, class T1>
void Person<T, T1>::print()
{
	cout << this->name << '\n';
	cout << this->age << '\n';
}
template<class T, class T1>
Person<T, T1>::Person(T name, T1 age)
{
	this->name = name;
	this->age = age;
}