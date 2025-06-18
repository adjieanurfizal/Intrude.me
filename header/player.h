#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <string.h>
#include "linkedlist.h"
#include "queue.h"

#define MAX_NAME 30
#define MAX_WORD 30

// Enum untuk peran pemain
typedef enum {
    DEVELOPER,
    MALWARE,
    BOT
} Role;

// Struktur data pemain
typedef struct Player {
    char name[MAX_NAME];
    Role role;
    char word[MAX_WORD];
    char clue[MAX_WORD];
    bool eliminated;
} Player;

extern Queue queueClue;
extern int displayIndex;

// Fungsi-fungsi dasar
Player* CreatePlayer(const char* name, Role role);
Player* FindPlayerByName(List* list, const char* name);
int CountActivePlayers(List* list);
Player* GetActivePlayerByIndex(List* list, int index);
void InitRoleDisplay();
void RoleDisplay();
void DrawRoleDisplay();
void PrintPlayer(infotype data);
void InitPlayerList(List* list);
void AddPlayer(List* list, Player* newPlayer);
void PrintPlayers(const List* list);
void DistributeWords(List* list, const char* developerWord, const char* malwareWord);
void AddPlayersToQueue(List* list, Queue* q);
void assignRole(List* list);
void fasePemain(List* list, char pemain[], char lanjut[]);
void SimpanClue(List* list, const char* nama, const char* clue);

#endif
