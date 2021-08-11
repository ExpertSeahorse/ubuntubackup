#include <stdio.h>
/* This program reads an input and returns all of the numbers.
 * David Feldman*/
int main(){
	printf("Input: ");
	char ch;
	/* Reads the input and ends at the newline character */
	while((ch = getchar()) != '\n'){
		/* If the character is between 0 and 9, it gets printed */
		if (ch >= '0' && ch <= '9')
			printf("%c", ch);
	}
	printf("\n");
	return 0;
}
