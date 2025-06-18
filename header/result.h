#ifndef RESULT_H
#define RESULT_H

#include <raylib.h>
#include "player.h"
#include "linkedlist.h"
#include "vote.h"
#include "log.h"

void InitResultPhase(List* list);
void UpdateResultPhase(List* list);
void DrawResultPhase();
bool IsGameOver();

#endif
