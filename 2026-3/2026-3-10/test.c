#include "test.h"
void StackInit(ST* ps)
{
	assert(ps);
	ps->top = -1;
	ps->date = (TyDate*)malloc(sizeof(TyDate) * 4);
	assert(ps->date);
	ps->capacity = 4;
}
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->date);
}
void StackPush(ST* ps, TyDate x)
{
	if (ps->top == ps->capacity-1)
	{
		TyDate* tmp = (TyDate*)realloc(ps->date, (ps->capacity * 2)*sizeof(TyDate));
		assert(tmp);
		ps->date = tmp;
		ps->capacity *= 2;
	}
	ps->top++;
	ps->date[ps->top] = x;
}
void StackPop(ST* ps)
{
	assert(ps->top >= 0);
	ps->top -= 1;
}
TyDate StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top >= 0);
	return ps->date[ps->top];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
int StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == -1;
}