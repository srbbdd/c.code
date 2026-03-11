#include "test.h"
//╤сап
void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	QueuePush(&q, 7);
	QueuePush(&q, 8);
	QueuePush(&q, 9);

	while (QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestort(&q);
}
int main()
{
	test();
	return 0;
}