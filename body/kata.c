#include "header/kata.h"

PairKata currentPair; // global pasangan aktif

Address buildTreeKataRahasia() {
    Address root = newNode("KATA RAHASIA");

    // Kategori Umum
    Address makanan = newNode("Makanan");
    insertChild(makanan, newNode("Apel"));
    insertChild(makanan, newNode("Pir"));
    insertChild(makanan, newNode("Semangka"));
    insertChild(makanan, newNode("Melon"));
    insertChild(makanan, newNode("Ayam"));
    insertChild(makanan, newNode("Bebek"));

    Address kota = newNode("Kota");
    insertChild(kota, newNode("Bandung"));
    insertChild(kota, newNode("Cimahi"));
    insertChild(kota, newNode("Jakarta"));
    insertChild(kota, newNode("Bekasi"));

    // Kategori Informatika
    Address informatika = newNode("Informatika");
    Address struktur = newNode("Struktur Data");
    insertChild(struktur, newNode("Stack"));
    insertChild(struktur, newNode("Queue"));
    insertChild(struktur, newNode("Tree"));
    insertChild(struktur, newNode("Graph"));

    Address bahasa = newNode("Bahasa");
    insertChild(bahasa, newNode("Python"));
    insertChild(bahasa, newNode("JavaScript"));

    Address tools = newNode("Tools");
    insertChild(tools, newNode("VSCode"));
    insertChild(tools, newNode("Sublime"));

    insertChild(informatika, struktur);
    insertChild(informatika, bahasa);
    insertChild(informatika, tools);

    insertChild(root, makanan);
    insertChild(root, kota);
    insertChild(root, informatika);

    return root;
}

void addCustomCategory(Address root, char* categoryName) {
    Address newCategory = newNode(categoryName);
    insertChild(root, newCategory);
}

void addCustomWordPair(Address root, char* categoryName, char* kata1, char* kata2) {
    Address p = root->firstChild;
    while (p != NULL && strcmp(p->label, categoryName) != 0) {
        p = p->nextSibling;
    }
    if (p != NULL) {
        insertChild(p, newNode(kata1));
        insertChild(p, newNode(kata2));
        tambahPairKata(categoryName, kata1, kata2);
    }
}

PairKata randomPairByCategory(const char* kategori) {
    PairKata pilihan[MAX_PAIR];
    int jumlah = 0;
    for (int i = 0; i < jumlahPasangan; i++) {
        if (strcmp(daftarPasangan[i].kategori, kategori) == 0) {
            pilihan[jumlah++] = daftarPasangan[i];
        }
    }
    if (jumlah > 0) {
        return pilihan[rand() % jumlah];
    } else {
        return daftarPasangan[0];
    }
}

void assignKataRahasia(PlayerList* list, const char* kategori) {
    srand(time(NULL));
    currentPair = randomPairByCategory(kategori);

    Player* current = list->head;
    while (current != NULL) {
        if (current->role == DEVELOPER) {
            strncpy(current->word, currentPair.kata1, MAX_WORD);
        } else if (current->role == MALWARE) {
            strncpy(current->word, currentPair.kata2, MAX_WORD);
        }
        current = current->next;
    }
}

void printKataRahasiaTerpilih() {
    printf("🔒 Kata Rahasia Developer: %s\n", currentPair.kata1);
    printf("🛑 Kata Rahasia Malware  : %s\n", currentPair.kata2);
}
