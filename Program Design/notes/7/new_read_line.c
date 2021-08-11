#include <stdio.h>
#include <ctype.h>
#define STR_LEN 10


int read_line(char *str, int n){
	int i=0, ch;
	while ((ch=getchar()) != '\n'){
		if (i==0 && ch == ' ')
			continue;
		if(i < n){
			*str++= ch;
			i++;
		}
	}
	*str = '\0';		// terminates string
	return i;		//num char stored
}


int main(){
	int num_chars;
	char sen[STR_LEN+1];

	printf("Enter a sentence:");
	num_chars = read_line(sen, STR_LEN);	
	
	printf("You entered: %s, it has %d characters.\n", sen, num_chars);
	return 0;
}
