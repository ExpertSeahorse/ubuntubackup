#include <stdio.h>
#include <string.h>
//David Feldman
//This program reads an encrypted file and decrypts it into another file


void extract(char words[][101], int num_word, char *result){
	// Decodes the message by stripping he first character from every word and returning them as a string
	// words: an array of every word in the input file
	// num_word: the actual number of words
	// result: output; stores all of the first characters
	int i;
	for(i=0; i<num_word; i++){
		result[i] = words[i][0];
	}
	result[i] = '\0';
}


int main(){
	char file_name[101], words[1001][101], result[1001];
	int i=0;

	// Gets the name of the encrypted file
	printf("Enter the name of the file: ");
	scanf("%s", file_name);

	FILE *fin = fopen(file_name, "r");
	if(fin==NULL){
		printf("Error opening file\n");
		return 1;
	}
	
	// Reads the encrypted file
	while(!feof(fin) && !ferror(fin)){
		if (fscanf(fin, "%s", words[i])==1)
			i++;
	}
	
	// Decodes the message
	extract(words, i, result);

	// Writes the decoded message to a file with the same name as the encrypted file, but with".dcf" at the end
	strcat(file_name, ".dcf");
	FILE *fout = fopen(file_name, "w");
	if(fout==NULL){
		printf("Error opening file\n");
		return 1;
	}

	fprintf(fout, "%s", result);
	printf("Output file name: %s\n", file_name);

	fclose(fin);
	fclose(fout);

	return 0;
}
