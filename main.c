#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "../header/queue.h"

int main() {
    int jumlahPemain, i, pilihan;
    char nama[MAX_NAME];
    PlayerList playerList;
    InitPlayerList(&playerList);

    printf("Masukkan jumlah pemain: ");
    scanf("%d", &jumlahPemain);
    getchar(); // buang newline

    for (i = 0; i < jumlahPemain; i++) {
        printf("\n--- Pemain #%d ---\n", i + 1);

        printf("Nama: ");
        fgets(nama, MAX_NAME, stdin);
        nama[strcspn(nama, "\n")] = 0; // Hapus newline dari fgets

        printf("Pilih peran:\n");
        printf("0. DEVELOPER\n1. MALWARE\n2. CIVILIAN\n3. BOT\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // buang newline

        AddPlayer(&playerList, CreatePlayer(nama, (Role)pilihan));
    }

    // Input kata rahasia
    char devWord[MAX_WORD], malWord[MAX_WORD];
    printf("\nMasukkan kata untuk Developer: ");
    fgets(devWord, MAX_WORD, stdin);
    devWord[strcspn(devWord, "\n")] = 0;

    printf("Masukkan kata untuk Malware: ");
    fgets(malWord, MAX_WORD, stdin);
    malWord[strcspn(malWord, "\n")] = 0;

    DistributeWords(&playerList, devWord, malWord);

    // Tampilkan daftar pemain
    printf("\n=== Daftar Pemain ===\n");
    PrintPlayers(&playerList);

    // Masukkan ke queue
    Queue giliran;
    CreateQueue(&giliran);
    AddPlayersToQueue(&playerList, &giliran);

    printf("\n=== Giliran Bermain ===\n");
    Player* p = playerList.head;
    while (p != NULL) {
        printf("%s\n", p->name);
        p = p->next;
    }

    return 0;
}
