#include <iostream>
using namespace std;
struct Tree
{
    int val;
    Tree* left;
    Tree* right;
};
Tree* CreatTree(int* add, int child, int n)
{
    if (child > n)
    {
        return NULL;
    }
    Tree* root = (Tree*)malloc(sizeof(Tree));
    root->val = add[child];
    root->left = root->right = NULL;
    root->left = CreatTree(add, child * 2 + 1, n);
    root->right = CreatTree(add, child * 2 + 2, n);
    return root;
}
void TreeBhead(Tree* root, int x)
{
    if (root == NULL)
    {
        return;
    }
    TreeBhead(root->left, 1);
    TreeBhead(root->right, 1);
    if (x)
    {
        cout << root->val << " ";
    }
    else
    {
        cout << root->val;
    }
}
int main()
{
    int m = 0;
    int n = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int add[n];
        for (int j = 0; j < n; j++)
        {
            cin >> add[j];
        }
        getchar();
        int root = 0;
        Tree* newroot = CreatTree(add, root, n - 1);
        if (add[root] < add[root * 2 + 1])
        {
            while (root * 2 + 1 <= n - 1)
            {
                if (root * 2 + 2 < n && add[root] > add[root * 2 + 2])
                {
                    cout << "Not Heap" << "\n";
                    TreeBhead(newroot, 0);
                    if (i != m - 1)
                    {
                        cout << "\n";
                    }
                    break;
                }
                else if (add[root] > add[root * 2 + 1])
                {
                    cout << "Not Heap" << "\n";
                    TreeBhead(newroot, 0);
                    if (i != m - 1)
                    {
                        cout << "\n";
                    }

                    break;
                }
                root++;
            }
            if (root * 2 + 1 > n - 1)
            {
                cout << "Min Heap" << "\n";
                TreeBhead(newroot, 0);
                if (i != m - 1)
                {
                    cout << "\n";
                }

            }
        }
        else
        {
            while (root * 2 + 1 <= n - 1)
            {
                if (root * 2 + 2 < n && add[root] < add[root * 2 + 2])
                {
                    cout << "Not Heap" << "\n";
                    TreeBhead(newroot, 0);
                    if (i != m - 1)
                    {
                        cout << "\n";
                    }
                    break;
                }
                else if (add[root] < add[root * 2 + 1])
                {
                    cout << "Not Heap" << "\n";
                    TreeBhead(newroot, 0);

                    if (i != m - 1)
                    {
                        cout << "\n";
                    }
                    break;
                }
                root++;
            }
            if (root * 2 + 1 > n - 1)
            {
                cout << "Max Heap" << "\n";
                TreeBhead(newroot, 0);
                if (i != m - 1)
                {
                    cout << "\n";
                }
            }
        }
    }
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int k = 0;
    cin >> k;
    int number = 0;
    int passage = 0;
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> passage;
        for (int j = 0; j < passage; j++)
        {
            if (i >= index || passage >= index)
            {
                cin >> number;
            }
            else
            {
                getchar();
                getchar();
            }
        }
        getchar();
        if (i > index || passage > index)
        {
            i > passage ? index = i : index = passage;
        }
    }
    cout << number << "\n";
    return 0;
}