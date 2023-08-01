// Kurssi: Käyttöjärjestelmät ja systeemiohjelmointi
// Tekijä: Joona Kareinen
// Päivämäärä: (Aloitus) 	9.4.2021
// (Muokattu/Kommentoitu) 	16.4.2021
// (Lopetus) 					17.4.2021 
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 128

void readGivenFile(char *fName){
	FILE *file;
	char buffer[SIZE];

	// Opening file
	if((file = fopen(fName, "r")) == NULL){
		printf("my-cat: cannot open file\n");
		exit(1);
	}

	// Reading lines from file and printing them out
	while (fgets(buffer, SIZE, file) != NULL){
		printf("%s", buffer);
	}
	fclose(file);
}


int main( int argc, char *argv[] ){
	// If argument count is more than 1 then we can operate our program
	if (argc > 1){
		for (int i = 1; i < argc; i++){
			readGivenFile(argv[i]);
		}
	}
	return (0);	
}
