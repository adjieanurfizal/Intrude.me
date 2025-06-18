#ifndef LOGUI_H
#define LOGUI_H

#define GUIDE_PAGE_COUNT 3

#include "linkedlist.h"
#include "log.h"

void InitLogScreen();
void UpdateLogScreen();
void DrawLogScreen();

void InitLeaderboardScreen();
void UpdateLeaderboardScreen();
void DrawLeaderboardScreen();

void InitGuideScreen();
void UpdateGuideScreen();
void DrawGuideScreen();

#endif
