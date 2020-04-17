#include "datatype.c"

#ifndef INTEGRATING_C
#define INTEGRATING_C

int menux(){
	int output;
	printf("\nPilihan menu: \n");
	printf("1. Input File Eksternal\n");
	printf("2. Cetak kata random\n");
	printf("3. Exit\n");
	printf("Pilihan menu: ");
	scanf("%d", &output);
	return(output);
}

void loading(void){
    int i;
    puts("\nPlease wait Loading ...");
    for(i=0; i<76; ++i){
        #ifdef _WIN32
        Sleep(30);
        #else
        usleep(30*1000);
        #endif
        printf("%c", 219);
    }
    puts("");
}

#endif
