#include "xx.h"
void seqlistint(sl* ps)
{
	//memset(ps->a,0, sizeof(Sqdate)*max);//初始化max个元素，每个元素Sqdate个字节
	ps->a = (Sqdate*)malloc(sizeof(Sqdate) * 2);
	assert(ps->a);
	ps->size = 0;
	ps->capacity = 2;
}
void seqlistintPushback(sl* ps, Sqdate x)
{
	if (ps->size == ps->capacity)
	{
		Sqdate* p1 = (Sqdate*)realloc(ps->a, (sizeof(Sqdate) * ps->capacity) * 2);
		assert(p1);
		ps->a = p1;
		ps->capacity *= 2;
	}
	ps->a[ps->size] = x;
	ps->size++;
}