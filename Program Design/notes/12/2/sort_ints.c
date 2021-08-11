#include <stdio.h>
#include <stdlib.h>


int int_compare(const void *p, const void *q){
/*
	int *p = p, *q = q;

	if(p < q)  return -1;
	else if(p == q)  return 0;
	else  return 1;
*/
	printf("%d\t%d\n", *(int *)p, *(int *)q);
	return *(int *)p - *(int *)q;
}


int main(){
	int n, i, *a;
	
	printf("Enter the length of the array: ");
	scanf("%d", &n);
	a = malloc(n*sizeof(int));

	for(i = 0; i < n; i++){                
		printf("Enter a number: ");                
		scanf("%d", &a[i]);        
	}

	qsort(a, n, sizeof(int), int_compare);        

	printf("In sorted order:\n");        
	for(i = 0; i < n; i++)                
		printf("%d\t", a[i]);        

	printf("\n");        
	return 0;
}
