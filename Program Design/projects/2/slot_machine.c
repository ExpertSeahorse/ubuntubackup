#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int bal, num1, num2, num3, choice;
	srand(time(NULL));

	printf("Enter your initial balance in cents: ");
	scanf("%d", &bal);
	do{
		printf("\n");
		int i;
		for(i=0; i < 3; i++){
			int num = rand() % 13;

			switch(num){
			case 0:
				printf("Pineapple");
				break;
						
			case 1:
				printf("Kiwi");
				break;
			
			case 2:
				printf("Apple");
				break;

			case 3:
				printf("Orange");
				break;

			case 4:
				printf("Lime");
				break;

			case 5:
				printf("Peach");
				break;

			case 6:
				printf("Lemon");
				break;

			case 7:
				printf("Pear");
				break;

			case 8:
				printf("Banana");
				break;

			case 9:
				printf("Cherry");
				break;

			case 10:
				printf("Grape");
				break;

			case 11:
				printf("Blueberry");
				break;

			case 12:
				printf("Blackberry");
				break;

			case 13:
				printf("Apricot");
				break;

			}
			printf(" ");
			if (!num1)
				num1 = num;
			else if (!num2)
				num2 = num;
			else if (!num3)
				num3 = num;
		}
		printf("\n");	
		if (num1 == num2 && num2 == num3){
			printf("Congratulations! You have won 100 cents!");
			bal += 100;
		}
		else
			bal -= 5;
		printf("Remaining balance: %d cents.\nPress 1 to play again or 0 to quit:", bal);
		scanf("%d", &choice);
	}while(choice && bal >= 5);

	printf("Thank you for playing!\nRemaining balance: %d cents.\n", bal);
	return 0;
}
