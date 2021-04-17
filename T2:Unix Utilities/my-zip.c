// Kurssi: Käyttöjärjestelmät ja systeemiohjelmointi
// Tekijä: Joona Kareinen
// Päivämäärä: (Aloitus) 	9.4.2021
// (Muokattu/Kommentoitu) 	16.4.2021
// (Lopetus) 					17.4.2021 
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

void zipFile(int argc, char* argv[]){
	FILE* file;
	char read[SIZE];
	char *str = NULL;
	size_t str_len = 0;
	
	// Going through all the input files
	for (int i = 1; i < argc; i++){
		if((file = fopen(argv[i], "r")) == NULL){
			printf("my-zip: cannot open file\n");
			exit(1);
		}
		// Reading lines from file
		while (fgets(read, SIZE, file) != NULL){
			str_len = str_len + strlen(read);
			if((str = realloc(str, str_len + 1)) == NULL) {
				printf("malloc failed\n");
				exit(1);
		  	}
			strcat(str, read);
		}
		fclose(file);
	}
// Lets create variable i for moving character by character and also second variable k to keep track of repeated characters
	int k = 0;
	// We count number of characters in a row and then fwrite/print output
	for (int i = 0; i<strlen(str); i++){
		k = 1;
		while(i < strlen(str) - 1 && str[i] == str[i+1]){
			i++;
			k++;
		}
		fwrite((const void*) & k, sizeof(int), 1, stdout);
		//printf("%d", k);
		printf("%c", str[i]);
	}

	// freeing memory allocated to str
	free(str);
}

int main( int argc, char *argv[] ){
	switch(argc){
		// No file given so error message is printed
		case 1:
			printf("my-zip: file1 [file2 ...]\n");
			exit(1);
		default:
			zipFile(argc, argv);
		break;	
	}
	return (0);	
}
