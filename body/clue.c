#include "../header/clue.h"

void faseClue(List L) {
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("🔁  FASE CLUE RONDE DIMULAI\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    Queue queueClue;
    CreateQueue(&queueClue);

    // Ambil dari stackReClue
    while (!IsStackEmpty(stackReClue)) {
        infotype temp;
        Pop(&stackReClue, &temp);
        char* name = (char*)temp;
        Enqueue(&queueClue, name);
    }

    // Ambil dari stackVoting
    while (!IsStackEmpty(stackVoting)) {
        infotype temp;
        Pop(&stackVoting, &temp);
        Vote* v = (Vote*)temp;
        char* voter = strdup(v->voter); // duplikat karena v akan di-free
        Enqueue(&queueClue, voter);
        free(v);
    }

    while (!IsEmpty(queueClue)) {
        infotype temp;
        Dequeue(&queueClue, &temp);
        char* nama = (char*)temp;

        char clue[100];
        printf("🧠 %s, berikan clue: ", nama);
        fgets(clue, 100, stdin);
        clue[strcspn(clue, "\n")] = 0;

        catatClue(nama, clue, ronde);
        tampilkanClue(nama, clue);
    }
}

void tampilkanClue(List* list, const char* nama, const char* clue) {
    SimpanClue(list, nama, clue);
    printf("📌 Clue dari %s: %s\n", nama, clue);
}

