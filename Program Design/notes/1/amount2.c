#include <stdio.h>

#define Q 25
#define D 10
#define N 5
#define P 1

int main(void) {
	
	int num_quarters = 0, num_dimes = 0, num_nickles = 0, num_pennies = 0;
	
	printf("Enter the number of quarters:\n");
	scanf("%d", &num_quarters);

	printf("Enter the number of dimes:\n");
	scanf("%d", &num_dimes);

	printf("Enter the number of nickles:\n");
	scanf("%d", &num_nickles);

	printf("Enter the number of pennies:\n");
	scanf("%d", &num_pennies);

	int amount = num_quarters * Q + num_dimes * D + num_nickles * N + num_pennies * P;

	double dollar_amount = amount / 100.0;

	printf("The total amount of money is $%.2f or %d cents\n", dollar_amount, amount);
	return 0;

}
