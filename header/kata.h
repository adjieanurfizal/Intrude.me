// kata.h
#ifndef KATA_H
#define KATA_H

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include "tree.h"
#include "player.h"
#include "queue.h"

#define MAX_KATA 50
#define MAX_PAIR 100

typedef struct {
    char kategori[MAX_KATA];
    char kata1[MAX_KATA]; // untuk Developer
    char kata2[MAX_KATA]; // untuk Malware
} PairKata;

extern PairKata daftarPasangan[];
extern int jumlahPasangan;

PairKata randomPair();
PairKata randomPairByCategory(const char* kategori);
void tambahPairKata(const char* kategori, const char* kata1, const char* kata2);

Address buildTreeKataRahasia();
void addCustomCategory(Address root, char* categoryName);
void addCustomWordPair(Address root, char* categoryName, char* kata1, char* kata2);
void assignKataRahasia(PlayerList* list, const char* kategori);
void printKataRahasiaTerpilih();

#endif