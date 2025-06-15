#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/ui.h"

#include "header/linkedlist.h"
#include "header/player.h"
#include "header/kata.h"
#include "header/log.h"
#include "header/vote.h"
#include "header/clue.h"

void menuUtama() {
    imporLogDariFile();

    int pilihan;
    do {
        printf("\n======= MENU UTAMA =======\n");
        printf("1. Mulai Permainan\n");
        printf("2. Tampilkan Leaderboard\n");
        printf("3. Lihat Log Clue & Vote\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);
        getchar();

        if (pilihan == 1) {
            PlayerList pemain;
            InitPlayerList(&pemain);
            int jumlah;
            printf("\nMasukkan jumlah pemain: ");
            scanf("%d", &jumlah);
            getchar();

            for (int i = 0; i < jumlah; i++) {
                char nama[50];
                printf("Masukkan nama pemain %d: ", i + 1);
                fgets(nama, 50, stdin);
                nama[strcspn(nama, "\n")] = 0;
                Role r = (i == 0) ? DEVELOPER : (i == 1) ? MALWARE : CIVILIAN;
                AddPlayer(&pemain, CreatePlayer(nama, r));
            }

            Address tree = buildTreeKataRahasia();
            char kategori[50];
            printf("\nPilih kategori (Makanan/Kota/Informatika): ");
            fgets(kategori, 50, stdin);
            kategori[strcspn(kategori, "\n")] = 0;

            assignKataRahasia(&pemain, kategori);
            printKataRahasiaTerpilih();

            int ronde = 1;
            int lanjut = 1;
            while (lanjut) {
                faseClueRonde(pemain, ronde);
                faseVotingRonde(pemain, ronde);

                printf("\nLanjut ke ronde berikutnya? (1 = ya, 0 = tidak): ");
                scanf("%d", &lanjut);
                getchar();
                ronde++;
            }

            Player* p = pemain.head;
            while (p != NULL) {
                tambahSkor(p->name, !p->eliminated, p->eliminated);
                p = p->next;
            }

            Player* temp;
            while (pemain.head != NULL) {
                temp = pemain.head;
                pemain.head = pemain.head->next;
                free(temp);
            }
        } else if (pilihan == 2) {
            tampilkanLeaderboard();
        } else if (pilihan == 3) {
            tampilkanLogClue();
            tampilkanLogVote();
        }
    } while (pilihan != 0);

    eksporLogKeFile();

    for (int i = 0; i < jumlahSkor; i++) {
        memset(&leaderboard[i], 0, sizeof(PlayerScore));
    }
    jumlahSkor = 0;
    jumlahClue = 0;
    jumlahVote = 0;

    printf("\n👋 Terima kasih telah bermain!\n");
}
