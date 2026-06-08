#include "xx.h"
void Payroll::Mune()
{
	cout << "0.退出\n";
	cout << "1.添加\n";
	cout << "2.修改\n";
	cout << "3.删除\n";
	cout << "4.显示\n";
	cout << "5.查找\n";
	cout << "6.排序\n";
	cout << "7.清空\n";
}
Employee::Employee(int number, string name, string job)
{
	this->name = name;
	this->job = job;
	this->number = number;
}
void Employee:: print()
{
	cout << "job = " << job << '\n';
	cout << "name = " << name << '\n';
	cout << "number = " << number << '\n';
}
void Payroll::addworker()
{
	cout << "输入添加数量\n";
	int addnumber = 0;
	cin >> addnumber;
	if (addnumber > 0)
	{
		int newsize = this->mount + addnumber;
		Person** p1 = new Person * [newsize];
		if (this->woker != NULL)
		{
			for (int i = 0; i < this->mount; i++)
			{
				p1[i] = this->woker[i];
			}
		}
		for (int i = 0; i < addnumber; i++)
		{
			int id;
			string name;
			string job;
			cout << "id\n";
			cin >> id;
			cout << "name\n";
			cin >> name;
			cout << "job\n";
			cin >> job;
			Person* p2;
			p2 = new Employee(id, name, job);//父类指针可以指向子类
			p1[mount + i] = p2;//父类指针存储子类
		}
		delete[]this->woker;//释放原空间
		this->mount = newsize;
		this->woker = p1;
		this->fileempty = false;
	}
	else
	{
		cout << "*\n";
	}
}
void Payroll:: print()
{
	for (int i = 0; i < this->mount; i++)
	{
		cout << woker[i]->job << '\n';
		cout << woker[i]->name << '\n';
		cout << woker[i]->number << '\n';
		cout << "\n\n";
	}
}
Payroll::~Payroll()
{
	this->save();
	if (this->woker != NULL)
	{
		delete[]this->woker;
		this->woker = NULL;
	}
}
void Payroll::save()
{
	ofstream p1;
	p1.open(file, ios::out);//写文件
	for (int i = 0; i < this->mount; i++)
	{
		p1 << this->woker[i]->job << " " << this->woker[i]->name << " " << this->woker[i]->number << "\n";
	}
	p1.close();
}
int Payroll:: getPerson()
{
	ifstream p1;
	p1.open(file, ios::in);
	int number1;
	string name1;
	string job1;
	int ret = 0;
	while (p1 >> job1&&p1 >> name1 &&p1>> number1)//统计人数
	{
		ret++;
	}
	return ret;
}
Payroll::Payroll()
{
	ifstream p1;
	p1.open(file, ios::in);//读文件
	if (!p1.is_open())//如果文件不存在就走if
	{
		cout << "文件不存在\n";
		this->woker = NULL;
		this->mount = 0;
		this->fileempty = true;//记录文件不存在
		p1.close();
		return ;
	}
	this->mount = this->getPerson();
	if (mount == 0)//文件为空
	{
		cout << "空文件\n";
		this->woker = NULL;
		this->mount = 0;
		this->fileempty = true;//记录文件不存在
		p1.close();
		return;
	}
	if (mount)
	{
		this->woker = new Person * [this->mount];
		int number1;
		string name1;
		string job1;
		int index = 0;
		while (p1 >> job1 && p1 >> name1 && p1 >> number1)//统计人数
		{
			Person* pp = new Employee(number1, name1, job1);
			this->woker[index] = pp;
			index++;
		}
	}
}
int Payroll::ifExist(int id)
{
	for (int i = 0; i < this->mount; i++)
	{
		if (this->woker[i]->number == id)
		{
			return i;
		}
	}
	return -1;
}
void Payroll::deletewoker()
{
	cout << "输入员工id\n";
	int id;
	cin >> id;
	int ret = this->ifExist(id);
	if (ret!= -1)
	{
		for (ret; ret < this->mount-1; ret++)
		{
			this->woker[ret]->job = this->woker[ret + 1]->job;
			this->woker[ret]->name = this->woker[ret + 1]->name;
			this->woker[ret]->number = this->woker[ret + 1]->number;
		}
		delete this->woker[ret];
		this->mount -= 1;
	}
	else
	{
		cout << "id不存在\n";
	}
}
void Payroll::Mod()
{
	cout << "请输入要修改的编号\n";
	int id1;
	cin >> id1;
	int ret = this->ifExist(id1);
	if (ret == -1)
	{
		cout << "错误\n";
	}
	else
	{
		cout << "输入修改的id，name，job\n";
		int id;
		string name;
		string job;
		cin >> id >> name >> job;
		this->woker[ret]->number = id;
		this->woker[ret]->name = name;
		this->woker[ret]->job = job;
	}
}
void Payroll::seek()
{
	cout << "id\n";
	int id;
	cin >> id;
	int ret = this->ifExist(id);
	if (ret == -1)
	{
		cout << "不存在\n";
	}
	else
	{
		cout << this->woker[ret]->job<<"\n";
		cout << this->woker[ret]->name<<"\n";
		cout << this->woker[ret]->number<<"\n";
	}
}
void Payroll::sort()
{
	int i = 0;
	for (int i = 0; i < this->mount - 1; i++)
	{
		for (int j = 0; j < this->mount - i - 1; j++)
		{
			if (this->woker[j]->number > this->woker[j + 1]->number)
			{
				Person* p1 = this->woker[j + 1];
				this->woker[j + 1] = this->woker[j];
				this->woker[j] = p1;
			}
		}
	}
}
void Payroll::Clean_file()
{
	int a = 0;
	cout << "请输入1确认清空\n";
	cin >> a;
	if (a)
	{
		ofstream p1(file, ios::trunc);//打开方式为创建，如果文件存在就删掉重新创建
		p1.close();
		if (this->woker != NULL)
		{
			for (int i = 0; i < this->mount; i++)
			{
				if (this->woker[i] != NULL)
				{
					delete this->woker[i];
				}
			}
			delete this->woker;
			this->woker = NULL;
			this->mount = 0;
			this->fileempty = true;
		}
	}
	else
	{
		return;
	}
}
