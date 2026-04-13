#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
    int year = 0;
    cin >> year;
    int n = 0;
    cin >> n;
    int yearsold = 0;
    while (1)
    {
        bool remerble[10] = { false };
        int i = 0;
        int ret = year;
        for (i = 0; i < n; i++)
        {
            if (remerble[ret % 10] == true)
            {
                break;
            }
            else
            {
                remerble[ret % 10] = true;
            }
            ret /= 10;
        }
        if (i == n)
        {
            break;
        }
        yearsold += 1;
        year += 1;
    }
    printf("%d %04d", yearsold, year);
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int add[9];
    int i = 0;
    for (i = 0; i < 9; i++)
    {
        cin >> add[i];
    }
    for (i = 1; i <= 8; i++)
    {
        if (i % 2 != 0)
        {
            add[i] += add[i - 1] / 2;
            add[i - 1] = add[i - 1] % 2;
        }
        else
        {
            add[i] += add[i - 1] / 3;
            add[i - 1] = add[i - 1] % 3;
        }
        cout << add[i - 1]<<" ";
    }
    cout << add[i - 1]<<"\n";
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
struct exam
{
    char time[21];
    int number;
    int score;
};
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;
    exam add[n];
    int index[n];
    for (int j = 0; j < n; j++)
    {
        add[j] = { 0 };
        index[j] = 0;
    }
    int* p1 = index;
    bool arr[m + 1] = { false };
    bool arr1[m + 1] = { false };
    for (int j = 0; j < m + 1; j++)
    {
        arr[j] = false;
        arr1[j] = false;
    }
    int i = 0;
    getchar();
    for (i = 0; i < n; i++)
    {
        exam ret;
        cin.get(ret.time, sizeof(ret.time));
        scanf("%d %d", &ret.number, &ret.score);
        getchar();
        if (arr[ret.number] != true && add[ret.number].score == ret.score)
        {
            add[ret.number] = ret;
            *p1 = ret.number;
        }
        else if (add[ret.number].score < ret.score)
        {
            add[ret.number] = ret;
            *p1 = ret.number;
            arr[ret.number] = true;
        }
        p1++;
    }
    p1--;
    for (i = 0; i < n; i++)
    {
        if (arr1[*p1] == true)
        {
            *p1 = 0;
        }
        if (arr1[*p1] != true)
        {
            arr1[*p1] = true;
        }
        p1--;
    }
    int fal = 1;
    for (i = 0; i < n; i++)
    {
        if (index[i] != 0 && fal)
        {
            printf("%s%d %d", add[index[i]].time, add[index[i]].number, add[index[i]].score);
            fal = 0;
        }
        else if (index[i] != 0)
        {
            printf("\n%s%d %d", add[index[i]].time, add[index[i]].number, add[index[i]].score);

        }
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
    string s1;
    cin >> s1;
    int a = 0;
    int fa = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        string c1;
        string c2;
        string c3;
        switch (a)
        {
        case 1:
            cin >> c1;
            if (s1.find(c1) == -1)
            {
                if (fa)
                {
                    cout << -1;
                    fa = 0;
                }
                else
                {
                    cout << "\n" << -1;
                }
            }
            else
            {
                if (fa)
                {
                    printf("%d", s1.find(c1));
                    fa = 0;
                }
                else
                {
                    printf("\n%d", s1.find(c1));
                }
            }
            break;

        case 2:
            cin >> c1 >> c2;
            if (s1.find(c1) == -1)
            {
                if (fa)
                {
                    cout << s1;
                }
                else
                {
                    cout << "\n" << s1;
                }
            }
            else
            {
                s1.replace(s1.find(c1), c1.length(), c2);
                if (fa)
                {
                    cout << s1;
                }
                else
                {
                    cout << "\n" << s1;
                }
            }
            break;
        case 3:
            cin >> c1 >> c2 >> c3;
            int pow = s1.find(c1);
            while (s1.find(c1,pow) != -1)
            {
                s1.insert(pow+1, c3);
                pow += c3.length();
                pow += 1;
                pow += c2.length();
            }
            if (fa)
            {
                cout << s1;
            }
            else
            {
                cout << "\n" << s1;
            }
            break;
        }

    }
    return 0;
}
#include<iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char>comble;
    stack<int>number;
    int n = 0;
    cin >> n;
    int i = 0;
    int a = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        number.push(a);
    }
    char b = 0;
    for (i = 0; i < n - 1; i++)
    {
        cin >> b;
        comble.push(b);
    }
    int ret = number.top();
    number.pop();
    for (i = 0; i < n - 1; i++)
    {
        b = comble.top();
        if (b == '+')
        {
            ret += number.top();
        }
        if (b == '-')
        {
            ret -= number.top();
        }
        if (b == '*')
        {
            ret *= number.top();
        }
        if (b == '/')
        {
            if (number.top() == 0 || ret == 0)
            {
                printf("ERROR: %d/0\n", number.top());
                return 0;
            }
            ret /= number.top();
        }
        number.pop();
        comble.pop();
    }
    cout << ret << "\n";
    return 0;
}