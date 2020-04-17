#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>

#ifndef DATATYPE_H
#define DATATYPE_H
/* deklarasi circular linked list */
typedef struct node{ 
    char *word;
    struct node *next;
}node;

typedef struct queue{
	node *front, *rear;
} queue;

#endif
