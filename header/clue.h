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
extern StackString stackReClue; // Dari skip voting
extern StackVote stackVoting; // Dari vote aktif

void faseClue(PlayerList* L);  // jika pakai pointer

void tampilkanClue(char* nama, char* clue);

#endif