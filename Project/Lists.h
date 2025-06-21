#ifndef LISTS_H_INCLUDED
#define LISTS_H_INCLUDED
typedef int type;
typedef struct nodeT{
    type info;
    struct nodeT *next;
}Node;
typedef struct list{
    Node *head;
}List;
void createList(List *l);
int isListEmpty(List l);
int isListFull(List *l);
void insertList(int pos,type item,List *l);
type retreive(int pos,List *l);
#endif // LISTS_H_INCLUDED
