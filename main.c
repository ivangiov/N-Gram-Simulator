#include "function.h"

//Detect OS
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int main(){
	srand(time(0));
	
	node* linkedList;
     
	int textLength = 0;
	int n_gram;
	int random;
	int menu;
     
	aboutUs();
	
	printf("SELAMAT DATANG DI N-PROGRAM\n");
	printf("Program memiiliki tiga menu, yaitu input text eksternal, cetak kata-kata random dari n-gram, dan exit\n");

	menu = menux();
	while(menu != 3){
		if (menu == 1){//input file eksternal
			freeList(&linkedList, textLength);
			linkedList = (node*)malloc(sizeof(char));
			linkedList = NULL;
			printf("Masukkan nama file : ");
			char* filename = (char*)malloc(sizeof(char));
			scanf("%s", filename);
			textLength = fileHandling(filename, &linkedList);
			free(filename);
			printf("Banyaknya kata: %d\n",textLength);
			menu = menux();
			}
		else if(menu == 2){//mencetak kata-kata dari key n_gram
			if(textLength == 0){
				printf("File eksternal belum diinput, silakan input terlebih dahulu!\n");
				menu = 1;
				}
			else{
				printf("Masukkan banyaknya n pada n-gram: ");
				scanf("%d", &n_gram);
				while(n_gram < 2){
					printf("n harus bernilai sama dengan dua atau lebih\n");
					printf("Masukkan banyaknya n pada n-gram: ");
					scanf("%d", &n_gram);}
				printf("Masukkan jumlah kata random yang akan dicetak: ");
				scanf("%d", &random);
				generateText(linkedList, textLength, random, n_gram);
				printf("\nyay!");
				menu = menux();
				}
			}
		else if(menu == 3){//keluar
			printf("Terima kasih telah menggunakan program kami!\n");
			freeList(&linkedList, textLength);
			exit(1);
			}
		else{//pilihan salah
			printf("Masukkan input salah! Silakan input kembali");
			menu = menux();
			}
		}
	return(0);
 }
