#include "../header/ui.h"

void UpdateGame() {
    int key = GetCharPressed();
    while (key > 0) {
        if ((key >= 32) && (key <= 125) && (strlen(inputText) < sizeof(inputText) - 1)) {
            int len = strlen(inputText);
            inputText[len] = (char)key;
            inputText[len + 1] = '\0';
        }
        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE)) {
        int len = strlen(inputText);
        if (len > 0) inputText[len - 1] = '\0';
    }

    if (state == 0) {
        if (IsKeyPressed(KEY_ENTER)) {
            int n = atoi(inputText);
            if (n >= 4 && n <= MAX_PLAYERS) {
                playerCount = n;
                currentInput = 0;
                inputText[0] = '\0';
                InitPlayerList(&pemain);
                state = 1;
            }
        }
    } else if (state == 1) {
        if (IsKeyPressed(KEY_ENTER)) {
            strncpy(players[currentInput].name, inputText, MAX_NAME_LENGTH);
            players[currentInput].role = (currentInput == 0) ? DEVELOPER : (currentInput == 1) ? MALWARE : BOT;
            AddPlayer(&pemain, &players[currentInput]);
            currentInput++;
            inputText[0] = '\0';

            if (currentInput >= playerCount) {
                char kategori[] = "Makanan"; // default kategori untuk sekarang
                assignKataRahasia(&pemain, kategori);
                state = 2;
                currentInput = 0;
            }
        }
    } else if (state == 2) {
        if (IsKeyPressed(KEY_SPACE)) {
            ClearBackground(BLACK);
            DrawText(players[currentInput].role == DEVELOPER ? "DEVELOPER" : players[currentInput].role == MALWARE ? "MALWARE" : "BOT", 50, 200, 30, RED);
            DrawText(players[currentInput].word, 50, 250, 30, GREEN);
            DrawText("Tekan [ENTER] jika sudah dibaca", 50, 350, 20, GRAY);
            EndDrawing();

            while (!IsKeyPressed(KEY_ENTER)) {
                BeginDrawing();
                EndDrawing();
            }
            currentInput++;
            if (currentInput >= playerCount) {
                state = 3;
            }
        }
    } else if (state == 3) {
        if (IsKeyPressed(KEY_ENTER)) {
            faseClue(pemain, ronde);
            faseVoting(pemain, ronde);
            ronde++;
        }
    }
}

void DrawGame() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (state == 0) {
        DrawText("Masukkan jumlah pemain (4-10):", 50, 50, 20, DARKGRAY);
        DrawText(inputText, 50, 90, 20, BLACK);
    } else if (state == 1) {
        char prompt[50];
        sprintf(prompt, "Masukkan nama pemain %d:", currentInput + 1);
        DrawText(prompt, 50, 50, 20, DARKGRAY);
        DrawText(inputText, 50, 90, 20, BLACK);
    } else if (state == 2) {
        char title[50];
        sprintf(title, "Pemain %d: %s", currentInput + 1, players[currentInput].name);
        DrawText(title, 50, 50, 30, DARKBLUE);
        DrawText("Klik [SPACE] untuk melihat peran", 50, 100, 20, DARKGRAY);
    } else if (state == 3) {
        DrawText("Fase Clue dan Voting Selesai.", 50, 100, 20, DARKGREEN);
        DrawText("Tekan ENTER untuk lanjut ronde.", 50, 150, 20, DARKGREEN);
        DrawText("Tekan ESC untuk keluar.", 50, 200, 20, DARKGRAY);
    }

    EndDrawing();
}
