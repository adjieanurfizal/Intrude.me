#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"
#include "BOOLEAN.H"

typedef struct {
    address Head;
    address Tail;
} Queue;

void CreateQueue(Queue *Q);
boolean IsEmpty(Queue Q);
void Enqueue(Queue *Q, infotype X);
void Dequeue(Queue *Q, infotype *X);
void PrintQueue(Queue Q, void (*printfunc)(infotype));

#endif
