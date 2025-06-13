#ifndef QUEUE_H
#define QUEUE_H

typedef struct Player {
    char name[50];
    struct Player* next;
} Player;

typedef struct {
    Player* front;
    Player* rear;
} Queue;

void initQueue(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, const char* name);
char* dequeue(Queue* q);
void printQueue(Queue* q);

#endif
