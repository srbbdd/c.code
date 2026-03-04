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
void ListPrint(ListNode* plist);