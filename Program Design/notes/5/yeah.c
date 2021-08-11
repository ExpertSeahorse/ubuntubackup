#include <stdio.h>


void find_two_largest(int a[], int n, int *largest, int *second_largest){
	int i;
	int large, large2;
	large = large2 = a[0];
	for(i=0; i<n; i++){
		if (a[i] > large){
			large2 = large;
			large = a[i];
		}
		else if (a[i] > large2 && a[i] < large)
			large2 = a[i];
	}
	*largest = large;
	*second_largest = large2;
}


int main(){
	int i, n, max, second_max;

	printf("Enter the size of the array:");
	scanf("%d", &n);

	int arr[n];
	printf("Enter the values in the array:\n");
	for (i=0; i<n; i++)	
		scanf("%d", &arr[i]);

	find_two_largest(arr, n, &max, &second_max);

	printf("The largest value is %d, the second largest value is %d.\n", max, second_max);

	return 0;
}
