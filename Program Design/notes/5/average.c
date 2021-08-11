#include <stdio.h>

double array_avg(int arr[], int n){
	int i, sum=0;
	double average;
	for(i=0; i<n; i++)
		sum += arr[i];
	average = (double)sum/n;
	return average;
}


int main(){
	int a[5] = {5,8,6,3,2};
	double average;
	average = array_avg(a, 5);
	printf("The average is: %f\n", average);



	int h = 25;
	int *p=&h;
	printf("This is P: %p\n", &p);
	return 0;
}
