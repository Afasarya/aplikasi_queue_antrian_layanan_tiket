#include <stdio.h>
#include "pengunjung.h"
#include "queueP.h"
#include "loket.h"

/* Program   : antreanlayanan.c */
/* Deskripsi : Simulasi antrean pengunjung pada empat loket layanan */
/* Tanggal   : 29 September 2026 */
/***********************************/

/*procedure MasukAntrean(input/output QA,QB,QI,QP:QueueP, input P:Pengunjung)
{I.S.: seluruh queue dan P terdefinisi}
{F.S.: P masuk ke queue yang sesuai dengan jenis layanannya, bila queue belum penuh} */
void MasukAntrean(QueueP *QA, QueueP *QB, QueueP *QI, QueueP *QP, Pengunjung P){
    char layanan;
    QueueP *QTujuan;

    layanan = GetLayananPengunjung(P);
    QTujuan = NULL;

    switch (layanan){
        case 'A':
            QTujuan = QA;
            break;
        case 'B':
            QTujuan = QB;
            break;
        case 'I':
            QTujuan = QI;
            break;
        case 'P':
            QTujuan = QP;
            break;
        default:
            printf("Layanan %c tidak tersedia untuk ", layanan);
            PrintPengunjung(P);
            printf(".\n");
    }

    if (QTujuan != NULL){
        if (!isFullQueue(*QTujuan)){
            enqueue(QTujuan, P);
            PrintPengunjung(P);
            printf(" masuk ke antrean layanan %c.\n", layanan);
        } else {
            printf("Antrean layanan %c penuh. ", layanan);
            PrintPengunjung(P);
            printf(" tidak dapat masuk.\n");
        }
    }
}

/*procedure ProsesAntrean(input/output Q:QueueP, input/output daftarLoket:array of Loket,
                          input n:integer, input layanan:character)
{I.S.: Q dan daftarLoket terdefinisi}
{F.S.: sebanyak mungkin pengunjung pada Q mulai dilayani oleh loket yang tersedia} */
void ProsesAntrean(QueueP *Q, Loket daftarLoket[], int n, char layanan){
    int indeksLoket;
    Pengunjung P;

    indeksLoket = CariLoket(daftarLoket, n, layanan);
    while (!isEmptyQueue(*Q) && indeksLoket != 0){
        dequeue(Q, &P);
        MulaiLayani(&daftarLoket[indeksLoket], P);

        PrintPengunjung(P);
        printf(" mulai dilayani di Loket %d.\n", GetIdLoket(daftarLoket[indeksLoket]));

        indeksLoket = CariLoket(daftarLoket, n, layanan);
    }
}

/*procedure TampilkanSatuAntrean(input nama:string, input Q:QueueP)
{I.S.: Q terdefinisi}
{F.S.: isi Q ditampilkan ke layar} */
void TampilkanSatuAntrean(char nama[], QueueP Q){
    printf("%-14s: ", nama);
    if (isEmptyQueue(Q)){
        printf("(kosong)");
    } else {
        viewQueue(Q);
    }
    printf("\n");
}

/*procedure TampilkanKondisi(input QA,QB,QI,QP:QueueP,
                             input daftarLoket:array of Loket, input n:integer)
{I.S.: seluruh queue dan daftarLoket terdefinisi}
{F.S.: kondisi seluruh antrean dan loket ditampilkan ke layar} */
void TampilkanKondisi(QueueP QA, QueueP QB, QueueP QI, QueueP QP,
                      Loket daftarLoket[], int n){
    int i;

    printf("\nKondisi antrean:\n");
    TampilkanSatuAntrean("Administrasi", QA);
    TampilkanSatuAntrean("Pembayaran", QB);
    TampilkanSatuAntrean("Informasi", QI);
    TampilkanSatuAntrean("Pengaduan", QP);

    printf("\nKondisi loket:\n");
    for (i = 1; i <= n; i++){
        PrintLoket(daftarLoket[i]);
    }
}

