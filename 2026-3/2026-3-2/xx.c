#include "test.h"
void test()
{
	SLTNode* plist = NULL;
	SListPushFronrt(&plist, 0);
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushFronrt(&plist,0);
	SListPushFronrt(&plist, 0);
	//SLTNode* pos = SListFind(plist, 0);
	//if (pos)
	//{
	//	SListInsert(&plist, pos, 30);
	//}
	SLTNode* pos = SListFind(plist, 1);
	if (pos != NULL)
	{
		SListErase(&plist, pos);
	}
	SListPrint(plist);
}
int main()
{
	test();
	return 0;
}