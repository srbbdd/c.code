#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int add[] = { 0,0,0,0,0,0,0,1,2,3,4,5,6,7,8 };
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    int i = 0;
    char arr[4];
    for (i = 0; i < m; i++)
    {
        scanf("%s", arr);
        char* p1 = arr;
        int j = 0;
        int root = 0;
        for (j = 0; j < n; j++)
        {
            if (p1[j] == 'y')
            {
                root = (root * 2) + 1;
            }
            else
            {
               root = (root * 2) + 2;
            }
        }
        printf("%d", add[root]);
    }
    return 0;
}