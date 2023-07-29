// Kurssi: Käyttöjärjestelmät ja systeemiohjelmointi
// Tekijä: Joona Kareinen
// Päivämäärä: (Aloitus) 	26.1.2021 
// (Muokattu/Kommentoitu) 	16.4.2021
// (Lopetus) 					27.4.2021 
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#define SIZE 10

// Luodaan struct linkitettyä listaa varten
struct Node{
	char *text;
	struct Node *pNext;
};
typedef struct Node Node;


// Reading given file and creating linked list with read texts
Node *readFile(Node *pStart, char *fName) {
    Node *pEnd = NULL, *ptrNew;
    FILE *file;
    char read[SIZE];
	 char *temp = NULL, *str = NULL;	
	 size_t str_len = 0;

	// Opening file
	if ((file = fopen(fName, "r")) == NULL) {
			fprintf(stderr, "reverse: cannot open file '%s'\n", fName);
			exit(1);
		}
	while (fgets(read, SIZE, file) != NULL) {

		// saving read input to temp
		if((temp = malloc(strlen(read) + 1)) == NULL) {
	      fprintf(stderr, "malloc failed\n");
	      exit(1);
	  	}
		strcat(temp, read);

		// temp doesn't end with newline so we copy/concatenate temp to str
		if(temp[strlen(temp) - 1] != '\n'){
			str_len = str_len + strlen(temp);
			if((str = realloc(str, str_len + 1)) == NULL) {
				fprintf(stderr, "malloc failed\n");
				exit(1);
		  	}
			strcat(str, temp);
			free(temp);
		// line read so we add temp one last time and create new node
		}else{
			// Changing newline to 'null character'
			temp[strlen(temp) - 1] = '\0';
			str_len = str_len + strlen(temp);
			if((str = realloc(str, str_len + 1)) == NULL) {
				fprintf(stderr, "malloc failed\n");
				exit(1);
			}
			strcat(str, temp);
			free(temp);
			// allocating memory
		  	if((ptrNew=(Node*)malloc(sizeof(Node))) == NULL) {
		      fprintf(stderr, "malloc failed\n");
		      exit(1);
		  	}
			// allocating memory for our string 
			if((ptrNew->text = malloc(str_len+1)) == NULL) {
		      fprintf(stderr, "malloc failed\n");
		      exit(1);
		  	}
			// Copying read string to node text
	  		strcpy(ptrNew->text ,str);
			ptrNew->pNext = NULL;

			// first node in making
			if (pStart == NULL) {
		    	pStart = ptrNew;
		    	pEnd = ptrNew;
			// other nodes
			} else {
		    	pEnd->pNext = ptrNew;
		    	pEnd = ptrNew;
			}
			free(str);
			str = NULL;
			str_len = 0;
		}
	}
	fclose(file);
	return pStart;
}

Node *listMaker(Node *pStart){
	Node *pEnd = NULL, *ptrNew;
	char read[SIZE];
	char *temp = NULL, *str = NULL;	
	size_t str_len = 0;
	// Reading stdin until ctrl + d is called.
	while(fgets(read, SIZE, stdin) != NULL){
		
		// saving read input to temp
		if((temp = malloc(strlen(read) + 1)) == NULL) {
	      fprintf(stderr, "malloc failed\n");
	      exit(1);
	  	}
		strcat(temp, read);
		// temp doesn't end with newline so we copy/concatenate temp to str
		if(temp[strlen(temp) - 1] != '\n'){
			str_len = str_len + strlen(temp);
			if((str = realloc(str, str_len + 1)) == NULL) {
				fprintf(stderr, "malloc failed\n");
				exit(1);
		  	}
			strcat(str, temp);
			free(temp);
		// line read so we add temp one last time and create new node
		}else{
			temp[strlen(temp)-1] = '\0';
			str_len = str_len + strlen(temp);
			if((str = realloc(str, str_len + 1)) == NULL) {
				fprintf(stderr, "malloc failed\n");
				exit(1);
		  	}
			strcat(str, temp);
			free(temp);
			if((ptrNew = (Node*)malloc(sizeof(Node))) == NULL) {
				fprintf(stderr, "malloc failed\n");
		 		exit(1);
			}
			if((ptrNew->text = malloc(str_len+1)) == NULL) {
			   fprintf(stderr, "malloc failed\n");
			   exit(1);
		  	}
			strcpy(ptrNew->text ,str);

			ptrNew->pNext = NULL;
			// first node
			if (pStart == NULL) {
			    pStart = ptrNew;
			    pEnd = ptrNew;
			// other nodes
			} else {
			    pEnd->pNext = ptrNew;
			    pEnd = ptrNew;
			}
			free(str);
			str = NULL;
			str_len = 0;
		}
	}
 	return pStart;
}

