#include <iostream>
using namespace std;
class Cpu
{
public:
	virtual void calculat() = 0;
};
class VideoCard
{
public:
	virtual void display() = 0;
};
class Ram
{
public:
	virtual void storage() = 0;
};
class Intel:public Cpu
{
public:
	void calculat()
	{
		cout << "Intel\n";
	}
};
class Ram1 :public Ram
{
public:
	void storage()
	{
		cout << "Ram1\n";
	}
};
class VideoCard1 :public VideoCard
{
public:
	void display()
	{
		cout << "VideoCard1\n";
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
};
int main()
{
	Cpu* p1 = new Intel;
	Ram* p2 = new Ram1;
	VideoCard* p3 = new VideoCard1;
	compute p4(p1, p2, p3);
	p4.test();
	delete p1;
	delete p2;
	delete p3;
	return 0;
}