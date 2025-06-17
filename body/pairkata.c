#include "../header/kata.h"

PairKata daftarPasangan[MAX_PAIR] = {
    {"Makanan", "Apel", "Pir"},
    {"Makanan", "Semangka", "Melon"},
    {"Makanan", "Ayam", "Bebek"},
    {"Kota", "Bandung", "Cimahi"},
    {"Kota", "Jakarta", "Bekasi"},
    {"Informatika", "Stack", "Queue"},
    {"Informatika", "Tree", "Graph"},
    {"Informatika", "Python", "JavaScript"},
    {"Informatika", "VSCode", "Sublime"}
};

int jumlahPasangan = 9;

PairKata randomPair() {
    srand(time(NULL));
    int index = rand() % jumlahPasangan;
    return daftarPasangan[index];
}

void tambahPairKata(const char* kategori, const char* kata1, const char* kata2) {
    if (jumlahPasangan < MAX_PAIR) {
        strncpy(daftarPasangan[jumlahPasangan].kategori, kategori, MAX_KATA);
        strncpy(daftarPasangan[jumlahPasangan].kata1, kata1, MAX_KATA);
        strncpy(daftarPasangan[jumlahPasangan].kata2, kata2, MAX_KATA);
        jumlahPasangan++;
    }
}
