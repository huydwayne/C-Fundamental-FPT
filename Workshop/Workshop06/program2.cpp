#include<stdio.h>
#include <stdlib.h>

Searchvalue(int arr[],int n){
	int solan=0;
	for (int i = 0 ; i<100;i++){
		if(arr[i]== n)
			solan ++;
	}
	printf("trong chuoi co tong cong %d phan tu %d ",solan,n);
}

swap(int min , int  max ){
	min = min +max;
	max = min - max;
	min -=max;
}

main(){
	int choice,i=0;
	int arr[100];
	int length;
	do{
	printf("1- Add  a value\n");
	printf("2- Search a value\n");
	printf("3- Print out the array \n");
	printf("4- Print out values in a range\n");
	printf("5- Print out the array in ascending order\n");
	printf("Others- Quit\n");
	printf("Choice : ");
	scanf("%d",&choice);
	switch (choice){
		case 1 : scanf("%d",&arr[i]);
			i++;
			break;
		case 2 : int n;
			printf("Phan tu trong chuoi ban muon : ");
			scanf("%d",&n);
			Searchvalue(arr,n);
			break;
		case 3 :
			for ( length = 0 ;length<i;length++)
			printf("%5d",arr[length]);
			printf("\n");
			break;
		case 4 :
			int minVal,maxVal;
			printf("nhap min value : ");
			scanf("%d",&minVal);
			printf("nhap max value : ");
			scanf("%d",&maxVal);
			if (minVal>maxVal){
				swap(minVal,maxVal);
			}
			for ( length = 0 ; length <i;length++){
				if (arr[length]>minVal && arr[length]<maxVal)
				printf("%4d",arr[length]);
			}
			printf("\n");
			break;
		case 5 :
			int temparr[i];
			for (length =0; length < i; length ++){
				temparr[length] = arr[length];
			}  			
			
			for (length = 0; length < i; length++) {
				int index = length; // cho thang index la thang nho~
				for (int tempLength = length + 1; tempLength < i; tempLength++){
					if (temparr[index] > temparr[tempLength]) {
						index = tempLength;
						
					}
				}
				if (index != length) {
					int temp = temparr[index];
					temparr[index] = temparr[length];
					temparr[length] = temp;
				}
			}
			printf("\n");
			printf("Mang sau khi sap xep la: ");
			for (length =0; length < i; length ++){
				printf("%d ", temparr[length]);
			}  
			printf("\n");
			break;
	}
}while (choice >=1 && choice <=5);
}
