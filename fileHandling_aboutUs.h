#include "fileHandling_aboutUs.c"

#ifndef FILEHANDLING_ABOUTUS_H
#define FILEHANDLING_ABOUTUS_H

//Fungsi fileHandling
/* Fungsi untuk memuat data dari file txt ke circular linked list dan menghitung total jumlah kata */
int fileHandling(char* filename,node **rear);

//Prosedur aboutUs
/* Prosedur untuk menampilkan judul program dan credits */
void aboutUs();

#endif
