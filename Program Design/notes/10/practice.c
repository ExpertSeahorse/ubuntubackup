#include <stdlib.h>
#include <stdio.h>


int main(){
	int n, i;
	printf("Enter the size of the array: ");
	scanf("%d", &n);

	int *a;
	a = malloc(n*sizeof(int));	//pointer = malloc(size);	//sizeof- return the # of bytes for a data type: int-4, char-1, double-8, struct-###, etc;
	if(a == NULL){
		printf("Memory alloation fail.");
		return 1;
	}
	// MUST FREE MEMORY BEFORE REASSIGNING. C WILL NOT PREFORM GARBAGE COLLECTION!
	printf("Enter %d array of numbers:\n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);

	free(a);
	return 0;
}
