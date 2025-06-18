#include "../header/log.h"
#include <string.h>
#include <stdio.h>

LogClue logClues[MAX_LOG];
int jumlahClue = 0;

LogVote logVotes[MAX_LOG];
int jumlahVote = 0;

PlayerScore leaderboard[MAX_LOG];
int jumlahSkor = 0;

void catatClue(const char* nama, const char* clue, int ronde) {
    if (jumlahClue < MAX_LOG) {
        strcpy(logClues[jumlahClue].nama, nama);
        strcpy(logClues[jumlahClue].clue, clue);
        logClues[jumlahClue].timestamp = time(NULL);
        logClues[jumlahClue].ronde = ronde;
        jumlahClue++;
    }
}

void catatVote(const char* voter, const char* target, int ronde) {
    if (jumlahVote < MAX_LOG) {
        strcpy(logVotes[jumlahVote].voter, voter);
        strcpy(logVotes[jumlahVote].target, target);
        logVotes[jumlahVote].timestamp = time(NULL);
        logVotes[jumlahVote].ronde = ronde;
        jumlahVote++;
    }
}

void tampilkanLogClue() {
    printf("\n📜 LOG CLUE:\n");
    for (int i = 0; i < jumlahClue; i++) {
        printf("[%d] %s: %s\n", logClues[i].ronde, logClues[i].nama, logClues[i].clue);
    }
}

void tampilkanLogVote() {
    printf("\n📜 LOG VOTE:\n");
    for (int i = 0; i < jumlahVote; i++) {
        printf("[%d] %s memilih %s\n", logVotes[i].ronde, logVotes[i].voter, logVotes[i].target);
    }
}

void tambahSkor(const char* nama, int menang, int kalah) {
    for (int i = 0; i < jumlahSkor; i++) {
        if (strcmp(leaderboard[i].nama, nama) == 0) {
            leaderboard[i].menang += menang;
            leaderboard[i].kalah += kalah;
            leaderboard[i].score += (3 * menang - kalah);
            return;
        }
    }
    if (jumlahSkor < MAX_LOG) {
        strcpy(leaderboard[jumlahSkor].nama, nama);
        leaderboard[jumlahSkor].menang = menang;
        leaderboard[jumlahSkor].kalah = kalah;
        leaderboard[jumlahSkor].score = 3 * menang - kalah;
        jumlahSkor++;
    }
}

void tampilkanLeaderboard() {
    printf("\n🏆 LEADERBOARD:\n");
    for (int i = 0; i < jumlahSkor; i++) {
        printf("%s - Skor: %d | Menang: %d | Kalah: %d\n",
               leaderboard[i].nama,
               leaderboard[i].score,
               leaderboard[i].menang,
               leaderboard[i].kalah);
    }
}

void eksporLogKeFile() {
    FILE *fc = fopen("txt/log_clue.txt", "w");
    FILE *fv = fopen("txt/log_vote.txt", "w");
    FILE *fs = fopen("txt/leaderboard.txt", "w");

    if (fc && fv && fs) {
        for (int i = 0; i < jumlahClue; i++) {
            fprintf(fc, "[%d] %s: %s\n", logClues[i].ronde, logClues[i].nama, logClues[i].clue);
        }

        for (int i = 0; i < jumlahVote; i++) {
            fprintf(fv, "[%d] %s memilih %s\n", logVotes[i].ronde, logVotes[i].voter, logVotes[i].target);
        }

        for (int i = 0; i < jumlahSkor; i++) {
            fprintf(fs, "%s - Skor: %d | Menang: %d | Kalah: %d\n",
                    leaderboard[i].nama,
                    leaderboard[i].score,
                    leaderboard[i].menang,
                    leaderboard[i].kalah);
        }

        fclose(fc);
        fclose(fv);
        fclose(fs);
        printf("\n📁 Log permainan telah disimpan di folder txt/.\n");
    } else {
        printf("\n❌ Gagal menyimpan salah satu log ke file.\n");
    }
}

void imporLogDariFile() {
    FILE *fc = fopen("txt/log_clue.txt", "r");
    FILE *fv = fopen("txt/log_vote.txt", "r");
    FILE *fs = fopen("txt/leaderboard.txt", "r");

    char baris[256];
    if (fc) {
        while (fgets(baris, sizeof(baris), fc)) {
            int ronde;
            char nama[50], clue[100];
            if (sscanf(baris, "[%d] %[^:]: %[^]", &ronde, nama, clue) == 3) {
                catatClue(nama, clue, ronde);
            }
        }
        fclose(fc);
    }

    if(fv) {
        while (fgets(baris, sizeof(baris), fv)) {
            int ronde;
            char voter[50], target[50];
            if (sscanf(baris, "[%d] %[^ ] memilih %[^]", &ronde, voter, target) == 3) {
                catatVote(voter, target, ronde);
            }
        }
        fclose(fv);
    }

    if (fs) {
        while (fgets(baris, sizeof(baris), fs)) {
            char nama[50];
            int skor, menang, kalah;
            if (sscanf(baris, "%[^-] - Skor: %d | Menang: %d | Kalah: %d", nama, &skor, &menang, &kalah) == 4) {
                tambahSkor(nama, menang, kalah);
            }
        }
        fclose(fs);
    }
}
