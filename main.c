#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/player.h"
#include "header/vote.h"
#include "header/clue.h"

void tampilkanMenuUtama();
void tampilkanPetunjuk();
void tampilkanLeaderboard();
void tampilkanPengaturan();
void jalankanPermainan(List* playerList);

int main(){
    int pilihan;
    List playerList;
    InitPlayerList(&playerList);

    do {
        tampilkanMenuUtama();
        printf("\nPilih menu (1-5): ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                jalankanPermainan(&playerList);
                break;
            case 2:
                tampilkanPetunjuk();
                break;
            case 3:
                tampilkanLeaderboard();
                break;
            case 4:
                tampilkanPengaturan();
                break;
            case 5:
                printf("\n👋 Terima kasih telah bermain INTRUDE.ME!\n");
                break;
            default:
                printf("\nPilihan tidak valid.\n");
        }
    } while (pilihan != 5);

    return 0;
}

void tampilkanMenuUtama() {
    printf("\n======================================\n");
    printf("🎮 SELAMAT DATANG DI INTRUDE.ME\n");
    printf("======================================\n");
    printf("1. Mulai Permainan\n");
    printf("2. Petunjuk Permainan\n");
    printf("3. Lihat Leaderboard\n");
    printf("4. Pengaturan\n");
    printf("5. Keluar\n");
}

void tampilkanPetunjuk() {
    printf("\n📘 PETUNJUK PERMAINAN:\n");
    printf("1. Setiap pemain mendapat peran dan kata rahasia.\n");
    printf("2. Pemain memberikan clue satu per satu.\n");
    printf("3. Pemain dapat memilih untuk vote atau skip.\n");
    printf("4. Pemain dengan suara terbanyak akan dieliminasi.\n");
    printf("5. Permainan berlanjut hingga menang/kalah tercapai.\n");
}

void tampilkanLeaderboard() {
    printf("\n🏆 LEADERBOARD (sementara)\n");
    printf("(fitur akan diimplementasikan)\n");
}

void tampilkanPengaturan() {
    printf("\n⚙ PENGATURAN\n");
    printf("(fitur akan diimplementasikan)\n");
}

void jalankanPermainan(List* playerList) {
    char pemain[30];
    char lanjut[10];

    fasePemain(playerList, pemain, lanjut);

    do {
        printf("\n🎙 FASE CLUE DIMULAI\n");
        faseClue(*playerList);

        printf("\n🗳 FASE VOTING DIMULAI\n");
        faseVoting(*playerList);

        printf("\nIngin lanjut ke ronde berikutnya? (ya/tidak): ");
        scanf("%s", lanjut);
        getchar();

    } while (strcmp(lanjut, "ya") == 0);

    // DEALOKASI LIST
    address p = First(*playerList);
    while (p != NULL) {
        address temp = p;
        p = Next(p);
        free(temp);
    }

    printf("\n🏁 Permainan selesai. Skor akhir dan leaderboard akan ditampilkan.\n");
}