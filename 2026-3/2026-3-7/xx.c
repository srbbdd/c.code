struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* p1 = NULL;
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    struct ListNode* p2 = p1;
    while (list1 && list2)
    {
        if ((list1->val) < (list2->val))
        {
            if (p2 == NULL)
            {
                p1 = p2 = list1;
            }
            else
            {
                p2->next = list1;
                p2 = p2->next;
            }
            list1 = list1->next;
        }
        else
        {
            if (p2 == NULL)
            {
                p1 = p2 = list2;
            }
            else
            {
                p2->next = list2;
                p2 = p2->next;
            }
            list2 = list2->next;
        }
    }
    if (list1)
    {
        p2->next = list1;
    }
    else if (list2)
    {
        p2->next = list2;
    }
    return p1;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL && list2 == NULL)
    {
        return NULL;
    }
    struct ListNode* p1 = NULL;
    if (list1 == NULL || list2 == NULL)
    {
        if (list1)
        {
            p1 = list1;
            list1 = list1->next;
        }
        else
        {
            p1 = list2;
            list2 = list2->next;
        }
    }
    else
    {
        if ((list1->val) <= (list2->val))
        {
            p1 = list1;
            list1 = list1->next;
        }
        else
        {
            p1 = list2;
            list2 = list2->next;
        }
    }
    struct ListNode* p2 = p1;
    while (list1 && list2)
    {
        if ((list1->val) <= (list2->val))
        {
            p1->next = list1;
            list1 = list1->next;
        }
        else if ((list1->val) > (list2->val))
        {
            p1->next = list2;
            list2 = list2->next;
        }
        p1 = p1->next;
    }
    if (list1)
    {
        p1->next = list1;
    }
    else if (list2)
    {
        p1->next = list2;
    }
    return p2;
}