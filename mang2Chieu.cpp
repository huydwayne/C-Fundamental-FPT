#include <stdio.h>

sapXep ( int array[], int length) {

	for (int i = 0; i < length; i++){
		if ( array[i] > array[i+1] && ( i + 1 )< length){
			int temp = array[i];
			array[i] = array[i+1];
			array[i+1] = temp;
			i = 0;
		}
	}
}

timPhanTu (int x, int array[][10]){
	
}

main(){
	int n;
	printf("Nhap vao so n: ");
	scanf("%d", &n);
	int A[n][n];
	int sum = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("A[%d][%d] = ", i, j);
			scanf("%d", &A[i][j]);
			if (i == j) {
				sum += A[i][j];
			}
		}
	}
	printf("\n Mang la: \n");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%5d", A[i][j]);
		}
		printf("\n");
	}
	
	int tempA[n*n];
	int length = 0;
		for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tempA[length] = A[i][j];
			length++;
		}
				printf("\n");

	}
	sapXep(tempA, n*n);
		
	int row = 0;
	int column = 0;
	int count = 0;
	for (int i = 0; i < n*n; i++) {
		A[row][column]  = tempA[i];
		column++; 
		count++;
		if (count == n) {
			row++;
			column = 0;
			count = 0;
		}
	}
		printf("\n Mang la: \n");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%5d", A[i][j]);
		}
		printf("\n");
	}
	
//	printf("\nTong cac phan tu o dong le la %d", sum);
}
