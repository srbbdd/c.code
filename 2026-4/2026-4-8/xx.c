#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
void FindBig(int (*construction)[5], bool(*constructionbackup)[5], int* x, int* y, int n, int m)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (*(*(construction+i)+j) > max && *(*(constructionbackup+i)+j) != false)
            {
                max = *(*(construction + i) + j);
                *x = i;
                *y = j;
            }
        }
    }
}
int main()
{
    int n = 0;
    int m = 0;
    int k = 0;
    scanf("%d %d %d", &n, &m, &k);
    int i = 0;
    bool constructionbackup[4][5] ;
    int construction[4][5];
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            scanf("%d",&construction[i][j]);
        }
    }
    for (i = 0; i < k; i++)
    {
        int x = 0;
        int y = 0;
        FindBig(construction, constructionbackup, &x, &y, n, m);
        int j = 0;
        int p = 0;
        for (j = 0; j < n; j++)
        {
            constructionbackup[j][y] = false;
        }
        for (p = 0; p < m; p++)
        {
            constructionbackup[x][p] = false;
        }
    }
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            if (constructionbackup[i][j] != false)
            {
                printf("%d ", construction[i][j]);
            }
        }
        if (constructionbackup[i][j])
        {
            printf("\n");
        }
    }
    return 0;
}