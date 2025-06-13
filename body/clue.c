#include "../header/clue.h"

void faseClue(List L) {
    CreateQueue(&queueClue);

    address p = First(L);
    while (p != NULL) {
        if (Info(p).aktif == 1) {
            EnQueue(&queueClue, Info(p).nama);
        }
        p = Next(p);
    }

    printf("\n🎙️  FASE CLUE DIMULAI\n");
    while (!is_Empty(queueClue)) {
        infotype nama;
        deQueue(&queueClue, &nama);

        char clue[100];
        printf("🧠 %s, berikan clue: ", nama);
        fgets(clue, 100, stdin);
        clue[strcspn(clue, "\n")] = 0;

        // Simpan ke log / array list clue jika diperlukan
        printf("📌 Clue dari %s: %s\n", nama, clue);
    }
}

// Untuk faseReClue dari stackReClue:
void faseReClue(Stack *S) {
    printf("\n🔁 FASE RE-CLUE DIMULAI\n");
    CreateQueue(&queueClue);

    while (!IsEmpty(*S)) {
        infotype nama;
        Pop(S, &nama);
        EnQueue(&queueClue, nama);
    }

    while (!is_Empty(queueClue)) {
        infotype nama;
        deQueue(&queueClue, &nama);

        char clue[100];
        printf("🧠 (ReClue) %s, berikan clue ulang: ", nama);
        fgets(clue, 100, stdin);
        clue[strcspn(clue, "\n")] = 0;

        // Simpan ke log / array list clue jika diperlukan
        printf("🔁 Clue ulang dari %s: %s\n", nama, clue);
    }
}
