#ifndef loket_H
#define loket_H
#include "boolean.h"
#include "pengunjung.h"

#define MAXLIST 10 //kapasitas list pengunjung yang sudah dilayani

/* type Loket = < id: integer,                          {id loket}
                status: integer,                        {1=melayani, 0=kosong}
                jenisLayanan: array [1..2] of character {kode layanan yang ditangani, '-' bila kosong}
                pengunjungAktif: Pengunjung             {pengunjung yang sedang dilayani}
                listPengunjung: array [1..10] of Pengunjung {pengunjung yang sudah dilayani}
                jumlahDilayani: integer                 {banyak elemen terisi pada listPengunjung} >
{jumlahDilayani ditambahkan sebagai modifikasi ADT, untuk mencatat isi listPengunjung} */
typedef struct {
    int id;
    int status;
    char jenisLayanan[3];                   //indeks 0 tidak dipakai
    Pengunjung pengunjungAktif;
    Pengunjung listPengunjung[MAXLIST+1];   //indeks 0 tidak dipakai
    int jumlahDilayani;
} Loket;

/*** KONSTRUKTOR ***/

/*procedure MakeLoket(output L:Loket, input id:integer, input status:integer, input layanan1:character, input layanan2:character)
{I.S.: -}
{F.S.: L terdefinisi dengan id, status, dan jenisLayanan=[layanan1, layanan2]}
{proses: pengunjungAktif diisi pengunjung kosong, listPengunjung diisi pengunjung kosong, jumlahDilayani=0}
{bila loket hanya melayani satu layanan, layanan2 diisi '-'} */
void MakeLoket(Loket *L, int id, int status, char layanan1, char layanan2);

/*** SELEKTOR ***/

/*function GetIdLoket(L:Loket) -> integer
{mengembalikan id loket L} */
int GetIdLoket(Loket L);

/*function GetStatus(L:Loket) -> integer
{mengembalikan status loket L (1=melayani, 0=kosong)} */
int GetStatus(Loket L);

/*function GetJenisLayanan(L:Loket, i:integer) -> character
{mengembalikan kode layanan ke-i (1..2) yang ditangani loket L} */
char GetJenisLayanan(Loket L, int i);

/*function GetPengunjungAktif(L:Loket) -> Pengunjung
{mengembalikan pengunjung yang sedang dilayani loket L} */
Pengunjung GetPengunjungAktif(Loket L);

/*function GetJumlahDilayani(L:Loket) -> integer
{mengembalikan banyak pengunjung yang sudah dilayani loket L} */
int GetJumlahDilayani(Loket L);

/*function GetPengunjungDilayani(L:Loket, i:integer) -> Pengunjung
{mengembalikan pengunjung ke-i pada listPengunjung loket L} */
Pengunjung GetPengunjungDilayani(Loket L, int i);

/*** MUTATOR ***/

/*procedure SetStatus(input/output L:Loket, input status:integer)
{I.S.: L terdefinisi}
{F.S.: status L berubah menjadi status} */
void SetStatus(Loket *L, int status);

/*procedure SetPengunjungAktif(input/output L:Loket, input P:Pengunjung)
{I.S.: L terdefinisi}
{F.S.: pengunjungAktif L berubah menjadi P} */
void SetPengunjungAktif(Loket *L, Pengunjung P);

/*procedure TambahListPengunjung(input/output L:Loket, input P:Pengunjung)
{I.S.: L terdefinisi}
{F.S.: P ditambahkan ke listPengunjung L dan jumlahDilayani bertambah 1, bila belum penuh} */
void TambahListPengunjung(Loket *L, Pengunjung P);

/*** PREDIKAT ***/

/*function IsLoketKosong(L:Loket) -> boolean
{mengembalikan true jika status L = 0} */
boolean IsLoketKosong(Loket L);

/*function IsListFull(L:Loket) -> boolean
{mengembalikan true jika listPengunjung L sudah penuh} */
boolean IsListFull(Loket L);

/*function CanServe(L:Loket, layanan:character) -> boolean
{mengembalikan true jika layanan termasuk jenisLayanan yang ditangani L} */
boolean CanServe(Loket L, char layanan);

/*** OPERASI SIMULASI ***/

/*procedure MulaiLayani(input/output L:Loket, input P:Pengunjung)
{I.S.: L terdefinisi dan kosong (status=0)}
{F.S.: pengunjungAktif L = P, status L = 1}
{proses: loket mulai melayani pengunjung P} */
void MulaiLayani(Loket *L, Pengunjung P);

/*procedure SelesaiLayani(input/output L:Loket, output P:Pengunjung)
{I.S.: L terdefinisi dan sedang melayani (status=1)}
{F.S.: P = pengunjung yang baru selesai dilayani, P masuk listPengunjung L,
       pengunjungAktif L = pengunjung kosong, status L = 0} */
void SelesaiLayani(Loket *L, Pengunjung *P);

/*function CariLoket(daftar:array [1..n] of Loket, n:integer, layanan:character) -> integer
{mengembalikan indeks loket yang kosong (status=0) dan bisa melayani layanan,
dengan id terkecil bila ada beberapa. Mengembalikan 0 bila tidak ada loket yang tersedia}
{asumsi: daftar terurut berdasarkan id loket, indeks 1..n} */
int CariLoket(Loket daftar[], int n, char layanan);

/*** PRINT ***/

/*procedure PrintLoket(input L:Loket)
{I.S.: L terdefinisi}
{F.S.: -}
{proses: mencetak id, status, jenisLayanan, pengunjungAktif, dan listPengunjung loket L ke layar} */
void PrintLoket(Loket L);

/*procedure PrintListPengunjung(input L:Loket)
{I.S.: L terdefinisi}
{F.S.: -}
{proses: mencetak semua pengunjung yang sudah dilayani loket L ke layar} */
void PrintListPengunjung(Loket L);

#endif
