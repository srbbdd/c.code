#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int DateType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	DateType date;
}ListNode;
ListNode* ListInit();
void LsitDestory(ListNode* plist);
void ListPushBack(ListNode* plist, DateType x);
void ListPushFront(ListNode* plist, DateType x);

void ListPrint(ListNode* plist);
void ListPopFront(ListNode* plist);
void ListPopBack(ListNode* plist);
ListNode* ListFind(ListNode* plist, DateType x);
void ListInsert(ListNode* plist,DateType x,DateType y);
void ListErase(ListNode* plist,DateType x);