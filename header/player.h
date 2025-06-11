// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

#define MAX_NAME 30
#define MAX_WORD 30

// Enum untuk peran pemain
typedef enum {
    DEVELOPER,
    MALWARE,
    CIVILIAN,
    BOT
} Role;

// Struktur data pemain (linked list)
typedef struct Player {
    char name[MAX_NAME];     // Nama pemain
    Role role;               // Peran
    char word[MAX_WORD];     // Kata rahasia yang diberikan
    bool eliminated;         // Apakah sudah dieliminasi
    struct Player* next;     // Pointer ke pemain berikutnya
} Player;

// List kepala
typedef struct {
    Player* head;
} PlayerList;

// Fungsi-fungsi dasar
void InitPlayerList(PlayerList* list);
Player* CreatePlayer(const char* name, Role role);
void AddPlayer(PlayerList* list, Player* newPlayer);
void PrintPlayers(const PlayerList* list);
void DistributeWords(PlayerList* list, const char* developerWord, const char* malwareWord);

// Integrasi dengan Queue (jika infotype diubah jadi pointer)
void AddPlayersToQueue(PlayerList* list, struct Queue* q);

#endif
