#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
char* strstr1(char* p1, char* p2)
{
    while (*p1 != '\0')
    {
        if (*p1 == *p2)
        {
            char* add = p1;
            char* arr = p2;
            while (*arr==*add)
            {
                arr++;
                add++;
            }
            if (*arr == '\0')
            {
                return p1;
            }
        }
        p1++;
    }
    return NULL;
}
using namespace std;
int main()
{
    char add[81] = { "\0" };
    int i = 0;
    int ret = 0;
    int emp = 1;
    int flase = 1;
    char arr[] = { "chi1 huo3 guo1" };
    while (add[0]!='.')
    {
        cin.getline(add,sizeof(add),'\n');
        if (strstr1(add, arr) != NULL)
        {
            ret++;
            flase = 0;
        }
        if (flase)
        {
            emp++;
        }
        i++;
    }
    if (ret != 0)
    {
        cout << i - 1 << "\n" << emp << " " << ret;
    }
    else
    {
        cout << i - 1 << "\n" << "-_-#";
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
char* strstr1(char* p1, int* i)
{
    (*i) = 0;
    while (*p1 == '6')
    {
        p1++;
        (*i)++;
    }
    if ((*i) > 3)
    {
        return p1;
    }
    else
    {
        return NULL;
    }
}
int main()
{
    char add[1001];
    cin.getline(add, sizeof(add), '\n');
    char* p1 = add;
    int i = 0;
    while (*p1)
    {
        if (*p1 == '6')
        {
            strstr1(p1, &i);
            if (i > 3 && i <= 9)
            {
                printf("9");
                p1 += i;
            }
            else if (i > 9)
            {
                printf("27");
                p1 += i;
            }
            else
            {
                printf("%c", *p1);
                p1++;
            }
        }
        else
        {
            printf("%c", *p1);
            p1++;
        }
    }
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int ret = 1;
    int a = 0;
    int b = 0;
    cin >> a;
    cin >> b;
    int i = 0;
    for (i = 3; i <= b; i++)
    {
        ret *= i;
    }
    cout << ret;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int k = 0;
    cin >> k;
    char add[8];
    getchar();
    cin.getline(add, sizeof(add), '\n');
    char* p1 = add;
    int k1 = k;
    while (*p1 != 'E')
    {
        if (k1 == 0)
        {
            k1 = k+1;
            printf("%s", add);
        }
        else
        {
            switch (*p1)
            {
            case 'C':
                cout << "Bu\n";
                break;
            case 'J':
                cout << "ChuiZi\n";
                break;
            case 'B':
                cout << "JianDao\n";
                break;
            }
        }
        cin.getline(add, sizeof(add), '\n');
        p1 = add;
        k1--;
    }
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int add[6];
    int i = 0;
    for (i = 0; i < 6; i++)
    {
        scanf("%d ", &add[i]);
    }
    int n = 0;
    cin >> n;
    for (i = 0; i < 6; i++)
    {
        if (7 - n > add[i])
        {
            printf("%d ", 7 - n);
        }
        else
        {
            printf("%d ", 7 - n - 1);
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
    int m = 0;
    cin >> n;
    cin >> m;
    std::string s1;
    std::string s2 = "easy";
    std::string s3 = "qiandao";
    int i = 0;
    getchar();
    for (i = 0; i < n; i++)
    {
        getline(cin, s1);
        if (m == 0)
        {
            cout << s1;
            return 0;
        }
        if (s1.find(s2) != std::string::npos || s1.find(s3) != std::string::npos)
        {
            ;
        }
        else
        {
            m--;
        }
    }
    if (m > 0)
    {
        printf("wo AK 1s");
    }
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int m = 0;
    cin >> n;
    cin >> m;
    int ret = 0;
    int i = 0;
    getchar();
    int a = 0;
    for (i = 0; i < m; i++)
    {
        cin >> a;
        ret += a;
    }
    cout << ret % n;
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int s = 1;
    int i = 0;
    int sum = 0;
    for (i = 1; i <= n; i++)
    {
        s *= i;
        sum += s;
    }
    cout << sum;
    return 0;
}