#include <stdio.h>

int main(void) {
	int hours;
	double amount;
	double hourly_rate = 25.7;

	printf("Hourly rate is: %.2f\n", hourly_rate);
	
	printf("Enter the number of hours:\n");
	scanf("%d", &hours);

	amount = hours * hourly_rate;
	printf("\nHourly rate is: %.2f, and I've made %.2f this week.\n", hourly_rate, amount);

	return 0;
}
