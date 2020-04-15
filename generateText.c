#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"circLinkedList_randRear.h"

//Fungsi mengosongkan isi list
void freeList(node** head, int n)
{
   node* temp;
   int i;

   for(i = 0; i < n; ++i){
        temp = *head;
       *head = (*head)->next;
       free(temp);
   }
}

//Fungsi mencari value dari key pada text
void searchValue(node **text, queue **key, int textLength){
	node *currText = randRear(*text,textLength);
	node *testText;
	node *currKey;
	int found = 0;

	while (found == 0){
		currKey = (*key)->front;
		testText = currText;

		while(currKey != NULL){

			//Kasus kata tidak sama
			if (strcmp(testText->word,currKey->word)!= 0)
				break;

			//Kasus kata sama
			currKey = currKey->next;
			testText = testText->next;
		}

		//Jika key ditemukan pada text
		if (currKey == NULL){
			found = 1;
		}
		else {
			currText = currText->next;
		}
	}
	//Print the value
	printf("%s ",testText->word);

	//Editing the key linked list
	dequeue(*key);
	enqueue(*key, testText->word);
}

//Fungsi membuat text baru
void generateText(node*text, int textLength, int word_count, int n_grams){
	queue *key = (queue*)malloc(sizeof(queue));
	key->front = NULL;
	key->rear = NULL;
	node *test = randRear(text,textLength);
	int i;

	//Generate Key dengan jumlah kata = n_gram
	for (i = 0; i < n_grams; i++)
	{
		enqueue(key,test->word);
		test = test->next;
	}

	//Generate Text dengan jumlah kata = word_count
	printf("... ");
	for (i = 0; i < word_count; ++i)
	{
		searchValue(&text,&key,textLength);
	}
	printf("... \n");

	freeList(&(key->front),n_grams);
}