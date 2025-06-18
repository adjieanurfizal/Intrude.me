#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"
#include "kata.h"
#include "player.h"


#define MAX_LOG 100

typedef struct {
    char nama[50];
    char clue[100];
    int ronde;
    time_t timestamp;
} LogClue;

typedef struct {
    char voter[50];
    char target[50];
    int ronde;
    time_t timestamp;
} LogVote;

typedef struct {
    char nama[50];
    int score;
    int menang;
    int kalah;
} PlayerScore;

extern LogClue logClues[MAX_LOG];
extern int jumlahClue;
extern LogVote logVotes[MAX_LOG];
extern int jumlahVote;
extern PlayerScore leaderboard[MAX_LOG];
extern int jumlahSkor;

void catatClue(const char* nama, const char* clue, int ronde);
void catatVote(const char* voter, const char* target, int ronde);
void tampilkanLogClue();
void tampilkanLogVote();
void tambahSkor(const char* nama, int menang, int kalah);
void tampilkanLeaderboard();
void eksporLogKeFile();
void imporLogDariFile();

#endif
