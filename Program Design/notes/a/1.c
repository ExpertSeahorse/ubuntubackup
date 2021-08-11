#include <stdio.h>

int main(){
	char b[] = "The quick", buffer[6];
	int i;
	for (i=0; i<6; i++)
		buffer[i] = b[i];
//	buffer[6] = '\0';
	printf("%s\n", buffer);
	
	return 0;
}
