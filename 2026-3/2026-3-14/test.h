#include <stdio.h>
#include <stdlib.h>
typedef char BTDateType;
typedef struct BinnaryTreeNode
{
	struct BinnaryTreeNode* pleft;
	struct BinnaryTreeNode* pright;
	BTDateType date;
}BNode;
void PreVOrder(BNode* root);