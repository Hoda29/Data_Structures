#ifndef QUEUEADT_H_INCLUDED
#define QUEUEADT_H_INCLUDED
#define MAX 10

typedef int entrytype;
 typedef struct{
     int front;
     int rear;
     int size;
     entrytype entry[MAX];
 }QueueType;

 void createQueue(QueueType *q);
 int isQueueFull(QueueType q);
 int isQueueEmpty(QueueType q);
 void Enqueue(entrytype item,QueueType *q);
 entrytype Dequeue(QueueType *q);
 int sizeQueue(QueueType *q);

#endif // QUEUEADT_H_INCLUDED
