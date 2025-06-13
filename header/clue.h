// clue.h
// Header untuk faseClue dan faseReClue

#ifndef CLUE_H
#define CLUE_H

#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "linkedlist.h"
#include "stack.h" // Untuk Stack ReClue

Queue queueClue;

void faseClue(List L);
void faseReClue(Stack *S);

#endif