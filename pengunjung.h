#ifndef pengunjung_H
#define pengunjung_H
#include "boolean.h"

/* Program   : pengunjung.h */
/* Deskripsi : ADT Pengunjung untuk antrean layanan loket */
/* Tanggal   : 29 September 2026*/
/***********************************/

#define MAXNAMA 50 //panjang maksimum nama pengunjung

/* type Pengunjung = < id: integer,       {id pengunjung}
                       nama: string,      {nama pengunjung}
                       layanan: character {kode layanan: 'A','B','I','P'} >
{cara akses: P:Pengunjung, P.id, P.nama, P.layanan} */
typedef struct {
    int id;
    char nama[MAXNAMA];
    char layanan;
} Pengunjung;

/*** KONSTRUKTOR ***/

/*procedure MakePengunjung(output P:Pengunjung, input id:integer, input nama:string, input layanan:character)
{I.S.: -}
{F.S.: P terdefinisi dengan id, nama, dan layanan sesuai masukan}
{proses: mengisi setiap komponen P} */
void MakePengunjung(Pengunjung *P, int id, char nama[], char layanan);

/*function PengunjungKosong() -> Pengunjung
{mengembalikan pengunjung kosong, yaitu id=0, nama="-", layanan='-'}
{dipakai sebagai penanda elemen kosong pada queue dan loket} */
Pengunjung PengunjungKosong();

/*** SELEKTOR ***/

/*function GetIdPengunjung(P:Pengunjung) -> integer
{mengembalikan id pengunjung P} */
int GetIdPengunjung(Pengunjung P);

/*procedure GetNamaPengunjung(input P:Pengunjung, output nama:string)
{mengisi nama dengan nama pengunjung P} */
void GetNamaPengunjung(Pengunjung P, char nama[]);

/*function GetLayananPengunjung(P:Pengunjung) -> character
{mengembalikan kode layanan pengunjung P} */
char GetLayananPengunjung(Pengunjung P);

/*** MUTATOR ***/

/*procedure SetIdPengunjung(input/output P:Pengunjung, input id:integer)
{I.S.: P terdefinisi}
{F.S.: id P berubah menjadi id} */
void SetIdPengunjung(Pengunjung *P, int id);

/*procedure SetNamaPengunjung(input/output P:Pengunjung, input nama:string)
{I.S.: P terdefinisi}
{F.S.: nama P berubah menjadi nama} */
void SetNamaPengunjung(Pengunjung *P, char nama[]);

/*procedure SetLayananPengunjung(input/output P:Pengunjung, input layanan:character)
{I.S.: P terdefinisi}
{F.S.: layanan P berubah menjadi layanan} */
void SetLayananPengunjung(Pengunjung *P, char layanan);

/*** PREDIKAT ***/

/*function IsPengunjungKosong(P:Pengunjung) -> boolean
{mengembalikan true jika P adalah pengunjung kosong (id=0)} */
boolean IsPengunjungKosong(Pengunjung P);

/*** PRINT ***/

/*procedure PrintPengunjung(input P:Pengunjung)
{I.S.: P terdefinisi}
{F.S.: -}
{proses: mencetak satu pengunjung ke layar tanpa newline, misal: [1|Budi|A] } */
void PrintPengunjung(Pengunjung P);

#endif
