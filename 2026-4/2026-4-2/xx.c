#define _CRT_SECURE_NO_WARNINGS
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
    int index = ht;
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
Queue* QueueCreat()
{
    Queue* new = (Queue*)malloc(sizeof(Queue));
    new->p1 = NULL;
    new->p2 = NULL;
    return new;
}
void QueuePush(Queue* pq, Tree* x)
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
    return pq->p1 && pq->p2 == NULL;
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int zhong[7];
    int hou[7];
    int i = 0;
    getchar();
    for (i = 0; i < n; i++)
    {
        scanf("%d ", &hou[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &zhong[i]);
    }
    Tree* root = Tre(zhong, 0, n - 1, hou, 0, n - 1);
    Queue* pq = QueueCreat();
    QueuePush(pq, root);
    int j = n;
    while (j > 1)
    {
        Tree* new = QueuePop(pq);
        if (new->left != NULL)
        {
            QueuePush(pq, new->left);
        }
        if (new->right != NULL)
        {
            QueuePush(pq, new->right);
        }
        printf("%d ", new->date);
        j--;
    }
    Tree* new = QueuePop(pq);
    printf("%d ", new->date);
    return 0;
}