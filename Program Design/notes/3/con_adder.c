#include <stdio.h>

int main(){

	int sum=0, count, i;
	do{
		printf("Please enter the number for the sum of the consecutive integers: ");
		scanf("%d", &count);
	}while(count<1);
	
	printf("Output:\n");	
	for(i=1; i <= count; i++){
		sum += i;

		if ((sum % 2) == 0)
			printf("%d\n", sum);

		if(sum > 100){
			printf("The sum exceeded 100.\n");
			return 0;
		}
			
	}
	return 0;
}
