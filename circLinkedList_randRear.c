#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* deklarasi circular linked list */
typedef struct node{ 
    char *word;
    struct node *next;
}node;

node *AddNode (char*, node *);
node *randRear (node *, int);

/* fungsi menambahkan node pada ujung akhir list */
void AddNode (char *kata, node **rear){
   
    node *temp = (node*)malloc(sizeof(node));   // deklarasi node baru
    temp->word = (char*)malloc(sizeof(char));   // alokasikan memori untuk word
    strcpy(temp->word,kata);                    // isi word dengan kata

    /* untuk menangani list kosong */
    if (*rear == NULL){
        *rear = temp;
        (*rear)->next = *rear;
        return;
    }
    
    /* untuk menangani list yang tidak kosong */
        
    temp->next = (*rear)->next;    // tambahkan node di ujung akhir list dan circular
    (*rear)->next = temp;          // pastikan temp berada pada ujung akhir dengan pointer rear sebelumnya mengarah ke temp
    *rear = temp;                // deklarasi rear baru pada temp
    
    return;
}

/* fungsi untuk mendapatkan posisi rear secara acak dari list */
node *randRear (node *rear, int total){
    srand(time(0));
    int rand_int;
    int i;
    rand_int = (rand() % (total)); // generate random integer from 0 to total
    i = rand_int;
    rear = rear->next;             // move rear to the first node of list (usually head)

    /* randomize new position of rear */
    while (i != 0){ 
        rear = rear->next;
        i--;
    }

    return rear;
}