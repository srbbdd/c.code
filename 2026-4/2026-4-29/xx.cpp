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
bool IsPass(int** a, int n, int m, Pt pos)
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
bool GetMaze(int** a , int n, int m, Pt cur)
{
    pq.push(cur);//入栈
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
    pq.pop();//没有返回true这步是错的撤回入栈
    return false;
}
int main()
{
    int n = 0;
    int m = 0;
    int** add = NULL;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        add = (int**)malloc(sizeof(int*) * n);//32位和64位地址大小有差异所以sizeof（int*）
        for (int i = 0; i < n; i++)
        {
            int* new1 = (int*)malloc(sizeof(int) * m);
            for (int j = 0; j < m; j++)
            {
                scanf(" %d",&new1[j]);
            }
            add[i] = new1;
        }
        GetMaze(add, n, m, { 0,0 });
    }
    stack<Pt>pq1;
    while (!(pq.empty()))//更换出栈顺序
    {
        Pt m = pq.top();
        pq1.push(m);
        pq.pop();
    }
    while (!(pq1.empty()))//打印
    {
        Pt m = pq1.top();
        printf("%d %d\n", m.y, m.x);
        pq1.pop();
    }
    for (int i = 0; i < n; i++)
    {
        free(add[i]);
    }
    free(add);
    add = NULL;
    return 0;
}