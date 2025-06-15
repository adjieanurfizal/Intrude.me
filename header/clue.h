// clue.h
// Header untuk faseClue dan faseReClue

#ifndef CLUE_H
#define CLUE_H

#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "linkedlist.h"
#include "stack.h"

Queue queueClue;
extern Stack stackReClue; // Dari skip voting
extern Stack stackVoting; // Dari vote aktif

void faseClue(List L);
void tampilkanClue(char* nama, char* clue);

#endif