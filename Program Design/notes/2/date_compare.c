#include <stdio.h>

int main() {
	int m1, d1, y1, m2, d2, y2, first_earlier;
	printf("Enter the first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &m1, &d1, &y1);
	
	
	printf("Enter the second date (mm/dd/yy): ");
	scanf("%d/%d/%d", &m2, &d2, &y2);
	

	if (y1 == y2){
		if (m1 == m2) {
			if (d1 < d2)
				first_earlier = 1;
			else
				first_earlier = 0;
		}
		else if (m1 < m2)		
			first_earlier = 1;
		else
			first_earlier = 0;
	}
	else if (y1 < y2)
		first_earlier = 1;
	else
		first_earlier = 0;
	
	if (first_earlier)
		printf("The first date is earlier\n");
	else
		printf("The second date is earlier\n");
	return 0;
}
