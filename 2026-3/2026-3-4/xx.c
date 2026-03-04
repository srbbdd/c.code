#include "test.h"
void test()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushFront(plist, 0);
	ListInsert(plist, 0, 4);
	ListErase(plist,0);
	ListErase(plist,2);
	ListPrint(plist);
}
int main()
{
	test();
	return 0;
}