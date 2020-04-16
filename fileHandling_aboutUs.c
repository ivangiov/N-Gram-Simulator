#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aboutUs();
int fileHandling(char* filename,node **rear);

int fileHandling(char* filename, node **rear){
    //Fungsi untuk memuat data dari file txt ke node dan menghitung jumlah kata
    //Input: nama file (string)
    //Output: jumlah kata

    char *word = malloc(sizeof(*word));
    char line[1024];
    char *newFilename = malloc(sizeof(*newFilename));
    int n;
    FILE *fp;

    n = 0;
    fp = fopen(filename,"r");
    
    //Jika file tidak ditemukan
    while (!fp){
        puts("File Not Found!");
        puts("Masukkan nama file kembali! : ");
        scanf("%s", newFilename);
        fp = fopen(newFilename, "r");
    }
    
    free(newFilename);
    //Jika pembacaan belum mencapai EOF
    while(fgets(line, 1024, fp)){

        line[strcspn(line, "\n")] = 0;                      //Menghilangkan \n
        word = strtok(line, " ");                           //Memisahkan kata dengan spasi

        //Menambahkan kata ke node
        while(word){
            //printf("%s | ",word); //for test only
            addNode(word, rear);
            n++;                                            //Menghitung jumlah kata
            word = strtok(NULL, " ");
        }
    }
    free(word);
    fclose(fp);
    return n;
}

void aboutUs(){
    //Prosedur untuk menampilkan judul program dan credits
    puts("");
    puts("----------------------------------------------------------------------------");
    puts(" _____         _    ______                _                 _              ");
    puts("|_   _|       | |   | ___ \\              | |               (_)             ");
    puts("  | | _____  _| |_  | |_/ /__ _ _ __   __| | ___  _ __ ___  _ _______ _ __ ");
    puts("  | |/ _ \\ \\/ / __| |    // _` | '_ \\ / _` |/ _ \\| '_ ` _ \\| |_  / _ \\ '__|");
    puts("  | |  __/>  <| |_  | |\\ \\ (_| | | | | (_| | (_) | | | | | | |/ /  __/ |   ");
    puts("  \\_/\\___/_/\\_\\__|  \\_| \\_\\__,_|_| |_|\\__,_|\\___/|_| |_| |_|_/___\\___|_|   ");
    puts("----------------------------------------------------------------------------");
    puts("");
    puts("\t\t\t\tCreated by:\n");
    puts("\t\t Dhanurangga Al-Fadh             (13218005)");
    puts("\t\t Ivan Giovanni                   (13218006)");
    puts("\t\t Sarah Alyaa Tsaabitah           (13218011)");
    puts("\t\t Christian Dinata                (13218024)");
    puts("\t\t Zulfikar Nima Arifuzzaki        (13218029)");
    puts("");
    puts("\t\t\t   Press Enter To Continue");
    while(getchar() != '\n');
    loading();
    system("cls");
}
