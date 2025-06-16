// player.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "queue.h"

Player* CreatePlayer(const char* name, Role role) {
    Player* newP = (Player*)malloc(sizeof(Player));
    if (newP) {
        strncpy(newP->name, name, MAX_NAME);
        newP->role = role;
        newP->word[0] = '\0';
        newP->eliminated = false;
        newP->clue[0] = '\0';
    }
    return newP;
}

void PrintPlayer(infotype data) {
    Player* p = (Player*)data;
    printf("Nama: %s | Role: %d | Kata: %s | Clue: %s | Eliminasi: %s\n",
           p->name, p->role, p->word, p->clue, p->eliminated ? "Ya" : "Tidak");
}

void InitPlayerList(List* list) {
    CreateList(list);
}

void AddPlayer(List* list, Player* newPlayer) {
    address P = Alokasi((infotype)newPlayer);
    InsertLast(list, P);
}

void PrintPlayers(const List* list) {
    PrintList(*list, PrintPlayer);
}

void DistributeWords(List* list, const char* developerWord, const char* malwareWord) {
    address P = list->head;
    while (P != NULL) {
        Player* player = (Player*)Info(P);
        if (player->role == DEVELOPER) {
            strncpy(player->word, developerWord, MAX_WORD);
        } else if (player->role == MALWARE) {
            strncpy(player->word, malwareWord, MAX_WORD);
        } else {
            player->word[0] = '\0';
        }
        P = Next(P);
    }
}

void AddPlayersToQueue(List* list, Queue* q) {
    address P = list->head;
    while (P != NULL) {
        Enqueue(q, Info(P));
        P = Next(P);
    }
}

void SimpanClue(List* list, const char* nama, const char* clue) {
    address P = list->head;
    while (P != NULL) {
        Player* pl = (Player*)Info(P);
        if (strcmp(pl->name, nama) == 0) {
            strncpy(pl->clue, clue, MAX_WORD);
            break;
        }
        P = Next(P);
    }
}

void assignRole(List* list) {
    int index = 0;
    Player* current = list->head;
    while (current) {
        if (index == 0) current->role = MALWARE;
        else if (index == 1) current->role = BOT;
        else current->role = DEVELOPER;
        index++;
        current = Next(current);
    }
}

void fasePemain(List* list, char pemain[], char lanjut[]); {
    InitPlayerList(list);
    printf("\n👥 Masukkan jumlah pemain: ");
    scanf("%d", jumlahPemain);
    getchar();

    for (int i = 0; i < *jumlahPemain; i++) {
        char nama[MAX_NAME];
        printf("Nama pemain ke-%d: ", i + 1);
        fgets(nama, MAX_NAME, stdin);
        nama[strcspn(nama, "\n")] = 0; // hapus newline

        Player* p = CreatePlayer(nama, DEVELOPER); // default sementara
        AddPlayer(list, p);
    }

    assignRole(list);

    printf("\n✅ Pemain berhasil dibuat:\n");
    PrintPlayers(list);
}