#include <stdio.h>
#include <stdlib.h>
typedef char BTDateType;
typedef struct BinnaryTreeNode
{
	struct BinnaryTreeNode* pleft;
	struct BinnaryTreeNode* pright;
	BTDateType date;
}BNode;
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
	return (a+(TreeSize(root->pright))+(TreeSize(root->pleft)));
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
//在具有2n个节点的完全二叉树叶子的节点个数为
//假设度为0的有X0个
//假设度为1的有X1个
//假设度为2的有X2个
//X0+X1+X2 = 2n
//度为0的节点个数的一个结论：度为0的节点数等于度为2的节点数+1，==X0 = X2+1
//X0 + X1 + X0-1 = 2n
//完全二叉树度为1的节点最多就1个，或者没有，这里不可能没有，因为如果X1 = 0那么，X0 =2n+1/2 这就整出了个小数，不肯能会有0.5个节点所以这里的X1=1
//2X0 + 1- 1 = 2n == X0 = n
struct ListNode* deleteDuplicates(struct ListNode* head)//消除链表中重复的数
{
	if (head == NULL)
	{
		return head;
	}
	struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));//创建头节点
	struct ListNode* cur = new;
	new->next = head;
	while (cur->next && cur->next->next)//如果第一个或者下一个为空就停止
	{
		if (cur->next->val == cur->next->next->val)//如果某一个和下一个val一样
		{
			int x = cur->next->val;
			while (cur->next && cur->next->val == x)//如果是相同的则直接将cur的next换到下下一个，循环到与x保存的val不同为止
			{
				cur->next = cur->next->next;
			}
		}
		else
		{
			cur = cur->next;//没有则直接下一个
		}
	}
	return new->next;
}
//列入输入 1，2，3，3，4，4，5//刚开始全部相同，直到cur到2的位置cur->next = cur->next->next;将2的next链接到第四个元素然后循环还是相同然后链接到第一个4，cur不动防止后面两个还是相同的，下次进入外循环，此时cur的next指向第一个4所以next和next->next相同再次循环，最后将2的next链接到5循环终止