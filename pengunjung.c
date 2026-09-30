#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "pengunjung.h"

/*** KONSTRUKTOR ***/

/*procedure MakePengunjung(output P:Pengunjung, input id:integer, input nama:string, input layanan:character)
{I.S.: -}
{F.S.: P terdefinisi dengan id, nama, dan layanan sesuai masukan}
{proses: mengisi setiap komponen P} */
void MakePengunjung(Pengunjung *P, int id, char nama[], char layanan){
    P->id = id;
    strncpy(P->nama, nama, MAXNAMA - 1);
    P->nama[MAXNAMA - 1] = '\0';
    P->layanan = layanan;
}

/*function PengunjungKosong() -> Pengunjung
{mengembalikan pengunjung kosong, yaitu id=0, nama="-", layanan='-'}
{dipakai sebagai penanda elemen kosong pada queue dan loket} */
Pengunjung PengunjungKosong(){
    Pengunjung P;
    MakePengunjung(&P, 0, "-", '-');
    return P;
}

/*** SELEKTOR ***/

/*function GetIdPengunjung(P:Pengunjung) -> integer
{mengembalikan id pengunjung P} */
int GetIdPengunjung(Pengunjung P){
    return P.id;
}

/*procedure GetNamaPengunjung(input P:Pengunjung, output nama:string)
{mengisi nama dengan nama pengunjung P} */
void GetNamaPengunjung(Pengunjung P, char nama[]){
    strcpy(nama, P.nama);
}

/*function GetLayananPengunjung(P:Pengunjung) -> character
{mengembalikan kode layanan pengunjung P} */
char GetLayananPengunjung(Pengunjung P){
    return P.layanan;
}

/*** MUTATOR ***/

/*procedure SetIdPengunjung(input/output P:Pengunjung, input id:integer)
{I.S.: P terdefinisi}
{F.S.: id P berubah menjadi id} */
void SetIdPengunjung(Pengunjung *P, int id){
    P->id = id;
}

/*procedure SetNamaPengunjung(input/output P:Pengunjung, input nama:string)
{I.S.: P terdefinisi}
{F.S.: nama P berubah menjadi nama} */
void SetNamaPengunjung(Pengunjung *P, char nama[]){
    strncpy(P->nama, nama, MAXNAMA - 1);
    P->nama[MAXNAMA - 1] = '\0';
}

/*procedure SetLayananPengunjung(input/output P:Pengunjung, input layanan:character)
{I.S.: P terdefinisi}
{F.S.: layanan P berubah menjadi layanan} */
void SetLayananPengunjung(Pengunjung *P, char layanan){
    P->layanan = layanan;
}

/*** PREDIKAT ***/

/*function IsPengunjungKosong(P:Pengunjung) -> boolean
{mengembalikan true jika P adalah pengunjung kosong (id=0)} */
boolean IsPengunjungKosong(Pengunjung P){
    return P.id == 0;
}

/*** PRINT ***/

/*procedure PrintPengunjung(input P:Pengunjung)
{I.S.: P terdefinisi}
{F.S.: -}
{proses: mencetak satu pengunjung ke layar tanpa newline, misal: [1|Budi|A] } */
void PrintPengunjung(Pengunjung P){
    printf("[%d|%s|%c]", P.id, P.nama, P.layanan);
}
