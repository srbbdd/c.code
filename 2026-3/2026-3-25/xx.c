#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct number
{
    int emr ;
    int date;
    int next ;
}number;
typedef struct list
{
    number* date;
    struct list* next;
}list;
int main()
{
    int l = 0 ;
    int n = 0;
    scanf("%d %d", &l, &n);
    number add[5];
    list* pq = (list*)malloc(sizeof(list));
    list* p1 = pq;
    list* p2 = pq;
    number datenumber[5];
    number* datenumber1 = datenumber;
    pq->next = NULL;
    //assert(pq);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &add[i].emr, &add[i].date, &add[i].next);
    }
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < n; j++)
        {
            if (add[j].emr == l)
            {
                if (l == -1)
                {
                    p1->next = NULL;
                    break;
                }
                list* new = (list*)malloc(sizeof(list));
                new->next = NULL;
                p1->date = add + j;
                p1->next = new;
                l = add[j].next;
                break;
            }
        }
        if (l == -1)
        {
            p1->next = NULL;
        }
        else
        {
            p1 = p1->next;
        }
    }
    i = 0;
    while (pq!= NULL)
    {
        p1 = pq->next;
        p2 = pq;
        int c = pq->date->date;
        while ( p1 != NULL)
        {
            if (c == p1->date->date||-c == p1->date->date)
            {
                list* new = p1;
                p1 = p1->next;
                p2->next = p1;
                datenumber1->date = new->date->date;
                datenumber1->emr = new->date->emr;
                datenumber1->next = new->date->next;
                datenumber1++;

                free(new);
            }
            else
            {
                if(p1 != NULL)
                {
                    p2->date->next = p1->date->emr;
                }
                p2->next = p1;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        if (pq->next == NULL)
        {
            printf("%05d %d -1\n", pq->date->emr, pq->date->date);
            break;
        }
        else
        {
            printf("%05d %d %05d\n", pq->date->emr, pq->date->date, pq->date->next);
        }
        pq = pq->next;
    }
    while (datenumber + i != datenumber1)
    {
        if (datenumber[i].next == -1)
        {
            printf("%05d %d %d\n", datenumber[i].emr, datenumber[i].date, datenumber[i].next);
        }
        else
        {
            printf("%05d %d %5d\n", datenumber[i].emr, datenumber[i].date, datenumber[i+1].emr);
        }
        i++;
    }
    return 0;
}
