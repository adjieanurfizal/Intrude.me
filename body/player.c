#include "player.h"

List InisialisasiPemain() {
    List L;
    CreateList(&L);
    int jumlah;
    printf("Masukkan jumlah pemain: ");
    scanf("%d", &jumlah);
    getchar();

    for (int i = 0; i < jumlah; i++) {
        infotype p;
        printf("Nama pemain ke-%d: ", i + 1);
        fgets(p.nama, 50, stdin);
        p.nama[strcspn(p.nama, "\n")] = 0;
        p.aktif = 1;
        // Tambahkan inisialisasi peran/kata rahasia di sini jika perlu
        InsVLast(&L, p);
    }
    return L;
}
