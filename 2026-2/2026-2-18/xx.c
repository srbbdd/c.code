#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//单链表求和
struct s
{
    int date;
    struct s* index;
};
int main()
{
    int n = 0;
    struct s* arr = (struct s*)malloc(sizeof(struct s));
    arr->index = NULL;
    struct s* p1 = arr;
    scanf("%d", &n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        struct s* p2 = (struct s*)malloc(sizeof(struct s));
        scanf("%d", &p1->date);
        p2->index = NULL;//将新申请的空间的下一个节点置空
        p1->index = p2;//将目前的节点地址存入新的节点
        p1 = p2;//指针指向新的节点准备存入下个新的节点
    }
    p1 = arr;
    int ret = 0;
    while (p1!= NULL)
    {
        ret += p1->date;
        p1 = p1->index;//最新的节点肯定是空指针
    }
    printf("%d", ret);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct s
{
    int date;
    struct s* index;
};
int main()
{
    int n = 0;
    struct s* arr = (struct s*)malloc(sizeof(struct s));
    struct s* p1 = arr;
    int i = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        struct s* p2 = (struct s*)malloc(sizeof(struct s));
        p2->index = NULL;
        scanf("%d", &p1->date);
        p1->index = p2;
        p1 = p2;
    }
    p1 = arr;
    while (n--)
    {
        printf("%d ", p1->date);
        p1 = p1->index;
    }
    return 0;
}