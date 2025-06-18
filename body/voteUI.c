#include "../header/vote.h"
#include "../header/ui.h"

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 40
#define BUTTON_MARGIN 10

static int voteIndex = 0;
static bool voteSubmitted = false;
static bool skipVoted = false;

void InitVotePhase(List* list, int ronde) {
    voteIndex = 0;
    GetSkipCount();
    CreateStack(&stackVoting);
    CreateStack(&stackReClue);
    voteSubmitted = false;
    skipVoted = false;
}

void UpdateVotePhase(List* list, int ronde) {

    if (voteSubmitted || voteIndex >= CountActivePlayers(list)) return;
    Player* voter = GetActivePlayerByIndex(list, voteIndex);
    if (!voter) return;
    int buttonY = 120;
    int playerCount = CountActivePlayers(list);

    for (int i = 0; i < playerCount; i++) {
        Player* target = GetActivePlayerByIndex(list, i);
        if (!target || strcmp(voter->name, target->name) == 0) continue;

        Rectangle rect = { 50, (float)buttonY, BUTTON_WIDTH, BUTTON_HEIGHT };
        if (CheckCollisionPointRec(GetMousePosition(), rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vote* v = CreateVote(voter->name, target->name);
            Push(&stackVoting, v);
            catatVote(v->voter, v->target, ronde);
            voteSubmitted = true;
            return;
        }
        buttonY += BUTTON_HEIGHT + BUTTON_MARGIN;
    }

    Rectangle skipRect = { 300, 100, BUTTON_WIDTH, BUTTON_HEIGHT };
    if (CheckCollisionPointRec(GetMousePosition(), skipRect) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && skipCount < 2) {
        Push(&stackReClue, voter);
        skipCount++;
        voteSubmitted = true;
        skipVoted = true;
    }
}

void DrawVotePhase(List* list) {
    ClearBackground(RAYWHITE);
    Player* voter = GetActivePlayerByIndex(list, voteIndex);
    if (!voter) {
        DrawText("⏳ Menunggu pemain berikutnya...", 50, 50, 20, DARKGRAY);
        return;
    }

    DrawText(TextFormat("🗳️ %s memilih siapa?", voter->name), 50, 50, 20, DARKBLUE);

    int buttonY = 120;
    int playerCount = CountActivePlayers(list);

    for (int i = 0; i < playerCount; i++) {
        Player* target = GetActivePlayerByIndex(list, i);
        if (!target || strcmp(voter->name, target->name) == 0) continue;

        Rectangle rect = { 50, (float)buttonY, BUTTON_WIDTH, BUTTON_HEIGHT };
        DrawRectangleRec(rect, LIGHTGRAY);
        DrawText(target->name, 60, buttonY + 10, 20, BLACK);

        if (CheckCollisionPointRec(GetMousePosition(), rect)) {
            DrawRectangleLinesEx(rect, 2, BLUE);
        }

        buttonY += BUTTON_HEIGHT + BUTTON_MARGIN;
    }

    Rectangle skipRect = { 300, 100, BUTTON_WIDTH, BUTTON_HEIGHT };
    DrawRectangleRec(skipRect, ORANGE);
    DrawText("Skip Voting", 310, 110, 20, WHITE);
    if (CheckCollisionPointRec(GetMousePosition(), skipRect)) {
        DrawRectangleLinesEx(skipRect, 2, RED);
    }

    if (voteSubmitted) {
        DrawText("✅ Vote diterima, tekan [SPACE] untuk lanjut", 50, 400, 20, DARKGREEN);
    }
}

void AdvanceVoteIfDone(List* list) {
    if (voteSubmitted) {
        voteSubmitted = false;
        voteIndex++;
    }
}

bool IsVotePhaseDone(List* list) {
    return voteIndex >= CountActivePlayers(list);
}

int GetSkipCount() {
    return skipCount;
}