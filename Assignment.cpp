#include <stdio.h>
#include <stdlib.h>

int choice = 0;
	
void printDetail(){
	printf("*************************************************\n");
	printf("\n");
	printf("* Date of Examination:\t 16/07/2019 \t\t*\n");
	printf("* Student Name:\t\t BUI ANH HUY \t\t*\n");
	printf("* Student Number:\t SE140028 \t\t*\n");
	printf("* BATCH:\t\t K14 \t\t\t*\n");
}

void printTaskChoice(){
	printf("* Please select the number for appropriate tasks*\n");
	printf("*\t 1. Quit program \t\t\t*\n");
	printf("*\t 2. Question 2 \t\t\t\t*\n");
	printf("*\t 3. Question 3 \t\t\t\t*\n");
	printf("\n");
}

void choiceMenu(){
	printDetail();
	printTaskChoice();
	printf("*************************************************\n");
	printf("\n");
	printf("* Your Choice: ");
	scanf("%d", &choice);
	printf("\n");
	fflush(stdin);
	system("CLS");
}
int calculateLeastCommonMultiple(int numberOne, int numberTwo){
	int result = 0;
	for (int i = 1; i <= numberTwo; i++){
		if ((numberOne*i)%numberTwo == 0) {
			return result = numberOne*i;
		}
	}
}

int calculateBinary(int n, int array[]){
	int temp = n;
	for (int i = 7 ; i >= 0; i--) {
		if (temp % 2 == 1) {
			array[i] = 1;
			temp = (temp - 1) / 2;
		} else {
			array[i] = 0;
			temp = temp / 2;
		}
	}
}
main(){
	choiceMenu();
	do {
		switch(choice) {
		case 1:
		printDetail();
		printf("\n");
		printf("*************************************************\n");
		printf("\n");
		printf("QUITTING PROGRAM !!!");
		break;
		
		case 2:
			{	
				printDetail();
				printf("\n");
				printf("*************************************************\n");
			
				int numberOne, numberTwo;
				
				printf("INPUT NUMBER 1: ");
				scanf("%d", &numberOne);
				printf("INPUT NUMBER 2: ");
				scanf("%d", &numberTwo);
				int result = calculateLeastCommonMultiple(numberOne,numberTwo);
				printf("\n");
				printf("The least common multiple of %d and %d is %d\n", numberOne, numberTwo, result);
				printf("\n");
				
				printf("PRESS ANY KEY TO CONTINUE ...");
				fflush(stdin);
				getchar();
				system("CLS");
				break;
			}
	

		
		case 3:
			{
				printDetail();
				printf("\n");
				printf("*************************************************\n");
				int n = 0;
				do {
				printf("INPUT NUMBER(0 - 127): ");
				scanf("%d",&n);
			} while (n > 127 || n <0);
				int array[8];
				calculateBinary(n, array);
				printf("Value Converted: ");
				for (int i = 0; i < 8; i++){
					printf("%d",array[i]);
				}
				printf("\n");
				printf("\n");
				printf("PRESS ANY KEY TO CONTINUE ...");
				fflush(stdin);
				getchar();
				system("CLS");
				
			break;
			}
		
	
	}
	if (choice != 1) {
			main();
	}

	
	}	while (choice != 1);
	

	
}
