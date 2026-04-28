#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;//迷宫问题
struct Pt
{
    int y;
    int x;
};
stack<Pt>pq;
bool IsPass(int (*a)[5], int n, int m, Pt pos)
{
    if (pos.y >= 0 && pos.y < n && pos.x >= 0 && pos.x < m && a[pos.y][pos.x] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool GetMaze(int (*a)[5], int n, int m, Pt cur)
{
    pq.push(cur);
    if (cur.y == n - 1 && cur.x == m - 1)
    {
        return true;
    }
    Pt next;
    a[cur.y][cur.x] = 2;//标记已搜索的路径
    next = cur;
    next.y -= 1;
    if (IsPass(a, n, m, next))//四个方向递归
    {
        if (GetMaze(a, n, m, next))//如果找到出路其他的路就不需要走了
        {
            return true;
        }
    }

    next = cur;
    next.y += 1;
    if (IsPass(a, n, m, next))
    {
        if (GetMaze(a, n, m, next))
        {
            return true;
        }
    }

    next = cur;
    next.x -= 1;
    if (IsPass(a, n, m, next))
    {
        if (GetMaze(a, n, m, next))
        {
            return true;
        }
    }

    next = cur;
    next.x += 1;
    if (IsPass(a, n, m, next))
    {
        if (GetMaze(a, n, m, next))
        {
            return true;
        }
    }
    pq.pop();
    return false;
}
int main()
{
    int n = 0;
    int m = 0;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int add[5][5];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &add[i][j]);
            }
        }
        GetMaze(add, n, m, {0,0}); 
    }
    while (!(pq.empty()))
    {
        Pt m = pq.top();
        printf("%d %d\n", m.x, m.y);
        pq.pop();
    }
    return 0;
}