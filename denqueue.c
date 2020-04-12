#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char *word;
	struct node *next;
} node;

typedef struct queue{
	node *front, *rear;
} queue;

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

//Testing
// int main(){
//     queue Q1;
//     Q1.front =NULL;
//     Q1.rear=NULL;
//     enqueue(&Q1, "test1");
//     enqueue(&Q1, "test2");
//     enqueue(&Q1, "test3");    
//     enqueue(&Q1, "test4");    
//     printf("%s", Q1.front->word);    
//     dequeue(&Q1);
//     printf("%s", Q1.front->word);    
//     dequeue(&Q1);
//     printf("%s", Q1.front->word);
//     dequeue(&Q1);
//     printf("%s", Q1.front->word);
//     //dequeue(&Q1); //Pas fungsi ini dipanggil lagi, jadi error programnya
//     //enqueue(&Q1, "test1");
//     printf("%s", Q1.front->word);

//     return 0;
// }