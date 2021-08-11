#include <stdio.h>
/* Calculates the due day of an assignment based on the current day. It also accounts for weekends to make sure all assignments fall on a weekday */
/* David Feldman */
int main() {
	int day, due;
	printf("Enter today's day of the week: ");
	scanf("%d", &day);
	/* Validates the day of the week */
	if (0 > day || day > 7){
		printf("The inputted day %d is not a valid day", day);
		return 0;
	}
	
	
	printf("Enter the number of days for doing the work: ");
	scanf("%d", &due);
	int totaldue = due;
	/* Calculates the day of the due date */
	while (due > 0) {
		day += 1;
		due -= 1;
		if (day == 7) 
			day = 0;
	}
	/* If the day fell on a weekend, move it to Monday and update total due to reflect the change */
	while (day >= 5 || day == 0) {
		day += 1;
		totaldue += 1;
		if (day == 7)
			day = 0;
	}
	if (day == 1)
		printf("The due date is on Monday, which is in %d days\n", totaldue);
	else if (day == 2 )
		printf("The due date is on Tuesday, which is in %d days\n", totaldue);
	else if (day == 3)
		printf("The due date is on Wednesday, which is in %d days\n", totaldue);
	else if (day == 4)
		printf("The due date is on Thursday, which is in %d days\n", totaldue);
	else
		printf("A mistake has been made");
	return 0;
}
