// clue.h
// Header untuk faseClue dan faseReClue

#ifndef CLUE_H
#define CLUE_H

#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"

Queue queueClue;
extern Stack stackReClue; // Dari skip voting
extern Stack stackVoting; // Dari vote aktif

void faseClue(List L);  // jika pakai pointer

void tampilkanClue(List* list, const char* nama, const char* clue);

#endif