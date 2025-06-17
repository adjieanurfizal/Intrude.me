#include <stdio.h>
#include <stdlib.h>
#include "../header/queue.h"

void CreateQueue(Queue *Q) {
    Q->Head = NULL;
    Q->Tail = NULL;
}

boolean IsEmpty(Queue Q) {
    return (Q.Head == NULL);
}

void Enqueue(Queue *Q, infotype X) {
    address P = Alokasi(X);
    if (P != NULL) {
        if (IsEmpty(*Q)) {
            Q->Head = P;
            Q->Tail = P;
        } else {
            Next(Q->Tail) = P;
            Q->Tail = P;
        }
    }
}

void Dequeue(Queue *Q, infotype *X) {
    if (!IsEmpty(*Q)) {
        address P = Q->Head;
        *X = Info(P);
        Q->Head = Next(P);
        if (Q->Head == NULL) {
            Q->Tail = NULL;
        }
        DeAlokasi(P);
    }
}

void PrintQueue(Queue Q, void (*printFunc)(infotype)) {
    address P = Q.Head;
    while (P != NULL) {
        printFunc(Info(P));
        P = Next(P);
    }
}
