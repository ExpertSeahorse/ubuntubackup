#include <stdio.h>

int sum (int (*f) (int), int start, int end);
int fact(int n);
int square(int n);
int cube(int n);


int main(){
	int start, end;

	printf("Enter start value: ");
	scanf("%d", &start);
	printf("Enter end value: ");
	scanf("%d", &end);

	int f_result = sum(fact, start, end);
	int s_result = sum(square, start, end);
	int c_result = sum(cube, start, end);
	printf("Sum of:\nFactorials: %d\nSquares: %d\nCubes: %d\n", f_result, s_result, c_result);
	return 0;
	//display the sum of factorials, the sum of squares, 
	//and the sum of cubes from start to endreturn 0;
}

int sum (int (*f) (int), int start, int end){
	int total=0, x;
	for(x=start+1; x<=end; x++)
		total+= f(x);
	return total;
}

int fact(int n){  
	if (n <= 1) return 1;  
	else return n * fact(n - 1);
}

int square(int n){  
	return n*n;
}

int cube(int n){  
	return n*n*n;
}

