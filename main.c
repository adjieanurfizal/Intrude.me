#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "vote.h"
#include "clue.h"

void tampilkanMenuUtama();
void tampilkanPetunjuk();
void tampilkanLeaderboard();
void tampilkanPengaturan();
void jalankanPermainan();

int main() {
    int pilihan;
    do {
        tampilkanMenuUtama();
        printf("\nPilih menu (1-5): ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                jalankanPermainan();
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

void jalankanPermainan() {
    List pemain = InisialisasiPemain();
    char lanjut[10];

    do {
        fasePemain(PlayerList* list, int* jumlahPemain)

        printf("\n🎙 FASE CLUE DIMULAI\n");
        faseClue(pemain);

        printf("\n🗳 FASE VOTING DIMULAI\n");
        faseVoting(pemain);

        printf("\nIngin lanjut ke ronde berikutnya? (ya/tidak): ");
        scanf("%s", lanjut);
        getchar();

    } while (strcmp(lanjut, "ya") == 0);

    // DEALOKASI LIST
    address p = First(pemain);
    while (p != NULL) {
        address temp = p;
        p = Next(p);
        free(temp);
    }

    printf("\n🏁 Permainan selesai. Skor akhir dan leaderboard akan ditampilkan.\n");
}