#include <iostream>
#include <string>
using namespace std;
class Cpu
{
public:
	virtual void calculat() = 0;
	string* name;
	virtual ~Cpu()
	{
		;
	}
};
class VideoCard
{
public:
	virtual void display() = 0;
	string* name;
	virtual ~VideoCard()
	{
		;
	}
};
class Ram
{
public:
	virtual void storage() = 0;
	string* name;
	virtual ~Ram()
	{
		;
	}
};
class Intel:public Cpu
{
public:
	Intel(string name)
	{
		this->name = new string(name);
	}
	void calculat()
	{
		cout <<*name<< "Intel\n";
	}
	~Intel()
	{
		if (name != NULL)
		{
			delete name;
		}
	}
};
class Ram1 :public Ram
{
public:
	Ram1(string name)
	{
		this->name = new string(name);
	}
	void storage()
	{
		cout <<*name<< "Ram1\n";
	}
	~Ram1()
	{
		if (name != NULL)
		{
			delete name;
		}
	}
};
class VideoCard1 :public VideoCard
{
public:
	VideoCard1(string name)
	{
		this->name = new string(name);
	}
	void display()
	{
		cout << *name<<"VideoCard1\n";
	}
	~VideoCard1()
	{
		if (name != NULL)
		{
			delete name;
		}
	}
};
class compute
{
public:
	compute(Cpu* p11,Ram* p22, VideoCard* p33)
	{
		p1 = p11;
		p2 = p22;
		p3 = p33;
	}
	Cpu* p1;
	Ram* p2;
	VideoCard* p3;
	void test()
	{
		p1->calculat();
		p2->storage();
		p3->display();
	}
	~compute()
	{
		if (p1 != NULL)
		{
			delete p1;
		}
		if (p2 != NULL)
		{
			delete p2;
		}
		if (p3 != NULL)
		{
			delete p3;
		}
	}
};
int main()
{
	Cpu* p1 = new Intel("aaa");
	Ram* p2 = new Ram1("bbb");
	VideoCard* p3 = new VideoCard1("ccc");
	compute* p4 = new compute(p1, p2, p3);
	p4->test();
	Cpu* a1 = new Intel("111");
	Ram* a2 = new Ram1("222");
	VideoCard* a3 = new VideoCard1("333");
	compute* a4 = new compute(a1, a2, a3);
	a4->test();
	delete a4;
	delete p4;
	return 0;
}