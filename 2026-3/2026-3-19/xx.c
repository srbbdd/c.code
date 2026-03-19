#define _CRT_SECURE_NO_WARNINGS
//void bl(struct TreeNode* root, int* a, int* i)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    a[(*i)] = root->val;
//    (*i)++;//i需要传地址进来否则递归结束回到这里进入右递归i的值不正确
//    bl(root->left, a, i);
//    bl(root->right, a, i);
//}
//int TreeNodeSize(struct TreeNode* root)
//{
//    return root == NULL ? 0 : TreeNodeSize(root->right) + TreeNodeSize(root->left) + 1;//计算树的总值
//}
//int* preorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    int size = TreeNodeSize(root);
//    int* a = (int*)malloc(sizeof(int) * size);
//    int i = 0;
//    bl(root, a, &i);
//    *returnSize = i;
//    return a;
//}
//int maxDepth(struct TreeNode* root)//计算二叉树的深度 
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//    int pright = maxDepth(root->right);//递归左右两天分支
//    int pleft = maxDepth(root->left);
//    int date = 1 + (pright > pleft ? pright : pleft);//取深度更深的加上这个节点本身相加，然后返回给上一个节点
//    return date;
//}
#include <stdio.h>
int main()
{
    int long long n = 0;
    scanf("%lld", &n);
    int date[10] = { 0 };
    while (n)
    {
        int number = n % 10;
        date[number] += 1;
        n /= 10;
    }
    for (int i = 0; i < 9; i++)
    {
        if (date[i] != 0)
        {
            printf("%d:%d\n", i, date[i]);
        }
    }
    return 0;
}
#include <stdio.h>
int main()
{
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    int i = 0;
    int size = 0;
    for (i = a; i <= b; i++)
    {
        printf("%d", i);
        size++;
    }
    printf("Sum = %d", (size * (a + b)) / 2);
    return 0;
}
#include <stdio.h>
int main()
{
    int n = 0;
    char c = 'c';
    scanf("%d %c", &n, &c);
    int i = 0;
    for (i = 1; i <= n; i++)
    {
        int j = 0;
        for (j = 1; j <= n; j++)
        {
            if (i % 2 == 0)
            {
                printf("\n");
                break;
            }
            else
            {
                printf("%c", c);
            }
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char a[10000];
    scanf("%s", &a);
    char* p1 = a;
    while (*p1)
    {
        if (!strchr(a, *p1))
        {
            printf("%c", *p1);
        }
        p1 += 1;
    }
    return 0;
}
#include <stdio.h>
int main()
{
    char a[50];
    scanf("%s", &a);
    char* p1 = a;
    float size = 0.0f;
    float er = 0.0f;
    if (*p1 = '-1')
    {
        p1++;
    }
    while (*p1)
    {
        if (*p1 == '2')
        {
            er++;
        }
        size++;
        p1++;
    }
    if (a[0] == '-')
    {
        printf("%.2f", (((size/er) * 1.5) * (size / 2 != 0 ? 2.0 : 1.0)) * 100.0);
    }
    else
    {
        printf("%.2f", (er / size * (size / 2 != 0 ? 2 : 1)) * 100.0);
    }
    return 0;
}