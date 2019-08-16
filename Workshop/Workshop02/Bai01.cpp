#include <stdio.h>

main(){
	double numberOne, numberTwo;
	char operationChoice;
	double result=0;
	
	
	printf("Nhap vao so thu 1: ");
	scanf("%lf", &numberOne);
	printf("Nhap vao so thu 2: ");
	scanf("%lf", &numberTwo);
	
	printf("Chon thuat toan ban muon su dung (+ - * /): ");
	scanf("%s", &operationChoice);
	
//	printf("%c", operationChoice);
	
	switch(operationChoice) {
		case '+':
		printf("Ket qua la: %lf", result = numberOne + numberTwo);
		break;
		
		case '-':
		printf("Ket qua la: %lf", result = numberOne - numberTwo);
		break;
		
		case '*':
		printf("Ket qua la: %lf", result = numberOne * numberTwo);
		break;
		
		case '/':
		if ( numberTwo == 0 )  {
			printf("Divide by 0");
		} else printf("ket qua la: %lf", result = numberOne / numberTwo);
		break;
		
		default:
		printf("Operation not supported");
		break;
	}
	
}
