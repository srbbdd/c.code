#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct TreeNode
{
    int date;
    struct TreeNode* left;
    struct TreeNode* right;
};
int add(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int pleft = add(root->left);
    int pright = add(root->right);
    return 1 + (pleft > pright ? pleft : pright);
}
bool isBalanced(struct TreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }
    int l = add(root->left);
    int r = add(root->right);
    return abs(l - r) < 2 && isBalanced(root->left) && isBalanced(root->right);//一次检查一颗树然后递归左右子树直到所有树全部被检查过
}
void DestoryTree(struct TreeNode* root)
{
    if (root == NULL)
    {
        return ;
    }
    DestoryTree(root->left);
    DestoryTree(root->right);
    free(root);
    root = NULL;
}
int main()
{
    struct TreeNode a;
    struct TreeNode b;
    struct TreeNode c;
    struct TreeNode d;
    struct TreeNode e;
    struct TreeNode f;
    struct TreeNode g;
    a.date = 1;
    b.date = 2;
    c.date = 2;
    d.date = 3;
    e.date = 3;
    f.date = 4;
    g.date = 4;
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    d.left = &f;
    d.right = &g;
    c.left = NULL;
    c.right = NULL;
    e.left = NULL;
    e.right = NULL;
    f.left = NULL;
    f.right = NULL;
    g.left = NULL;
    g.right = NULL;

    isBalanced(&a);
    return 0;
}