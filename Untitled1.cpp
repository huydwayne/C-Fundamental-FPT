#include <stdio.h>
#include <stdlib.h>
main(){
	double number_1, number_2;
	printf("Nhap 2 so: ");
	int checkCount = scanf("%lf %lf", &number_1, &number_2);
	
	while (checkCount != 2) {
		fflush(stdin);
		printf("\n");
		printf("Hai so vua duoc nhap la: %lf - %lf\n", number_1, number_2);
		printf("checkCount = %d; Khong phai la so duoc nhap vao\n", checkCount);
		printf("Vui long nhap lai 2 so: ");
		checkCount = scanf("%lf %lf", &number_1, &number_2);
	}
	
	printf("\nBan da nhap thanh cong\n");
	printf("Gia tri checkCount la: %d, Gia tri 2 so ban vua nhap la: %lf - %lf", checkCount, number_1, number_2);
}
