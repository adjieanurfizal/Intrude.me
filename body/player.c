#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/player.h"

Player* CreatePlayer(const char* name, Role role) {
    Player* newP = (Player*) malloc(sizeof(Player));
    if (newP) {
        strncpy(newP->name, name, MAX_NAME);
        newP->role = role;
        newP->word[0] = '\0';
        newP->clue[0] = '\0';
        newP->eliminated = false;
    }
    return newP;
}

void PrintPlayer(infotype data) {
    Player* pl = (Player*)data;
    printf("Nama: %s | Role: %d | Kata: %s | Clue: %s | Eliminasi: %s\n",
           pl->name, pl->role, pl->word, pl->clue, pl->eliminated ? "Ya" : "Tidak");
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
        Player* pl = (Player*)Info(P);
        if (pl->role == DEVELOPER) {
            strncpy(pl->word, developerWord, MAX_WORD);
        } else if (pl->role == MALWARE) {
            strncpy(pl->word, malwareWord, MAX_WORD);
        } else {
            pl->word[0] = '\0';
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
    address current = list->head;
    while (current) {
        Player* pl = (Player*) Info(current);
        if (index == 0) pl->role = MALWARE;
        else if (index == 1) pl->role = BOT;
        else pl->role = DEVELOPER;
        index++;
        current = Next(current);
    }
}

void fasePemain(List* list, char pemain[], char lanjut[]) {
    InitPlayerList(list);
    int jumlah;
    printf("\n\U0001F465 Masukkan jumlah pemain: ");
    scanf("%d", &jumlah);
    getchar();

    for (int i = 0; i < jumlah; i++) {
        char nama[MAX_NAME];
        printf("Nama pemain ke-%d: ", i + 1);
        fgets(nama, MAX_NAME, stdin);
        nama[strcspn(nama, "\n")] = 0;

        Player* p = CreatePlayer(nama, DEVELOPER); // default sementara
        AddPlayer(list, p);
    }

    assignRole(list);

    printf("\n\u2705 Pemain berhasil dibuat:\n");
    PrintPlayers(list);
}
