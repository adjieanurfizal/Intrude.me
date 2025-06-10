#include <stdlib.h>
#include "../header/linkedlist.h"

address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(Node));
    if (P != NULL) {
        P->info = X;
        P->next = NULL;
    }
    return P;
}

void Dealokasi(address P) {\
    free(P);
}