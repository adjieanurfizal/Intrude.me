// vote.c
// Sistem Voting & Skip Voting untuk INTRUDE.ME dengan integrasi ke Stack

#include "../header/vote.h"
#include "../header/stack.h"
#include "../header/linkedlist.h"

// Stack voting & skip
Stack stackVoting;
Stack stackReClue;

// Inisialisasi stack kosong untuk skip voting
void CreateSkipStack(Stack *S) {
    CreateEmpty(S);
}

// Tambahkan pemain ke stack skip voting
void PushSkip(Stack *S, Vote namaPemain) {
    Push(S, namaPemain);
}

// Ambil pemain terakhir yang skip voting
void PopSkip(Stack *S, Vote *namaKeluar) {
    Pop(S, namaKeluar);
}

// Inisialisasi stack voting
void CreateVoteStack(Stack *S) {
    CreateEmpty(S);
}

// Tambahkan voting ke stack
void PushVote(Stack *S, Vote v) {
    Push(S, v);
}

// Ambil voting terakhir dari stack
void PopVote(Stack *S, Vote *v) {
    Pop(S, v);
}

// Proses eliminasi berdasarkan voting yang tidak skip
void ProsesEliminasi(Stack S, List L) {
    if (IsEmpty(S)) {
        return;
    }

    typedef struct {
        char target[50];
        int count;
    } VoteCount;

    VoteCount hasil[50];
    int nHasil = 0;

    while (!IsEmpty(S)) {
        Vote v;
        Pop(&S, &v);
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
                Info(p).aktif = 0;
                break;
            }
            p = Next(p);
        }
    }
}

// Prosedur utama fase voting
void faseVoting(List L) {
    CreateVoteStack(&stackVoting);
    CreateSkipStack(&stackReClue);

    address p = First(L);
    while (p != NULL) {
        if (Info(p).aktif == 1) {
            char pilihan[10];
            printf("\n🗳️  %s, ingin vote atau skip? (vote/skip): ", Info(p).nama);
            scanf("%s", pilihan);
            getchar();

            if (strcmp(pilihan, "skip") == 0) {
                PushSkip(&stackReClue, Info(p).nama);
                printf("🔕 %s skip voting dan akan memberikan clue ulang.\n", Info(p).nama);
            } else {
                Vote v;
                strcpy(v.voter, Info(p).nama);

                char target[50];
                printf("👁️  %s memilih siapa? Masukkan nama target: ", Info(p).nama);
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
