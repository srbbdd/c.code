#pragma once//防止头文件重复包含
//#ifndef __SEQLIST__H__//如果没有定义__SEQLIST__H__则指向，否则执行endif//与#pragma once等价
//#define __SEQLIST__H__

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define max 10
typedef int Sqdate;
typedef struct seqlist
{
	Sqdate* a;
	int size;
	int capacity;
}sl;
void seqlistint(sl* ps);
void seqlistprintf(sl* ps);
void seqlistintPushback(sl* ps, Sqdate x);//尾插,sqdate类型的数据便于修改
void seqlistintFront(sl* ps, Sqdate x);//头插
void seqlistintPopback(sl* ps);//尾删
void seqlistintPopfront(sl* ps);//头删
void inserte(sl* ps, int pos, Sqdate x);
void delete(sl* ps, int pos);
void destory(sl* ps);
int fine(sl* ps, Sqdate x);
void modify(sl* ps, int pos, Sqdate x);
//#endif