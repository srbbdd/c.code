#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct ListNode
{
    int date;
    struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head)//·´×ªÁ´±í
{
    if (head == NULL)
    {
        return 0;
    }
    struct ListNode* p1 = NULL;
    struct ListNode* p2 = head->next;
    while (p2 != NULL)
    {
        head->next = p1;
        p1 = head;
        head = p2;
        p2 = p2->next;
    }
    head->next = p1;
    return head;
}
int main()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p1 = head;
    int i = 0;
    for(i = 1; i <= 5; i++)
    {
        struct ListNode* p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
        assert(p2);
        p2->next = NULL;
        p1->date = i;
        p1->next = p2;
        p1 = p2;
    }
    reverseList(head);

    return 0;
}