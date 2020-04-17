#include "generateText.c"

#ifndef GENERATETEXT_H
#define GENERATETEXT_H

//Fungsi Free List
/* Mengosongkan isi linked list yang sudah tidak diakses */
/* Input: head dari linked list, jumlah node pada linked list */
/* Hasil: memori linked list dihapus */
void freeList(node** head, int n);

//Fungsi Search Value
/* Mencari value dari key pada linked list */
/* Input: node dari linked list text, queue key, jumlah kata pada teks */
/* Hasil: value di print, key digeser satu kata */
void searchValue(node **text, queue **key, int textLength);

//Fungsi Generate Text
/* Mencetak string text baru */
/* Input: node dari linked list teks, jumlah kata yg akan dicetak, jumlah n-gram */
/* Hasil: teks random */
void generateText(node*text, int textLength, int word_count, int n_grams);

#endif
