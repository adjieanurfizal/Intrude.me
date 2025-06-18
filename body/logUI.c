#include "../header/logUI.h"
#include <raylib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

extern LogClue logClues[MAX_LOG];
extern int jumlahClue;

extern LogVote logVotes[MAX_LOG];
extern int jumlahVote;

extern PlayerScore leaderboard[MAX_LOG];
extern int jumlahSkor;

static int logScroll = 0;
static int leaderboardScroll = 0;
static int currentPage = 0;

void InitLogScreen() {
    logScroll = 0;
}

void UpdateLogScreen() {
    if (IsKeyPressed(KEY_Q)) {
        logScroll--;
        if (logScroll < 0) logScroll = 0;
    }
    if (IsKeyPressed(KEY_E)) {
        logScroll++;
    }
}

void DrawLogScreen() {
    ClearBackground(RAYWHITE);
    DrawText(" LOG CLUE:", 50, -20, 20, DARKGRAY);
    int y = 50;

    for (int i = logScroll; i < jumlahClue && y < GetScreenHeight() - 50; i++) {
        char timeStr[32];
        time_t now = logClues[i].timestamp;
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", localtime(&now));

        char buffer[256];
        sprintf(buffer, "[%d] %s: %s (%s)", logClues[i].ronde, logClues[i].nama, logClues[i].clue, timeStr);
        DrawText(buffer, 50, y, 18, BLACK);
        y += 25;
    }

    y += 20;
    DrawText(" LOG VOTE:", 50, y, 20, DARKGRAY);
    y += 30;
    for (int i = logScroll; i < jumlahVote && y < GetScreenHeight() - 50; i++) {
        char timeStr[32];
        time_t now = logVotes[i].timestamp;
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", localtime(&now));

        char buffer[256];
        sprintf(buffer, "[%d] %s memilih %s (%s)", logVotes[i].ronde, logVotes[i].voter, logVotes[i].target, timeStr);
        DrawText(buffer, 50, y, 18, BLACK);
        y += 25;
    }

    DrawText("Tekan [ESC] untuk kembali, [Q]/[E] untuk scroll", 50, GetScreenHeight() - 30, 18, GRAY);
}

void InitLeaderboardScreen() {
    leaderboardScroll = 0;
}

void UpdateLeaderboardScreen() {
    if (IsKeyPressed(KEY_Q)) {
        leaderboardScroll--;
        if (leaderboardScroll < 0) leaderboardScroll = 0;
    }
    if (IsKeyPressed(KEY_E)) {
        leaderboardScroll++;
    }
}

void DrawLeaderboardScreen() {
    ClearBackground(RAYWHITE);
    DrawText("LEADERBOARD:", 50, 20, 20, DARKBLUE);

    int y = 60;
    for (int i = leaderboardScroll; i < jumlahSkor && y < GetScreenHeight() - 50; i++) {
        char buffer[128];
        sprintf(buffer, "%s - Skor: %d | Menang: %d | Kalah: %d",
            leaderboard[i].nama,
            leaderboard[i].score,
            leaderboard[i].menang,
            leaderboard[i].kalah);
        DrawText(buffer, 50, y, 20, BLACK);
        y += 30;
    }

    DrawText("Tekan [ESC] untuk kembali, [Q]/[E] untuk scroll", 50, GetScreenHeight() - 30, 18, GRAY);
}

const char* guidePages[GUIDE_PAGE_COUNT] = {
    "👋 Selamat datang di Undercover Game!\n\n"
    "- Game ini dimainkan oleh 4-10 pemain.\n"
    "- Terdapat 3 role: Developer, Malware, dan Bot.\n"
    "- Developer harus menemukan siapa Malware!\n",
    "🎯 Tujuan Permainan:\n\n"
    "- Developer dan Malware mendapatkan kata yang hampir sama.\n"
    "- Bot tidak mendapat kata.\n"
    "- Pemain memberikan clue berdasarkan kata mereka.",
    "🗳️ Voting & Eliminasi:\n\n"
    "- Setelah clue, semua pemain memberikan voting.\n"
    "- Pemain yang mendapat voting terbanyak dieliminasi.\n"
    "- Jika semua Malware tereliminasi, Developer menang!\n"
    "- Jika Malware jumlahnya >= Developer, Malware menang!"
};

void InitGuideScreen() {
currentPage = 0;
}

void UpdateGuideScreen() {
    if (IsKeyPressed(KEY_LEFT)) {
        if (currentPage > 0) currentPage--;
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        if (currentPage < GUIDE_PAGE_COUNT - 1) currentPage++;
    }
        if (IsKeyPressed(KEY_ESCAPE)) {
        // Kembali ke main menu
        extern int screen;
        screen = 0;
    }
}

void DrawGuideScreen() {
    ClearBackground(RAYWHITE);
    DrawText(TextFormat("📖 Panduan Halaman %d / %d", currentPage + 1, GUIDE_PAGE_COUNT), 40, 40, 20, DARKBLUE);
    DrawText(guidePages[currentPage], 40, 80, 20, BLACK);
    DrawText("← Sebelumnya | → Selanjutnya | ESC: Kembali", 40, GetScreenHeight() - 40, 20, GRAY);
}