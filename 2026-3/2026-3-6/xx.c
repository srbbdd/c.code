#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct ListNode
{
    int date;
    struct ListNode* next;
};
//找中间节点
struct ListNode* middleNode(struct ListNode* head)//快慢指针
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* p1 = head;
    int ret = 0;
    while (p1)
    {
        ret++;
        p1 = p1->next;
    }
    ret = (ret / 2 == 0 ? ((ret / 2) - 1) : (ret / 2));
    while (ret>0)
    {
        head = head->next;
        ret--;
    }
    return head;
}
int main()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p1 = head;
    int i = 0;
    p1->date = 1;
    p1->next = NULL;
    //for (i = 2; i <= 5; i++)
    //{
    //    struct ListNode* p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    //    assert(p2);
    //    p2->next = NULL;
    //    p2->date = i;
    //    p1->next = p2;
    //    p1 = p2;
    //}
    middleNode(head);

    return 0;
}