#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* CreatTree(int* inorder, int inStart, int inEnd, int* postorder, int poStart, int poEnd)//中序和后序还原二叉树
{
    if (inStart > inEnd)
    {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[poEnd];
    root->left = NULL;
    root->right = NULL;
    int index = inStart;
    for (index; index < inEnd; index++)//找到分割点
    {
        if (root->val == inorder[index])
        {
            break;
        }
    }
    int TreeLeft = index - inStart;//测量左子树的节点个数
    root->left = CreatTree(inorder, inStart, index - 1, postorder, poStart, poStart + TreeLeft - 1);//每次建一个节点分割线-1，建树的位置是初始位置加左子树节点数量减一，这样每次递归TreeLeft都会减少一个
    root->right = CreatTree(inorder, index + 1, inEnd, postorder, poStart + TreeLeft, poEnd - 1);//左子树建完中序起始位置改为分割处+1重新分割右子树的左分支，中序起始位置加一个左子树元素位置，因为是后序，后面第一个为根节点，搞完左子树也意味着要建下一个根节点了
    return root;
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    return CreatTree(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    return CreatTree(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}
int main()
{
    int add[] = { 9,3,15,20,7 };
    int arr[] = { 9,15,7,20,3 };
    buildTree(add, 5, arr, 5);
}