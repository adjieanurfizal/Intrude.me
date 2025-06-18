#include "../header/result.h"

static char winnerText[100] = "";
static bool gameOver = false;
static bool resultCalculated = false;

void InitResultPhase(List* list) {
    resultCalculated = false;
    gameOver = false;
    winnerText[0] = '\0';
}

void UpdateResultPhase(List* list) {
    if (!resultCalculated) {
        ProsesEliminasi(stackVoting, *list);
        resultCalculated = true;

        int malwareAlive = 0, developerAlive = 0;
        address p = list->head;
        while (p != NULL) {
            Player* pl = (Player*)Info(p);
            if (!pl->eliminated) {
                if (pl->role == MALWARE || pl->role == BOT) malwareAlive++;
                else developerAlive++;
            }
            p = Next(p);
        }

        if (malwareAlive == 0) {
            sprintf(winnerText, "🎉 Developer menang!");
        } else if (developerAlive <= malwareAlive) {
            sprintf(winnerText, "💀 Malware/Bot menang!");
        } else {
            sprintf(winnerText, "⏭ Lanjutkan ke ronde berikutnya");
        }

        // Update skor
        p = list->head;
        while (p != NULL) {
            Player* pl = (Player*)Info(p);
            tambahSkor(pl->name, (strstr(winnerText, pl->role == DEVELOPER ? "Developer" : "Malware") != NULL),
                                  (strstr(winnerText, pl->role == DEVELOPER ? "Malware" : "Developer") != NULL));
            p = Next(p);
        }

        if (strstr(winnerText, "menang")) gameOver = true;
    }
}

void DrawResultPhase() {
    ClearBackground(RAYWHITE);
    DrawText(winnerText, 50, 150, 30, (gameOver ? DARKGREEN : DARKGRAY));

    if (gameOver) {
        DrawText("Tekan [R] untuk ronde baru atau [Q] untuk kembali ke menu", 50, 220, 20, GRAY);
    } else {
        DrawText("Tekan [SPACE] untuk lanjut ke ronde berikutnya", 50, 220, 20, GRAY);
    }
}

bool IsGameOver() {
    return gameOver;
}
