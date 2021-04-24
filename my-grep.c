/**************************************************************/
/*CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi      	*/
/*Tekijä: Akseli Törrönen					*/
/*Opiskelijanumero: 0542794					*/
/*Harjoitustyö: Unix utilities: my-grep.c			*/
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(int argc, char* argv[]){
	//checking the amount of argumetns
	if(argc < 2 || argc > 3){printf("my-grep: searchterm [file ...]\n");exit(1);}
	FILE* fptr;
	char buffer[MAX];
	int temp;
	//reading stdin
	if(argc==2){
		fprintf(stdout, "exit with an integer\n");
		while(1){
			printf("Enter a string: ");
			/*if the string user entered can be turned into an integer the program exits with return value 0*/
			if(fscanf(stdin, "%d", &temp)){return 0;} 
			else{fgets(buffer, 256, stdin);
				if(strstr(buffer, argv[1]) != NULL){printf("%s",buffer);}//checking if there's a match
			}
			
		}
	
	}
	else{	

		fptr = fopen(argv[2], "r");
		//Error handler
		if(fptr == NULL){printf("my-grep: cannot open file\n");exit(1);}
		//reading the file 
		while(fgets(buffer, MAX, fptr) != NULL){
			if(strstr(buffer, argv[1]) != NULL){printf("%s",buffer);}
		}
	
		fclose(fptr);
	}
	return 0;
}

