#include "header/ui.h"

int main(void) {
    InitWindow(1024, 768, "Intrude.Me");
    SetTargetFPS(60);

    InitGame(); // custom init function (load avatars, fonts, etc if needed)

    while (!WindowShouldClose()) {
        UpdateGame();
        DrawGame();
    }

    CloseWindow();
    return 0;
}
