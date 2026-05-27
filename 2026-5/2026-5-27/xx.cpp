#include <iostream>
#include <cstring>
//#pragma warning(disable : 4996)
using namespace std;
#include<fstream>
#include <string>
//
//class Person {
//
//public:
//    char* name; // 姓名
//    int age;    // 年龄
//
//    Person(const char* name, int age) {
//        this->name = new char[strlen(name) + 1];
//        strcpy(this->name, name);
//        this->age = age;
//    }
//
//    // write your code here......
//    Person(const Person& p1)
//    {
//        this->age = p1.age;
//        this->name = new char[strlen(p1.name) + 1];
//        strcpy(this->name, p1.name);
//    }
//
//    void showPerson() {
//        cout << name << " " << age << endl;
//    }
//
//    ~Person() {
//        if (name != nullptr) {
//            delete[] name;
//            name = nullptr;
//        }
//    }
//
//};
//
//int main() {
//
//    char name[100] = { 0 };
//    int age;
//
//    cin >> name;
//    cin >> age;
//
//    Person p1(name, age);
//    Person p2 = p1;
//
//    p2.showPerson();
//
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//class Array {
//private:
//	int n;//数组大小 
//	int* a;//数组 
//public:
//	Array() {
//		cin >> n;
//		a = new int[n];
//		for (int i = 0; i < n; i++) cin >> a[i];
//	}
//	~Array() {
//		delete[]a;
//	}
//	int getlen() {
//		return n;
//	}
//	int get(int i) {
//		return a[i];
//	}
//	// write your code here......
//	Array(const Array& p1)
//	{
//		this->a = new int[p1.n];
//		for (int i = 0; i < p1.n; i++)
//		{
//			this->a[i] = p1.a[i];
//		}
//		this->n = p1.n;
//	}
//	void show() {
//		for (int i = 0; i < n; i++) cout << a[i] << ' ';
//	}
//};
//int main() {
//	Array a;
//	Array b = a;
//	b.show();
//	return 0;
//}
int main()
{
	//ofstream p1;//输出流
	//p1.open("text.txt", ios::out);//打开文件，文件text.txt，打开方式ios::out写入
	//p1 << "111";//写入文件

	//p1.close();//关闭文件 
	ifstream p1;
	p1.open("text.txt", ios::in);
	if (!p1.is_open())//p1.is_open()文件打开失败会返回false成功为true
	{
		cout << "yy";
	}
	//char p2[1024] = { 0 };
	//while (p1 >> p2)//数据被读完会返回一个false结束循环//读取方法1
	//{
	//	cout << p2 << "\n";
	//}
	//while (p1.getline(p2, sizeof(p2)))//getline读取一行，读取目标是char*然后是最大读取长度//读取方法2
	//{
	//	cout << p2 << "\n";
	//}
	//方法三
	//string p2;
	//while (getline(p1, p2))//p1是输入流，第二个参数是读取到的位置
	//{
	//	cout << p2 << "\n";
	//}
	//方法四 
	char c;
	while ((c = p1.get()) != EOF)//读取直到EOF，文件末尾
	{
		cout << c << "\n";
	}
	p1.close();
	return 0;
}