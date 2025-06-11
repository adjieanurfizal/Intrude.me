// queue.c
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/**** Konstruktor/Kreator ****/
void CreateQueue(Queue *Q) {
    Q->Head = NULL;
    Q->Tail = NULL;
}

/**** Predikat untuk test keadaan Queue ****/
boolean IsEmpty(Queue Q) {
    return (Q.Head == NULL);
}

/**** Menambahkan elemen ke Queue (Enqueue) ****/
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

/**** Menghapus elemen dari Queue (Dequeue) ****/
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

/**** Mencetak elemen dalam Queue ****/
void PrintQueue(Queue Q) {
    address P = Q.Head;
    printf("Isi Queue: ");
    if (IsEmpty(Q)) {
        printf("Kosong\n");
    } else {
        while (P != NULL) {
            printf("%d ", Info(P));
            P = Next(P);
        }
        printf("\n");
    }
}
