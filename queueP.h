#ifndef queueP_H
#define queueP_H
#include "boolean.h"
#include "pengunjung.h"

#define MAXQ 10 //kapasitas queue

/* type QueueP = <  wadah: array [1..10] of Pengunjung ,
					head: integer ,
					tail: integer >
{cara akses: Q:QueueP, Q.head=head(Q) ...} */
typedef struct { Pengunjung wadah[MAXQ+1]; //kapasitas 10 elemen, indeks 0 tidak dipakai
                  int head; 
                  int tail; 
                } QueueP;

/*** KONSTRUKTOR ***/

/*procedure createQueue ( output Q:QueueP)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan pengunjung kosong, head=tail=0 }*/ 
void createQueue(QueueP *Q);

/*** SELEKTOR ***/

/*function Head(Q:QueueP)-> integer 
{mengembalikan elemen terdepan antrian Q} */
//int Head(QueueP Q);
#define head(Q) (Q).head //implementasi fisik macro

/*function Tail(Q:QueueP)-> integer 
{mengembalikan elemen terakhir antrian Q} */
//int Tail(QueueP Q);
#define tail(Q) (Q).tail //implementasi fisik macro

/*function infoHead(Q:QueueP)-> Pengunjung 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
Pengunjung infoHead(QueueP Q);

/*function infoTail(Q:QueueP)-> Pengunjung 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
Pengunjung infoTail(QueueP Q);

/*** PRINT ***/

/*function sizeQueue(Q:QueueP)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue(QueueP Q);

/*procedure printQueue(input Q:QueueP)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(QueueP Q);

/*procedure viewQueue(input Q:QueueP)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(QueueP Q);

/*** PREDIKAT ***/

/*function isEmptyQueue(Q:QueueP) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(QueueP Q);

/*function isFullQueue(Q:QueueP) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(QueueP Q);

/*function isOneElement(Q:QueueP) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(QueueP Q);

/*** MUTATOR ***/

/*procedure enqueue( input/output Q:QueueP, input e: Pengunjung )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(QueueP *Q, Pengunjung e);
  
/*procedure deQueue( input/output Q:QueueP, output e: Pengunjung )
{I.S.: }
{F.S.: e=infohead(Q) atau e=pengunjung kosong bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(QueueP *Q, Pengunjung *e);

#endif
