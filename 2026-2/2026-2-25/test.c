#include "xx.h"
void zr(sl* ps)
{
	if (ps->size == ps->capacity)
	{
		Sqdate* p1 = (Sqdate*)realloc(ps->a, (sizeof(Sqdate) * ps->capacity) * 2);
		assert(p1);
		ps->a = p1;
		ps->capacity *= 2;
	}
}
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
	zr(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void  seqlistprintf(sl* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void seqlistintFront(sl* ps, Sqdate x)
{
	zr(ps);
	int i = ps->size - 1;
	for (i; i >= 0; i--)
	{
		ps->a[i+1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->size++;
}
void seqlistintPopback(sl* ps)
{
	assert(ps->size > 0);
	ps->size--;//等下次使用已删除的数据空间直接覆盖
}
void seqlistintPopfront(sl* ps)
{
	assert(ps->size > 0);
	int i = 0;
	for (i = 0; i < ps->size-1; i++)
	{
		ps->a[i] = ps->a[i+1];
	}
	ps->size--;
}
void inserte(sl* ps, int pos, Sqdate x)
{
	assert(pos < ps->size && pos >= 0);
	zr(ps);
	int i = ps->size;
	for (i; i >= pos; i--)
	{
		ps->a[i] = ps->a[i-1];
	}
	ps->a[i] = x;
	ps->size++;
}
void delete(sl* ps, int pos)
{
	assert(pos < ps->size && pos >= 0);
	int i = pos - 1;
	for (i; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void destory(sl* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
int fine(sl* ps, Sqdate x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	printf("-1");
}
void modify(sl* ps, int pos, Sqdate x)
{
	assert(pos < ps->size && pos >= 0);
	ps->a[pos-1] = x;
}