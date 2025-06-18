#include "../header/clue.h"
#include "../header/ui.h"

static Player* currentCluer = NULL;
static char clueInput[100] = "";
static bool clueInProgress = false;

void InitCluePhase(Queue* queue, List* list, int ronde) {
    clueInput[0] = '\0';
    clueInProgress = false;
    currentCluer = NULL;
    if (!IsEmpty(*queue)) {
        infotype temp; 
        Dequeue(queue, &temp);     
        currentCluer = (Player*) temp;
        clueInProgress = true;
        printf("[Clue] Giliran %s\n", currentCluer->name);
    } else {
        printf("[Clue] InitCluePhase: queue kosong! Tidak ada pemain.\n");
    }
}

void UpdateCluePhase(Queue* queue, List* list, int ronde) {
    if (!clueInProgress) {
        if (!IsEmpty(*queue)) {
            infotype temp;
            Dequeue(queue, &temp);
            clueInput[0] = '\0';
            currentCluer = (Player*)temp;
            clueInProgress = true;
            printf("[Clue] Giliran %s\n", currentCluer->name);
            
        } else {
            currentCluer = NULL;
            clueInProgress = false;
        return;
        }
    }

    if (!currentCluer) return;

    int key = GetCharPressed();
    while (key > 0) {
        if ((key >= 32 && key <= 125) && strlen(clueInput) < sizeof(clueInput) - 1) {
            int len = strlen(clueInput);
            clueInput[len] = (char)key;
            clueInput[len + 1] = '\0';
        }
        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE)) {
        int len = strlen(clueInput);
        if (len > 0) clueInput[len - 1] = '\0';
    }

    if (IsKeyPressed(KEY_ENTER) && strlen(clueInput) > 0) {
        printf("[Clue] %s -> %s\n", currentCluer->name, clueInput);
        catatClue(currentCluer->name, clueInput, ronde);
        SimpanClue(list, currentCluer->name, clueInput);

        clueInput[0] = '\0';
        clueInProgress = false;
        currentCluer = NULL;
    }
}

void DrawCluePhase(Queue* queue) {
    ClearBackground(RAYWHITE);

    if (clueInProgress && currentCluer) {
        DrawText(TextFormat("🧠 %s, berikan clue:", currentCluer->name), 50, 50, 20, DARKBLUE);
        DrawText(clueInput, 50, 90, 20, BLACK);
        DrawText("Tekan ENTER setelah selesai", 50, 130, 20, GRAY);
    } else if (IsEmpty(*queue) && !clueInProgress) {
        DrawText("✅ Semua clue telah diberikan!", 50, 50, 20, DARKGREEN);
        DrawText("Tekan SPACE untuk lanjut ke voting...", 50, 90, 20, DARKGRAY);
    } else {
        DrawText("⏳ Menunggu giliran clue berikutnya...", 50, 50, 20, GRAY);
    }

    int y = 150;
    for (int i = 0; i < jumlahClue; i++) {
        DrawText(TextFormat("📌 [%s] %s", logClues[i].nama, logClues[i].clue), 50, y, 20, BLACK);
        y += 30;
    }
}

bool IsCluePhaseDone() {
    return IsEmpty(queueClue) && !clueInProgress;
}
