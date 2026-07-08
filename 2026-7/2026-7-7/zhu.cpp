#include "test.h"
int main()
{
	deque<Person> p1;
	Person v1("a");
	Person v2("b");
	Person v3("c");
	Person v4("d");
	Person v5("e");
	p1.push_back(v1);
	p1.push_back(v2);
	p1.push_back(v3);
	p1.push_back(v4);
	p1.push_back(v5);
	for (int i = 0; i < p1.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int a = 0;
			cin >> a;
			p1.at(i).score.push_back(a);
		}
	}
	mount(p1);
	sort(p1.begin(), p1.end(),cmp);
	p1.pop_back();
	p1.pop_front();
	printv(p1);
	/*for (int i = 0; i < p1.size(); i++)
	{
		for (deque<int>::iterator head = (p1.at(i).score.begin()); head != p1.at(i).score.end(); head++)
		{
			p1.at(i).zong += *head;
		}
		p1.at(i).zong /= 10;
	}*/
}