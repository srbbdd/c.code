//’ª∫Õ∂”¡–
#include "test.h"
int main()
{
	ST st;
	StackInit(&st);
	StackPush(&st,1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	StackPush(&st, 4);
	StackPush(&st, 5);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	StackPush(&st, 6);
	StackPush(&st, 7);
	StackPush(&st, 8);
	StackPush(&st, 9);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	StackDestory(&st);
	return 0;
}