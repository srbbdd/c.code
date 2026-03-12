#include <stdio.h>
#include <stdbool.h>
bool isValid(char* s)
{
    int lon = strlen(s);
    char b[lon];
    int i = 0;
    int ret = 0;
    if (lon % 2 != 0)
    {
        return false;
    }
    while (s[i] != '\0')
    {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{')
        {
            b[ret] = s[i];
            ret++;
        }
        if (s[i] == ']' || s[i] == ')' || s[i] == '}')
        {
            if (ret == 0)
            {
                return false;
            }
            switch (s[i])
            {
            case '}':
                if (b[ret - 1] != '{')
                {
                    return false;
                }
                break;
            case ']':
                if (b[ret - 1] != '[')
                {
                    return false;
                }
                break;
            case ')':
                if (b[ret - 1] != '(')
                {
                    return false;
                }
                break;
            default:
            {
                return false;
            }
            }
            ret--;
        }
        i++;
    }
    if (ret > 0)
    {
        return false;
    }
    return true;
}
typedef struct ss
{
    int date;
    struct ss* next;
}ss;


typedef struct
{
    ss* p1;
    ss* p2;
} MyStack;


MyStack* myStackCreate()
{
    MyStack* p = (MyStack*)malloc(sizeof(MyStack));
    p->p1 = p->p2 = NULL;
    return p;
}

void myStackPush(MyStack* obj, int x)
{
    ss* newnode = (ss*)malloc(sizeof(ss));
    newnode->next = NULL;
    newnode->date = x;
    if (obj->p1 == NULL)
    {
        obj->p1 = obj->p2 = newnode;
    }
    else
    {
        newnode->next = obj->p1;
        obj->p1 = newnode;
    }
}

int myStackPop(MyStack* obj)
{
    int date = obj->p1->date;
    if (obj->p1 == obj->p2)
    {
        free(obj->p1);
        obj->p1 = obj->p2 = NULL;
        return date;
    }
    else
    {
        ss* newnode = obj->p1;
        obj->p1 = obj->p1->next;
        free(newnode);
        return date;
    }
}

int myStackTop(MyStack* obj)
{
    return obj->p1->date;
}

bool myStackEmpty(MyStack* obj)
{
    return obj->p1 == NULL;
}

void myStackFree(MyStack* obj)
{
    obj->p2 = NULL;
    while (obj->p1)
    {
        ss* newnode = obj->p1;
        obj->p1 = obj->p1->next;
        free(newnode);
    }
}