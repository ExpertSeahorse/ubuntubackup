#include <stdio.h>

// This program finds the index of the first orrurance of a desired value
// David Feldman

int search(int a[], int n, int value){
// This function finds the index of the first orrurance of a desired value or returns -1 is the value is not in the array.
	int i;
	// If this value is equal to the value the program is searching for, return it's positon.
	for(i=0;i<n;i++)
		if(value == a[i])
			return i;
	return -1;
}


int main(){
	int n, val, i, out;
	// Collecting input
	printf("Enter the length of the array: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter the values of the array: \n");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	printf("Enter the desired value: ");
	scanf("%d", &val);

	// Running the above function against the array
	out = search(arr, n, val);

	// Prints the index of the first occurance
	printf("Output: %d\n", out);

	return 0;
}
