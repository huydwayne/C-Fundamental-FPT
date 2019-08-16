#include <stdio.h>
#include <string.h>

main(){
	char array[100][20];
	
//	scanf("%20[^\n]", array[0]);
	int count = 0;
	int choice = 0;
	do {
		printf("Nhap lua chon: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				fflush(stdin);
			printf("Nhap them 1 sinh vien: ");
			scanf("%20[^\n]",&array[count]);
			count++;
			break;
			case 2:
			printf("Cac sinh vien la: \n");
			for (int i = 0; i < count; i++){
				printf("Sinh vien thu %d la %s \n", i+1, array[i]);
			}
			break;
		}
		fflush(stdin);
	} while (choice != 0);
}
