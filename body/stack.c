/* File        : stack.c                                                */
/* Deskripsi   : Body ADT stack yang diimplementasikan dgn linked list  */
/* Dibuat oleh : Ade Chandra Nugraha                                    */

#include "../header/stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**** Perubahan nilai komponen struktur ****/
void SetTop (Stack *S, Stack NewTop ){
	if (NewTop != NULL) {
        *S = NewTop; // Menggeser top ke alamat yang baru
    }
}

/*    PROTO TYPE    */
/* Konstruktor/Kreator */
void CreateEmpty (Stack *S){
	*S = NULL;
}

/* Predikat untuk test keadaan KOLEKSI */
bool IsEmpty (Stack S){
	return (isEmpty(S));
}

/* Menambahkan sebuah elemen ke Stack */
void Push (Stack *S, infotype X){
	InsVFirst(S, X);  
}

/**** Menghapus sebuah elemen Stack ****/
void Pop (Stack *S, infotype *X){
	DelVFirst(S, X); // nama modul disesuaikan dengan pseudocode linked list pribadi
}