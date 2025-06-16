#include "../header/vote.h"
#include <string.h>
#include <stdio.h>

StackVote stackVoting;
StackString stackReClue;

// --- Fungsi Stack Voting (Vote Struct) ---
void CreateVoteStack(StackVote *S) {
    *S = NULL;
}

bool IsVoteStackEmpty(StackVote S) {
    return S == NULL;
}

void PushVote(StackVote *S, Vote v) {
    addressVote P = (addressVote)malloc(sizeof(ElmtVoteStack));
    if (P != NULL) {
        P->info = v;
        P->next = *S;
        *S = P;
    }
}

void PopVote(StackVote *S, Vote *v) {
    if (!IsVoteStackEmpty(*S)) {
        addressVote P = *S;
        *v = P->info;
        *S = P->next;
        free(P);
    }
}

// --- Fungsi Stack Skip Voting (String) ---
void CreateSkipStack(StackString *S) {
    *S = NULL;
}

void PushSkip(StackString *S, char nama[]) {
    addressStr P = (addressStr)malloc(sizeof(ElmtStrStack));
    if (P != NULL) {
        strcpy(P->info, nama);
        P->next = *S;
        *S = P;
    }
}

void PopSkip(StackString *S, char nama[]) {
    if (*S != NULL) {
        addressStr P = *S;
        strcpy(nama, P->info);
        *S = P->next;
        free(P);
    }
}

// --- Proses Eliminasi ---
void ProsesEliminasi(StackVote S, List L) {
    if (IsVoteStackEmpty(S)) return;

    typedef struct {
        char target[50];
        int count;
    } VoteCount;

    VoteCount hasil[50];
    int nHasil = 0;

    while (!IsVoteStackEmpty(S)) {
        Vote v;
        PopVote(&S, &v);

        int found = 0;
        for (int i = 0; i < nHasil; i++) {
            if (strcmp(hasil[i].target, v.target) == 0) {
                hasil[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(hasil[nHasil].target, v.target);
            hasil[nHasil].count = 1;
            nHasil++;
        }
    }

    // Temukan vote tertinggi
    int max = -1, idxMax = -1;
    for (int i = 0; i < nHasil; i++) {
        if (hasil[i].count > max) {
            max = hasil[i].count;
            idxMax = i;
        }
    }

    if (idxMax != -1) {
        address p = First(L);
        while (p != NULL) {
            if (strcmp(Info(p).nama, hasil[idxMax].target) == 0) {
                Info(p).aktif = 0;  // dieliminasi
                break;
            }
            p = Next(p);
        }
    }
}

// --- Fase Voting ---
void faseVoting(playerList* L) {
    CreateVoteStack(&stackVoting);
    CreateSkipStack(&stackReClue);

    address p = First(L);
    while (p != NULL) {
        if (Info(p).aktif == 1) {
            char pilihan[10];
            printf("\n🗳  %s, ingin vote atau skip? (vote/skip): ", Info(p).nama);
            scanf("%s", pilihan);
            getchar();

            if (strcmp(pilihan, "skip") == 0) {
                PushSkip(&stackReClue, Info(p).nama);
                printf("🔕 %s skip voting dan akan memberikan clue ulang.\n", Info(p).nama);
            } else {
                Vote v;
                strcpy(v.voter, Info(p).nama);

                char target[50];
                printf("👁  %s memilih siapa? Masukkan nama target: ", Info(p).nama);
                fgets(target, 50, stdin);
                target[strcspn(target, "\n")] = 0;
                strcpy(v.target, target);

                PushVote(&stackVoting, v);
            }
        }
        p = Next(p);
    }

    printf("\n⏳ Proses eliminasi dimulai...\n");
    ProsesEliminasi(stackVoting, L);
}