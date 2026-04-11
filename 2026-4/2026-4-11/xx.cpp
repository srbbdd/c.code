#include <iostream>
#include <queue>
using namespace std;
struct Tree
{
    int val;
    struct Tree* left;
    struct Tree* right;
};
Tree* CreatTree(int* front, int fhead, int fend, int* behind, int bhead, int bend)
{
    if (bhead > bend)
    {
        return NULL;
    }
    Tree* root = (Tree*)malloc(sizeof(Tree));
    root->val = front[fhead];
    root->left = NULL;
    root->right = NULL;
    int index = bhead;
    for (index; index < bend; index++)
    {
        if (behind[index] == root->val)
        {
            break;
        }
    }
    int leftloog = index - bhead;
    root->left = CreatTree(front, fhead + 1, fhead + leftloog, behind, bhead, index - 1);
    root->right = CreatTree(front, fhead + leftloog + 1, fend, behind, index + 1, bend);
    return root;
}
int reverseTree(Tree* root)
{
    if (root->right != NULL)
    {
        root->left->val = reverseTree(root->right);
    }
    if (root->left != NULL)
    {
        root->right->val = reverseTree(root->left);
    }
    return root->val;
}
int main()
{
    int n = 0;
    cin >> n;
    int front[7];
    int behind[7];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        cin >> behind[i];
    }
    getchar();
    for (i = 0; i < n; i++)
    {
        cin >> front[i];
    }
    Tree* root = CreatTree(front, 0, n - 1, behind, 0, n - 1);
    //reverseTree(root);
    queue<Tree*>pq;
    pq.push(root);
    while (!pq.empty())
    {
        Tree* newTree = pq.front();
        if (newTree->right != NULL)
        {
            pq.push(newTree->right);
        }
        if (newTree->left != NULL)
        {
            pq.push(newTree->left);
        }
        printf("%d ", newTree->val);
        pq.pop();
        free(newTree);
    }
    return 0;
}