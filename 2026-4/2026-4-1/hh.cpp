#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int m = 0;
    int q = 0;
    scanf("%d %d %d", &n, &m, &q);
    bool add[5][5] = { false };
    int t = 0;
    int c = 0;
    int i = 0;
    for (i = 0; i < q; i++)
    {
        cin >> t;
        cin >> c;
        int j = 0;
        if (t == 0)
        {
            for (j = 0; j < m; j++)
            {
                add[c-1][j] = true;
            }
        }
        else
        {
            for (j = 0; j < n; j++)
            {
                add[j][c-1] = true;
            }
        }
    }
    int ret = 0;
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            if (add[i][j] == false)
            {
                ret++;
            }
        }
    }
    printf("%d", ret);
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
    for (i = 0; i < n; i++)
    {
        cin >> add[i];
    }
    int k = 0;
    cin >> k;
    int a = 0;
    for (i = 0; i < k; i++)
    {
        int j = 0;
        int b = 0;
        for (j = 0; j < n; j++)
        {
            cin >> a;
            if (a != add[j]&&a!=0)
            {
                b = 0;
                break;
            }
            b += a;
        }
        if (b != 0)
        {
            cout << "Da Jiang!!!\n";
        }
        else
        {
            cout << "Ai Ya\n";
        }
    }
    return 0;
}
#include <iostream>
using namespace std;
struct peplo
{
    int date;
    char name[9];
};
int main()
{
    int n = 0;
    cin >> n;
    peplo add[7];
    int i = 0;
    int ret = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%s %d", add[i].name,&add[i].date);
        ret += add[i].date;
    }
    ret =(ret/n)/2;
    int min = 100;
    int emp = 0;
    int index = 0;
    for (i = 0; i < n; i++)
    {
        emp = ret > add[i].date ? ret - add[i].date : add[i].date - ret;
        if (emp < min)
        {
            min = emp;
            index = i;
        }
    }
    printf("%d %s", ret, add[index].name);
    return 0;
}
