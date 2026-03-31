#include <iostream>
using namespace std;
int main()
{
    int f = 0;
    cin >> f;
    cout << 5 * (f - 32) / 9;
    return 0;
}
#include <iostream>
using namespace std;
void add(int a)
{
	if (a)
	{
		add(a / 10);
		switch (a % 10)
		{
		   case 0:
			   cout << "ling ";
			   break;
		   case 1:
			   cout << "yi ";
			   break;

		   case 2:
			   cout << "er ";
			   break;

		   case 3:
			   cout << "san ";
			   break;

		   case 4:
			   cout << "si ";
			   break;

		   case 5:
			   cout << "wu ";
			   break; 
		   case 6:
			   cout << "liu ";
			   break;

		   case 7:
			   cout << "1i ";
			   break;

		   case 8:
			   cout << "ba ";
			   break;

		   case 9:
			   cout << "jiu ";
			   break;

		} 
	}
}
int main()
{
	int a = 0;
	cin >> a;
	if (a < 0)
	{
		cout << "fu";
	}
	if (a != 0)
	{
		add(a);
	}
	else
	{
		cout << "ling";
	}
	return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    printf("2^%d = ", n);
    cout << pow(2, n);
    return 0;
}