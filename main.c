#include <stdio.h>
#include "header/queue.h"

int main() {
    Queue giliran;
    initQueue(&giliran);

    enqueue(&giliran, "Ali");
    enqueue(&giliran, "Budi");
    enqueue(&giliran, "Citra");

    printQueue(&giliran);

    char* nama = dequeue(&giliran);
    printf("Sekarang giliran: %s\n", nama);
    free(nama);

    printQueue(&giliran);
    return 0;
}
