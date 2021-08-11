#include <stdio.h>

int main(){
	int i=4;
	int* p = &i;
	printf("Values:\ni: %d, p: %d\n", i, *p);
	printf("Addresses:\ni: %p, p: %p\n", &i, p);
	*p = 32;
	printf("Post Reassignment:\ni: %d, p: %d\n", i, *p);


	int a[4] = {23,4,6,19};
	int j;

	for(j=0; j<4;j++){
		printf("&a[%d]: %p\n", j, &a[j]);
	}
	return 	0;
}
