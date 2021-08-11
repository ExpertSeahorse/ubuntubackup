#include <stdio.h>
#include <math.h>

#define PI 3.14259265

// double, from a function pointed to by f, with a double as a parameter
double integrate(double (*f)(double), double a, double b){
	double stepsize = 0.01, integral = 0.0, x;

	for(x=a+stepsize; x<=b ; x+=stepsize)	
		integral += stepsize*f(x);	// f function is passed paramater x
	return integral;
}


int main(){
	double result;
	result = integrate(sin, 0.0, PI/2);
	printf("integrating sin from 0.0 to pi/2: %.3lg\n", result);

	result = integrate(exp, 0.0, PI/2);
	printf("integrating exp from 0.0 to pi/2: %.3lg\n", result);

	result = integrate(sqrt, 0.0, PI/2);
	printf("Integrating sqrt from 0.0 to pi/2: %.3lg\n", result);

	return 0;
}
