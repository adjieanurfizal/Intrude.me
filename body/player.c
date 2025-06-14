// player.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "queue.h"

void InitPlayerList(PlayerList* list) {
    list->head = NULL;
}

Player* CreatePlayer(const char* name, Role role) {
    Player* newPlayer = (Player*)malloc(sizeof(Player));
    if (newPlayer) {
        strncpy(newPlayer->name, name, MAX_NAME);
        newPlayer->role = role;
        newPlayer->word[0] = '\0';
        newPlayer->eliminated = false;
        newPlayer->next = NULL;
    }
    return newPlayer;
}

void AddPlayer(PlayerList* list, Player* newPlayer) {
    if (!list->head) {
        list->head = newPlayer;
    } else {
        Player* temp = list->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newPlayer;
    }
}

void PrintPlayers(const PlayerList* list) {
    Player* current = list->head;
    while (current) {
        printf("Nama: %s | Role: %d | Kata: %s | Eliminasi: %s\n",
               current->name,
               current->role,
               current->word,
               current->eliminated ? "Ya" : "Tidak");
        current = current->next;
    }
}

void DistributeWords(PlayerList* list, const char* developerWord, const char* malwareWord) {
    Player* current = list->head;
    while (current) {
        if (current->role == DEVELOPER || current->role == CIVILIAN) {
            strncpy(current->word, developerWord, MAX_WORD);
        } else if (current->role == MALWARE) {
            strncpy(current->word, malwareWord, MAX_WORD);
        } else {
            current->word[0] = '\0'; // Bot tidak dapat kata
        }
        current = current->next;
    }
}

void AddPlayersToQueue(PlayerList* list, Queue* q) {
    Player* current = list->head;
    while (current) {
        Enqueue(q, (infotype)current); // Casting pointer ke infotype
        current = current->next;
    }
}
