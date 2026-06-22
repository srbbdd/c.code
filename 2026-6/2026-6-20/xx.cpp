#include <iostream>
using namespace std;

template<class T>
class Person
{
public:
	T* p1;
	Person(int capacity)
	{
		p1 = NULL;
		this->capacity = capacity;
		p1 = new T[capacity];
		nowcapacity = 0;
	}
	Person(const Person& p1)
	{
		this->capacity = p1.capacity;
		this->nowcapacity = p1.nowcapacity;
		this->p1 = new T[p1.capacity];
		for (int i = 0; i < this->nowcapacity; i++)
		{
			this->p1[i] = p1.p1[i];
		}
	}
	void behindinsert(T p1)
	{
		if (nowcapacity < capacity)
		{
			this->p1[nowcapacity] = p1;
			nowcapacity+=1;
		}
	}
	void behinddelete()
	{
		nowcapacity -= 1;
	}
	int getcapacity()
	{
		return this->nowcapacity-1;
	}
	~Person()
	{
		delete []p1;
	}
	Person& operator=(const Person& p1)
	{
		if (this->p1 != NULL)
		{
			delete []this->p1;
			this->p1 = NULL;
			this->capacity = 0;
			this->nowcapacity = 0;
		}
		this->capacity = p1.capacity;
		this->nowcapacity = p1.nowcapacity;
		this->p1 = new T[p1.capacity];
		for (int i = 0; i < p1.nowcapacity; i++)
		{
			this->p1[i] = p1.p1[i];
		}
		return *this;
	}
	void print()
	{
		for (int i = 0; i < this->nowcapacity; i++)
		{
			cout << this->p1[i] << "<<";
		}
		cout << '\n';
	}
private:
	int nowcapacity;
	int capacity;
};
int main()
{
	Person<int> p(4);
	p.behindinsert(1);
	p.behindinsert(2);
	p.behindinsert(3);
	cout << p.getcapacity()<<'\n';
	p.print();
	p.behinddelete();
	cout << p.getcapacity() << '\n';
	p.print();
	Person<int> p1(p);
	p1.print();
	p.behindinsert(3);
	p.print();
	Person<int> p2(p);
	p2.print();
	p2 = p1;
	p2.print();
	p2 = p;
	p2.print();
}