#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int m = 0;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a = pow(2, n)-1;
        int a1 = 0;
        int j = 0;
        char c = 0;
        for (j = 0; j < n; j++)
        {
            cin >> c;
            if (c == 'y')
            {
                a1 = (a1 * 2) + 1;
            }
            else
            {
                a1 = (a1*2)+ 2;
            }
        }
        cout << a1+1 - a<< "\n";
    }
    return 0;
}

#include <iostream>
#include <string> 
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    string max;
    float smax = 0.0;
    string small;
    float ssmall = 100.0;
    string a1;
    float a = 0.0;
    int i = 0;
    getchar();
    for (i = 0; i < n; i++)
    {
        getline(cin,a1);
        cin >> a;
        if (a > smax)
        {
            max = a1;
            smax = a;
        }
        if (a < ssmall)
        {
            small = a1;
            ssmall = a;
        }
        getchar();
    }
    printf("%.2f, ", smax);
    cout << max << '\n';
    printf("%.2f, ", ssmall);
    cout << small << '\n';
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int max = 0;
    int ibackup = 0;
    int i = 0;
    int a = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        if (a > max)
        {
            ibackup = i;
            max = a;
        }
    }
    printf("%d %d\n", max, ibackup);
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int i = 0;
    int a = 1;
    for (i = 1; i < n - 1;i++)
    {
        int j = 0;
        for (j = 0; j < n - i; j++)
        {
            cout << ' ';
        }
        for (int p = 0; p < a; p++)
        {
            cout << i;
        }
        a += 2;
        cout << '\n';
    }
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    char add[11];
    cin.getline(add, 11);
    char* p1 = add;
    int digit = 0;
    int letter = 0;
    int other = 0;
    while (*p1)
    {
        if (*p1 >= '0' && *p1 <= '9')
        {
            digit++;
        }
        else if (*p1 >= 'a' && *p1 <= 'z'||*p1>='A'&&*p1<='Z')
        {
            letter++;
        }
        else
        {
            other++;
        }
        p1++;
    }
    cout << "letter = " << letter << ", " << "digit = " << digit << ", " << "other = " << other << "\n";

    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int add[5];
    int i = 0;
    int max = 0;
    int maxindex = 0;
    int small = 100;
    int smallindex = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &add[i]);
        if (add[i] > max)
        {
            max = add[i];
            maxindex = i;
        }
        if (add[i] < small)
        {
            small = add[i];
            smallindex = i;
        }
    }
    int ret = add[0];
    add[0] = small;
    add[smallindex] = ret;
    if (maxindex == 0)
    {
        maxindex = smallindex;
    }
    ret = add[n - 1];
    add[n - 1] = max;
    add[maxindex] = ret;
    for (i = 0; i < n; i++)
    {
        cout <<' ' << add[i];
    }
    return 0;
}
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    float areas = 0;
    cin >> areas;
    int a = 0;
    cin >> a;
    cout << fixed << setprecision(a);
    cout << 3.14 * pow(areas, 2);
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int a = 0;
    int n = 0;
    cin >> a;
    cin >>n;
    int i = 0;
    int c = 0;
    int flase = 1;
    for (i = 0; i < a; i++)
    {
        cin >>c;
        if (c == n)
        {
            printf("%d", i);
            flase = 0;
            break;
        }
    }
    if (flase)
    {
        cout << "Not Found";
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int add[n];
    int i = 0;
    float ret = 0;
    int ret1 = 0;
    for (i = 0; i < n; i++)
    {
        cin >> add[i];
        ret += add[i];
        if (add[i] < 60)
        {
            ret1++;
        }
    }
    sort(add, add+n);
    cout << "Max: " << add[n - 1] << "\n";
    cout << "Min: " << add[0] << "\n";
    cout << "Ave: " << ret / n << "\n";
    cout << "Fail: " << ret1 << "\n";
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    float a = 0;
    int i = 0;
    int b = 0;
    for (i = 0; i < 4; i++)
    {
        cin >> b;
        a += b;
    }
    cout << "Sum = ";
    printf("%.0f", a);
    printf("; Average = %.1f",a/4);
    return 0;
}
void recursive(bool* book, int* like, int (*bookjz)[4],int n,int m)
{
	int i = 0;
	for (i = 0; i < m; i++)
	{
		if (book[i] == false)
		{
			break;
		}
	}
	if (i == m)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", like[j]);
		}
	}
	else
	{
		for (int j = 0; j < n; j++)
		{
			if ((*bookjz)[j] == 1 && book[j] != true)
			{
				(*like) = j;
				book[j] = true;
				recursive(book, like + 1, bookjz + 1, n, m);
				book[j] = false;
				(*like) = 0;
			}
		}
	}
}
int main()
{
	int n = 0;
	int m = 0;
	cin >> n;
	cin >> m;
	bool book[4] = {false};
	int like[3] = { 0 };
	int* p1 = like;
	int bookjz[3][4] = {0};
	int i = 0;
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < m; j++)
		{
			scanf("%d", &bookjz[i][j]);
		}
	}
	recursive(book, p1, bookjz,n,m);
	return 0;
}