/*procedure SelesaikanSemuaLoket(input/output daftarLoket:array of Loket, input n:integer)
{I.S.: daftarLoket terdefinisi}
{F.S.: pelayanan pada seluruh loket aktif selesai dan pengunjung masuk ke list loket} */
void SelesaikanSemuaLoket(Loket daftarLoket[], int n){
    int i;
    Pengunjung P;

    for (i = 1; i <= n; i++){
        if (!IsLoketKosong(daftarLoket[i])){
            SelesaiLayani(&daftarLoket[i], &P);
            PrintPengunjung(P);
            printf(" selesai dilayani di Loket %d.\n", GetIdLoket(daftarLoket[i]));
        }
    }
}

/*procedure TampilkanRiwayat(input daftarLoket:array of Loket, input n:integer)
{I.S.: daftarLoket terdefinisi}
{F.S.: list pengunjung yang sudah dilayani setiap loket ditampilkan ke layar} */
void TampilkanRiwayat(Loket daftarLoket[], int n){
    int i;

    printf("\nRiwayat pelayanan setiap loket:\n");
    for (i = 1; i <= n; i++){
        printf("Loket %d:", GetIdLoket(daftarLoket[i]));
        if (GetJumlahDilayani(daftarLoket[i]) == 0){
            printf(" (belum ada)\n");
        } else {
            PrintListPengunjung(daftarLoket[i]);
        }
    }
}

int main(void){
    /* Kamus */
    Pengunjung P1, P2, P3, P4, P5;
    QueueP QA, QB, QI, QP;
    Loket daftarLoket[5];

    /* Algoritma */
    MakePengunjung(&P1, 1, "Andi", 'A');
    MakePengunjung(&P2, 2, "Budi", 'B');
    MakePengunjung(&P3, 3, "Citra", 'I');
    MakePengunjung(&P4, 4, "Dinda", 'P');
    MakePengunjung(&P5, 5, "Eko", 'B');

    MakeLoket(&daftarLoket[1], 1, 0, 'A', 'B');
    MakeLoket(&daftarLoket[2], 2, 0, 'B', '-');
    MakeLoket(&daftarLoket[3], 3, 0, 'I', 'P');
    MakeLoket(&daftarLoket[4], 4, 0, 'P', '-');

    createQueue(&QA);
    createQueue(&QB);
    createQueue(&QI);
    createQueue(&QP);

    printf("=== SIMULASI ANTREAN LAYANAN ===\n\n");
    printf("Pengunjung masuk ke antrean:\n");
    MasukAntrean(&QA, &QB, &QI, &QP, P1);
    MasukAntrean(&QA, &QB, &QI, &QP, P2);
    MasukAntrean(&QA, &QB, &QI, &QP, P3);
    MasukAntrean(&QA, &QB, &QI, &QP, P4);
    MasukAntrean(&QA, &QB, &QI, &QP, P5);

    TampilkanKondisi(QA, QB, QI, QP, daftarLoket, 4);

    printf("\n=== PELAYANAN TAHAP 1 ===\n");
    ProsesAntrean(&QA, daftarLoket, 4, 'A');
    ProsesAntrean(&QB, daftarLoket, 4, 'B');
    ProsesAntrean(&QI, daftarLoket, 4, 'I');
    ProsesAntrean(&QP, daftarLoket, 4, 'P');
    TampilkanKondisi(QA, QB, QI, QP, daftarLoket, 4);

    printf("\nPengunjung pada loket tahap 1 selesai dilayani:\n");
    SelesaikanSemuaLoket(daftarLoket, 4);

    printf("\n=== PELAYANAN TAHAP 2 ===\n");
    ProsesAntrean(&QA, daftarLoket, 4, 'A');
    ProsesAntrean(&QB, daftarLoket, 4, 'B');
    ProsesAntrean(&QI, daftarLoket, 4, 'I');
    ProsesAntrean(&QP, daftarLoket, 4, 'P');
    TampilkanKondisi(QA, QB, QI, QP, daftarLoket, 4);

    printf("\nPengunjung pada loket tahap 2 selesai dilayani:\n");
    SelesaikanSemuaLoket(daftarLoket, 4);

    printf("\n=== HASIL AKHIR ===\n");
    TampilkanKondisi(QA, QB, QI, QP, daftarLoket, 4);
    TampilkanRiwayat(daftarLoket, 4);

    return 0;
}
