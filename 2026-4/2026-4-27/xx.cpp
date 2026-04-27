#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;
struct Pt
{
    int y;
    int x;
};
bool IsPass(int** a, int n, int m, Pt pos)
{
    if (pos.y >= 0 && pos.y <= n && pos.x >= 0 && pos.x <= m && a[pos.y][pos.x] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool GetMaze(int** a, int n, int m, Pt cur)
{
    Pt next;
    next = cur;
    next.y -= 1;
    if (IsPass(a, n, m, next))
    {

    }

    next = cur;
    next.y += 1;


    next = cur;
    next.x -= 1;


    next = cur;
    next.x += 1;
}
int main()
{
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int add[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &add[i][j]);
            }
        }
        GetMaze((int**)add, n, m, { 0,0 });
    }
    return 0;
}