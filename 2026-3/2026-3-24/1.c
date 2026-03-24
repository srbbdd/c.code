#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    char date;
    struct Queue* next;
}Queue;
typedef struct QueueIndex
{
    Queue* head;
    Queue* tail;
}Index;
void QueueCreat(Index* pq)
{
    pq->head = NULL;
    pq->tail = NULL;
}
void QueuePush(Index* pq, char x)
{
    Queue* new = (Queue*)malloc(sizeof(Queue));
    new->next = NULL;
    new->date = x;
    if (pq->head == NULL)
    {
        pq->head = new;
        pq->tail = new;
    }
    else
    {
        pq->tail->next = new;
        pq->tail = new;
    }
}
char QueuePop(Index* pq)
{
    if (pq->head == NULL)
    {
        return '\0';
    }
    char emp = pq->head->date;
    if (pq->head == pq->tail)
    {
        free(pq->head);
        pq->head = pq->tail = '\0';
    }
    else
    {
        Queue* new = pq->head->next;
        free(pq->head);
        pq->head = new;
    }
    return emp;
}
int main()
{
    int n = 0;
    Index pq;
    QueueCreat(&pq);
    int i = 1;
    char c = 0;
    scanf("%d %c", &n, &c);
    char* add = (char*)malloc(sizeof(char));
    char j = 0;
    int p = 0;
    getchar();
    while ((j = (char)getchar())!= '\n')
    {
        add[p] = j;
        p++;
        add = (char*)realloc(add,sizeof(char) * (p+2));
    }
    add[p] = '\n';
    if (p > n)
    {
        int l = 0;
        for (l = 0; l <= n; l++)
        {
            printf("%c", add[p - n+ l]);
        }
    }
    else
    {
        for (i = p; i < n; i++)
        {
            QueuePush(&pq, c);
        }
        while (*add != '\n')
        {
            if (*add == '\n')
            {
                QueuePush(&pq, ' ');
            }
            else
            {
                QueuePush(&pq, *add);
            }
            add++;
        }
        while ((c = QueuePop(&pq)) != '\0')
        {
            printf("%c", c);
        }
    }
    return 0;
}
#include <stdio.h>
int main()
{
    int n = 0;
    char arr[1001] = "0";
    scanf("%d %s ", &n, arr);
    char* p1 = arr;
    char* p2 = arr;
    while (*p1 != '0')
    {
        p1++;
    }
    while (p1 - n >= arr)
    {
        p1 -= n;
        int i = 0;
        for (i = 0; i < n; i++)
        {
            printf("%c", *(p1 + i));
        }
    }
    while (p2 != p1)
    {
        printf("%c", *p2);
        p2++;
    }
    return 0;
}