#include "../header/vote.h"
#include "../header/stack.h"

Stack stackVoting;
Stack stackReClue;

Vote* CreateVote(const char* voter, const char* target) {
    Vote* v = (Vote*)malloc(sizeof(Vote));
    if (v) {
        strncpy(v->voter, voter, 50);
        strncpy(v->target, target, 50);
    }
    return v;
}

void PrintVote(infotype data) {
    Vote* v = (Vote*)data;
    printf("Voter: %s -> Target: %s\n", v->voter, v->target);
}

void ProsesEliminasi(Stack S, List L) {
    if (IsStackEmpty(S)) return;

    typedef struct {
        char target[50];
        int count;
    } VoteCount;

    VoteCount hasil[50];
    int nHasil = 0;

    while (!IsStackEmpty(S)) {
        infotype temp;
        Pop(&S, &temp);
        Vote* v = (Vote*)temp;

        int found = 0;
        for (int i = 0; i < nHasil; i++) {
            if (strcmp(hasil[i].target, v->target) == 0) {
                hasil[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(hasil[nHasil].target, v->target);
            hasil[nHasil].count = 1;
            nHasil++;
        }

        free(v);
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
            Player* pl = (Player*)Info(p);
            if (strcmp(pl->name, hasil[idxMax].target) == 0) {
                pl->eliminated = true;
                printf("❌ %s telah dieliminasi!\n", pl->name);
                break;
            }
            p = Next(p);
        }
    }
}

void faseVoting(List L) {
    CreateStack(&stackVoting);
    CreateStack(&stackReClue);

    address p = First(L);
    while (p != NULL) {
        Player* pl = (Player*)Info(p);
        if (!pl->eliminated) {
            char pilihan[10];
            printf("\n🗳  %s, ingin vote atau skip? (vote/skip): ", pl->name);
            scanf("%s", pilihan);
            getchar();

            if (strcmp(pilihan, "skip") == 0) {
                Push(&stackReClue, pl);
                printf("🔕 %s skip voting dan akan memberikan clue ulang.\n", pl->name);
            } else {
                char target[50];
                printf("👁  %s memilih siapa? Masukkan nama target: ", pl->name);
                fgets(target, 50, stdin);
                target[strcspn(target, "\n")] = 0;

                Vote* v = CreateVote(pl->name, target);
                Push(&stackVoting, v);
            }
        }
        p = Next(p);
    }

    printf("\n⏳ Proses eliminasi dimulai...\n");
    ProsesEliminasi(stackVoting, L);
}
