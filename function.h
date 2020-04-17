#include "integrating.h"
#include "generateText.h"
#include "queuehandling.h"
#include "fileHandling_aboutUs.h"
#include "circLinkedList_randRear.h"

//Prosedur untuk memunculkan loading bar
void loading(void);
void aboutUs();
void enqueue(queue *Q, char *text);
void dequeue(queue *Q);

// fungsi menambahkan node pada ujung akhir list
void addNode (char *kata, node **rear);
int fileHandling(char* filename, node **rear);

// fungsi untuk mendapatkan posisi rear secara acak dari list
node *randRear (node *rear, int total);

//Fungsi ngerandom node awal di text
node* randomHead(node **text,int textLength);

//Fungsi mencari value dari key pada text
void searchValue(node **text, queue **key, int textLength);

//Fungsi membuat text baru
void generateText(node *text, int textLength, int word_count, int n_grams);

//Fungsi untuk menampilkan menu
int menux();

void freeList(node **head, int n);
