#ifndef LISTS_H_INCLUDED
#define LISTS_H_INCLUDED
typedef int entryType;
typedef struct{
    entryType info;
    struct node *next;
}Node;
typedef struct{
    Node *head;
    int size;
}Listtype;

void createList(Listtype *l);
int isListEmpty(Listtype l);
int isListFull(Listtype l);
void insertList(entryType item,int pos,Listtype *l);
entryType retrieve(int pos,Listtype *l);
void printList(Listtype *l);

#endif // LISTS_H_INCLUDED
