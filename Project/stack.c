#include "stack.h"

void createStack(Stack *s)
{
    s->top= -1;
}
int isStackFull(Stack s)
{
    return (s.top == MAX-1);
}
int isStackEmpty(Stack s)
{
    return (s.top == -1);
}
void Push(stack_entry item,Stack *s)
{
    if (s->top == MAX-1)
        printf("Stack Overflow\n");
    else
    {
        s->items[++s->top]=item;
    }
}
stack_entry Pull(Stack *s)
{
    stack_entry item;
    if (s->top == -1)
        printf("Stack UnderFlow");
    else
        item=(s->items[s->top--]);
        return item;
}
stack_entry Peek(Stack s)
{
    stack_entry item;
    item = s.items[s.top];
    return item;
}
int stack_size (Stack s)
{
    if (s.top=-1)
        return 0;
    else
    {
        int elements = s.top + 1;
        int sizeOfStack = elements * sizeof(stack_entry);
        return sizeOfStack;
    }
}
stack_entry (stack s)
{
    if (s.top!=-1)
    return items[0];
}
void destroyStack(Stack *s)
{
    s->top=-1;
}
void copyStack(Stack *c,Stack *s)
{
    for(int i=0;i<top-1;i++)
    {
        c->items[i]=s->items[i];
    }
}
