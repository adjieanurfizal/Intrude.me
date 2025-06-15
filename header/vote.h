// vote.h
// Header untuk modul voting & skip voting

#ifndef VOTE_H
#define VOTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "../BOOLEAN.H"
#include "linkedlist.h"
#include "stack.h"
#include "log.h"

// Struktur vote
typedef struct {
    char voter[50];
    char target[50];
} Vote;

// Stack global
extern Stack stackVoting;
extern Stack stackReClue;

// Voting Stack
void CreateVoteStack(Stack *S);
void PushVote(Stack *S, Vote v);
void PopVote(Stack *S, Vote *v);

// Skip Voting Stack
void CreateSkipStack(Stack *S);
void PushSkip(Stack *S, Vote namaPemain);
void PopSkip(Stack *S, Vote *namaKeluar);

// Proses voting eliminasi
void ProsesEliminasi(Stack S, List L);

// Prosedur fase voting
void faseVoting(List L);

#endif
