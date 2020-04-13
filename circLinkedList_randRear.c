#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* deklarasi circular linked list */
typedef struct node{ 
    char *word;
    struct node *next;
}node;

node *AddNode (char*, node **);
node *randRear (Node *, int);

/* fungsi menambahkan node pada ujung akhir list */
Node *AddNode (char *kata, Node **rear){
    // deklarasi node baru
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->word = (char*)malloc(sizeof(char));
    strcpy(temp->word,kata);

    /* untuk menangani list kosong */
    if (rear == NULL){
        *rear = temp;
        (*rear)->next = *rear;
        return rear;
    }
    
    /* untuk menangani list yang tidak kosong */
    strcpy(temp->word,kata);    // isi word dengan kata
    temp->next = (*rear)->next;    // tambahkan node di ujung akhir list dan circular
    (*rear)->next = temp;          // pastikan temp berada pada ujung akhir dengan pointer rear sebelumnya mengarah ke temp
    *rear = temp;                // deklarasi rear baru pada temp
    
    return rear;
}

/* fungsi untuk mendapatkan posisi rear secara acak dari list */
Node *randRear (Node *rear, int total){
    int rand_int;
    int i;
    rand_int = (rand() % (total - 0 + 1)); // generate random integer from 0 to total
    i = rand_int;
    rear = rear->next;

    /* randomize new position of rear */
    while (i != 0){ 
        rear = rear->next;
        i--;
    }
    
    return rear;
}

