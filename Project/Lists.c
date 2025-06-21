#include "Lists.h"
#include <stdio.h>
void createList(List *l)
{
    l->head = NULL;
}
int isListEmpty(List l)
{
    return l.head == NULL;
}
int isListFull(List *l)
{
    return 0;
}
void insertList(int pos,type item,List *l)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->info = item;
    if (pos == 0)
    {
        p->next=l->head;
        l->head=p;
    }
    else
    {
        Node *q;
        q=l->head;
        for(int i=0;i<pos-1;i++)
            q=q->next;
        p->next = q->next;
        q->next=p;
    }
}
type retreive(int pos,List *l)
{
    Node *q, *tmp;
    type item;
    if(pos==0)
    {
        tmp=l->head;
        item=tmp->info;
        l->head=l->head->next;
        free(tmp);
        return item;
    }
    else
    {
        q=l->head;
        for(int i=0;i<pos-1;i++)
        q=q->next;
        tmp=q->next;
        item=tmp->info;
        q->next=tmp->next;
        free(tmp);
        return item;
    }
}
