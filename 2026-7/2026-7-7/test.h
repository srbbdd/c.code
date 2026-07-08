#pragma once;
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
class Person
{
public:
	Person(string name);
	string name;
	deque<int>score;
	int zong;
};
void mount(deque<Person>& p1);
bool cmp(Person v1,Person v2);
void printv(deque<Person> v1);