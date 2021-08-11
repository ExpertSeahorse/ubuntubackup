#include <stdio.h>


int main(){
	char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
	
	char planets2[][8] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};

	planets[0][2] = 'k';

	int i;
	for(i=0; i<8; i++)
		printf("%s\n", planets2[i]);

	return 0;
}

