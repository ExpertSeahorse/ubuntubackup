#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int find_largest(int a[], int n){   
	int largest_index = 0;    
	int i;   
	for (i = 1; i < n; i++)    
		if (a[i] > a[largest_index])      
			largest_index = i;   
	return largest_index;
}


void selection_sort(int a[], int n){  
	int largest = 0, temp;  
	if (n == 1)   
		 return;  
	largest = find_largest(a, n);  
	if (largest < n - 1) {    
		temp = a[n-1];    
		a[n-1] = a[largest];    
		a[largest] = temp;  
	}  
	selection_sort(a, n - 1);
}


int main(int argc, char *argv[]){  
	int i;  
	int a[argc-1];
  
	for (i = 1; i < argc; i++)    
		a[i-1] = atoi(argv[i]);

	printf("\n");  
	
	selection_sort(a, argc-1); 

	printf("In sorted order:");  
	for (i = 0; i < argc-1; i++){    
		printf(" %d", a[i]);  
	}

	printf("\n");  
	return 0;}
	
