#pragma once;
#include <iostream>
#include <cmath>
using namespace std;
class Point
{
public:
	void setx(int x1);
	int getx();
	void sety(int y1);
	int gety();
private:
	int x;
	int y;
};
class yuan
{
public:
	void setr(int r1);
	int getr();
	void setxin(Point xin1);
	Point getxin();
private:
	int r;
	Point xin;
};