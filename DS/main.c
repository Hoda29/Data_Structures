#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
int main()
{
    Listtype l;
    createList(&l);
    insertList(10,0,&l);
    insertList(20,1,&l);
    insertList(30,2,&l);
    insertList(40,3,&l);
    insertList(50,4,&l);
    printList(&l);
}
