#ifndef CLUE_H
#define CLUE_H

#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"
#include "vote.h"
#include "log.h"

extern Stack stackReClue;
extern Stack stackVoting;
extern Queue queueClue;

void faseClue(List L, int ronde);
void tampilkanClue(List* list, const char* nama, const char* clue);

#endif
