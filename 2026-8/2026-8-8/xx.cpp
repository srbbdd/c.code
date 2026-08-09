#include "test.h"
int main()
{
	vector<Person> v1;
	Person p1("张三",1000,"美术");
	Person p2("李四", 1800, "策划");
	Person p3("王五", 3000, "研发");
	Person p4("哈哈", 1400, "研发");
	Person p5("零零", 2000, "策划");
	Person p6("呼呼", 1000, "美术");
	Person p7("给v", 1000, "美术") ;
	Person p8("广告费",1030, "研发");
	Person p9("广泛" , 3456, "美术");
	Person p10("瑟得瑟", 1657, "策划");
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);
	v1.push_back(p6);
	v1.push_back(p7);
	v1.push_back(p8);
	v1.push_back(p9);
	v1.push_back(p10);
	multimap<string, Person> m1;
	for (int i = 0; i < 10; i++)
	{
		m1.insert(make_pair(v1.back().work, v1.back()));
		v1.pop_back();
	}
	for (multimap<string, Person>::iterator head = m1.begin(); head != m1.end(); head++)
	{
		cout << head->second.name << "     " << head->second.wage << "     " << head->first << '\n';
	}
}