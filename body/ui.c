#include "../header/ui.h"


int screen = 0; // 0=menu, 1=input jumlah pemain, 2=input nama, 3=role view, 4=clue, 5=voting, 6=result
int playerCount = 0; // Jumlah pemain yang akan bermain
int skipCount = 0; // Jumlah skip yang sudah dilakukan
static bool clueStarted = false;
Player players[MAX_PLAYERS];

void InitGame() {
    InitPlayerList(&listVote);
    CreateQueue(&queueClue);
    currentInput = 0;
    GetSkipCount();
    inputText[0] = '\0';
    ronde = 1;
}

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
    
    switch (screen) {
        case 0:  
            UpdateMenu();
            DrawMenu();
            break;
        case 1:
            if (IsKeyPressed(KEY_ENTER)) {
                int total = atoi(inputText);
                if (total >= 4 && total <= MAX_PLAYERS) {
                    playerCount = total;
                    developerCount = playerCount - (malwareCount + botCount);
                    if (developerCount > 0) {
                        inputText[0] = '\0';
                        currentInput = 0;
                        screen = 2;
                    }
                }
            }
            break;

        case 2:
            if (IsKeyPressed(KEY_ENTER)) {
                strncpy(players[currentInput].name, inputText, MAX_NAME_LENGTH);
                inputText[0] = '\0';
                currentInput++;
                if (currentInput >= playerCount) {
                    for (int i = 0; i < playerCount; i++) {
                        Role r = (i < malwareCount) ? MALWARE : (i < malwareCount + botCount) ? BOT : DEVELOPER;
                        players[i].role = r;
                    }
                    PairKata pair = randomPair();
                    for (int i = 0; i < playerCount; i++) {
                        if (players[i].role == DEVELOPER) strncpy(players[i].word, pair.kata1, MAX_WORD);
                        else if (players[i].role == MALWARE) strncpy(players[i].word, pair.kata2, MAX_WORD);
                    }
                    currentInput = 0;
                    screen = 3;
                }
            }
            break;

        case 3:
            RoleDisplay();
            if (displayIndex >= playerCount) {
                screen = 4;
                clueStarted = false;
                for (int i = 0; i < playerCount; i++) {
                    if (!players[i].eliminated) {
                        Enqueue(&queueClue, &players[i]);
                    }
                }
            }
            break;

        case 4:
            if (!clueStarted) {
                InitCluePhase(&queueClue, &listVote, ronde);
                clueStarted = true;
            }
            UpdateCluePhase(&queueClue, &listVote, ronde);
            if (IsCluePhaseDone()) {              
                InitVotePhase(&listVote, ronde);
                screen = 5;
            }
            break;

        case 5:
            UpdateVotePhase(&listVote, ronde);
            if (IsVotePhaseDone(&listVote)) {
                InitResultPhase(&listVote);
                screen = 6;
            }
            break;

        case 6:
            UpdateResultPhase(&listVote);
            if (IsGameOver()) {
                if (IsKeyPressed(KEY_R)) {
                    InitGame();
                    screen = 1;
                } else if (IsKeyPressed(KEY_Q)) {
                    screen = 0;
                }
            } else {
                if (IsKeyPressed(KEY_SPACE)) {
                    ronde++;
                    screen = 3;
                }
            }
            break;
        case 7:
            UpdateGuideScreen();      
            break;
        case 8:
            UpdateLeaderboardScreen();
            UpdateLogScreen();            
            if (IsKeyPressed(KEY_BACKSPACE)) {
                screen = 0; // Kembali ke menu utama
            }
            break;
    }  
}


void DrawGame() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    switch (screen) {
        case 0:
           break;
        case 1:
            DrawText("Masukkan jumlah pemain (4-10):", 50, 50, 20, DARKGRAY);
            DrawText(inputText, 50, 90, 20, BLACK);
            break;
        case 2:
            {
                char prompt[50];
                sprintf(prompt, "Nama pemain %d:", currentInput + 1);
                DrawText(prompt, 50, 50, 20, DARKGRAY);
                DrawText(inputText, 50, 90, 20, BLACK);
            }
            break;
        case 3:
            DrawRoleDisplay();
            break;
        case 4:
            DrawCluePhase(&queueClue);
            break;
        case 5:
            DrawVotePhase(&listVote);
            break;
        case 6:
            DrawResultPhase();
            break;
        case 7:
            DrawGuideScreen();
            break;
        case 8:
            DrawLeaderboardScreen();
            DrawLogScreen();
            break;
        case 9:
            DrawExitConfirm();  
            break;
    default:
        DrawText("Unknown screen", 50, 50, 20, RED);
    }

    EndDrawing();
}
