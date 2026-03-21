#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//二叉树遍历
typedef struct Tree
{
    struct Tree* left;
    struct Tree* right;
    char date;
}Tree;
Tree* arr(char** p1)
{
    if ((**p1) == '/0' || (**p1) == '#')//题目要求#为空并且输入的是前序遍历
    {
        (*p1) += 1;
        return NULL;
    }
    Tree* new = (Tree*)malloc(sizeof(Tree));//每次递归开一个新空间存储元素
    new->date = (**p1);
    (*p1) += 1;
    new->left = arr(&(*p1));//然后递归左右，并且返回这次节点的地址
    new->right = arr(&(*p1));
    return new;
}
void TreeBl(Tree* p1)
{
    if (p1 == NULL)
    {
        return;
    }
    TreeBl(p1->left);
    printf("%c ", p1->date);
    TreeBl(p1->right);
}
int main()
{
    char add[101];
    scanf("%s", add);
    Tree* new = NULL;
    char* p1 = add;
    new = arr(&p1);
    TreeBl(new);
    return 0;
}