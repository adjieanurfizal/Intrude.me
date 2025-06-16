#ifndef VOTE_H
#define VOTE_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "linkedlist.h"
#include "player.h"

// --- Struktur Vote ---
typedef struct {
    char voter[50];
    char target[50];
} Vote;

// --- Stack global (untuk permainan) ---
extern Stack stackVoting;
extern Stack stackReClue;

// --- Prototipe fungsi voting ---
Vote* CreateVote(const char* voter, const char* target);
void PrintVote(infotype data);
void ProsesEliminasi(Stack S, List L);
void faseVoting(List L);

#endif