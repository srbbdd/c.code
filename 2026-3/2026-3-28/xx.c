#include <stdio.h>
#include <stdlib.h>
struct TreeNode 
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* CreatTree(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd)//先序和中序，先序的第一个元素是根节点
{
    if (preStart > preEnd)
    {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preStart];
    root->left = NULL;
    root->right = NULL;
    int index = inStart;
    for (index; index < inEnd; index++)//将先序的根节点在中序中找到，分割为左右子树
    {
        if (inorder[index] == root->val)
        {
            break;
        }
    }
    int TreeLeft = index - inStart;
    root->left = CreatTree(preorder, preStart + 1, preStart + TreeLeft, inorder, inStart, index - 1);//index减少TreeLeft也会减少直到将左子树全部放入树
    root->right = CreatTree(preorder, preStart + TreeLeft + 1, preEnd, inorder, index + 1, inEnd);//然后加TreeLeft + 1来到右子树，再次分割右子树的左子树节点和右子树节点
    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    return CreatTree(preorder, 0, preorderSize, inorder, 0, inorderSize);
}
int main()
{
    int add[] = { 3,9,20,15,7 };
    int arr[] = { 9,3,15,20,7 };
    return 0;
}