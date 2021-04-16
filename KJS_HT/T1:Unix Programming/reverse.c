// Kurssi: Käyttöjärjestelmät ja systeemiohjelmointi
// Tekijä: Joona Kareinen
// Päivämäärä: (Aloitus) 26.1.2021 (Lopetus) 26.1.2021
// ** DISCLAIMER ** Koodi tulee olemaan englanniksi mutta kommentit suomeksi. 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

// Luodaan struct linkitettyä listaa varten
struct Node{
	char *text;
	struct Node *pNext;
};
typedef struct Node Node;

Node *readFile(Node *pStart, char *fName) {
    Node *pEnd = NULL, *ptrNew;
    FILE *file;
    char read[SIZE];
    printf("Reading file '%s'\n", fName);

	if ((file = fopen(fName, "r")) == NULL) {
			fprintf(stderr, "error: cannot open file",fName,"\n");
			exit(1);
		}
   size_t length = strlen(read);
	while (fgets(read, SIZE, file) != NULL) {
     	length = strlen(read);
     	if (read[length - 1] == '\n'){
      	read[--length] = '\0';
     	}
		if (read[0] == '\n'){
			break;
		}
     	if((ptrNew=(Node*)malloc(sizeof(Node))) == NULL) {
         fprintf(stderr, "malloc failed\n");
         exit(1);
     	}
  		ptrNew->text = malloc(strlen(read)+1);
  		strcpy(ptrNew->text ,read);
		ptrNew->pNext = NULL;
   	if (pStart == NULL) {
       	pStart = ptrNew;
       	pEnd = ptrNew;
   	} else {
       	pEnd->pNext = ptrNew;
       	pEnd = ptrNew;
		}
	}
	fclose(file);	
	printf("\nFile '%s' read.\n\n", fName);
	return pStart;
}

/*https://stackoverflow.com/questions/56606496/how-to-add-a-string-to-linked-list-in-c*/
Node *listMaker(Node *pStart){
	Node *pEnd = NULL, *ptrNew;
	char read[SIZE];
	while(fgets(read, SIZE, stdin) != NULL){
   	if((ptrNew = (Node*)malloc(sizeof(Node))) == NULL) {
			fprintf(stderr, "malloc failed\n");
	 		exit(1);
	   }
		ptrNew->text = malloc(strlen(read)+1);
		strcpy(ptrNew->text ,read);

	   ptrNew->pNext = NULL;
	   if (pStart == NULL) {
	       pStart = ptrNew;
	       pEnd = ptrNew;
	   } else {
	       pEnd->pNext = ptrNew;
	       pEnd = ptrNew;
	   }
	}
 	return pStart;
}

void writeFile(Node *pStart, char *fName){
 	Node *ptr = pStart;
	FILE *file;
	if ((file = fopen(fName, "w")) == NULL) {
  		fprintf(stderr, "error: cannot open file",fName,"\n");
     	exit(1);
 	}
 	while (ptr != NULL){
     	fprintf(file, "%s\n", ptr->text);
     	ptr = ptr->pNext;
 	}
 	fclose(file);
}

Node *Reverse(Node *pStart){
 	Node *ptrCurrent = pStart;
 	Node *ptrPrev = NULL;
 	Node *ptrNext = NULL;

 	while (ptrCurrent != NULL){
		ptrNext = ptrCurrent->pNext;
		ptrCurrent->pNext = ptrPrev;
		ptrPrev = ptrCurrent;
		ptrCurrent = ptrNext;
	}
	pStart = ptrPrev;
	return pStart;
}

void Print(Node *pStart){
	Node *ptr = pStart;
	while (ptr != NULL){
		printf(ptr->text);
		printf("\n");
		ptr = ptr->pNext;
	}
}

int main( int argc, char *argv[] ){
	Node *pStart = NULL;
	argc = 1;
	char fileIn[] = argv[0];
	char fileOut[] = argv[1];
	switch(argc){
		case 0:
         pStart = listMaker(pStart);
         pStart = Reverse(pStart);
         Print(pStart);
         break;
     	case 1:
		   // file = argv[0]
		   pStart = readFile(pStart, fileIn);
		   pStart = Reverse(pStart);
		   Print(pStart);
		   break;
      case 2:
      	if(argv[0] == argv[1]){
	          fprintf(stderr, "Input and output file must differ\n");
	          exit(1);
      	}else{
	          pStart = readFile(pStart, fileIn);
	          pStart = Reverse(pStart);
	          writeFile(pStart, fileOut);
      	}
   		break;
  		default:
         	fprintf(stderr, "usage: reverse <input> <output>\n");
         	exit(1);
	}
	printf("\nThanks for using my program! :)\n");
	return 0;
}
