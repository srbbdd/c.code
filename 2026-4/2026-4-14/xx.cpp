#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct people
{
    int number;
    char personality;
};
struct Tree
{
    people* val;
    Tree* left;
    Tree* right;
};
Tree* CreatTree(Tree* root, people* x)
{
    if (root == NULL)
    {
        Tree* root = (Tree*)malloc(sizeof(Tree));
        root->val = x;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (x->number < root->val->number)
    {
        root->left = CreatTree(root->left, x);
    }
    else
    {
        root->right = CreatTree(root->right, x);
    }
    return root;
}
char SortTree(Tree* root, int x)
{
    char c = 0;
    if (root->val->number == x)
    {
        return root->val->personality;
    }
    if (x <= root->val->number)
    {
        c = SortTree(root->left, x);
    }
    if (x >= root->val->number)
    {
        c = SortTree(root->right, x);
    }
    return c;
}
int main()
{
    int mount = 0;
    cin >> mount;
    people add[mount];
    for (int i = 0; i < mount; i++)
    {
        cin >> add[i].number >> add[i].personality;
        getchar();
    }
    Tree* root = (Tree*)malloc(sizeof(Tree));
    root->val = &(add[mount - 1]);
    root->left = NULL;
    root->right = NULL;
    for (int i = mount - 1; i >= 0; i--)
    {
        CreatTree(root, &(add[i]));
    }
    int m = 0;
    cin >> m;
    int fas = 1;
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        int k = 0;
        cin >> k;
        int x = 0;
        int j = 0;
        for (j = 0; j < k; j++)
        {
            cin >> x;
            if (SortTree(root, x) != 'i')
            {
                break;
            }
        }
        for (int p = j + 1; p < k; p++)
        {
            cin >> x;
        }
        if (j == k && fas)
        {
            cout << i + 1;
            fas = 0;
            count = 1;
        }
        else if (j == k)
        {
            cout << " " << i + 1;
        }
    }
    if (count)
    {
        cout << "\n";
    }
    else
    {
        cout << "None" << "\n";
    }
    return 0;
}
#include <iostream>
using namespace std;
struct Tree
{
    int val;
    Tree* left;
    Tree* right;
};
Tree* CreatTree(int* back, int bhead, int bend, int* middle, int mhead, int mend)
{
    if (bhead > bend)
    {
        return NULL;
    }
    Tree* root = (Tree*)malloc(sizeof(Tree));
    root->val = back[bend];
    root->left = root->right = NULL;
    int index = mhead;
    for (index; index < mend; index++)
    {
        if (middle[index] == root->val)
        {
            break;
        }
    }
    int TreeLeft = index - mhead;
    root->left = CreatTree(back, bhead, bhead + TreeLeft - 1, middle, mhead, index - 1);
    root->right = CreatTree(back, bhead + TreeLeft, bend - 1, middle, index + 1, mend);
    return root;
}
void CompareTree(Tree* root, int i, int* b)
{
    if (root == NULL)
    {
        return;
    }
    if (root->val % i != 0)
    {
        *b = -1;
        return;
    }
    CompareTree(root->left, i + 1, b);
    CompareTree(root->right, i + 1, b);
    return;
}
int main()
{
    int m = 0;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int amount = 0;
        cin >> amount;
        int back[amount];
        int middle[amount];
        int j = 0;
        for (j = 0; j < amount; j++)
        {
            cin >> back[j];
        }
        getchar();
        for (j = 0; j < amount; j++)
        {
            cin >> middle[j];
        }
        Tree* root = CreatTree(back, 0, amount - 1, middle, 0, amount - 1);
        int a = 1;
        int b = 0;
        CompareTree(root, a, &b);
        if (b != -1)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }

    return 0;
}