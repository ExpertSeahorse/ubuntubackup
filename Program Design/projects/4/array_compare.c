#include <stdio.h>
// DAVID FELDMAN


void count_diff(int *a1, int *a2, int n, int *num_diff){
	// Counts the number of differences between arrays (of size n) a1 and a2 and leaves the number in num_diff
	int *p=a1, *q=a2, i;	
	
	for(i=0; i<n; i++){
		if (*p != *q){
			*num_diff += 1;}
		p++;
		q++;
	}
}

int main(){
	// Compares the values in two seperate arrays and returns the number of differences
	
	
	int n, *i, diff=0;
	// Collects input
	printf("Enter the size of the arrays: ");
	scanf("%d", &n);
	
	int arr1[n], arr2[n];
	
	printf("Enter the numbers of the first array:\t");
	for(i=arr1; i<arr1+n; i++){
		scanf("%d", i);}

	printf("Enter the numbers of the second array:\t");
	for(i=arr2; i<arr2+n; i++)
		scanf("%d", i);

	//see method
	count_diff(arr1, arr2, n, &diff);
	
	//printing outputs
	if (diff)
		printf("There are %d differences between the arrays.\n", diff);
	else
		printf("There are no differences between the arrays. \n");
	

	return 0;
}
