#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//线性表是具有相同特性的数据元素的一个有限序列
typedef struct
{
	int x;
	int z;
}dxs;
void suspand(int* count,dxs**dxsx)
{
	(*count)++;
	dxs* p1 = realloc(*dxsx, (*count)*sizeof(dxs));
	assert(p1);
	(*dxsx) = p1;
	p1 = NULL;
}
int main()
{
	dxs* dxs1 = (dxs*)calloc(1,sizeof(dxs));
	dxs* dxs2 = (dxs*)calloc(1,sizeof(dxs));
	dxs* dxs3 = (dxs*)calloc(1,sizeof(dxs));
	int count1 = 1;
	int count2 = 1;
	int count3 = 1;
	dxs* p1 = dxs1;
	dxs* p2 = dxs2;
	dxs* p3 = dxs3;
	while (scanf("%d %d",&p1->x,&p1->z) != EOF)
	{
		suspand(&count1,&dxs1);
		p1 = dxs1 + (count1 - 1);
		p1->x = NULL;
		p1->z = NULL;
	}
	while (scanf("%d %d", &p2->x, &p2->z)!=EOF)
	{
		suspand(&count2, &dxs2);
		p2 = dxs2 + (count2 - 1);
		p2->x = NULL;
		p2->z = NULL;
	}
	p1 = dxs1;
	p2 = dxs2;
	while (p1->x != NULL || p2->x != NULL)
	{
		if (p1->z > p2->z)
		{
			p3->z = p2->z;
			p3->x = p2->x;
			p2++;
		}
		else if (p1->z < p2->z)
		{
			p3->z = p1->z;
			p3->x = p1->x;
			p1++;
		}
		else
		{
			p3->x = (p1->x)+(p2->x);
			p3->z = p1->z;
			p1++;
			p2++;
		}
		suspand(&count3, &dxs3);
		p3 = dxs3 + (count3 - 1);
	}
	int i = 0;
	for (i = 0; i < count3-1; i++)
	{
		printf("%d %d\n", (dxs3+i)->x,(dxs3+i)->z);
	}
	return 0;
}