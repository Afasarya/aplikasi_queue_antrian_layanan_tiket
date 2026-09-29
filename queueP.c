#include <stdio.h>
#include <string.h>
#include "queueP.h"
#include "boolean.h"

/*procedure createQueue ( output Q:QueueP)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan pengunjung kosong, head=tail=0 }*/ 
void createQueue(QueueP *Q){
    Q->head = 0;
    Q->tail = 0;
    for (int i = 1; i <= MAXQ;i++){
        Q->wadah[i] = PengunjungKosong();
    }
}

/*function infoHead(Q:QueueP)-> Pengunjung 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
Pengunjung infoHead(QueueP Q){
    if (isEmptyQueue(Q)){
        return PengunjungKosong();
    }
    return (Q).wadah[1];
}

/*function infoTail(Q:QueueP)-> Pengunjung 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
Pengunjung infoTail(QueueP Q){
    if (Q.tail != 0){
        return Q.wadah[tail(Q)];
    }
    return PengunjungKosong();
}

/*function sizeQueue(Q:QueueP)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue(QueueP Q){
    return tail(Q);
}

/*procedure printQueue(input Q:QueueP)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(QueueP Q){
    for (int i = 1; i <= MAXQ; i++ ){
        printf(" ");
        PrintPengunjung(Q.wadah[i]);
    }
    printf("\n");
}

/*procedure viewQueue(input Q:QueueP)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(QueueP Q){
    for (int i = 1; i <= sizeQueue(Q);i++){
        printf(" ");
        PrintPengunjung(Q.wadah[i]);
    }
}

/*function isEmptyQueue(Q:QueueP) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(QueueP Q){
    return tail(Q) == 0;
}

/*function isFullQueue(Q:QueueP) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(QueueP Q){
    return tail(Q) == MAXQ;
}

/*function isOneElement(Q:QueueP) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(QueueP Q){
    return tail(Q) == 1;
}

/*procedure enqueue( input/output Q:QueueP, input e: Pengunjung )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(QueueP *Q, Pengunjung e){
    if (!isFullQueue(*Q)){
        Q->wadah[tail(*Q)+1] = e;
        Q->tail = tail(*Q) + 1;
        Q->head = 1;
    }
}

/*procedure deQueue( input/output Q:QueueP, output e: Pengunjung )
{I.S.: }
{F.S.: e=infohead(Q) atau e=pengunjung kosong bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(QueueP *Q, Pengunjung *e){
    if(!isEmptyQueue(*Q)) {
        if (isOneElement(*Q)) {
            *e =infoHead(*Q);
            Q->wadah[head(*Q)] = PengunjungKosong();
            head(*Q) = 0;
            tail(*Q) = 0;
        } else {
            *e = infoHead(*Q);
            for (int i = head(*Q) + 1; i <= tail(*Q); i++) {
                Q->wadah[i-1] = Q->wadah[i];
            }
            Q->wadah[tail(*Q)] = PengunjungKosong();
            tail(*Q) = tail(*Q) - 1;
        }
    } else {
        *e = PengunjungKosong();
    }
}

/*procedure enqueue2( input/output Q1:QueueP, input/output Q2:QueueP, input e: Pengunjung )
{I.S.: e terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek dari Q1 atau Q2} */
void enqueue2(QueueP *Q1, QueueP *Q2, Pengunjung e){
    if (sizeQueue(*Q2) >= sizeQueue(*Q1)){
        if (!isFullQueue(*Q1)){
            enqueue(Q1,e);
        }
    }else{
        if (!isFullQueue(*Q2)){
            enqueue(Q2,e);
        }
    }
}

/*procedure dequeue2( input/output Q1:QueueP, input/output Q2:QueueP, output e: Pengunjung )
{I.S.: }
{F.S.: e=infohead Q1 atau Q2 atau e=pengunjung kosong bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeue2(QueueP *Q1, QueueP *Q2, Pengunjung *e) {
    // Kamus Lokal
    int i;

    // Algoritma
    if (sizeQueue(*Q1) >= sizeQueue(*Q2)) {
        dequeue(Q1,e);
    } else {
        dequeue(Q2,e);
    }

}
