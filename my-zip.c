/**************************************************************/
/*CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi      	*/
/*Tekijä: Akseli Törrönen					*/
/*Opiskelijanumero: 0542794					*/
/*Harjoitustyö: Unix utilities: my-zip.c			*/
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(int argc, char* argv[]){
	//checking the arguments
	if(argc < 2){fprintf(stderr, "my-zip: file1 [file2 ...]\n");exit(1);}
	FILE* in_file;
	int j, k;
	char buffer[MAX];
	char temp = 'a';
	int rleLen, len;

	for(j = 1; j < argc; j++){
		in_file = fopen(argv[j], "r");
		//Error handler
		if(in_file == NULL){fprintf(stderr, "cannot open file %s\n", argv[j]);exit(1);}
		//reading the file
		while(fgets(buffer, MAX, in_file) != NULL){
			
			len = strlen(buffer);
			for(k=0; k<len; k++){
				rleLen = 1;
				while(k + 1 < len && buffer[k] == buffer[k + 1]){
					rleLen++; //how many letters we have of a single character
					k++; //moving to the next letter in the buffer
				}
				temp = buffer[k]; //saving the letter into temp
				fwrite(&rleLen, 4, 1, stdout); //writing the number first
				fwrite(&temp, 1, 1, stdout); //writing the letter second
			}
		}
		fclose(in_file);
	}
	return 0;
}
