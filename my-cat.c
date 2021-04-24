/**************************************************************/
/*CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi      	*/
/*Tekijä: Akseli Törrönen					*/
/*Opiskelijanumero: 0542794					*/
/*Harjoitustyö: Unix utilities: my-cat.c			*/
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int main(int argc, char* argv[]){
	//if no files specified, my-cat exits with value 0
	if(argc == 1){return 0;}
	FILE* fptr;
	char buffer[MAX];
	int i;
	//going through the list of files given
	for(i = 1; i<argc; i++){
		fptr = fopen(argv[i], "r");
		//Error handler
		if(fptr == NULL){fprintf(stderr, "my-cat: cannot open file %s\n",argv[i]);exit(1);}
		
		//reading the file and printing each line
		while(fgets(buffer, MAX, fptr) != NULL){
			printf("%s",buffer);
		}

		fclose(fptr);
	}
	return 0;
}
