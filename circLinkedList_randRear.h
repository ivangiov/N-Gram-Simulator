#include "circLinkedList_randRear.c"

#ifndef CIRCLINKEDLIST_RANDREAR_H
#define CIRCLINKEDLIST_RANDREAR_H

//Fungsi AddNode
/* Generate Circular Linked List yang menyimpan kata per kata hasil parsing pada tiap node */
void AddNode (char *kata, node **rear);

//Fungsi randRear
/* Mengacak posisi rear dari Circular Linked List yang kemudian dijadikan head pada list */
node *randRear (node *rear, int total);

#endif
