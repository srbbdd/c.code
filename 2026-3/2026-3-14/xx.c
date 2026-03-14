//树
//节点的度，一个节点含有多少个子节点，子节点的个数就是节点的度
//叶节点或终端节点，度为0的节点称为叶节点
//非终端节点或分支节点，度不为0的节点
//双亲节点或父节点，若一个节点含有子节点，则这个节点称为该子节点的父节点
//孩子节点或子节点，A分支出B和C那么A是B,C的父节点，B,C是A的子节点
//兄弟节点，具有相同父节点的节点胡成为兄弟节点
//树的度，一棵树中最大的节点的度成为树的度
//节点的层次，从根开始定义起，根为第0层/第1层两种数法，根的子节点为第1层/第二层
//节点的祖先，从跟到该节点所经分支上的所有节点
//子孙，以某点为根的子树中任一节点都称为该节点的子孙
//森林，n棵树互不相交的多棵树的集合称为森林
//二叉树
//每个节点最多有两颗子树，不存在超过大于二的节点
//前序(先根遍历)：先跟，在左子树，在右子树
//中序(中根遍历)：左子树 根 右子树，NULL D NULL B NULL E NULL A NULL C NULL
//后序：右子树 左子树 根
#include "test.h"
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
	BNode*  C = (BNode*)malloc(sizeof(BNode));
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
	printf("\033[41;32m%d\033[0m\n",a);
}