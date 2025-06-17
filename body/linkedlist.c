#include <limits.h>
#include <malloc.h>
#include "../header/linkedlist.h"

/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L){
	return (L.head == NULL);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List* L){
	L->head = NULL;
}

/**** Manajemen Memory ****/
address Alokasi (infotype X){
	address P;
	
	P = (address)malloc(sizeof(ElmtList));
	if (P != NULL){
        Info(P) = X;
        Next(P) = NULL;
	}
	return (P);
}

void DeAlokasi (address P){
	if (P != NULL){
	    free (P);
	}
}

/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X){
	
	address P;
	boolean found =  false;
	
	P = First(L);
	while ((P != NULL) && (!found)){
		if (Info(P) == X){	
            found = true; 	
        }
		else{
            P = Next(P);	
        }
    }	
	return (P);
}

boolean FSearch (List L, address P){

	boolean found=false;
    address PSearch;
	
	PSearch = First(L);
	while ((PSearch != NULL) && (!found)){
		if (PSearch == P){	
            found = true; 	
        }
		else{	
            PSearch = Next(PSearch);	
        }
	}	 
	return (found);
}

address SearchPrec (List L, infotype X){
	
	address Prec, P;
	boolean found=false;
	
	Prec = NULL;
	P = First(L);
	while ((P != NULL) && (!found)){
		if (Info(P) == X){	
            found = true;	
        }
		else{
			Prec = P;
			P = Next(P);
		}
	} 
	if (found){	
        return (Prec);		
    }
	else{	
        return (NULL);		
    }
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (List * L, infotype X){
	
	address P;
	
	P = Alokasi(X);
	if (P != NULL) {
		Next(P) = First(*L);
		First(*L) = P;
	}
}

void InsVLast (List *L, infotype X){
   
    address P, temp;

    P = Alokasi(X); 
    if (P != NULL) { 
        Next(P) = NULL; 
        
        if (First(*L) == NULL) { 
            First(*L) = P; 
        } else {
            temp = First(*L);
            while (Next(temp) != NULL) { 
                temp = Next(temp);
            }
            Next(temp) = P; 
        }
    }
}

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, infotype * X){
	
	address P;
	
	if (First(*L) != NULL){
		P = First(*L);
		First(*L) = Next(P);
		*X = Info(P);
		Next(P) = NULL;
		DeAlokasi (P);
	}
}

void DelVLast (List * L, infotype * X){

	address PDel, prec;
	
	if (First(*L) != NULL)
	{
		PDel = First(*L);
		if (Next(PDel) == NULL){
			*X = Info(PDel);
			First(*L) = NULL;
			DeAlokasi(PDel);
		} else {
			prec = NULL;
			while (Next(PDel) != NULL){
				prec = PDel;
				PDel = Next(PDel);
			}
			Next(prec) = NULL;
			*X = Info(PDel);
		}
		DeAlokasi(PDel);
	}
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P){
	if (P != NULL){
		Next(P) = L->head;
     	L->head = P;
	}
}

void InsertAfter (List * L, address P, address Prec){
	
    if (P != NULL && Prec != NULL) {
        Next(P) = Next(Prec); // P menunjuk ke elemen setelah Prec
        Next(Prec) = P; // Prec menunjuk ke P sebagai elemen berikutnya
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

/**** Penghapusan sebuah elemen ****/
void DelFirst(List* L, address* P) {
    if (!ListEmpty(*L)) {
        *P = L->head;
        L->head = Next(L->head);
        Next(*P) = NULL;
    }
}

void DelP (List * L, infotype X){

	address P, Prec;
	boolean found=false;
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

void DelAfter (List * L, address * Pdel, address Prec){
    if (Prec != Nil && Next(Prec) != Nil) { 
        *Pdel = Next(Prec); 
        Next(Prec) = Next(*Pdel); 
        Next(*Pdel) = Nil;
    }
}


/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintList(List L, void (*printFunc)(infotype)) {
    address P = L.head;
    while (P != NULL) {
        printFunc(Info(P));
        P = Next(P);
    }
}

void DelAll (List * L){

	address PDel;
	
	PDel = First(*L);
	DeAlokasi(PDel);
}



