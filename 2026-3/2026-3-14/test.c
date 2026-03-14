#include "test.h"
void PreVOrder(BNode* root)//Ç°Ðò±éÀú
{
	if (root == NULL)
	{
		return;
	}
	printf("%c\n", root->date);
	PreVOrder(root->pleft);
	PreVOrder(root->pright);
}