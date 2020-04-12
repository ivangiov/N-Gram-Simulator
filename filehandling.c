#include <stdio.h>
#include <string.h>

int fileHandling(char* filename){
    //Fungsi untuk memuat data dari file txt ke node dan menghitung jumlah kata
    //Input: nama file (string)
    //Output: jumlah kata

    char *word;
    char line[1024];
    int n;
    FILE *fp;

    n = 0;
    fp = fopen(filename,"r");

    if (!fp){
        puts("File Not Found!");
        return (-999);
    }
    
    while(fgets(line, 1024, fp)){

        line[strcspn(line, "\n")] = 0;
        word = strtok(line, " ");
        
        
        while(word){
            //printf("%s | ",word); //test
            //addnode(word);
            n++;
            word = strtok(NULL, " ");
        }
    }
    fclose(fp);
    return n;
}
