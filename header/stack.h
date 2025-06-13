/* File        : stack.h                                                        */
/* Deskripsi   : Deklarasi stack yang diimplementasikan dgn using ADT linked    */
/*		 	     Top adalah alamat elemen puncak                                */
/* Dibuat oleh : Ade Chandra Nugraha                                            */

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../header/vote.h"

typedef address Stack;

/* Perubahan nilai komponen struktur */
void SetTop(Stack *S, Stack NewTop);

/*    PROTO TYPE    */

/* Konstruktor/Kreator */
void CreateEmpty (Stack *S);

/* Predikat untuk test keadaan KOLEKSI */
bool IsEmpty (Stack S);

/* Menambahkan sebuah elemen ke Stack */
void Push (Stack *S, Vote v);

/* Menghapus sebuah elemen Stack */
void Pop (Stack *S, Vote *v);

#endif
