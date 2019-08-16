#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	time_t t;
	int pick1=1,pick2,x,y,total;
	do{
	printf("Total you want between 3 and 19: ");
	scanf("%d",&total);
	}while (total<2&&total>20);
	srand((unsigned) time(&t));
	do{
		x=1+rand()%10;
		y=1+rand()%10;
		pick1++;
		pick2=pick1+1;
		printf("Result of picks %d and %d : %d + %d \n",pick1,pick2,x,y);
	}while (x+y!=total);
}
