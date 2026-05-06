#include "add.h";
void add(yuan& p1, Point& p2)
{
	int c = (int)pow(p1.getxin().getx() - p2.getx(), 2) + (int)pow(p1.getxin().gety() - p2.gety(), 2);
	int r1 = pow(p1.getr(), 2);
	if (c == r1)
	{
		cout << "ÉÏ";
	}
	else if (c > r1)
	{
		cout << "Íâ";
	}
	else
	{
		cout << "Àï";
	}
}
int main()
{
	yuan c;
	c.setr(10);
	Point cx;
	cx.setx(10);
	cx.sety(0);
	c.setxin(cx);
	Point d;
	d.setx(10);
	d.sety(9);
	add(c, d);
	return 0;
}