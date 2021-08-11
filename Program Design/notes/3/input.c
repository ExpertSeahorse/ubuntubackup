#include <stdio.h>

int main(){
	
	int num;
	do{
		printf("Please enter a number between 0 to 5, inclusive: ");
		scanf("%d",&num);

	}while(num < 0 || num > 5);
	/*
	while(num < 0 || num > 5){
		printf("%d is not within the range from 0 to 5, inclusive\n", num);
		printf("Please enter a number between 0 to 5, inclusive: ");
		scanf("%d",&num);
	}*/

	for(;;){ /* == while(1)*/

		printf("Please enter a number between 0 to 5, inclusive: ");
		scanf("%d",&num);
		if(num>=0||num<=5)
			break;
	}
	/*for(sum,i; i<=N; i++)*/
	return 0;
}
