/**************************************************************/
/*CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi      	*/
/*Tekijä: Akseli Törrönen					*/
/*Opiskelijanumero: 0542794					*/
/*Harjoitustyö: Unix utilities: my-unzip.c			*/
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(int argc, char* argv[]){
	//checking the amount of arguments
	if(argc < 2){printf("my-unzip: file1 [file2 ...]\n");exit(1);}
	FILE* zipped_file;
	char buffer[MAX];
	int count=1, temp=1, i;
	for(i = 1; i<argc; i++){
		zipped_file = fopen(argv[i], "r");
		//Error handler
		if(zipped_file == NULL){fprintf(stderr, "cannot open file %s\n", argv[i]);exit(1);}
		
		//as long as fread is able to read the file temp is going to have the value 1;
		while(temp == 1){
			temp = fread(buffer, sizeof(int), 1, zipped_file);
			count = buffer[0];//saving the count to count
			temp = fread(buffer, sizeof(char), 1, zipped_file);
			for(int i = 0; i<count; i++){printf("%c", buffer[0]);}/*printing the character as many
										times as previously specifed*/
		}
		fclose(zipped_file);
	}
	return 0;
}
