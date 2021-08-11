#include <stdio.h>

void minmax(int *a, int n, int *max, int *min){
	int *p;
	*max=*min=*a;
	for (p=a; p < a+n; p++){
		if (*max < *p)
			*max = *p;
		else if (*min > *p)
			*min = *p;
	}
}

int main(){
	int max_a=0, min_a=0;
	int a[8] = {100, 65, 46, 13, 87, 14, 75, 54};

	minmax(a, 8, &max_a, &min_a);
	
	printf("Max: %d, Min: %d\n", max_a, min_a);

	return 0;
}
