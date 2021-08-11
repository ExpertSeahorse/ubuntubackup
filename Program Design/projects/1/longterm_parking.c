#include <stdio.h>

/*David Feldman
 * This program finds the total fee for parking at an airport for a given number of hours and minutes*/

int main() {
	
	/*day_fee is used for the daily logic, while the min fee is used for the minute based logic*/
	int hours, minutes, day_fee = 0, min_fee = 0;
	
	printf("Enter hours parked: ");
	scanf("%d", &hours);
	
	while (hours < 0) {
		printf("Please enter a valid time: ");
		scanf("%d", &hours);
	}
	
	printf("Enter minutes parked: ");
	scanf("%d", &minutes);


	while (minutes < 0) {
		printf("Please enter a valid time: ");
		scanf("%d", &minutes);
	}

	minutes = minutes + hours * 60;
	
	/*This part handles entire days*/
	while (minutes > 1440) {
		day_fee += 18;
		minutes -= 1440;
	}

	/* this part handles within one dat*/
	if (day_fee ==0) {
		if (minutes <= 60) {
			min_fee = 0;
		}
		else {
			while (minutes > 0) {
				min_fee +=2;
				minutes -= 20;
			}
			if (min_fee > 18)
				min_fee = 18;
		}
	}
	else {
		while (minutes > 0) {
			min_fee +=2;
			minutes -= 20;
		}
		if (min_fee > 18)
			min_fee = 18;
	}

	/*The output chunk*/
	int fee = min_fee + day_fee;
	printf("The total fee is: $%d\n", fee);
	
	return 0;
}
