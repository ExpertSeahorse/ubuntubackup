#include <stdio.h>
#define N 10

int find_largest(int arr[], int n){
	int max_index=0, i;
	for(i=1; i<n; i++){
		if (arr[i] > arr[max_index])
			max_index = i;
	}
	return max_index;
}
	



int main(){
	int i, index_largest;
	int a[N];
	
	printf("Enter %d elements for the array: ", N);
	for(i=0; i<N; i++)
		scanf("%d", &a[i]);
	
	index_largest = find_largest(a, N);

	printf("The largest value is: %d at index %d\n", a[index_largest], index_largest);

	return 0;
}
