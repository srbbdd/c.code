#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1 = "abcdefga";
	size_t ret = s1.find('a');//查找是否有a,并返回下标,如果不存在返回-1
	cout << ret << '\n';
	size_t ret1 = s1.rfind('a');//rfind是从尾往头找，find是从头往尾找
	cout << ret1 << '\n';
	string s2 = "abcdefg";
	s2.replace(0, 3, "sssssss");//替换函数,从第0个开始，替换后面三个替换成sssssss，可以理解先删除从0开始往后三个然后从0开始插入sssssss
	cout << s2 << '\n';
	string s3 = "hello";
	string s4 = "hello";
	if (s3.compare(s4) == 0)//compare比较函数s3和s4比较，等于返回0，小于返回-1，大于返回1,逐个字符比较ascll值
	{
		cout << "=\n";
	}
	string s5 = "xello";
	string s6 = "hello";
	if (s5.compare(s6) == 1)
	{
		cout << ">\n";
	}
	string p1 = "hello";
	for (int i = 0; i < p1.size(); i++)//size获得p1的长度
	{
		//cout << p1[i] << '\n';
		cout << p1.at(i) << '\n';//与p1[i]一样
	}
	p1[0] = 'x';
	cout << p1 << '\n';
	p1.at(0) = 'z';//与p1[0]='z'一样
	cout << p1 << '\n';
	return 0;
}