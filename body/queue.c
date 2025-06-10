#include "../header/queue.h"

void CreateQueue(Queue *Q) {
    Q->Front = NULL;
    Q->Rear = NULL;
}

boolean is_Empty(Queue Q) {
    return (Q.Front == NULL);
}

boolean is_Full(Queue Q) {
    return false; // Karena menggunakan linked list, queue tidak bisa penuh
}

void EnQueue(Queue *Q, infotype X) {
    address P = Alokasi(X);
    if (P != NULL) {
        if (is_Empty(*Q)) {
            Q->Front = Q->Rear = P;
        } else {
            Q->Rear->next = P;
            Q->Rear = P;
        }
    }
}

void deQueue(Queue *Q, infotype *X) {
    if (!is_Empty(*Q)) {
        address P = Q->Front;
        *X = P->info;
        Q->Front = Q->Front->next;
        if (Q->Front == NULL) {
            Q->Rear = NULL;
        }
        Dealokasi(P);
    }
}