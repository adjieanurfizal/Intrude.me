#ifndef UI_H
#define UI_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "raylib.h"
#include "player.h"
#include "kata.h"
#include "log.h"
#include "queue.h"
#include "vote.h"
#include "clue.h"
#include "linkedlist.h"
#include "result.h"
#include "logUI.h"

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 30
#define MAX_SKIP 2
#define MENU_OPTION_COUNT 4

extern int playerCount;
static int currentInput = 0;
static int malwareCount = 1;
static int botCount = 1;
static int developerCount = 0;
static char inputText[128] = "";
static List listVote;
static int state = 0;
static List pemain;
static int ronde = 1;
static int lanjut = 1;
extern Player players[MAX_PLAYERS];
extern int skipCount;
extern int selectedMenuIndex;
extern bool confirmExit;
extern int selectedExitIndex;
extern int screen;

void menuUtama();
void DrawGame();
void InitGame();
void UpdateGame();

void InitMenu();
void UpdateMenu();
void DrawMenu();
void InitExitConfirm();
void ExitConfirm();
void DrawExitConfirm();

#endif