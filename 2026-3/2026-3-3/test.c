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