#include <stdio.h>
// Read size, elements of an array
int main(){
	int n, i;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int arr[n];

	printf("Enter the %d elements of the array: \n", n);

	for (i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	int temp=arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
		
	printf("Printing array: ");
	for (i=0; i<n; i++){
		printf("Position %d: %d\n", i, arr[i]);
	}
	return 0;
}	
