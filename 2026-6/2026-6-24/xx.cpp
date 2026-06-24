#include <iostream>
#include <string>
using namespace std;
void test()
{
	//字符串拼接
	string s1 = "aaa";
	s1 += "bbb";
	cout << s1 << '\n';
	s1 += 'c';
	cout << s1 << '\n';
	string s2 = "111";
	s2 += s1;
	cout << s2 << '\n';
	string s3 = "i";
	s3.append("sss");//拼接函数
	cout << s3 << '\n';
	s3.append("aaaaaaaaa", 3);//拼接前三个
	cout << s3 << '\n';
	s3.append(s1);
	cout << s3 << '\n';
	string s4;
	s4.append(s1, 0, 3);//截取s1，从下标为0的开始,截取三个字符
	cout << s4 << '\n';
}
int main()
{
	//string s1;
	//const char* str = "hhh";
	//string s2(str);
	//cout << s2 << '\n';
	//string s3(s2);
	//cout << s3 << '\n';
	//string s4(5,'a');
	//cout << s4 << '\n';
	//string str1 = "ff";
	//string str2 = str1;
	//cout << str2 << '\n';
	//string str3;
	//str3.assign("hh");
	//cout << str3 << '\n';
	//string str4;
	//str4.assign("aaaaaaaa", 2);//仅赋值前两个
	//cout << str4 << '\n';
	//string str5;
	//str5.assign(str4);
	//cout << str5 << '\n';
	//string str6;
	//str6.assign(str5, 1);//仅拷贝前一个
	//cout << str6 << '\n';
	//string str7;
	//str7.assign(10, 'w');
	//cout << str7 << '\n';
	test();
	return 0;
}