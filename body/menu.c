#include "../header/ui.h"

void menuUtama() {
    InitWindow(800, 600, "intrude.Me");
    SetTargetFPS(60);
    srand(time(NULL));

    while (!WindowShouldClose()) {
        UpdateGame();
        DrawGame();
    }

    CloseWindow();
}

const char* menuOptions[MENU_OPTION_COUNT] = {
    " Mulai Permainan",
    " Panduan",
    " Leaderboard",
    " Keluar"
};

int selectedMenuIndex = 0;

void InitMenu() {
    selectedMenuIndex = 0;
}

void UpdateMenu() {
    if (IsKeyPressed(KEY_DOWN)) {
        selectedMenuIndex = (selectedMenuIndex + 1) % MENU_OPTION_COUNT;
    }
    if (IsKeyPressed(KEY_UP)) {
        selectedMenuIndex = (selectedMenuIndex - 1 + MENU_OPTION_COUNT) % MENU_OPTION_COUNT;
    }
    if (IsKeyPressed(KEY_ENTER)) {
    extern int screen;
    switch (selectedMenuIndex) {
        case 0:
            screen = 1; // mulai permainan
            break;
        case 1:
            screen = 7; // guide
            break;
        case 2:
            screen = 8; // leaderboard dan log
            break;
        case 3:
            screen = 9; 
            ExitConfirm(); // keluar
            break;
        }
    }
}
void DrawMenu() {
    ClearBackground(RAYWHITE);
    DrawText("Selamat datang di Intrude.Me", 50, 50, 30, DARKBLUE);
    for (int i = 0; i < MENU_OPTION_COUNT; i++) {
        Color color = (i == selectedMenuIndex) ? DARKBLUE : GRAY;
        DrawText(menuOptions[i], 50, 100 + i * 40, 20, color);
    }
    DrawText("Gunakan panah ↑ ↓ dan tekan [ENTER]", 100, 350, 20, GRAY);
}

bool confirmExit = false;
int selectedExitIndex = 0; // 0 = Yes, 1 = No

void InitExitConfirm() {
    confirmExit = true;
    selectedExitIndex = 0;
}

void ExitConfirm() {
    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_UP)) {
        selectedExitIndex = (selectedExitIndex - 1 + 2) % 2;
    } else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_DOWN)) {
        selectedExitIndex = (selectedExitIndex + 1) % 2;
    }
    if (IsKeyPressed(KEY_ENTER)) {
        if (selectedExitIndex == 0) {
            playerCount = 0;
            currentInput = 0;
            inputText[0] = '\0';
            CloseWindow();
        } else {
            confirmExit = false; // Batal keluar
        }
    }
    if (IsKeyPressed(KEY_ESCAPE)) {
        confirmExit = false; // Batal keluar dengan ESC
    }
}

void DrawExitConfirm() {
    DrawRectangle(80, 160, 600, 200, Fade(LIGHTGRAY, 0.95f));
    DrawRectangleLines(80, 160, 600, 200, GRAY);
    DrawText("Apakah Anda yakin ingin keluar dari permainan?", 100, 190, 22, DARKGRAY);
    const char* options[2] = {"Ya", "Tidak"};
    for (int i = 0; i < 2; i++) {
        Color color = (i == selectedExitIndex) ? RED : DARKGRAY;
        DrawText(options[i], 250 + i * 150, 250, 30, color);
    }
}