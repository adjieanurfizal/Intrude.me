#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../BOOLEAN.H"

typedef int infotype;

typedef struct tNode* address;
typedef struct tNode {
    infotype info;
    address next;
} Node;

address Alokasi(infotype X);
void Dealokasi(address P);

#endif