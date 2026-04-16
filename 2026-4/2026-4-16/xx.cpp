#include <iostream>
using namespace std;
int main()
{
    int add[4] = { 0 };
    int max = 0;
    int min = 100000;
    int ty = 0;
    int yz = 0;
    int index = 0;
    int tybj = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> add[i];
        if (add[i] > max)
        {
            max = add[i];
        }
        if (add[i] < min)
        {
            min = add[i];
            index = i;
        }
    }
    cin >> ty >> yz;
    for (int j = 0; j < 4; j++)
    {
        if (add[j] < ty)
        {
            tybj++;
        }
    }
    if (max - min > yz)
    {
        tybj++;
    }
    if (tybj >= 2)
    {
        cout << "Warning: please check all the tires!\n";
    }
    else if (min<ty || max - min>yz)
    {
        cout << "Warning: please check #" << index + 1 << "!\n";
    }
    else
    {
        cout << "Normal\n";
    }
    return 0;
}