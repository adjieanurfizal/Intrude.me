// log.h
#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kata.h"
#include "player.h"

#define MAX_LOG 100

// Struktur Log Clue
typedef struct {
    char nama[50];
    char clue[100];
    int ronde;
} LogClue;

// Struktur Log Vote
typedef struct {
    char voter[50];
    char target[50];
    int ronde;
} LogVote;

// Struktur Skor Akhir
typedef struct {
    char nama[50];
    int score;
    int menang;
    int kalah;
} PlayerScore;

// Global log
extern LogClue logClues[MAX_LOG];
extern int jumlahClue;

extern LogVote logVotes[MAX_LOG];
extern int jumlahVote;

extern PlayerScore leaderboard[MAX_LOG];
extern int jumlahSkor;

// Fungsi Log
void catatClue(const char* nama, const char* clue, int ronde);
void catatVote(const char* voter, const char* target, int ronde);
void tampilkanLogClue();
void tampilkanLogVote();

// Leaderboard
void tambahSkor(const char* nama, int menang, int kalah);
void tampilkanLeaderboard();

#endif
