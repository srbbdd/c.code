#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int TDate;
typedef struct stack
{
    TDate* date;
    int top;
    int capacit;
}TD;
typedef struct
{
    TD p1;
    TD p2;
} MyQueue;
void TDCread(TD* p1)
{
    p1->date = (TDate*)malloc(sizeof(TDate));
    p1->top = -1;
    p1->capacit = 1;
}
void TDPush(TD* p1, TDate x)
{
    if (p1->top == p1->capacit - 1)
    {
        TDate* new = (TDate*)realloc(p1->date, sizeof(TDate) * (p1->capacit * 2));
        p1->date = new;
        p1->capacit *= 2;
    }
    p1->top++;
    p1->date[p1->top] = x;
}
int DTPop(TD* p1)
{
    if (p1->top == -1)
    {
        return 0;
    }
    int a = p1->date[p1->top];
    p1->top -= 1;
    return a;
}
int DTPeek(TD* p1)
{
    return p1->date[p1->top];
}
bool DTEmpty(TD* p1)
{
    return p1->top == -1;
}
void DTFree(TD* p1)
{
    free(p1->date);
    p1->date = NULL;
    p1->capacit = p1->top = 0;
}
MyQueue* myQueueCreate()
{
    MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
    TDCread(&pq->p1);
    TDCread(&pq->p2);
    return pq;
}

void myQueuePush(MyQueue* obj, int x)
{
    TDPush(&obj->p1, x);
}

int myQueuePop(MyQueue* obj)
{
    if (DTEmpty(&obj->p2))
    {
        int x = 0;
        while (x = DTPop(&obj->p1))
        {
            TDPush(&obj->p2, x);
        }
    }
    return DTPop(&obj->p2);
}

int myQueuePeek(MyQueue* obj)
{
    if (DTEmpty(&obj->p2))
    {
        int x = 0;
        while (x = DTPop(&obj->p1))
        {
            TDPush(&obj->p2, x);
        }
    }
    return  DTPeek(&obj->p2);
}

bool myQueueEmpty(MyQueue* obj)
{
    return (DTEmpty(&obj->p1) && DTEmpty(&obj->p2));
}

void myQueueFree(MyQueue* obj)
{
    DTFree(&obj->p1);
    DTFree(&obj->p2);
}
int main()

{
    MyQueue* job = myQueueCreate();
    myQueuePush(job,1);
    myQueuePush(job,2);
    myQueuePeek(job);
    myQueuePop(job);
    myQueueEmpty(job);
}