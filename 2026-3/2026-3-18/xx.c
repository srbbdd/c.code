typedef char BTDateType;
typedef struct BinnaryTreeNode
{
	struct BinnaryTreeNode* pleft;
	struct BinnaryTreeNode* pright;
	BTDateType date;
}BNode;
#include "test.h"
void PreVOrder(BNode* root)//前序遍历, 先中在左在右
{
	if (root == NULL)
	{
		return;
	}
	printf("%c\n", root->date);
	PreVOrder(root->pleft);
	PreVOrder(root->pright);
}
void InOrder(BNode* root)//中序，先左在中在右
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->pleft);
	printf("%c\n", root->date);
	InOrder(root->pright);
}
void PostOrder(BNode* root)//后序，先左在右在中
{
	if (root == NULL)
	{
		return;
	}
	PostOrder(root->pleft);
	PostOrder(root->pright);
	printf("%c\n", root->date);
}
int TreeSize(BNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int a = 0;
	a++;
	return (a + (TreeSize(root->pright)) + (TreeSize(root->pleft)));
}
int TreeSize2(BNode* root)//简化版
{
	return root == NULL ? 0 : (TreeSize2(root->pleft) + TreeSize2(root->pright) + 1);
}
int TreeLeafSize(BNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->pleft == NULL && root->pright == NULL)
	{
		return 1;
	}
	return (TreeLeafSize(root->pleft) + TreeLeafSize(root->pright));
}
void LevelOrder(BNode* root)//层序遍历
{
	//上层出带下层入
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front->pright != NULL)
		{
			QueuePush(&q, front->pright);
		}
		if (front->pleft != NULL)
		{
			QueuePush(&q, front->pright);
		}
	}
	QueueDestort(&q);
}
int main()
{
	BNode* A = (BNode*)malloc(sizeof(BNode));
	A->date = 'A';
	A->pleft = NULL;
	A->pright = NULL;
	BNode* B = (BNode*)malloc(sizeof(BNode));
	B->date = 'B';
	B->pleft = NULL;
	B->pright = NULL;
	BNode* C = (BNode*)malloc(sizeof(BNode));
	C->date = 'C';
	C->pleft = NULL;
	C->pright = NULL;
	BNode* D = (BNode*)malloc(sizeof(BNode));
	D->date = 'D';
	D->pleft = NULL;
	D->pright = NULL;
	BNode* E = (BNode*)malloc(sizeof(BNode));
	E->date = 'E';
	E->pleft = NULL;
	E->pright = NULL;
	A->pleft = B;
	A->pright = C;
	B->pleft = D;
	B->pright = E;
	PreVOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	int a = 0;
	printf("\033[41;32m%d\033[0m\n", a);
	int b = TreeSize2(A);
	printf("%d\n", b);
	b = TreeSize2(B);
	printf("%d\n", b);
	b = TreeLeafSize(A);
	printf("%d\n", b);
}
//前中后序遍历也叫深度优先遍历
//层序遍历 ，广度优先遍历