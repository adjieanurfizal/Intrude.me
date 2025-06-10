#ifndef LINKED_H
#define LINKED_H

#include "boolean.h"

typedef int infotype;

typedef struct tNode* address;
typedef struct tNode {
    infotype info;
    address next;
} Node;

address Alokasi(infotype X);
void Dealokasi(address P);

#endif