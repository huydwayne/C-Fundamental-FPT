#include <stdio.h>

int const pa = 9000000;
int const pd = 3600000;
int income = 0;
int numberDependent = 0;
float const LEVEL_1 = 0.05;
float const LEVEL_2 = 0.1;
float const LEVEL_3 = 0.15;
float const LEVEL_4 = 0.2;


main(){
	
	printf("Nhap income cua ban: ");
	scanf("%d", &income);
	printf("Nhap so dependent: ");
	scanf("%d", &numberDependent);
	
	unsigned int tf = 12*( pa + numberDependent*pd);
//	printf("%d", taxFreeIncome);
	
	int ti = income - tf;
	int incomeTax;
	if (ti <= 0) {
		incomeTax = 0;
	}
	else if (ti <= 5000000) {
		incomeTax = ti * LEVEL_1;
	} 
	else if (ti > 5000000 && ti <= 10000000) {
		incomeTax = ti * LEVEL_2;
	} 
	else if (ti > 10000000 && ti <= 18000000) {
		incomeTax = ti * LEVEL_3;
	}
	else if (ti > 18000000 ) {
		incomeTax = ti * LEVEL_4;
	}
	
	printf ("Your income of this year: %d\n", income);
	printf ("Number of dependent: %d\n", numberDependent);
	printf ("Tax-free income: %d\n", tf);
	printf ("Taxable income: %d\n", ti);
	printf ("Income tax: %d", incomeTax);
	
}
