#include <stdio.h>


int main(){
	char buffer[1001];
	FILE * fp, *fw;
	fp = fopen("filename.txt", "r");	// r- read; w- write; a- append
	fw = fopen("dump.txt", "w");

	if(fp == NULL){
		printf("Error opening file.");
		return 1;
	}
	// Prints all lines in file with #char <= 1000
	while(fgets(buffer, 1001, fp) != NULL){
		printf("%s", buffer);
		fputs(buffer, fw);
	}

	fclose(fp);	
	fclose(fw);
	return 0;
}
