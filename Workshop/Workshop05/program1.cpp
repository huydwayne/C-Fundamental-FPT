#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{	
int total,x,y,count=1;
	time_t t;
	do{
		printf("nhap tong 2 mat xuc xac : ");
		scanf("%d",&total);
	}
	while (total<2||total>12);
	srand((unsigned) time(&t));
	do{
		x=1+rand()%6;
		y=1+rand()%6;
		printf("\nket qua lan %d :%d+%d\n",count,x,y );
		count ++;		
	}
	while (x+y!=total);
}
