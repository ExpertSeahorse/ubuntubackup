#include <stdio.h>
#include <ctype.h>
#define N 50


void extract(char *str1, char *str2){

	char *p, *q = str2;
	for(p=str1; *p != '\0'; p++)
		if (*p >= '0' && *p <= '9')
			*q++ = *p;	// *q = *p; then q++
	*q = '\0';	
}


int read_line(char *str, int n){
	int i=0, ch;
	while ((ch=getchar()) != '\n')
		if(i < n){
			*str++= ch;
			i++;
		}
	*str = '\0';		// terminates string
	return i;		//num char stored
}


int main(){
	printf("Input: \n");
	//char *str1 = "as9d8f78sf9a7df097";
	char str1[N+1];
	char str2[N+1];
	int n;
	// Read a line of input
	n = read_line(str1, N);
	extract(str1, str2);

	printf("Output: %s", str2);

	printf("\n");
	return 0;
}
