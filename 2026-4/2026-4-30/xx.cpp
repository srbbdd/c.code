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
stack<Pt>minpq;
bool IsPass(int** a, int n, int m, Pt pos)
{
    if (pos.y >= 0 && pos.y < n && pos.x >= 0 && pos.x < m && a[pos.y][pos.x] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void GetMaze(int** a, int n, int m, Pt cur, int p)
{
    pq.push(cur);//入栈
    if (cur.y == 0 && cur.x == m - 1)
    {
        if (p >= 0 && minpq.empty() || pq.size() < minpq.size())//更新最短路径
        {
            minpq = pq;//拷贝要开新空间不能让两个栈指针指向一个地址，因为后面会pop，pq会越界，也会内存泄漏
        }
    }
    Pt next;
    a[cur.y][cur.x] = 2;//标记已搜索的路径
    next = cur;
    next.y -= 1;
    if (IsPass(a, n, m, next))//四个方向递归
    {
        GetMaze(a, n, m, next, p);
    }

    next = cur;
    next.y += 1;
    if (IsPass(a, n, m, next))
    {
        GetMaze(a, n, m, next, p - 3);
    }

    next = cur;
    next.x -= 1;
    if (IsPass(a, n, m, next))
    {
        GetMaze(a, n, m, next, p - 1);
    }

    next = cur;
    next.x += 1;
    if (IsPass(a, n, m, next))
    {
        GetMaze(a, n, m, next, p - 1);
    }
    a[cur.y][cur.x] = 1;//找其他路径可能会走同一个格子
    pq.pop();//没有返回true这步是错的撤回入栈
    return;
}
int main()
{
    int n = 0;
    int m = 0;
    int** add = NULL;
    int tli = 0;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        cin >> tli;
        add = (int**)malloc(sizeof(int*) * n);//32位和64位地址大小有差异所以sizeof（int*）
        for (int i = 0; i < n; i++)
        {
            int* new1 = (int*)malloc(sizeof(int) * m);
            for (int j = 0; j < m; j++)
            {
                scanf(" %d", &new1[j]);
            }
            add[i] = new1;
        }
        GetMaze(add, n, m, { 0,0 }, tli);
    }
    if (!minpq.empty())
    {
        stack<Pt>pq1;
        while (!(minpq.empty()))//更换出栈顺序
        {
            Pt a = minpq.top();
            pq1.push(a);
            minpq.pop();
        }
        while (pq1.size() != 1)//打印
        {
            Pt a = pq1.top();
            printf("[%d,%d],", a.y, a.x);
            pq1.pop();
        }
        Pt a = pq1.top();
        printf("[%d,%d]", a.y, a.x);
        pq1.pop();
    }
    else
    {
        printf("Can not escape!");
    }
    for (int i = 0; i < n; i++)
    {
        free(add[i]);
    }
    free(add);
    add = NULL;
    return 0;
}