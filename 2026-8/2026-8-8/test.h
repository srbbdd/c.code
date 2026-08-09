#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Person
{
public:
	Person(string name, int wage, string work)
	{
		this->name = name;
		this->wage = wage;
		this->work = work;
	}
	string name;
	int wage;
	string work;
};