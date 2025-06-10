#include <stdio.h>
#include "header/queue.h"

int main() {
    Queue Q;
    int X;

    CreateQueue(&Q);
    EnQueue(&Q, 10);
    EnQueue(&Q, 20);
    EnQueue(&Q, 30);

    printf("Isi queue setelah enqueue 10, 20, 30:\n");
    Queue temp = Q;
    while (!is_Empty(temp)) {
        deQueue(&temp, &X);
        printf("%d ", X);
    }
    printf("\n");

    // Enqueue lagi setelah kosong
    EnQueue(&Q, 40);
    EnQueue(&Q, 50);

    printf("Isi queue setelah enqueue 40, 50:\n");
    while (!is_Empty(Q)) {
        deQueue(&Q, &X);
        printf("%d ", X);
    }
    printf("\n");

    return 0;
}