#include <iostream>
using namespace std;

// 点类
class Pointer {

private:
    int x;  // x 坐标
    int y;  // y 坐标

public:
    void setX(int x) {
        this->x = x;
    }

    int getX() {
        return x;
    }

    void setY(int y) {
        this->y = y;
    }

    int getY() {
        return y;
    }

};

// 圆类
class Circle {

private:
    Pointer center; // 圆心
    int radius; // 半径

public:
    void setCenter(int x, int y) {
        center.setX(x);
        center.setY(y);
    }

    void setRadius(int radius) {
        this->radius = radius;
    }

    void isPointerInCircle(Pointer p1)
    {
        if (p1.getX() <= center.getX() - radius || p1.getX() >= center.getX() + radius)
        {
            cout << "out";
        }
        else if (p1.getY() >= center.getY() + radius || p1.getY() <= center.getY() - radius)
        {
            cout << "on";
        }
        else
        {
            cout << "in";
        }
    }

};

int main() {

    // 键盘输入点的坐标
    int x, y;
    cin >> x;
    cin >> y;

    // 创建一个点
    Pointer p;
    p.setX(x);
    p.setY(y);

    // 创建一个圆
    Circle c;
    c.setCenter(5, 0);
    c.setRadius(5);

    // 判断点和圆的关系
    c.isPointerInCircle(p);

    return 0;
}
#include <iostream>
using namespace std;

class Time {

public:
    int hours;      // 小时
    int minutes;    // 分钟

    Time() {
        hours = 0;
        minutes = 0;
    }

    Time(int h, int m) {
        this->hours = h;
        this->minutes = m;
    }

    void show() {
        cout << hours << " " << minutes << endl;
    }

    // write your code here......
    bool operator<(Time p1)
    {
        return this->hours < p1.hours;
    }

};
#include <iostream>
using namespace std;

class Time {

public:
    int hours;      // 小时
    int minutes;    // 分钟

    Time() {
        hours = 0;
        minutes = 0;
    }

    Time(int h, int m) {
        this->hours = h;
        this->minutes = m;
    }

    void show() {
        cout << hours << " " << minutes << endl;
    }

    // write your code here......

};
Time operator+(Time& p1, Time& p2)
{
    Time p3;
    p3.hours = p1.hours + p2.hours;
    p3.minutes = (p1.minutes + p2.minutes) + p3.hours * 60;
    p3.hours = p3.minutes / 60;
    p3.minutes %= 60;
    return p3;
}
int main() {

    int h, m;
    cin >> h;
    cin >> m;

    Time t1(h, m);
    Time t2(2, 20);

    Time t3 = t1 + t2;
    t3.show();

    return 0;
}