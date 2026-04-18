#include <iostream>
#include <string>
using namespace std;
struct a
{
    int a;
    int b;
};
bool cmp(const a* p1, const a* p2)
{
    return (*p1).a < (*p2).a;
}
int main()
{
    int n = 0;
    cin >> n;
    bool arr[100000] = { false };
    a add[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &add[i].a, &add[i].b);
        if (add[i].b == 0)
        {
            arr[add[i].a] = true;
        }
        else
        {
            arr[add[i].a] = false;
        }
    }
    
    int fal = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[add[i].a] == true)
        {
            if (fal)
            {
                cout << add[i].a;
                fal = 0;
            }
            else
            {
                cout << " " << add[i].a;
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
    string s1;
    char a = 1;
    for (int i = 0; i < 12; i++)
    {
        a = 1;
        int ret = 0;
        while (a != '\n')
        {
            a = getchar();
            if (a == '\n')
            {
                break;
            }
            ret++;
        }
        cout << ret;
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
void converse(int x, int y, string& s1,int long)
{
    int a = x;
    int b = y;
    while (a < b)
    {
        char c = s1[a];
        s1[a] = s1[b];
        s1[b] = c;
        a++;
        b--;
    }
}
void insertzf(string& s1, int x, char b)
{

    return ;
}
int main()
{
    int n = 0;
    cin >> n;
    string s1;
    cin >> s1;
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        char b = 0;
        if (a == 1)
        {
            cin >> b;
            for (int i = 0; i < s1.length(); i++)
            {
                if (s1[i] == b)
                {
                    cout << i;
                }
            }
            cout << "\n";
        }
        else if (a == 2)
        {
            cin >> b;
            int x = 0;
            cin >> x;
            insertzf(s1,x, b);
            cout << s1 << "\n";
        }
        else
        {
            int x = 0;
            int y = 0;
            cin >> x >> y;
            converse(x, y,s1 ,s1.length());
            cout << s1;
        }
    }
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int t = 0;
    cin >> n >> t;
    int add[10];
    for (int i = 0; i < n; i++)
    {
        cin >> add[i];
    }
    int ret = n;
    int fal = 1;
    int jl = 1;
    while (ret>0)
    {
        int emp = 0;
        if (jl % 2 != 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (add[i] <= t && add[i] >= 0)
                {
                    if (fal)
                    {
                        cout << i + 1;
                        fal = 0;
                    }
                    else
                    {
                        cout << " " << i + 1;
                    }
                    add[i] = -1;
                    ret -= 1;
                }
                else if (add[i] != -1)
                {
                    emp += add[i];
                }
            }
        }
        else
        {
            for (int i = n; i>=0; i--)
            {
                if (add[i] <= t && add[i] >= 0)
                {
                    if (fal)
                    {
                        cout << i + 1;
                        fal = 0;
                    }
                    else
                    {
                        cout << " " << i + 1;
                    }
                    add[i] = -1;
                    ret -= 1;
                }
                else if (add[i] != -1)
                {
                    emp += add[i];
                }
            }
        }
        jl++;
        if (ret == 0)
        {
            break;
        }
        t =  emp / ret;
    }
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int max = 0;
    int max1 = 0;
    int index = 0;
    int index1 = 0;
    int add[10];
    for (int i = 0; i < n; i++)
    {
        cin >> add[i];
        if (add[i] > max)
        {
            max = add[i];
            index = i;
        }
        if (add[i] > max1 && i != index)
        {
            max1 = add[i];
            index1 = i;
        }
    }
    cout << index + 1 << " " << index1 + 1 << "\n";
    int x = 0;
    cin >> x;
    int fal = 0;
    for (int i = 0; i < x; i++)
    {
        int date = 0;
        cin >> date;
        int min = 100;
        int minindex = 0;
        for (int j = 0; j < n; j++)
        {
            if (add[i]<min && add[i]>date)
            {
                min = add[i];
                minindex = i;
            }
        }
        if (fal)
        {
            cout << minindex + 1;
            fal = 0;
        }
        else
        {
            cout << "\n" << minindex + 1;
        }
    }
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n = 0;
    int t = 0;
    cin >> n >> t;
    stack<int>add;
    stack<int>arr;
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        add.push(a);
    }
    while (!add.empty())
    {
        int c = add.size();
        for (int i = 0; i < c; i++)
        {
            int date = add.top();
            if (date > t)
            {
                arr.push(date);
            }
            else
            {

            }
        }
    }
    return 0;
}