#include <stdio.h>
/*	This program deletes a specified value from an array	
 *	David Feldman*/

int delete(int a[], int n, int value){
	// This function deletes all instances of a value from an array
	int i, count=0, temp_n;
	int temp_arr[n];
	// Moves every value from the original arrray to the new array, except for the values that the user wants deleted. The count var increases as more values are deleted.
	for(i=0;i<n;i++){
		if (a[i] != value)
			temp_arr[i-count] = a[i];
		else
			count++;
	}
	//This loop moves all of the values from the temp array back to the original array and fills the remaining space with the value the user wanted deleted, as per the project requirements.
	temp_n = n - count;
	for(i=0;i<n;i++){
		if (i<temp_n)
			a[i] = temp_arr[i];
		else
			a[i] = value;
	}

	return temp_n;	
}


int main(){
	int n, new_n, val, i;
	//Colecting input
	printf("Enter the length of the array: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter the values of the array: \n");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	printf("Enter the value to be deleted: ");
	scanf("%d", &val);
	
	// Runs the above function against the array
	new_n = delete(arr, n, val);
	
	// Outputs the array until the deleted values
	printf("Output arry : \n");
	for (i=0; i<new_n; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
