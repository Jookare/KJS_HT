#include <stdio.h>
#include <stdlib.h>

#define SIZE 128

void readGivenFile(char *fName){
	FILE *file;
	char buffer[SIZE];

	// Opening file
	if((file = fopen(fName, "r")) == NULL){
		printf("Can't open file\n");
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
	}else{
		printf("Usage: my-cat: file [files]\n");
	}
	return (0);	
}
