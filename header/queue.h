/* File        : queue.h */
/* Deskripsi   : Deklarasi Queue menggunakan ADT Linked List */
/* Dibuat oleh : Ade Chandra Nugraha */

#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"
#include "BOOLEAN.H"

/* Definisi Queue sebagai Linked List dengan Head dan Tail */
typedef struct {
    address Head;
    address Tail;
} Queue;

/**** Konstruktor/Kreator ****/
void CreateQueue(Queue *Q);
/* IS : Q sembarang */
/* FS : Membuat Queue kosong dengan Head dan Tail bernilai NULL */

/**** Predikat untuk test keadaan Queue ****/
boolean IsEmpty(Queue Q);
/* Mengirim true jika Queue kosong */

/**** Menambahkan elemen ke Queue (Enqueue) ****/
void Enqueue(Queue *Q, infotype X);
/* Menambahkan X sebagai elemen Queue di posisi Tail */
/* IS : Q mungkin kosong */
/* FS : X menjadi elemen di Tail */

/**** Menghapus elemen dari Queue (Dequeue) ****/
void Dequeue(Queue *Q, infotype *X);
/* Menghapus elemen dari Head Queue */
/* IS : Queue tidak mungkin kosong */
/* FS : X adalah nilai elemen Head yang lama, Head bergeser */

/**** Mencetak elemen dalam Queue ****/
void PrintQueue(Queue Q);
/* Menampilkan seluruh elemen dalam Queue */

#endif
