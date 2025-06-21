#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED
#include "list.h"
typedef int stack_entry;

typedef struct stack{
    Listtype list;
}Stack;

void createStack(Stack *s);
int isStackFull(Stack s);
int isStackEmpty(Stack s);
void Push(stack_entry item,Stack *s);
int stack_size (Stack s);
stack_entry Pull(Stack *s);
stack_entry Peek(Stack s);

#endif // LINKEDSTACK_H_INCLUDED
