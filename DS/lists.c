#include "lists.h"
#include <stdio.h>
void createList(Listtype *l)
{
    l->head=NULL;
    l->size=0;
}
int isListEmpty(Listtype l)
{
    return (l.size==0);
}
int isListFull(Listtype l)
{
    return 0;
}
void insertList(entryType item,int pos,Listtype *l)
{
    if(pos<0 && pos>l->size)
    {
        printf("Wrong position");
        return;
    }
    else
    {
        Node *p = (Node *)malloc(sizeof(Node));
        p->info=item;
        if(pos==0)
        {
            p->next=l->head;
            l->head=p;
        }
        else
        {
            Node *q;
            q->next=l->head;
            for(int i=0;i<pos-1;i++)
                q=q->next;
            p->next=q->next;
            q->next=p;
        }
    }
    l->size++;
}
entryType retrieve(int pos,Listtype *l)
{
    if(isListEmpty)
        {
            printf("Empty List");
            return;
        }
    else
    {
        if(pos<0 && pos>l->size)
            {
                printf("Wrong position");
                return;
            }
        else
        {
            entryType item;
            Node *q,*tmp;
            if(pos=0)
            {
                item = l->head->info;
                tmp=l->head;
                l->head=l->head->next;
                free(tmp);
            }
            else
            {
                for(int i=0;i<pos-1;i++)
                    q=q->next;
                tmp=q->next;
                item = tmp->info;
                q->next=tmp->next;
                free(tmp);
            }
            l->size--;
            return item;
        }
    }
}
void printList(Listtype *l)
{
    Node *q;
    q=l->head;
    for(int i=0;i<l->size;i++)
    {
        printf("%d[%d]->",i,q->info);
        q=q->next;
    }
}
