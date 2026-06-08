#pragma once
#include <iostream>
#include <string>
#include <fstream>
#define file "text.txt"
using namespace std;
class Person
{
public:
	virtual void print() = 0;
	string name;
	int number;
	string job;
};
class Payroll
{
public:
	Payroll();
	void Mune();
	Person** woker;
	int mount;
	void addworker();
	void print();
	void save();
	bool fileempty;//文件标志
	int getPerson();
	int ifExist(int id);
	void deletewoker();
	void Mod();
	void seek();
	void sort();
	void Clean_file();
	~Payroll();
};
class Employee :public Person
{
public:
	Employee(int number, string name, string job);
	void print();
};