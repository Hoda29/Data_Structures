#include "QueueADT.h"

void createQueue(QueueType *q)
{
    q->size=0;
    q->front=0;
    q->rear=MAX-1;
}
int isQueueFull(QueueType q)
{
    if(q.size == MAX-1)
        return 1;
    else return 0;
}
int isQueueEmpty(QueueType q)
{
    if(q.size == 0)
        return 1;
    else return 0;
}
void Enqueue(entrytype item,QueueType *q)
{
    if (q->size == MAX-1)
        printf("Queue Overflow\n");
    else
    {
        q->rear=(q->rear+1)%MAX;
        q->entry[q->rear]=item;
        q->size++;
    }
}
entrytype Dequeue(QueueType *q)
{
    entrytype item;
    if (q->size == 0)
        return -1;
    else
    {
        item = q->entry[q->front];
        q->front=(q->front+1)%MAX;
        q->size--;
        return item;
    }
}
entrytype firstElement(QueueType *q)
{
    entrytype item;
    q->rear = (q->rear+(MAX-1))%MAX;
    item = q->entry[q->rear];
    q->rear=(q->rear+1)%MAX;
    return item;
}
void destroyQueue(QueueType *q)
{
    q->size=0;
    q->front=0;
    q->rear=MAX-1;
}
void copyQueue(QueueType *q,QueueType *t)
{
    for(int i=0;i<q->size;i++)
    {
        t->entry[i]=q->entry[i];
    }
}
int sizeQueue(QueueType *q)
{
    return q->size;
}
