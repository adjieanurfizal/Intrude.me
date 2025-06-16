/* File        : stack.h                                                        */
/* Deskripsi   : Deklarasi stack yang diimplementasikan dgn using ADT linked    */
/*		 	     Top adalah alamat elemen puncak                                */
/* Dibuat oleh : Ade Chandra Nugraha                                            */

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "vote.h"

typedef int infotype;

typedef struct tElmtStack *addressStack;
typedef struct tElmtStack {
    infotype info;
    address next;
} tElmtStack;
typedef address Stack;

/* Perubahan nilai komponen struktur */
void SetTop(Stack *S, Stack NewTop);

/*    PROTO TYPE    */

/* Konstruktor/Kreator */
void CreateEmpty (Stack *S);

/* Predikat untuk test keadaan KOLEKSI */
bool IsStackEmpty (Stack S);

/* Menambahkan sebuah elemen ke Stack */
void Push (Stack *S, infotype v);

/* Menghapus sebuah elemen Stack */
void Pop (Stack *S, infotype *v);

#endif
