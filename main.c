#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/player.h"
#include "header/vote.h"
#include "header/clue.h"

List pemain;

int main() {
    pemain = InisialisasiPemain();

    char lanjut[10];
    do {
        faseClue(pemain);        // clue awal
        faseVoting(pemain);      // voting
        faseReClue(&stackReClue); // clue ulang dari skip

        printf("\nIngin lanjut ke ronde berikutnya? (ya/tidak): ");
        scanf("%s", lanjut);
        getchar();

    } while (strcmp(lanjut, "ya") == 0);

    // DEALOKASI LINKED LIST
    address p = First(pemain);
    while (p != NULL) {
        address temp = p;
        p = Next(p);
        free(temp);
    }

    printf("\nTerima kasih telah bermain INTRUDE.ME!\n");
    return 0;
}
