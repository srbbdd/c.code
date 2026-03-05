#include "test.h"
void test()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
	LsitDestory(&plist);
}
int main()
{
	test();
	return 0;
}