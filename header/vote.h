#ifndef VOTE_H
#define VOTE_H

#include "stack.h"
#include "linkedlist.h"
#include "player.h"
#include "log.h"

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char voter[50];
    char target[50];
} Vote;

Vote* CreateVote(const char* voter, const char* target);
void PrintVote(infotype data);
void ProsesEliminasi(Stack S, List L);
void faseVoting(List L, int ronde);

#endif
