#include "../header/clue.h"

void printFaseClueRound(List L) {
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("🔁  FASE CLUE RONDE DIMULAI\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    CreateQueue(&queueClue);

    // Tambahkan pemain dari stackReClue (skip)
    while (!IsEmpty(stackReClue)) {
        infotype nama;
        Pop(&stackReClue, &nama);
        EnQueue(&queueClue, nama);
    }

    // Tambahkan pemain dari stackVoting (vote aktif)
    while (!IsEmpty(stackVoting)) {
        Vote v;
        Pop(&stackVoting, &v);
        EnQueue(&queueClue, v.voter);
    }

    while (!is_Empty(queueClue)) {
        infotype nama;
        deQueue(&queueClue, &nama);

        char clue[100];
        printf("🧠 %s, berikan clue: ", nama);
        fgets(clue, 100, stdin);
        clue[strcspn(clue, "\n")] = 0;

        catatClue(nama, clue, ronde);
        tampilkanClue(nama, clue);
    }
}

void tampilkanClue(char* nama, char* clue) {
    printf("📌 Clue dari %s: %s\n", nama, clue);
}
