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

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 30

static int state = 0;
static int currentInput = 0;
static int playerCount = 0;
static char inputText[128] = "";
static Player players[MAX_PLAYERS];
static List pemain;
static int ronde = 1;
static int lanjut = 1;

void menuUtama();
void DrawGame();
void UpdateGame();

#endif