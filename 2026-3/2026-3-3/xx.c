//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
////Ë«Á´±í
//typedef struct s
//{
//	int date;
//	struct s* next1;
//	struct s* next2;
//}s;
//int main()
//{
//	s* p1 = (s*)malloc(sizeof(s));
//	p1->next1 = NULL;
//	p1->next2 = NULL;
//	p1->date = 1;
//	int i = 0;
//	for (i = 1; i <= 5; i++)
//	{
//		s* p2 = (s*)malloc(sizeof(s));
//		assert(p2);
//		p2->date = i;
//		p1->next1 = p2;
//		p2->next2 = p1;
//		p2->next1 = NULL;
//		p1 = p2;
//	}
//	while(p1->next2!= NULL)
//	{
//		printf("%d ", p1->date);
//		p1 = p1->next2;
//	}
//}
#include "test.h"
void test()
{
	ListNode* plist = ListInit();
	ListPushBack(plist,1);
	ListPushBack(plist,2);
	ListPushBack(plist,3);
	ListPushBack(plist,4);
	ListPrint(plist);

}
int main()
{
	test();
	return 0;
}