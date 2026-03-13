typedef struct Que
{
    int date;
    struct Que* next;
}QU;
typedef struct Queue
{
    QU* p1;
    QU* p2;
}Queue;
typedef struct
{
    Queue a1;
    Queue a2;
} MyStack;
void QueueCreate(Queue* pq)
{
    pq->p1 = pq->p2 = NULL;
}
void Queuepush(Queue* pq, int x)
{
    assert(pq);
    QU* newnode = (QU*)malloc(sizeof(QU));
    newnode->next = NULL;
    newnode->date = x;
    if (pq->p1 == NULL)
    {
        pq->p1 = pq->p2 = newnode;
    }
    else
    {
        pq->p2->next = newnode;
        pq->p2 = newnode;
    }
}
bool QueueEmpty(Queue* pq)
{
    return pq->p1 == NULL;
}
int QueueSize(Queue* pq)
{
    int ret = 0;
    QU* newnode = pq->p1;
    while (newnode)
    {
        ret++;
        newnode = newnode->next;
    }
    return ret;
}
int QueueFront(Queue* pq)
{
    assert(pq->p1);
    int ret = 0;
    ret = pq->p1->date;
    return ret;
}
void QueuePop(Queue* pq)
{
    if (pq->p1 == NULL)
    {
        return;
    }
    if (pq->p1 == pq->p2)
    {
        free(pq->p1);
        pq->p1 = pq->p2 = NULL;
    }
    else
    {
        QU* new = pq->p1;
        pq->p1 = pq->p1->next;
        free(new);
    }
}
int QueueTop(Queue* pq)
{
    return pq->p2->date;
}
void destroy(Queue* pq)
{
    if (pq->p1 == NULL)
    {
        return;
    }
    pq->p2 = NULL;
    while (pq->p1)
    {
        QU* new = pq->p1->next;
        free(pq->p1);
        pq->p1 = new;
    }
}
MyStack* myStackCreate()
{
    MyStack* s = (MyStack*)malloc(sizeof(MyStack));
    QueueCreate(&s->a1);
    QueueCreate(&s->a2);
    return s;
}

void myStackPush(MyStack* obj, int x)
{
    if (!QueueEmpty(&obj->a1))
    {
        Queuepush(&obj->a1, x);
    }
    else
    {
        Queuepush(&obj->a2, x);
    }
}

int myStackPop(MyStack* obj)
{
    Queue* a = &obj->a1;
    Queue* b = &obj->a2;
    if (QueueEmpty(&obj->a1))
    {
        a = &obj->a2;
        b = &obj->a1;
    }
    while (QueueSize(a) > 1)
    {
        Queuepush(b, QueueFront(a));
        QueuePop(a);
    }
    int ret = QueueFront(a);
    QueuePop(a);
    return ret;
}

int myStackTop(MyStack* obj)
{
    if (!QueueEmpty(&obj->a1))
    {
        return QueueTop(&obj->a1);
    }
    else
    {
        return QueueTop(&obj->a2);
    }
}

bool myStackEmpty(MyStack* obj)
{
    return (QueueEmpty(&obj->a1) && QueueEmpty(&obj->a2));
}

void myStackFree(MyStack* obj)
{
    if (!QueueEmpty(&obj->a1))
    {
        destroy(&obj->a1);
    }
    else
    {
        destroy(&obj->a2);
    }
    free(obj);
    obj = NULL;
}