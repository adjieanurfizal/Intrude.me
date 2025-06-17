#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "BOOLEAN.H"
#include <stdio.h>
#include <stdlib.h>

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).head

typedef void* infotype;
typedef struct tElmtList* address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

typedef struct {
    address head;
} List;

/*********** PROTOTYPE ****************/
boolean ListEmpty(List L);
void CreateList(List* L);
address Alokasi(infotype X);
void DeAlokasi(address P);
address Search(List L, infotype X);
boolean FSearch(List L, address P);
address SearchPrec(List L, infotype X);
void InsVFirst(List* L, infotype X);
void InsVLast(List* L, infotype X);
void DelVFirst(List* L, infotype* X);
void DelVLast(List* L, infotype* X);
void InsertFirst(List* L, address P);
void InsertAfter(List* L, address P, address Prec);
void InsertLast(List* L, address P);
void DelFirst(List* L, address* P);
void DelP(List* L, infotype X);
void DelLast(List* L, address* P);
void DelAfter(List* L, address* Pdel, address Prec);
void PrintList(List L, void (*printFunc)(infotype));
void DelAll(List* L);

#endif
