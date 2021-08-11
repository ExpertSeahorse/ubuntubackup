#include <stdio.h>
#define N 10


int find_largest(int a[], int n){
	int i, max_i = 0;
	
	for(i=1; i<n; i++)
		if (a[max_i] < a[i])
			max_i = i;
	
	return max_i;
}


void selection_sort(int a[], int n){
	int largest = 0, temp;  
	if (n==1)
		return;	
	largest = find_largest(a, n);

	temp = a[n-1];
	a[n-1] = a[largest];
	a[largest] = temp;
	
	n--;
	selection_sort(a, n);
}


int main(void){  
	int i;  
	int a[N];  

	printf("Enter %d numbers to be sorted: ", N);  
	for (i = 0; i < N; i++)    
		scanf("%d", &a[i]);  

	selection_sort(a, N);  

	printf("In sorted order:");  
	for (i = 0; i < N; i++)    
		printf(" %d", a[i]);  	

	printf("\n");  
	
	return 0;
}

