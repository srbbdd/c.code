#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int SLTDate;
struct SListNode
{
	SLTDate date;
	struct SListNode* next;
};
typedef struct SListNode SLTNode;
void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** phead, SLTDate x);
void SListPushFronrt(SLTNode* phead, SLTDate x);