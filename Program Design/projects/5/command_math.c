#include <stdio.h>
#include <stdlib.h>

// Reads input from the command line and runs the operation from the first parameter against the integers in the second and third parameters
// David Feldman

int main(int argc, char *argv[]){
//argc -> number of arguements
//argv[1] -> the operation; +, -, x, or /
//argv[2]&&argv[3] -> the integers to operate on

	// Validates the input
	if (argc < 4 || argc >5){	
		printf("Improper arguments. Expecting: <sign> ### ###\n");
		return 1;
	}
	
	int num1 = atoi(argv[2]), num2 = atoi(argv[3]);

	// prints the two integers combined by the operator
	printf("Output: ");
	if (*argv[1] == '+')
		printf("%d", num1 + num2);
	else if (*argv[1] == '-')
		printf("%d", num1 - num2);
	else if (*argv[1] == 'x')	
		printf("%d", num1 * num2);
	else if (*argv[1] == '/')	
		printf("%d", num1 / num2);
	else
		printf("Invalid option. Enter: +, -, x, or /.");
	
	printf("\n");
	return 0;
}	
