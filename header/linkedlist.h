/* File        : linkedlist.h                                       */
/* Deskripsi   : ADT list berkait dengan representasi fisik pointer */
/*		         Representasi address dengan pointer                */
/*		         InfoType adalah integer                            */
/* Dibuat oleh : Ade Chandra Nugraha                                */
/* Tanggal     : 24-10-2001                                         */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "../BOOLEAN.H"
#include <stdio.h>
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype info;
	address  next;
} ElmtList;


typedef struct {
	address First;
} List;

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L);

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L);

/**** Manajemen Memory ****/
address Alokasi (infotype X);

void DeAlokasi (address P);

/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X);

boolean FSearch (List L, address P);

address SearchPrec (List L, infotype X);

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (List * L, infotype X);

void InsVLast (List * L, infotype X);

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, infotype * X);

void DelVLast (List * L, infotype * X);

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P);

void InsertAfter (List * L, address P, address Prec);

void InsertLast (List * L, address P);

/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P);

void DelP (List * L, infotype X);

void DelLast (List * L, address * P);

void DelAfter (List * L, address * Pdel, address Prec);

/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L);

void DelAll (List * L);

#endif
