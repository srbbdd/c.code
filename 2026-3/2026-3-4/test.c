#include "test.h"
ListNode* BuyListNode(DateType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	assert(newnode);
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->date = x;
	return newnode;
}
ListNode* ListInit()
{
	//初始化头节点
	ListNode* plist = BuyListNode(0);
	plist->next = plist;
	plist->prev = plist;
	return plist;
}
void ListPushBack(ListNode* plist, DateType x)
{
	ListNode* tail = plist->prev;
	ListNode* newnode = BuyListNode(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = plist;
	plist->prev = newnode;
}
void ListPrint(ListNode* plist)
{
	ListNode* cur = plist->next;
	while (cur != plist)
	{
		printf("%d ", cur->date);
		cur = cur->next;
	}
}
void ListPushFront(ListNode* plist, DateType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* tail = plist->next;
	tail->prev = newnode;
	newnode->next = tail;
	newnode->prev = plist;
	plist->next = newnode;
}
void ListPopFront(ListNode* plist)
{
	assert(plist->next != plist);
	ListNode* tail = plist->next;
	ListNode* first = tail->next;
	first->prev = plist;
	plist->next = first;
	free(tail);
	tail = NULL;
}
void ListPopBack(ListNode* plist)
{
	assert(plist->next != plist);
	ListNode* tail = plist->prev;
	ListNode* first = tail->prev;
	first->next = plist;
	plist->prev = first;
	free(tail);
}
ListNode* ListFind(ListNode* plist, DateType x)
{
	ListNode* p1 = plist->next;
	while (p1 != plist)
	{
		if (p1->date == x)
		{
			return p1;
		}
		p1 = p1->next;
	}
	return NULL;
}
void ListInsert(ListNode* plist, DateType x,DateType y)
{
	ListNode* newnode = BuyListNode(y);
	ListNode* p1 = ListFind(plist,x);
	ListNode* p2 = p1->prev;
	p2->next = newnode;
	newnode->prev = p2;
	newnode->next = p1;
	p1->prev = newnode;
}
void ListErase(ListNode* plist, DateType x)
{
	ListNode* p1 = ListFind(plist,x);
	ListNode* p2 = p1->prev;
	ListNode* p3 = p1->next;
	p2->next = p3;
	p3->prev = p2;
	free(p1);
}