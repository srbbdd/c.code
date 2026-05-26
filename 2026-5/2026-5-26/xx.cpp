//#include <iostream>
//using namespace std;
//
//class Base {
//
//private:
//    int x;
//    int y;
//
//public:
//    Base(int x, int y) {
//        this->x = x;
//        this->y = y;
//    }
//
//    int getX() {
//        return x;
//    }
//
//    int getY() {
//        return y;
//    }
//
//};
//
//class Sub : public Base {
//
//private:
//    int z;
//
//public:
//    Sub(int x, int y, int z) :Base(x, y)
//    {
//        this->z = z;
//    }
//    int getZ() {
//        return z;
//    }
//
//    int calculate() {
//        return Base::getX() * Base::getY() * this->getZ();
//    }
//
//};
//
//int main() {
//
//    int x, y, z;
//    cin >> x;
//    cin >> y;
//    cin >> z;
//    Sub sub(x, y, z);
//    cout << sub.calculate() << endl;
//
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//class Base {
//
//private:
//    int x;
//    int y;
//
//public:
//    Base(int x, int y) {
//        this->x = x;
//        this->y = y;
//    }
//
//    int getX() {
//        return x;
//    }
//
//    int getY() {
//        return y;
//    }
//
//    void calculate() {
//        cout << getX() * getY() << endl;
//    }
//
//};
//
//class Sub : public Base
//{
//public:
//    Sub(int x, int y) :Base(x, y)
//    {
//        ;
//    }
//    void calculate()
//    {
//        if (getY() != 0)
//        {
//            cout << getX() / getY() << "\n";
//        }
//        else {
//            cout << "Error";
//        }
//    }
//
//};
//
//int main() {
//
//    int x, y, z;
//    cin >> x;
//    cin >> y;
//    Sub sub(x, y);
//    sub.calculate();
//
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//class rectangle {
//private:
//    int length, width;
//public:
//    rectangle(int x, int y) {
//        length = x;
//        width = y;
//    }
//    void set(int x, int y) {
//        length = x;
//        width = y;
//    }
//    int area() {
//        return length * width;
//    }
//};
//class cuboid :public rectangle {
//private:
//    int height;
//public:
//    cuboid(int x, int y, int z) :rectangle(x, y)
//    {
//        height = z;
//    }
//    // write your code here...
//    int getvolume()
//    {
//        return area() * height;
//    }
//
//};
//int main() {
//    int x, y, z;
//    cin >> x >> y >> z;
//    cuboid a(x, y, z);
//    cout << a.getvolume();
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//class rectangle {
//private:
//    int length, width;
//public:
//    rectangle(int x, int y) {
//        length = x;
//        width = y;
//    }
//    void set(int x, int y) {
//        length = x;
//        width = y;
//    }
//    int getlength() {
//        return length;
//    }
//    int getwidth() {
//        return width;
//    }
//    int area() {
//        return length * width;
//    }
//};
//class cuboid :public rectangle {
//private:
//    int height;
//public:
//    // write your code here...
//    cuboid(int x, int y, int z) :rectangle(x, y)
//    {
//        height = z;
//    }
//    int area()
//    {
//        return 2 * ((getlength() * getwidth()) + (getlength() * height) + (getwidth() * height));
//    }
//};
//int main() {
//    int x, y, z;
//    cin >> x >> y >> z;
//    cuboid a(x, y, z);
//    cout << a.rectangle::area() << '\n' << a.area();
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//class BaseCalculator {
//public:
//    int m_A;
//    int m_B;
//    // write your code here......
//    virtual int getResult() = 0;
//
//};
//
//// 加法计算器类
//class AddCalculator : public BaseCalculator {
//    // write your code here......
//    int getResult()
//    {
//        return m_A + m_B;
//    }
//};
//
//// 减法计算器类
//class SubCalculator : public BaseCalculator {
//    // write your code here......
//    int getResult()
//    {
//        return m_A - m_B;
//    }
//};
//
//
//int main() {
//
//    BaseCalculator* cal = new AddCalculator;
//    cal->m_A = 10;
//    cal->m_B = 20;
//    cout << cal->getResult() << endl;
//    delete cal;
//
//    cal = new SubCalculator;
//    cal->m_A = 20;
//    cal->m_B = 10;
//    cout << cal->getResult() << endl;
//    delete cal;
//
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;
class rectangle {
private:
	int length, width;
public:
	rectangle(int x, int y) {
		length = x;
		width = y;
	}
	void set(int x, int y) {
		length = x;
		width = y;
	}
	int getlength() {
		return length;
	}
	int getwidth() {
		return width;
	}
	// write your code here...
	virtual int getval()
	{
		return this->length * this->width;
	}

};
class cuboid :public rectangle {
private:
	int height;
public:
	cuboid(int x, int y, int z) :rectangle(x, y) {
		height = z;
	}
	// write your code here...
	int getval()
	{
		return this->rectangle::getval() * this->height;
	}
};
int main() {
	int x, y, z;
	cin >> x >> y >> z;
	cuboid a(x, y, z);
	rectangle b(x, y);

	rectangle* p = &b;
	cout << p->getval() << '\n';

	p = &a;
	cout << p->getval();
	return 0;
}