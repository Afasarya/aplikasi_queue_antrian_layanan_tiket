#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "loket.h"
#include "pengunjung.h"

/*** KONSTRUKTOR ***/

/*procedure MakeLoket(output L:Loket, input id:integer, input status:integer, input layanan1:character, input layanan2:character)
{I.S.: -}
{F.S.: L terdefinisi dengan id, status, dan jenisLayanan=[layanan1, layanan2]}
{proses: pengunjungAktif diisi pengunjung kosong, listPengunjung diisi pengunjung kosong, jumlahDilayani=0}
{bila loket hanya melayani satu layanan, layanan2 diisi '-'} */
void MakeLoket(Loket *L, int id, int status, char layanan1, char layanan2){
    L->id = id;
    L->status = status;
    L->jenisLayanan[1] = layanan1;
    L->jenisLayanan[2] = layanan2;
    L->pengunjungAktif = PengunjungKosong();
    for (int i = 1; i <= MAXLIST;i++){
        L->listPengunjung[i] = PengunjungKosong();
    }
    L->jumlahDilayani = 0;
}

/*** SELEKTOR ***/

/*function GetIdLoket(L:Loket) -> integer
{mengembalikan id loket L} */
int GetIdLoket(Loket L){
    return L.id;
}

/*function GetStatus(L:Loket) -> integer
{mengembalikan status loket L (1=melayani, 0=kosong)} */
int GetStatus(Loket L){
    return L.status;
}

/*function GetJenisLayanan(L:Loket, i:integer) -> character
{mengembalikan kode layanan ke-i (1..2) yang ditangani loket L} */
char GetJenisLayanan(Loket L, int i){
    if (i >= 1 && i <= 2){
        return L.jenisLayanan[i];
    }
    return '-';
}

/*function GetPengunjungAktif(L:Loket) -> Pengunjung
{mengembalikan pengunjung yang sedang dilayani loket L} */
Pengunjung GetPengunjungAktif(Loket L){
    return L.pengunjungAktif;
}

/*function GetJumlahDilayani(L:Loket) -> integer
{mengembalikan banyak pengunjung yang sudah dilayani loket L} */
int GetJumlahDilayani(Loket L){
    return L.jumlahDilayani;
}

/*function GetPengunjungDilayani(L:Loket, i:integer) -> Pengunjung
{mengembalikan pengunjung ke-i pada listPengunjung loket L} */
Pengunjung GetPengunjungDilayani(Loket L, int i){
    if (i >= 1 && i <= L.jumlahDilayani){
        return L.listPengunjung[i];
    }
    return PengunjungKosong();
}

/*** MUTATOR ***/

/*procedure SetStatus(input/output L:Loket, input status:integer)
{I.S.: L terdefinisi}
{F.S.: status L berubah menjadi status} */
void SetStatus(Loket *L, int status){
    L->status = status;
}

/*procedure SetPengunjungAktif(input/output L:Loket, input P:Pengunjung)
{I.S.: L terdefinisi}
{F.S.: pengunjungAktif L berubah menjadi P} */
void SetPengunjungAktif(Loket *L, Pengunjung P){
    L->pengunjungAktif = P;
}

/*procedure TambahListPengunjung(input/output L:Loket, input P:Pengunjung)
{I.S.: L terdefinisi}
{F.S.: P ditambahkan ke listPengunjung L dan jumlahDilayani bertambah 1, bila belum penuh} */
void TambahListPengunjung(Loket *L, Pengunjung P){
    if (!IsListFull(*L)){
        L->jumlahDilayani = L->jumlahDilayani + 1;
        L->listPengunjung[L->jumlahDilayani] = P;
    }
}

/*** PREDIKAT ***/

/*function IsLoketKosong(L:Loket) -> boolean
{mengembalikan true jika status L = 0} */
boolean IsLoketKosong(Loket L){
    return L.status == 0;
}

/*function IsListFull(L:Loket) -> boolean
{mengembalikan true jika listPengunjung L sudah penuh} */
boolean IsListFull(Loket L){
    return L.jumlahDilayani == MAXLIST;
}

/*function CanServe(L:Loket, layanan:character) -> boolean
{mengembalikan true jika layanan termasuk jenisLayanan yang ditangani L} */
boolean CanServe(Loket L, char layanan){
    return (L.jenisLayanan[1] == layanan) || (L.jenisLayanan[2] == layanan);
}

/*** OPERASI SIMULASI ***/

/*procedure MulaiLayani(input/output L:Loket, input P:Pengunjung)
{I.S.: L terdefinisi dan kosong (status=0)}
{F.S.: pengunjungAktif L = P, status L = 1}
{proses: loket mulai melayani pengunjung P} */
void MulaiLayani(Loket *L, Pengunjung P){
    L->pengunjungAktif = P;
    L->status = 1;
}

/*procedure SelesaiLayani(input/output L:Loket, output P:Pengunjung)
{I.S.: L terdefinisi dan sedang melayani (status=1)}
{F.S.: P = pengunjung yang baru selesai dilayani, P masuk listPengunjung L,
       pengunjungAktif L = pengunjung kosong, status L = 0} */
void SelesaiLayani(Loket *L, Pengunjung *P){
    *P = L->pengunjungAktif;
    TambahListPengunjung(L, *P);
    L->pengunjungAktif = PengunjungKosong();
    L->status = 0;
}

/*function CariLoket(daftar:array [1..n] of Loket, n:integer, layanan:character) -> integer
{mengembalikan indeks loket yang kosong (status=0) dan bisa melayani layanan,
dengan id terkecil bila ada beberapa. Mengembalikan 0 bila tidak ada loket yang tersedia}
{asumsi: daftar terurut berdasarkan id loket, indeks 1..n} */
int CariLoket(Loket daftar[], int n, char layanan){
    for (int i = 1; i <= n;i++){
        if (IsLoketKosong(daftar[i]) && CanServe(daftar[i],layanan)){
            return i;
        }
    }
    return 0;
}

/*** PRINT ***/
/*procedure PrintLoket(input L:Loket)
{I.S.: L terdefinisi}
{F.S.: -}
{proses: mencetak id, status, jenisLayanan, pengunjungAktif, dan listPengunjung loket L ke layar} */
void PrintLoket(Loket L){
    printf("Loket %d | ", GetIdLoket(L));
    if (GetStatus(L) == 1){
        printf("Melayani: ");
        PrintPengunjung(GetPengunjungAktif(L));
    } else {
        printf("Kosong");
    }
    printf(" | Layanan: %c,%c | Dilayani: %d\n",
        GetJenisLayanan(L,1), GetJenisLayanan(L,2), GetJumlahDilayani(L));
}

/*procedure PrintListPengunjung(input L:Loket)
{I.S.: L terdefinisi}
{F.S.: -}
{proses: mencetak semua pengunjung yang sudah dilayani loket L ke layar} */
void PrintListPengunjung(Loket L){
    for (int i = 1; i <= L.jumlahDilayani;i++){
        printf(" ");
        PrintPengunjung(GetPengunjungDilayani(L,i));
    }
    printf("\n");
}