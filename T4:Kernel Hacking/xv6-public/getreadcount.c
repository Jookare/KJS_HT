// Kurssi: Käyttöjärjestelmät ja systeemiohjelmointi
// Tekijä: Joona Kareinen
// Päivämäärä: (Aloitus) 	9.4.2021
// (Muokattu/Kommentoitu) 	16.4.2021
// (Lopetus) 					17.4.2021 
//

#include "types.h"
#include "user.h"

// Got some help for this atoi from gfg.
// https://www.geeksforgeeks.org/write-your-own-atoi/
// changes the argument from str to int.
int myAtoi(char* str){
	int result = 0;
	
	for (int i = 0; str[i] != '\0'; i++){
		result = result * 10 + str[i] - '0';
	}
	return result;
}


int main(int argc, char *argv[])
{
// only one arg so we run program normally
	if (argc == 1){
		printf(1, "Number of read calls: %d\n", getreadcount());

// Two arguments so we check if the second argument equals zero (keyword for resetting counter)
	}else if(argc == 2){
		int arg = myAtoi(argv[1]);
		if (arg == 0){
			resetreadcount();
			printf(1, "readcount reset\n");

// Wr print 'error' message and also hint to user.
		}else{
			printf(1, "Unknown argument %s.\n", argv[1]);
			printf(1, "To reset use argument 0.\n");
		}

// If more than 2 arguments then we print this error message.
	}else{
		printf(1,"Usage: getreadcount: [arg]\n");
	}
	exit();
}
