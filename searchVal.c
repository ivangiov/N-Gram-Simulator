#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char word[15];
	struct node *next;
} node;

typedef struct queue{
	node *front, *rear;

} queue;

//Test
node* randomHead(node **text,int n){
	int r = (rand() % n) + 1;
	int i = 0;
	node *head = *text;

	//Mencari node ke-r
	for(i = 0; i < r; i++){
		head = head->next;
	}

	return (head);
}

//Fungsi mencari value dari key pada text
void searchValue(node **text, queue **key, int n){
	node *currText = randomHead(text,n);
	node *testText;
	node *currKey;
	int found = 0;

	while (found == 0){
		currKey = (*key)->front;
		testText = currText;

		while(currKey!=NULL){

			//Kasus kata tidak sama
			if (strcmp(testText->word,currKey->word)!=0)
				break;

			//Kasus kata sama
			currKey = currKey->next;
			testText = testText->next;
		}

		//Jika key ditemukan pada text
		if (currKey==NULL){
			found = 1;
		}
		else {
			currText = currText->next;
		}
	}

	//Print the value
	printf("%s ",testText->word);

	//Editing the key linked list
	dequeue(key);
	enqueue(key, testText->word);
}
