#include <stdio.h>
#include <math.h>
int prime( int n ) {
	
int m = sqrt(n); /* m: square root of n */
int i; /* variable having value from 2 to m */

for ( i=2; i <= m; i++) {
	if (n%i==0) return 0 ; 
} 
return 1; /* n is a prime */
}

void printMinMaxDigits( int n)
	{ int digit; /* Variable for extracting 1 digit */
	int min, max ; /* Result variables */
	digit = n% 10; /* get the first rightmost digit: 3 */
	int remainder = digit;
	n=n/10; /* 1029, the remainder needs to proceed after*/
	min = max = remainder; /* initialize results */
	while (n > 0)
	{ digit = n%10; /* Get the next digit */
	n=n/10;
	remainder = digit;
	if (min > remainder) min=remainder; /* update results */
	if (max < remainder) max=remainder;
	}
	printf("%d ", min);
	printf("%d", max);
}

main(){
	int choice = 0;
	do {
		printf("1- Process primes\n");
		printf("2- Print min, max digit in an integer\n");
		printf("3- Quit\n");
		printf("Select an operation: ");
		scanf("%d", &choice);
		switch (choice) {
			int n;
			case 1:
			do {
				printf("Nhap n: ");
				scanf("%d", &n);
			} while (n<0);
			if (prime(n) == 1) {
				printf("It is a prime\n");
			} else printf("It is not a prime \n");
			break;
			
			case 2:
			do {
				printf("Nhap n: ");
				scanf("%d", &n);
			} while (n < 0);
			printMinMaxDigits( n );
			printf("\n");
			break;
		}
	} while (choice > 0 && choice < 3);
}
