#include <limits.h>
#include <malloc.h>
#include "../header/linkedlist.h"

/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L){
	return (First(L) == Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L){
	First(*L) = Nil;
}

/**** Manajemen Memory ****/
address Alokasi (infotype X){
	address P;
	
	P = (address) malloc (sizeof (ElmtList));
	if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
	}
	return (P);
}

void DeAlokasi (address P){
	if (P != Nil){
	    free (P);
	}
}

/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X){
	
	address P;
	boolean found =  false;
	
	P = First(L);
	while ((P != Nil) && (!found)){
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
	while ((PSearch != Nil) && (!found)){
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
	
	Prec = Nil;
	P = First(L);
	while ((P != Nil) && (!found)){
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
        return (Nil);		
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
	
	if (First(*L) != Nil){
		P = First(*L);
		First(*L) = Next(P);
		*X = Info(P);
		Next(P) = Nil;
		DeAlokasi (P);
	}
}

void DelVLast (List * L, infotype * X){

	address PDel, prec;
	
	if (First(*L) != Nil)
	{
		PDel = First(*L);
		if (Next(PDel) == Nil){
			*X = Info(PDel);
			First(*L) = Nil;
			DeAlokasi(PDel);
		} else {
			prec = Nil;
			while (Next(PDel) != Nil){
				prec = PDel;
				PDel = Next(PDel);
			}
			Next(prec) = Nil;
			*X = Info(PDel);
		}
		DeAlokasi(PDel);
	}
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P){
	if (P != Nil){
		Next(P) = First(*L);
		First(*L) = P;
	}
}

void InsertAfter (List * L, address P, address Prec){
	
    if (P != NULL && Prec != NULL) {
        Next(P) = Next(Prec); // P menunjuk ke elemen setelah Prec
        Next(Prec) = P; // Prec menunjuk ke P sebagai elemen berikutnya
    }
}

void InsertLast (List * L, address P){
	
	address Last;

	Last = First(*L);
	while (Next(Last) != Nil){
		Last = Next(Last);
	}
	Next(Last) = P;
	Next(P) = Nil;
}

/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P){
	First(*L) = Next(*P);
	Next(*P) = Nil;
}


void DelP (List * L, infotype X){

	address P, Prec;
	boolean found=false;
}

void DelLast (List * L, address * P){
	
	address Prec;
	
	*P = First(*L);
		while (Next(*P) != Nil){
			Prec = (*P);
			(*P) = Next(*P);
		}
	Next(Prec) = Nil;
	(*P) = Prec;
}

void DelAfter (List * L, address * Pdel, address Prec){
    if (Prec != Nil && Next(Prec) != Nil) { 
        *Pdel = Next(Prec); 
        Next(Prec) = Next(*Pdel); 
        Next(*Pdel) = Nil;
    }
}


/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L){

	address P;
	
	P = First(L);
	if (ListEmpty(L)){
		printf(" ");
	} 
	else{
		while ((P) != Nil){
			printf("%d ", Info(P));
			P = Next(P);
		}
		printf("\n");
	}
}


void DelAll (List * L){

	address PDel;
	
	PDel = First(*L);
	DeAlokasi(PDel);
}



