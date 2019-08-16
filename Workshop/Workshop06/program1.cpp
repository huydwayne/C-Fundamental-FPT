#include <stdio.h>

int checkISBN(int n[]){
	int Total=0,multi=10;
	for (int i =0; i<9;i++){
		Total+=n[i]*multi;
		multi--;
	}
	return Total;
}

int main(){
	int ISBN[10];
	int I;
	do{	
	printf("ISBN Validator ================\n");
	printf("ISBN (0 to quit ) :");
	scanf("%d",&I);
	switch (I){
		case 0 : 
		printf("Have a Nice Day!");
		return 0 ;
		break;
		default : for (int i=9;i >= 0;i--){
			ISBN[i] = I%10;
			I=I/10;
	}
	int total = checkISBN(ISBN) + ISBN[9];
	if (total %11 == 0){
		printf("This is a valid ISBN \n");
	}else printf("This is not a valid ISBN\n");
	break;
	}
	}while (I >=0);
}
	

