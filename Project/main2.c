#include <stdio.h>
#include "Lists.h"
int main()
{
    List l;
    createList(&l);
    insertList(0,20,&l);
    insertList(1,10,&l);
    insertList(2,20,&l);
    insertList(3,30,&l);
    printf("%d",retreive(3,&l));
}

