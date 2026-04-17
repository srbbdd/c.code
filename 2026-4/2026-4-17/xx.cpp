#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int i = 1;
    long long int number = 1;
    while (1)
    {
        if (number % n == 0)
        {
            cout << number / n << " " << i << "\n";
            break;
        }
        number = number * 10 + 1;
        i++;
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
string divide(int len, int x)
{
    int remerble = 0;
    string str;
    for (int i = 0; i < len; i++)
    {
        remerble = remerble * 10 + 1;//计算出每一位初x的结果
        str.push_back(remerble / x + '0');
        remerble %= x;//更新remerble/x后的余数
    }
    int index = 0;
    while (index < str.length() && str[index] == '0')
    {
        index++;//去零
    }
    return str.substr(index);
}
int main()
{
    int x = 0;
    cin >> x;
    int i = 1;
    int remerble = 0;
    while (1)
    {
        remerble = (remerble * 10 + 1) % x;//计算i位可以整除x
        if (remerble == 0)
        {
            break;
        }
        i++;
    }
    string s1 = divide(i, x);
    cout << s1 << " " << i << "\n";
    return 0;
}