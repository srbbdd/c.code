#include "xx.h"
int main()
{
	Payroll p1;
	int a;

	do
	{
		p1.Mune();
		cout << " ‰»Î\n";
		cin >> a;
		system("cls");//«Â∆¡
		switch (a)
		{
		case 1:
			p1.addworker();
			break;
		case 2:
			p1.Mod();
			break;
		case 3:
			p1.deletewoker();
			break;
		case 4:
			p1.print();
			break;
		case 5:
			p1.seek();
			break;
		case 6:
			p1.sort();
			break;
		case 7:
			break;
		}
	} while (a);
	return 0;
}