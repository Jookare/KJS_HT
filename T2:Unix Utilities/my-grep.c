// Kurssi: Käyttöjärjestelmät ja systeemiohjelmointi
// Tekijä: Joona Kareinen
// Päivämäärä: (Aloitus) 	9.4.2021
// (Muokattu/Kommentoitu) 	16.4.2021
// (Lopetus) 					17.4.2021 
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

void searchFromFile(char *term,char *fName){
	FILE *file;
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t line_size;

	// opening file 
	if((file = fopen(fName, "r")) == NULL){
		printf("my-grep: cannot open file\n");
		exit(1);
	}

	// Using getline()-command to get line
	line_size = getline(&buffer, &buffer_size, file);
	while(line_size > 0){

		// Checking if read string contains searched 'string'
		if(strstr(buffer, term)){
			printf("%s", buffer);
		}		
	line_size = getline(&buffer, &buffer_size, file);
	}
	// Cleaning up
	free(buffer);
	buffer = NULL;
	fclose(file);
}

// You can input EOF with ctrl + D
void searchFromStdin(char *term){
	char read[SIZE]; 
	char *text = malloc(1);
	size_t read_len, text_len = 1;

	// With stdin we can use fgets
	while (fgets(read, SIZE, stdin) != NULL){
		read_len = strlen(read);

		// Checking if read string contains searched 'string'
		if(strstr(read, term)){

			// Mallocin memory for text string so we can concatenate all acceptable rows to it.
			
			if((text = realloc(text, (read_len + text_len))) == NULL) {
				printf("malloc failed\n");
				exit(1);
		  	}
			strcat(text, read);
			text_len = strlen(text);
		}
	}
	printf("%s", text);
}		


int main( int argc, char *argv[] ){
	switch(argc){
		// case 1 = no search term given and without it program can't operate
		case 1:
			printf("my-grep: searchterm [file ...]\n");
			exit(1);

		// case 2 = searchterm given so we can search if we find that from stdin
		case 2:
			searchFromStdin(argv[1]);
			break;

		// In default case we have 1 or more file to search from
		default:
			for (int i = 2; i < argc; i++){
				searchFromFile(argv[1], argv[i]);
			}
			break;
	}
	return (0);
}

