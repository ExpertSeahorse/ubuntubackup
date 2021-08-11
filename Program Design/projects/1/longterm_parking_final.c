#include <stdio.h>

int main() {

	int hours, minutes, day_fee = 0, min_fee = 0;
	
	printf("Enter hours parked: ");
	scanf("%d", &hours);
	
	printf("Enter minutes parked: ");
	scanf("%d", &minutes);

	minutes = minutes + hours * 60;
	
	/*This part is for day counter*/
	while (minutes > 1440) {
		day_fee += 18;
		minutes -= 1440;
	}

	/* this part is for remainder*/
	if (day_fee ==0) {
		if (minutes <= 60) {
			min_fee = 0;
		}
		else {
			min_fee += 4;
			minutes -= 80;
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
	int fee = min_fee + day_fee;
	printf("The total fee is: %d\n", fee);
	
	return 0;
}
