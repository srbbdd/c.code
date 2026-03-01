#include "test.h"
void SListPushBack(SLTNode** phead, SLTDate x)
{
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
    newnode->next = NULL;
    newnode->date = x;
    if (*phead == NULL)
    {
        *phead = newnode;
    }
    else
    {
        SLTNode * tail = *phead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}
void SListPrint(SLTNode* phead)
{
    SLTNode* p1 = phead;
    while (p1 != NULL)
    {
        printf("%d ", p1->date);
        p1 = p1->next;
    }
}