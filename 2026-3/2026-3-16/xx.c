//树
//每个结点有且只有一个父结点
//假设一颗满二叉树的高度是h
//总结点个数 = 2^0+2^1.....+2^h-1 = N
//2^h-1 = N
//h = log2为底N+为对数1;
//完全二叉树，假设树的高度是h
//前h-1层都是满的
//最后一层不满；但最后一层从左往右都是连续的
//完全二叉树2^h-1-x = N//x是缺的节点
//最多缺失是2^(h-1)-1
//搜索二叉树，任何一颗树，左子树都比根要小，右子树都比根要大，搜索中查找一个树，最多查找高度次
#include <stdio.h>
#include <stdlib.h>
typedef char BTDateType;
typedef struct BinnaryTreeNode
{
	struct BinnaryTreeNode* pleft;
	struct BinnaryTreeNode* pright;
	BTDateType date;
}BNode;
void PreVOrder(BNode* root)//前序遍历
{
	if (root == NULL)
	{
		return;
	}
	printf("%c\n", root->date);
	PreVOrder(root->pleft);
	PreVOrder(root->pright);
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
	int a = 0;
	printf("\033[41;32m%d\033[0m\n", a);
}