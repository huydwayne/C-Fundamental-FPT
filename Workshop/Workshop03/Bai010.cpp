#include <stdio.h>
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
	int n;
	do {
		printf("Nhap n: ");
		scanf("%d", &n);
		printMinMaxDigits(n);
	} while (n < 0);
}


