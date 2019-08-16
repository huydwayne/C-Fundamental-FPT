#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int time = 0;

void readname(char code[][8], char name[][20], double salary[][1], double allowance[][1], int time){
	printf("Enter the code : ");
	fflush(stdin);
	scanf("%[^\n]",code[time]);
	printf("Enter the name :");
	fflush(stdin);
	scanf("%[^\n]",name[time]);
	printf("Enter the salary :");
	fflush(stdin);
	scanf("%[^\n]",salary[time]);
	printf("Enter the salary :");
	fflush(stdin);
	scanf("%[^\n]",allowance[time]);
}

void findData(char code[][8], char name[][20], double salary[][1], double allowance[][1], char temp[]){
	for(int i =0;i <time ; i++){
		int result = strcmp(code[i],temp);
		if(result == 0){
			puts(name[i]);
			printf("salary : %d\n",salary[i]);
			printf("allowance : %d\n",allowance[i]);
		}
	}	
}

void removeData(char code[][8], char name[][20], double salary[][1], double allowance[][1], char temp[]){
	int indexFound ;
	for(int i =0;i <time ; i++){
		int result = strcmp(code[i],temp);
		if(result == 0){
			indexFound = i ;
		}
	}
	for (int i = indexFound; i < time; i++){	//lay vi tri tren remove de len vi tri muon remove
		for (int j = 0; j < 40; j++) {
			code[i][j] = code[i+1][j];
			name[i][j] = name[i+1][j];
			salary[i][j] = salary[i+1][j];
			allowance[i][j] = allowance[i+1][j];
		}
	}
	time--;	
}

void swapStudent(char code[][8], char name[][20], double salary[][1], double allowance[][1], int time){
	char temp[40];
	for(int i = 0; i< time; i++){
		for(int j = time ; j > i; j--){
			double result1=salary[i][j] + allowance[i][j];
			double result2=salary[i][j-1] + allowance[i][j-1];
			if(result1 > result2){
				strcpy(temp,name[j]);
				strcpy(name[j],name[j-1]);
				strcpy(name[j-1],temp);
				
				strcpy(temp,code[j]);
				strcpy(code[j],code[j-1]);
				strcpy(code[j-1],temp);
			}
		}
	}
}

main(){
	int choice;
	char codeEmployee[100][8];
	char nameEmployee[100][20];
	char tempCode[8];
	double salary[100][1],allowance[100][1];
	do{
		printf("1.Adding a new employee\n");
		printf("2.Find data about employees\n");
		printf("3.Remove an employee \n");
		printf("4.Print the list in descending order\n");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice){
			case 1:
				system("cls");
				readname(codeEmployee,nameEmployee,salary,allowance,time);
				time++;
				break;
			case 2:
				system("cls");
				printf("Enter the code of the employee : ");
				fflush(stdin);
				scanf("%[^\n]",tempCode);
				findData(codeEmployee,nameEmployee,salary,allowance,tempCode);
				break;
			case 3:
				system("cls");
				printf("Enter the code of the employee : ");
				fflush(stdin);	
				scanf("%[^\n]",tempCode);
				removeData(codeEmployee,nameEmployee,salary,allowance,tempCode);
				break;
			case 4:
				system("cls");
				
		}
	}while (choice >0 && choice <5);	
} // giac mo tuyet trang
