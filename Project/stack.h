#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define MAX 2
typedef char stack_entry;

typedef struct stack{
    int top;
    stack_entry items[MAX];
}Stack;

void createStack(Stack *s);
int isStackFull(Stack s);
int isStackEmpty(Stack s);
void Push(stack_entry item,Stack *s);
int stack_size (Stack s);
stack_entry Pull(Stack *s);
stack_entry Peek(Stack s);
#endif // STACK_H_INCLUDED
