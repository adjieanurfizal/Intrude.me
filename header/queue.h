#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "linkedlist.h"

typedef struct {
    address Front;
    address Rear;
} Queue;

void CreateQueue(Queue *Q);
boolean is_Empty(Queue Q);
boolean is_Full(Queue Q); // Tidak relevan jika pakai linked list, tapi tetap didefinisikan
void EnQueue(Queue *Q, infotype X);
void deQueue(Queue *Q, infotype *X);

#endif