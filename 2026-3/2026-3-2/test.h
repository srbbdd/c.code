#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDate;
struct SListNode
{
	SLTDate date;
	struct SListNode* next;
};
typedef struct SListNode SLTNode;
void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** phead, SLTDate x);
void SListPushFronrt(SLTNode**phead, SLTDate x);
void SListPopFront(SLTNode** phend);
void SListPopBack(SLTNode** phend);
SLTNode* SListFind(SLTNode* phead, SLTDate x);
void SListInsert(SLTNode** phead,SLTNode* pov,SLTDate x);
void SListErase(SLTNode** phead, SLTNode* pov);