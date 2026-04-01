#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    char a = 'a';
    int ret = 0;
    while (a != '\n'&&a!='\0')
    {
        a = getchar();
        if (a == ',')
        {
            printf(";");
            ret = 0;
        }
        if (ret % 2 == 0 && ret != 0)
        {
            printf("%c", a);
        }
        if (a == '/')
        {
            ret++;
        }
    }
    printf(";");
    return 0;
}
#include <stdio.h>
int main()
{
    char add[4];
    scanf("%s", add);
    char* p1 = add;
    while(*p1 == '0')
    {
        p1++;
    }
    char* p2 = add + 2;
    while (p2 >= p1)
    {
        printf("%c", *p2);
        p2--;
    }
    printf("\n");
    return 0;
}
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int add[4];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &add[i]);
    }
    int* p1 = add + (n - 1);
    while (p1 >= add)
    {
        printf("%d ", *p1);
        p1--;
    }
    return 0;
}
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int a = 1;
    int i = 0;
    for (i = 0; i < n - 1; i++)
    {
        a += 2;
    }
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (j = 0; j < a; j++)
        {
            printf("%d", i + 1);
        }
        printf("\n");
        a -= 2;
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int cmp(const void* p1, const void* p2)
{
    return (*(int*)p1) - (*(int*)p2);
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int add[10];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &add[i]);
    }
    qsort(add, n,sizeof(int), cmp);
    int* p1 = add;
    int a = add[0];
    int ret = 0;
    while (*p1 == a)
    {
        ret++;
        p1++;
    }
    printf("%d %d\n", a, ret);
    p1 = add + n - 1;
    a = add[n - 1];
    ret = 0;
    while (*p1 == a)
    {
        ret++;
        p1--;
    }
    printf("%d %d", a, ret);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Tree
{
    int date;
    struct Tree* left;
    struct Tree* right;
}Tree;
Tree* Tre(int* zhong, int zt, int zEnd, int* hou, int ht, int hEnd)
{
    if (zt > zEnd)
    {
        return NULL;
    }
    Tree* root = (Tree*)malloc(sizeof(Tree));
    root->date = hou[hEnd];
    root->left = NULL;
    root->right = NULL;
    int index = 0;
    for (index; index < zEnd; index++)
    {
        if (zhong[index] == root->date)
        {
            break;
        }
    }
    int TreeLeft = index - zt;
    root->left = Tre(zhong, zt, index - 1, hou, ht, ht + TreeLeft - 1);
    root->right = Tre(zhong, index + 1, zEnd, hou, ht + TreeLeft, hEnd - 1);
    return root;
}
typedef struct node
{
    Tree* date;
    struct node* next;
}node;
typedef struct Queue
{
    node* p1;
    node* p2;
}Queue;
void QueueCreat(Queue* pq)
{
    pq = (Queue*)malloc(sizeof(Queue));
    pq->p1 = NULL;
    pq->p2 = NULL;
}
void QueuePush(Queue* pq, int x)
{
    node* new = (node*)malloc(sizeof(node));
    new->date = x;
    new->next = NULL;
    if (pq->p1 == NULL)
    {
        pq->p1 = pq->p2 = new;
    }
    else
    {
        pq->p2->next = new;
        pq->p2 = pq->p2->next;
    }
}
Tree* QueuePop(Queue* pq)
{
    Tree* a = pq->p1->date;
    if (pq->p1 == pq->p2)
    {
        free(pq->p1);
        pq->p1 = pq->p2 = NULL;
    }
    else
    {
        node* new = pq->p1->next;
        free(pq->p1);
        pq->p1 = new;
    }
    return a;
}
bool QueueEmpty(Queue* pq)
{
    return ((pq->p1 == pq->p2) == NULL);
}
int main()
{
    int n = 0;
    scanf("%d", & n);
    int zhong[7];
    int hou[7];
    int i = 0;
    getchar();
    for (i = 0; i < n; i++)
    {
        scanf("%d ", & hou[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d ", &zhong[i]);
    }
    Tree* root = Tre(zhong, 0, n - 1, hou, 0, n - 1);
    Queue pq;
    QueueCreat(&pq);
    QueuePush(&pq, root);
    while (!QueueEmpty(&pq))
    {
        Tree* new = QueuePop(&pq);
        if (new->left != NULL)
        {
            QueuePush(&pq, new->left);
        }
        if (new->right != NULL)
        {
            QueuePush(&pq, new->right);
        }
        printf("%d", new->date);
    }
    return 0;
}