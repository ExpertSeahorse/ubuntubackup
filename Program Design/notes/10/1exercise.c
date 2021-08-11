#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int read_line(char str[], int n){  
	int ch, i = 0;  

	while ((ch = getchar()) != '\n') {    
		if (i < n)      
			str[i++] = ch;  
	}  
	
	str[i] = '\0';  
	return i;
}


int compare_strings(const void *p, const void *q){
	return strcmp(*(char **)p, *(char **)q);
}


int main(){    
	char input_buffer[1001];    
	int length = 0, i;    
	char *sentences[50];    
	int num_sentences = 0;    

	while(1){
		printf ("Please type a sentence:\n");    
		read_line(input_buffer, 1000);    	
		length = strlen(input_buffer);    
		if (!length)
			break;

		sentences[num_sentences] = malloc(length+1);
		if(sentences[num_sentences] == NULL){
			printf("malloc failed");
			return 1;    
		}    

		strcpy (sentences[num_sentences], input_buffer);
		num_sentences++;
		if (num_sentences == 50) break;
	}
	
	qsort(sentences, num_sentences, sizeof(char *), compare_strings);   
	
	for(i=0; i < num_sentences; i++){
		printf("%s\n", sentences[i]);
		free(sentences[i]);		
	}

	return 0;
}
