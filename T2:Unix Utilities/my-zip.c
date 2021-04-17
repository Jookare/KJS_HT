#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 512

void zipFile(int argc, char* argv[]){
	FILE* file;
	char read[SIZE];
	char *str;
	size_t str_len = 0;
	
	// Going through all the input files
	for (int i = 1; i < argc; i++){
		if((file = fopen(argv[i], "r")) == NULL){
			printf("wzip: cannot open file\n");
			exit(1);
		}
		// Reading lines from file
		while (fgets(read, SIZE, file) != NULL){
			// First time reading so we malloc memory for str and also copy read to str
			if (str_len == 0){
				str_len = strlen(read);
				str = malloc(str_len + 1);
				strcpy(str, read);
			// Afterwards we realloc more memory to str and concatenate read to str
			}else{
				str_len = str_len + strlen(read);
				str = realloc(str, str_len + 1);
				strcat(str, read);
			}
		}
		fclose(file);
	}
// Lets create variable i for moving character by character and also second variable k to keep track of repeated characters
	int i = 0;
	int k = 0;

	// If str length is 1 we can just print it out
	if (strlen(str) == 1){
		k = 1;
		fwrite((const void*) & k, sizeof(int), 1, stdout);
		printf("%s",str);

	// We count number of characters in a row and then fwrite/print output
	}else{
		for (i = 0; i<strlen(str); i++){
			k = 1;
			while(i < strlen(str) - 1 && str[i] == str[i+1]){
				i++;
				k++;
			}
			fwrite((const void*) & k, sizeof(int), 1, stdout);
			//printf("%d", k);
			printf("%c", str[i]);
		}
	}

	// freeing memory allocated to str
	free(str);
}

int main( int argc, char *argv[] ){
	switch(argc){
		// No file given so error message is printed
		case 1:
			printf("wzip: file1 [file2 ...]\n");
			exit(1);
		default:
			zipFile(argc, argv);
		break;	
	}
	return (0);	
}
