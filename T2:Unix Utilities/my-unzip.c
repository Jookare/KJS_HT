// Kurssi: Käyttöjärjestelmät ja systeemiohjelmointi
// Tekijä: Joona Kareinen
// Päivämäärä: (Aloitus) 	9.4.2021
// (Muokattu/Kommentoitu) 	16.4.2021
// (Lopetus) 					17.4.2021 
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define SIZE 10

void unzipFile(char *fName){
	FILE* file;
	int read;
	char ch;

	// Opening file
	if((file = fopen(fName, "r")) == NULL){
		printf("my-unzip: cannot open file\n");
		exit(1);
	}
	// 
	int c = 1;
	while (c == 1){
		// reading 4 bytes and transforming them to integer
		if (fread(&(read), sizeof(int) , 1, file) == 1){
			// reading 1 byte and printing it out as a character
			if (fread(&(ch), sizeof(char), 1, file) == 1){
			}
			for(int i = 0; i<read;i++){
				printf("%c", ch);
			}
		// File read so we change c to zero
		}else{
			c = 0;
		}
	}
	fclose(file);
}


int main( int argc, char *argv[] ){
	switch(argc){
		// Error message
		case 1:
			printf("my-unzip: file1 [file2 ...]\n");
			exit(1);
		default:
			for (int i = 1; i < argc; i++){
				unzipFile(argv[i]);
			}
		break;	
	}
	return (0);	
}
