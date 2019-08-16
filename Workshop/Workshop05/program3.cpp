#include <stdio.h>
#include <stdlib.h>
//--------------------
//valid date
int validdate(int day,int month,int year)
{
	int maxday = 31;
	if(day<0||day>32||month<0||month>13)
	return 0;
	if (month == 4|| month == 6 || month == 9 || month == 11 )
	maxday =30;
	else if (month == 2 )
		{ if (year % 400 == 0 || (year%4==0 && year %100!=0))
		maxday =29;
		else maxday =28;
		}
	return day <= maxday;
}
//-------------------------
//print ASCII between 2 character
void Character(char c1,char c2 )
{	int i;
	if (c1>c2){
		c1+=c2;
		c2=c1-c2;
		c1-=c2;
	}
	for(i=c1;i<c2;i++)
	printf("%c : %d, %o, %X\n",i,i,i,i);
	
}
//--------------------------
//menu
int main()
{
	int choose;
	
	do{
	printf("1.Processing date data\n");
	printf("2.Character data\n");
	printf("3.Quit\n");
	scanf("%d",&choose);
	fflush(stdin);
	switch (choose){
		case 1 :int day,month,year; 
				printf("enter date : ");
				scanf("%d%*c%d%*c%d",&day,&month,&year);
				if (validdate(day,month,year)==1)
				printf("date is valid\n");
				else printf("date is invalid\n");
				break;
		case 2 :int c1,c2;
				printf("enter two characters : ");
				scanf("%c %c",&c1,&c2);
				Character(c1,c2);
				break; 
		case 3 : return 0;
		}
	}while (choose >0 &&choose < 3);
}
