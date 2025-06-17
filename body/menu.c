#include "../header/ui.h"

void menuUtama() {
    InitWindow(800, 600, "Undercover Game - Raylib");
    SetTargetFPS(60);
    srand(time(NULL));

    while (!WindowShouldClose()) {
        UpdateGame();
        DrawGame();
    }

    CloseWindow();
}

