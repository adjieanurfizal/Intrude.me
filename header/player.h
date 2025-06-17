#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
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

// Fungsi-fungsi dasar
Player* CreatePlayer(const char* name, Role role);
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
