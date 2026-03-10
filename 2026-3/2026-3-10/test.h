#pragma once;
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
typedef int TyDate;
typedef struct stack
{
	TyDate* date;
	int top;
	int capacity;
}ST;
void StackInit(ST* ps);
void StackDestory(ST* ps);

void StackPush(ST* ps,TyDate x);
void StackPop(ST* ps);
TyDate StackTop(ST* ps);
int StackSize(ST* ps);
int StackEmpty(ST* ps);