// Reading linked list and printing texts to output file
void writeFile(Node *pStart, char *fName){
 	Node *ptr = pStart;
	FILE *file;
	if ((file = fopen(fName, "w")) == NULL) {
  		fprintf(stderr, "reverse: cannot open file '%s'\n",fName);
     	exit(1);
 	}
 	while (ptr != NULL){
     	fprintf(file, "%s\n", ptr->text);
     	ptr = ptr->pNext;
 	}
 	fclose(file);
}


// Reversing our linked list so we can read it again and just print every text attached to node
Node *Reverse(Node *pStart){
 	Node *ptrCurrent = pStart;
 	Node *ptrPrev = NULL;
 	Node *ptrNext = NULL;

	// with quick paint sketch you get the idea
 	while (ptrCurrent != NULL){
		// next node is next
		ptrNext = ptrCurrent->pNext;
		// current node's new next node is previous
		ptrCurrent->pNext = ptrPrev;
		// previous node is current node
		ptrPrev = ptrCurrent;
		// New current node is next node
		ptrCurrent = ptrNext;
	}
	pStart = ptrPrev;
	return pStart;
}

// Going through linked list and printing node texts
void Print(Node *pStart){
	Node *ptr = pStart;
	while (ptr != NULL){
		printf("%s", ptr->text);
		printf("\n");
		ptr = ptr->pNext;
	}
}

//https://stackoverflow.com/questions/12502552/can-i-check-if-two-file-or-file-descriptor-numbers-refer-to-the-same-file
// Ran given tests and well this solved one test
// Here we check if two files refer to the same file.
int checkFiles(char* file1, char* file2){
	FILE* f1;
	FILE* f2;
	if ((f1 = fopen(file1, "r")) == NULL) {
  		fprintf(stderr, "reverse: cannot open file '%s'\n",file1);
     	exit(1);
 	}
	if ((f2 = fopen(file2, "w")) == NULL) {
  		fprintf(stderr, "reverse: cannot open file '%s'\n",file2);
     	exit(1);
 	}
	int filed1 = fileno(f1);
	int filed2 = fileno(f2);

	struct stat stat1, stat2;
	if (fstat(filed1, &stat1) < 0){
		return -1;
	}
	if (fstat(filed2, &stat2) < 0){
		return -1;
	}
	return (stat1.st_dev == stat2.st_dev && stat1.st_ino == stat2.st_ino);
}

void freeMemory(Node *pStart)  {
	Node *ptr;
	while (pStart != NULL){
		ptr = pStart;
		pStart = pStart->pNext;
		free(ptr->text);
		free(ptr);
	}
}

int main( int argc, char *argv[] ){
	Node *pStart = NULL;
	switch(argc){
		case 1:
		  	pStart = listMaker(pStart);
         pStart = Reverse(pStart);
         Print(pStart);
			freeMemory(pStart);
         break;
     	case 2:
			pStart = readFile(pStart, argv[1]);
			pStart = Reverse(pStart);
			Print(pStart);
			freeMemory(pStart);
		   break;

      case 3:
			// Checking if files have same name
			if (strcmp(argv[1], argv[2]) == 0){
				fprintf(stderr, "reverse: input and output file must differ\n");
				exit(1);
			// Checking if given filenames point to same file
			}else if(checkFiles(argv[1], argv[2])){
				fprintf(stderr, "reverse: input and output file must differ\n");
				exit(1);
			// running program with input and output file
			}else{
				pStart = readFile(pStart, argv[1]);
				pStart = Reverse(pStart);
				writeFile(pStart, argv[2]);
				freeMemory(pStart);
		  		break;
      	}
		// printing error message since 3 files given
  		default:
      	fprintf(stderr, "usage: reverse <input> <output>\n");
      	exit(1);
	}
	return 0;
}
