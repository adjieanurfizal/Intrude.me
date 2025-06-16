#ifndef VOTE_H
#define VOTE_H

#include <stdbool.h>
#include "linkedlist.h"

// --- Struktur Vote ---
typedef struct {
    char voter[50];
    char target[50];
} Vote;

// --- Stack khusus Vote ---
typedef struct tElmtVoteStack *addressVote;
typedef struct tElmtVoteStack {
    Vote info;
    addressVote next;
} ElmtVoteStack;

typedef addressVote StackVote;

// --- Stack khusus nama string (skip voting) ---
typedef struct tElmtStrStack *addressStr;
typedef struct tElmtStrStack {
    char info[50];
    addressStr next;
} ElmtStrStack;

typedef addressStr StackString;

// --- Stack global (untuk permainan) ---
extern StackVote stackVoting;
extern StackString stackReClue;

// --- Prototipe fungsi voting ---
void CreateVoteStack(StackVote *S);
bool IsVoteStackEmpty(StackVote S);
void PushVote(StackVote *S, Vote v);
void PopVote(StackVote *S, Vote *v);

// --- Prototipe fungsi skip voting ---
void CreateSkipStack(StackString *S);
void PushSkip(StackString *S, char nama[]);
void PopSkip(StackString *S, char nama[]);

// --- Proses voting & eliminasi ---
void ProsesEliminasi(StackVote S, List L);
void faseVoting(PlayerList* L);

#endif