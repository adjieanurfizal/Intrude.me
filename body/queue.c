#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, const char* name) {
    Player* newPlayer = (Player*)malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newPlayer;
    } else {
        q->rear->next = newPlayer;
        q->rear = newPlayer;
    }
}

char* dequeue(Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }

    Player* temp = q->front;
    char* name = strdup(temp->name); // return salinan nama

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return name;
}

void printQueue(Queue* q) {
    Player* current = q->front;
    while (current != NULL) {
        printf("%s -> ", current->name);
        current = current->next;
    }
    printf("NULL\n");
}
