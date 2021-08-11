#include <stdio.h>

int main(void) {
	
	int num_quarters = 6, num_dimes = 10, num_nickles = 3, num_pennies = 2;
	
	int whole_amount = num_quarters * 25 + num_dimes * 10 + num_nickles * 5 + num_pennies * 1;
	double real_amount = num_quarters * .25 + num_dimes * .10 + num_nickles * .05 + num_pennies * .01;
	printf("The total amount of money is $%.2f or %d cents\n", real_amount, whole_amount);
	return 0;

}
