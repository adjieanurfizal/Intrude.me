#ifndef VOTE_H
#define VOTE_H

#include <raylib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "linkedlist.h"
#include "player.h"
#include "log.h"

typedef struct {
    char voter[50];
    char target[50];
} Vote;

Vote* CreateVote(const char* voter, const char* target);
void PrintVote(infotype data);
void ProsesEliminasi(Stack S, List L);
void faseVoting(List L, int ronde);

int GetSkipCount();
void InitVotePhase(List* list, int ronde);
void UpdateVotePhase(List* list, int ronde);
void DrawVotePhase(List* list);
void AdvanceVoteIfDone(List* list);
bool IsVotePhaseDone(List* list);


#endif
