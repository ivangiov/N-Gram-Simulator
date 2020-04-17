/*
Programmer : Dhanurangga Al Fadh (13218005)
Tester : Sarah Alyaa Tsaabitah (13218011)
Deskripsi : Berisi implementasi fungsi untuk mengolah queue. Terdapat dua fungsi yaitu enqueue untuk menambah data dan dequeue untuk mengeluarkan data
*/

#include "datatype.c"

#ifndef QUEUEHANDLING_C
#define QUEUEHANDLING_C

void enqueue(queue *Q, char *text){
    //Membuat node baru dan meletakkan datanya
    node *newnode = (node*)malloc(sizeof(node));
    newnode->word = (char*)malloc(sizeof(char));
    strcpy(newnode->word,text);

    //Kasus queue masih kosong
    if(Q->rear == NULL){
        newnode->next = newnode;
        Q->rear= newnode;
        Q->front= newnode;
        return;
    }

    //Kasus queue sudah terisi
    Q->rear->next = newnode;
    newnode->next = NULL;
    Q->rear = newnode;
    return;
}


void dequeue(queue *Q){
    //Membuat pointer node sementara;
    node *temp;

    //Kasus queue kosong
    if(Q->front == NULL){
        printf("Queue kosong!\n");
        return;
    }

    //Kasus tersisa node terakhir
    //kasus ini gatau kenapa gabisa
    else if(Q->front == Q->rear){
        temp = Q->front;
        Q->front = NULL;
        Q->rear = NULL;
        free(temp);
        return;
    }

    //Kasus terdapat lebih dari 1 node
    temp = Q->front;
    Q->front = Q->front->next;
    free(temp);
    return;
}
#endif
