#include<iostream>
using namespace std;
void recursive(bool* book, int* like, int (*bookjz)[4], int n, int m, int* p1backup)
{
	int i = 0;
	int ret = 0;
	for (i = 0; i < m; i++)//如果n个人都分到书就打印并离开这次递归
	{
		if (book[i] == true)
		{
			ret++;
		}
	}
	if (ret == n)
	{
		int flase = 1;
		printf("(");
		for (int j = 0; j < n; j++)
		{
			if (flase)
			{
				printf("%d", p1backup[j]);
				flase = 0;
			}
			else
			{
				printf(", %d", p1backup[j]);
			}
		}
		printf(")");
		printf("\n");
		return ;
	}
	else
	{
		for (int j = 0; j < m; j++)
		{
			if ((*bookjz)[j] == 1 && book[j] != true)//找到喜欢的书
			{
				(*like) = j + 1;//记录的喜欢书的位置
				book[j] = true;//吧书本状态更新
				recursive(book, like + 1, bookjz + 1, n, m, p1backup);//递归找下一个人喜欢的书
				book[j] = false;//撤回分配，找下本喜欢的书，其他分配方案
				(*like) = 0;//撤回位置
			}
		}
	}
}
int main()//递归实现枚举
{
	int n = 0;
	int m = 0;
	cin >> n;
	cin >> m;
	bool book[4] = { false };//记录分书
	int like[3] = { 0 };//记录分到第几本书
	int* p1 = like;
	int bookjz[3][4] = { 0 };//喜欢的书
	int i = 0;
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < m; j++)
		{
			scanf("%d", &bookjz[i][j]);
		}
	}
	recursive(book, p1, bookjz, n, m, p1);
	return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long int n = 0;
    cin >> n;
    for (int i = log2(n); i >= 1; i--)
    {
        int j = 1;
        int ret = 0;
        while (ret < n)
        {
            ret += pow(j, i);
            j++;
        }
        if (ret == n)
        {
            int p = 0;
            for (p = 1; p <= j; p++)
            {
                if (p != j)
                {
                    printf("%d^%d+", p, i);
                }
                else
                {
                    printf("%d^%d", p, i);
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
    int a = 0;
    int b = 0;
    cin >> a >> b;
    if (b == 0)
    {
        if (a == 1)
        {
            printf("dudu\nmove");
        }
        else if (a == 0)
        {
            printf("biii\nstop");
        }
        else
        {
            printf("-\nstop");
        }
    }
    else
    {
        cout << "-\n";
        a == 1 ? cout << "move" : cout << "stop";
    }
    return 0;
}
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
    root->left = CreatTree(front, fhead + 1, fhead+leftloog, behind, bhead,index-1);
    root->right = CreatTree(front, fhead+leftloog+1 , fend, behind, index + 1, bend);
    return root;
}
void reverseTree(Tree* root)
{
    if (root == NULL)
    {
        return ;
    }
    if (root->left != NULL && root->right != NULL)
    {
        int ret = root->left->val;
        root->left->val = root->right->val;
        root->right->val = ret;
    }
    reverseTree(root->left);
    reverseTree(root->right);
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
    reverseTree(root);
    queue<Tree*>pq;
    pq.push(root);
    while (!pq.empty())
    {
        Tree* newTree = pq.front();
        if (newTree->left != NULL)
        {
            pq.push(newTree->left);
        }
        if (newTree->right != NULL)
        {
            pq.push(newTree->right);
        }
        printf("%d ", newTree->val);
        pq.pop();
        free(newTree);
    }
    return 0;
}