#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
    int a = 0;
    int b = 0;
    cin >> a;
    cin >> b;
    int add[3][2];
    int i = 0;
    for (i = 0; i < a; i++)
    {
        int j = 0;
        for (j = 0; j < b; j++)
        {
            cin >> add[i][j];
        }
    }
    int a1 = 0;
    int b1 = 0;
    int add1[3][2];
    cin >> a1;
    cin >> b1;
    if (b != a1)
    {
        printf("Error: %d != %d", b, a1);
    }
    else
    {
        printf("%d %d\n", a, b1);
        for (i = 0; i < a1; i++)
        {
            int j = 0;
            for (j = 0; j < b1; j++)
            {
                cin >> add1[i][j];
            }
        }
        for (i = 0; i < a; i++)
        {
            int j = 0;
            int q = 0;
            for (q = 0; q < b1; q++)
            {
                int ret = 0;
                for (j = 0; j < b; j++)
                {
                    ret += (add[i][j] * add1[j][q]);
                }
                if (q != b1 - 1)
                {
                    printf("%d ", ret);
                }
                else
                {
                    printf("%d", ret);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int cp;
    cin >> n;
    int i = 0;

    for (i = 0; i < n; i++)
    {
        cin >> cp;
        int ret = 0;
        int ret1 = 0;
        while (cp >= 1000)
        {
            ret += cp % 10;
            cp /= 10;
        }
        while (cp)
        {
            ret1 += cp % 10;
            cp /= 10;
        }
        if (ret == ret1)
        {
            cout << "You are lucky!\n";
        }
        else
        {
            cout << " you good luck.\n";

        }
    }
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int add[10];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        cin >> add[i];
    }
    sort(add, add + n);
    int* p1 = add;
    int* p2 = add + n - 1;
    int ret = 1;
    for (i = 0; i < n - 1; i++)
    {
        if (*p1 == *(p1 + 1))
        {
            p1++;
            ret++;
        }
        else
        {
            cout << *p1 << " " << ret << "\n";
            break;
        }
    }
    ret = 1;
    for (i = 0; i < n - 1; i++)
    {
        if (*p2 == *(p2 - 1))
        {
            p2--;
            ret++;
        }
        else
        {
            cout << *p2 << " " << ret;
            break;
        }
    }
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char n[8] = { "0" };
    scanf("%s", n);
    char* p1 = n;
    if (!(strlen(n)> 5))
    {
        if (*p1 < '2')
        {
            cout << "20" << *p1 << *(p1 + 1) << "-" << *(p1 + 2) << *(p1 + 3);
        }
        else if (*p1 == '2')
        {
            if (*(p1 + 1) < '2')
            {
                cout << "20" << *p1 << *(p1 + 1) << "-" << *(p1 + 2) << *(p1 + 3);
            }
            else
            {
                cout << "19" << *p1 << *(p1 + 1) << "-" << *(p1 + 2) << *(p1 + 3);
            }
        }
        else
        {
            cout << "19" << *p1 << *(p1 + 1) << "-" << *(p1 + 2) << *(p1 + 3);
        }
    }
    else
    {
        while (*p1)
        {
            printf("%c", *p1);
            p1++;
            if (p1 == n + 3)
            {
                cout << "-";
            }
        }

    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
int main()
{
	/*int add[] = { 1,2,3,4,5,6,7,8 };
	for (int i : add)
	{
		cout << i<<"\n";
	}*/
	string s1 = to_string(123);
	string s2 = to_string(456);
	printf("%s\n", (s1 + s2).c_str());
	cout << s1 + s2;
	return 0;
}