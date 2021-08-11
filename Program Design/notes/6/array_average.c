#include <stdio.h>


double array_average(int arr[], int n){

	int sum = 0;
	int *p;
	
	for (p = arr; p < arr+n; p++)
		sum += *p;
	return (double)sum/n;
	
}


int main(){
	int n=5;
	double avg;
	int a[] = {43,26,85,28,9};
	avg = array_average(a, n);

	printf("Average: %f\n", avg);

	return 0;
}
