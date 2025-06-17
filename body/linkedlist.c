#include <limits.h>
#include <malloc.h>
#include "../header/linkedlist.h"

boolean ListEmpty(List L) {
    return (L.head == NULL);
}

void CreateList(List* L) {
    L->head = NULL;
}

address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != NULL) {
        Info(P) = X;
        Next(P) = NULL;
    }
    return P;
}

void DeAlokasi(address P) {
    if (P != NULL) {
        free(P);
    }
}

address Search(List L, infotype X) {
    address P = First(L);
    while (P != NULL) {
        if (Info(P) == X) return P;
        P = Next(P);
    }
    return NULL;
}

boolean FSearch(List L, address P) {
    address PSearch = First(L);
    while (PSearch != NULL) {
        if (PSearch == P) return true;
        PSearch = Next(PSearch);
    }
    return false;
}

address SearchPrec(List L, infotype X) {
    address Prec = NULL, P = First(L);
    while (P != NULL && Info(P) != X) {
        Prec = P;
        P = Next(P);
    }
    return (P != NULL) ? Prec : NULL;
}

void InsVFirst(List* L, infotype X) {
    address P = Alokasi(X);
    if (P != NULL) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast(List* L, infotype X) {
    address P = Alokasi(X);
    if (P != NULL) {
        if (First(*L) == NULL) {
            First(*L) = P;
        } else {
            address temp = First(*L);
            while (Next(temp) != NULL) {
                temp = Next(temp);
            }
            Next(temp) = P;
        }
    }
}

void DelVFirst(List* L, infotype* X) {
    if (First(*L) != NULL) {
        address P = First(*L);
        First(*L) = Next(P);
        *X = Info(P);
        Next(P) = NULL;
        DeAlokasi(P);
    }
}

void DelVLast(List* L, infotype* X) {
    if (First(*L) != NULL) {
        address PDel = First(*L);
        if (Next(PDel) == NULL) {
            *X = Info(PDel);
            First(*L) = NULL;
        } else {
            address prec = NULL;
            while (Next(PDel) != NULL) {
                prec = PDel;
                PDel = Next(PDel);
            }
            Next(prec) = NULL;
            *X = Info(PDel);
        }
        DeAlokasi(PDel);
    }
}

void InsertFirst(List* L, address P) {
    if (P != NULL) {
        Next(P) = L->head;
        L->head = P;
    }
}

void InsertAfter(List* L, address P, address Prec) {
    if (P != NULL && Prec != NULL) {
        Next(P) = Next(Prec);
        Next(Prec) = P;
    }
}

void InsertLast(List* L, address P) {
    if (ListEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        address last = L->head;
        while (Next(last) != NULL) {
            last = Next(last);
        }
        Next(last) = P;
    }
}

void DelFirst(List* L, address* P) {
    if (!ListEmpty(*L)) {
        *P = L->head;
        L->head = Next(L->head);
        Next(*P) = NULL;
    }
}

void DelP(List* L, infotype X) {
    address P = First(*L), Prec = NULL;
    while (P != NULL && Info(P) != X) {
        Prec = P;
        P = Next(P);
    }
    if (P != NULL) {
        if (Prec == NULL) {
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        DeAlokasi(P);
    }
}

void DelLast(List* L, address* P) {
    if (!ListEmpty(*L)) {
        address prev = NULL;
        address curr = L->head;
        while (Next(curr) != NULL) {
            prev = curr;
            curr = Next(curr);
        }
        *P = curr;
        if (prev == NULL) {
            L->head = NULL;
        } else {
            Next(prev) = NULL;
        }
    }
}

void DelAfter(List* L, address* Pdel, address Prec) {
    if (Prec != Nil && Next(Prec) != Nil) {
        *Pdel = Next(Prec);
        Next(Prec) = Next(*Pdel);
        Next(*Pdel) = Nil;
    }
}

void PrintList(List L, void (*printFunc)(infotype)) {
    address P = L.head;
    while (P != NULL) {
        printFunc(Info(P));
        P = Next(P);
    }
}

void DelAll(List* L) {
    infotype dummy;
    while (!ListEmpty(*L)) {
        DelVFirst(L, &dummy);
    }
}
