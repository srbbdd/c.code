#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int QDateType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDateType date;
}QN;
typedef struct Queue
{
	QN* head;
	QN* tail;
}Queue;
void QueueInit(Queue* pq);
void QueueDestort(Queue* pq);
void QueuePush(Queue* pq,QDateType x);
void QueuePop(Queue* pq);
QDateType QueueFront(Queue* pq);
QDateType Queueback(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);