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
struct lsdxs
{
	int x;
	int z;
	struct lsdxs* index;
};
void suspand(int* count, dxs** dxsx)
{
	(*count)++;
	dxs* p1 = realloc(*dxsx, (*count) * sizeof(dxs));
	assert(p1);
	(*dxsx) = p1;
	p1 = NULL;
}
int main()
{
	dxs* dxs1 = (dxs*)calloc(1, sizeof(dxs));
	dxs* dxs2 = (dxs*)calloc(1, sizeof(dxs));
    struct lsdxs* dxs3 = (struct lsdxs*)calloc(1, sizeof(struct lsdxs));
	int count1 = 1;
	int count2 = 1;
	dxs* p1 = dxs1;
	dxs* p2 = dxs2;
	struct lsdxs* p3 = dxs3;
	while (scanf("%d %d", &p1->x, &p1->z) != EOF)
	{
		suspand(&count1, &dxs1);
		p1 = dxs1 + (count1 - 1);
		p1->x = NULL;
		p1->z = NULL;
	}
	while (scanf("%d %d", &p2->x, &p2->z) != EOF)
	{
		suspand(&count2, &dxs2);
		p2 = dxs2 + (count2 - 1);
		p2->x = NULL;
		p2->z = NULL;
	}
	p1 = dxs1;
	p2 = dxs2;
	while (p1->x != NULL && p2->x != NULL)
	{
		struct lsdxs* l = (struct lsdxs*)malloc(sizeof(struct lsdxs));//链表存储
		assert(l);
		l->index = NULL;
		if (p1->z < p2->z)
		{
			p3->z = p1->z;
			p3->x = p1->x;
			p1++;
		}
		else if (p1->z > p2->z)
		{
			p3->z = p2->z;
			p3->x = p2->x;
			p2++;
		}
		else
		{
			p3->z = p1->z;
			p3->x = (p1->x) + (p2->x);
			p1++;
			p2++;
		}
		p3->index = l;
		p3 = l;
	}
	if (p1->x == NULL)
	{
		while (p2->x != NULL)
		{
			struct lsdxs* l = (struct lsdxs*)malloc(sizeof(struct lsdxs));
			assert(l);
			l->index = NULL;
			p3->z = p2->z;
			p3->x = p2->x;
			p2++;
			p3->index = l;
			p3 = l;
		}
	}
	else
	{
		while (p1->x != NULL)
		{
			struct lsdxs* l = (struct lsdxs*)malloc(sizeof(struct lsdxs));
			assert(l);
			l->index = NULL;
			p3->z = p1->z;
			p3->x = p1->x;
			p1++;
			p3->index = l;
			p3 = l;
		}
	}
	p3 = dxs3;
	while (p3->index != NULL)
	{
		printf("%d %d\n", p3->x, p3->z);
		p3 = p3->index;
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct lbx
{
	int label;
	int s;
	struct lbx* index;
};
int main()
{
	int n = 0;
	int i = 0;
	struct lbx* p1 = (struct lbx*)malloc(sizeof(struct lbx));
	struct lbx* p2 = p1;
	scanf("%d %d", &n, &i);
	int ret = 1;
	while (scanf("%d", &p2->s) != EOF)
	{
		struct lbx* p3 = (struct lbx*)malloc(sizeof(struct lbx));
		assert(p2);
		p3->index = NULL;
		p2->index = p3;
		p2->label = ret;
		p2 = p3;
		ret++;
	}
	p2 = p1;
	while (1)
	{
		if (p2->label == i)//链表添加
		{
			struct lbx* p3 = (struct lbx*)malloc(sizeof(struct lbx));
			p3->index = p2->index;//新的节点连接上新节点前面节点的下一个节点的地址
			p2->index = p3;//前面的节点连新节点
			p3->s = i;
			break;
		}
		p2 = p2->index;
	}
	p2 = p1;
	while (p2->index != NULL)
	{
		printf("%d ", p2->s);
		p2 = p2->index;
	}
	return 0;
}