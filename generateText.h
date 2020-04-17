#include "generateText.c"

#ifndef GENERATETEXT_H
#define GENERATETEXT_H

//Fungsi Free List
/* Mengosongkan isi linked list
yang sudah tidak diakses*/
void freeList(node** head, int n);

//Fungsi Search Value
/* Mencari value dari key pada linked list*/
void searchValue(node **text, queue **key, int textLength);

//Fungsi Generate Text
/* Mencetak string text baru */
void generateText(node*text, int textLength, int word_count, int n_grams);

#endif
