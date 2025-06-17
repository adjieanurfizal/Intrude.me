#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char role[15];   // "Civilian", "Undercover", "Spy"
    char word[20];   // Word assigned
} Player;

const char *civilianWords[] = {"meja", "kursi", "pintu", "mobil", "buku"};
const char *undercoverWords[] = {"sofa", "bangku", "jendela", "truk", "novel"};
const int wordPairs = 5;

Player players[MAX_PLAYERS];
int playerCount = 0;
int state = 0;  // 0 = input jumlah, 1 = input nama, 2 = tampil peran

int currentInput = 0;
char inputText[30] = "";

void AssignRolesAndWords() {
    int i, j;
    int undercoverIndex = rand() % playerCount;
    int spyIndex = -1;

    // Jangan pilih spy sama dengan undercover
    do {
        spyIndex = rand() % playerCount;
    } while (spyIndex == undercoverIndex);

    // Pilih pasangan kata
    int wordIndex = rand() % wordPairs;

    for (i = 0; i < playerCount; i++) {
        if (i == undercoverIndex) {
            strcpy(players[i].role, "Undercover");
            strcpy(players[i].word, undercoverWords[wordIndex]);
        } else if (i == spyIndex) {
            strcpy(players[i].role, "Spy");
            strcpy(players[i].word, "-");
        } else {
            strcpy(players[i].role, "Civilian");
            strcpy(players[i].word, civilianWords[wordIndex]);
        }
    }
}

int main() {
    InitWindow(800, 600, "Undercover Game - Raylib");
    SetTargetFPS(60);
    srand(time(NULL));

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (state == 0) {
            DrawText("Masukkan jumlah pemain (4-10):", 50, 50, 20, DARKGRAY);
            DrawText(inputText, 50, 90, 20, BLACK);

            if (IsKeyPressed(KEY_ENTER)) {
                int n = atoi(inputText);
                if (n >= 4 && n <= MAX_PLAYERS) {
                    playerCount = n;
                    currentInput = 0;
                    inputText[0] = '\0';
                    state = 1;
                }
            }

        } else if (state == 1) {
            char prompt[50];
            sprintf(prompt, "Masukkan nama pemain %d:", currentInput + 1);
            DrawText(prompt, 50, 50, 20, DARKGRAY);
            DrawText(inputText, 50, 90, 20, BLACK);

            if (IsKeyPressed(KEY_ENTER)) {
                strncpy(players[currentInput].name, inputText, MAX_NAME_LENGTH);
                currentInput++;
                inputText[0] = '\0';

                if (currentInput >= playerCount) {
                    AssignRolesAndWords();
                    state = 2;
                    currentInput = 0;
                }
            }
        } else if (state == 2) {
            char title[50];
            sprintf(title, "Pemain %d: %s", currentInput + 1, players[currentInput].name);
            DrawText(title, 50, 50, 30, DARKBLUE);

            DrawText("Klik [SPACE] untuk melihat peran", 50, 100, 20, DARKGRAY);

            if (IsKeyPressed(KEY_SPACE)) {
                ClearBackground(BLACK);
                DrawText(players[currentInput].role, 50, 200, 30, RED);
                DrawText(players[currentInput].word, 50, 250, 30, GREEN);
                DrawText("Tekan [ENTER] jika sudah dibaca", 50, 350, 20, GRAY);
                EndDrawing();

                // Tunggu sampai ENTER ditekan
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
            DrawText("Semua pemain sudah melihat peran.", 50, 100, 20, DARKGREEN);
            DrawText("Silakan lanjutkan permainan secara lisan.", 50, 150, 20, DARKGREEN);
            DrawText("Tekan ESC untuk keluar.", 50, 200, 20, DARKGRAY);
        }

        // Input teks
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

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
