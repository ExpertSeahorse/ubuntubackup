#include <stdio.h>
#include <string.h>

// Parameters allow for information to be passed into the script
int main(int argc, char *argv[]){

	char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
	
	/*char planets2[][8] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};

	planets[0][2] = 'k';*/

	int i;
	for(i=0; i<8; i++){
		if(strcmp(planets[i], argv[1]) == 0){
			printf("It is a planet!\n");
			return 0;
		}
	}
	printf("It is not a planet.\n");
		
	return 0;
}

