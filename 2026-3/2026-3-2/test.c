#include "test.h"
SLTNode* kkk(SLTDate x)
{
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
    assert(newnode);
    newnode->date = x;
    newnode->next = NULL;
    return newnode;
}
void SListPushBack(SLTNode** phead, SLTDate x)
{
    SLTNode* newnode = kkk(x);
    if (*phead == NULL)
    {
        *phead = newnode;
    }
    else
    {
        SLTNode* tail = *phead;
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
void SListPushFronrt(SLTNode** phead, SLTDate x)
{
    SLTNode* newnode = kkk(x);
    newnode->next = *phead;
    *phead = newnode;
}
void SListPopFront(SLTNode** phend)
{
    SLTNode* p1 = *phend;
    *phend = (*phend)->next;
    free(p1);
}
void SListPopBack(SLTNode** phend)
{
    if (*phend == NULL)
    {
        return ;
    }
    else if ((*phend)->next == NULL)
    {
        free(*phend);
        *phend = NULL;
    }
    else
    {
        SLTNode* p1 = *phend;
        SLTNode* p2 = NULL;
        while (p1->next != NULL)
        {
            p2 = p1;
            p1 = p1->next;
        }
        free(p1);
        p2->next = NULL;
    }
}
SLTNode* SListFind(SLTNode* phead, SLTDate x)
{
    SLTNode* p1 = phead;
    while (p1)
    {
        if (p1->date == x)
        {
            return p1;
        }
        p1 = p1->next;
    }
    return NULL;
}
void SListInsert(SLTNode** phead, SLTNode* pov, SLTDate x)
{
    if (pov = *phead)
    {
        SListPushFronrt(phead, x);
    }
    else
    {
        SLTNode* p1 = *phead;
        while (p1->next != pov)
        {
            p1 = p1->next;
        }
        SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
        p1->next = newnode;
        newnode->date = x;
        newnode->next = pov;
    }
}
void SListErase(SLTNode** phead, SLTNode* pov)
{
    if (*phead == pov)
    {
        SListPopFront(phead);
    }
    else
    {
        SLTNode* p1 = *phead;
        while (p1->next != pov)
        {
            p1 = p1->next;
        }
        p1->next = pov->next;
        free(pov);
    }
}