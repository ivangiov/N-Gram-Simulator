#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* deklarasi circular linked list */
typedef struct node{ 
    char word[15];
    struct node *next;
}Node;

Node *AddNode (char*, Node *);
Node *randRear (Node *, int);

/* fungsi menambahkan node pada ujung akhir list */
Node *AddNode (char *kata, Node *rear){
    /* untuk menangani list kosong */
    if (rear == NULL){
        strcpy(rear->word,kata);
        rear->next = rear;
        return rear;
    }
    
    /* untuk menangani list yang tidak kosong */
    Node *temp = (Node *) malloc(sizeof(Node)); // deklarasi node baru

    strcpy(temp->word,kata);    // isi word dengan kata
    temp->next = rear->next;    // tambahkan node di ujung akhir list dan circular
    rear->next = temp;          // pastikan temp berada pada ujung akhir dengan pointer rear sebelumnya mengarah ke temp
    rear = temp;                // deklarasi rear baru pada temp
    
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
    printf("%d\n", rand_int);
    return rear;
}


int main(){
    srand(time(0));
    Node *rear = NULL; 
    rear = (Node *) malloc(sizeof(Node));
    
    rear = AddNode ("aku", rear);
    rear = AddNode ("lagi", rear);

    printf("%s", rear->word);
}