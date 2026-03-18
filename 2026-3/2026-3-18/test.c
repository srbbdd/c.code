#include "test.h"
void QueueInit(Queue* pq)
{
    pq->head = pq->tail = NULL; 
}
void QueueDestort(Queue* pq)
{
    assert(pq);
    pq->tail = NULL;
    while (pq->head)
    {
        QN* node = pq->head->next;
        free(pq->head);
        pq->head = node;
    }
}
void QueuePush(Queue* pq, QDateType x)
{
    assert(pq);
    QN* newnode = (QN*)malloc(sizeof(QN));
    assert(newnode);
    newnode->date = x;
    newnode->next = NULL;
    if (pq->head == NULL)
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}
void QueuePop(Queue* pq)
{
    assert(pq);
    assert(pq->head);
    if (pq->head->next == NULL)
    {
        free(pq->head);
        pq->head = pq->tail = NULL;
    }
    else
    {
        QN* node = pq->head->next;
        free(pq->head);
        pq->head = node;
    }
}
QDateType QueueFront(Queue* pq)
{
    assert(pq);
    assert(pq->head);
    return pq->head->date;
}
QDateType Queueback(Queue* pq)
{
    assert(pq);
    assert(pq->tail);
    return pq->tail->date;
}
int QueueSize(Queue* pq)
{
    QN* newnode = pq->head;
    int ret = 0;
    while (newnode)
    {
        ret += 1;
        newnode = newnode->next;
    }
    return ret;
}
bool QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->head != NULL;
}
