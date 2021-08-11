#include <stdio.h>
#include <string.h>

#define NUM_CHARS 30


struct magformer{
	char shape[NUM_CHARS+1];
	char color[NUM_CHARS+1];
	int quantity;
};


int compare_magformer(struct magformer m1, struct magformer m2){
	if (strcmp(m1.shape, m2.shape)==0 && !strcmp(m1.color, m2.color)==0 && m1.quantity == m2.quantity)
		return 1;
	return 0;
}


int main(){
	struct magformer m1={"square", "pink", 5};
	printf("m1: %s %s %d\n\n", m1.shape, m1.color, m1.quantity);

	struct magformer m2;
	printf("Enter quantity: ");
	scanf("%d", &m2.quantity);
	printf("Enter shape: ");
	scanf("%s", m2.shape);
	strcpy(m2.color, "green");
	printf("\nm2: %s %s %d\n", m2.shape, m2.color, m2.quantity);

	m1=m2;
	printf("\nAfter copying...\nm1: %s %s %d\n", m1.shape, m1.color, m1.quantity);
	// Can't do any comparisons (==, <, >) need to make own compare func
	printf("%d", compare_magformer(m1,m2));	

	return 0;
}
