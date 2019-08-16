#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int time=0;

void addStudent(char name[][40],int n){
		printf("Enter student name : ");
		fflush(stdin);
		scanf("%[^\n]",name[n]);
		strupr(name[n]);
}

void removeStudent(char name[][40], char tempName[]){
	int indexFound = 0;
	for (int i = 0 ; i<time ;i++){
			int result = strcmp(name[i],tempName);
			if( result == 0 ){
				indexFound = i;
		} // kiem dc vi tri ten muon remove
	}
	for (int i = indexFound; i < time; i++){	//lay vi tri tren remove de len vi tri muon remove
		for (int j = 0; j < 40; j++) {
			name[i][j] = name[i+1][j];
		}
	}
	time--;		
}

void searchStudent(char name[][40], char tempName[]){
	for (int i = 0 ; i < time ; i++){
			int result = strcmp(name[i],tempName);
			if( result == 0 ){
				printf("%d : %s",i+1,tempName);
			}
}
}

void swapStudent(char name[][40], int time){
	char tempName[40];
	for(int i = 0; i< time; i++){
		for(int j = time ; j > i; j--){
			if(strcmp(name[j], name[j-1]) < 0){
				strcpy(tempName,name[j]);
				strcpy(name[j],name[j-1]);
				strcpy(name[j-1],tempName);
			}
		}
	}
}

main(){	
	char student[100][40];
	char tempName[40] ;
	int choice;
	do{
		printf("1- Add a student\n");
		printf("2- Remove a student\n");
		printf("3- Search a student\n");
		printf("4- Print the list in ascending order\n");
		printf("5- Quit ");
		scanf("%d",&choice);
		switch (choice){
			case 1:
				system("cls");
				addStudent(student,time);
				time ++;
				break;
			case 2:
				system("cls");
				printf("Remove student name :");
				fflush(stdin);
				scanf("%[^\n]",tempName);
				strupr(tempName);
				removeStudent(student,tempName);
				break;
			case 3:
				system("cls");
				printf("Search student name :");
				fflush(stdin);
				scanf("%[^\n]",tempName);
				strupr(tempName);
				break;
			case 4:
				system("cls");
				fflush(stdin);
				swapStudent(student,time);
				for(int i = 0 ; i< time;i++){
				printf("student number %d : %s\n",i+1,student[i]);
			}
				break;
			case 5:
				return 0;
		}
	//	system("cls");
	}while(choice>0 && choice <6);
}

