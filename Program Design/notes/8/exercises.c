#include <stdio.h>


void char_count(){
	int sum;
	char buffer[1001], *p;
	FILE *fr;
	fr = fopen("test.txt", "r");
	while(fgets(buffer, 1001, fr) != NULL){
		printf("%s", buffer);
		for(p=buffer; *p != '\0'; p++)
			sum++;
	}
	fclose(fr);
	printf("\nThe number of characters is: %d\n", sum);
}


void array_dump(){
	int i;
	char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
	FILE *fp;
	fp = fopen("planets.txt", "w");
	for(i=0; i < 9; i++){
		fputs(planets[i], fp);
		fputs("\n", fp);
	}
	fclose(fp);
}


int main(){
	char_count();
	array_dump();
	return 0;
}
