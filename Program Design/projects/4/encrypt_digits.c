#include <stdio.h>
// DAVID FELDMAN

void encrypt(int *a, int *b, int n){
	// Reads the input array (a) of size n, changes the digits, and writes them to a new array(b)
	int *i, *j;
	for(i=a; i<a+n; i++){
		j = b + (i-a);
		*j = (6+*i)%10;
	}	
}


void swap(int *p, int *q){
	// Swaps integers p and q
	int temp = *q;
	*q = *p;
	*p = temp;
}


int main(){
	// Creates an encrypted number based on the one passed to it

	int n, *i;
	// Collecting inputs
	printf("Enter the number of digits: ");
	scanf("%d", &n);

	int org[n], enc[n]; //original array and encrypted array

	printf("Enter the number: ");
	for(i=org; i<org+n; i++)
		scanf("%1d", i);

	encrypt(org, enc, n);

	swap(enc, enc+(n-1));

	// Prints the output
	printf("Output: ");
	for(i=enc; i<enc+n; i++)
		printf("%d", *i);

	printf("\n");
	return 0;
}
